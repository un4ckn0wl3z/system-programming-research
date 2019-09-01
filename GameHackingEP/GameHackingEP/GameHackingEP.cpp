// GameHackingEP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>

// Obtaining the Game’s Process Identifier
DWORD getPIDFromWindow(HWND window)
{
	DWORD PID; // ประกาศตัวแปร dword ไว้เก็บ PID
	GetWindowThreadProcessId(window, &PID); // เรียกใช้ GetWindowThreadProcessId เพื่อ get pid
	return PID; // return pid
}

// Obtaining the Game’s Process Identifier
DWORD getPIDByName(std::wstring name)
{
	DWORD PID = -1;

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL); // เก็บ process list

	if (Process32First(snapshot, &entry) == TRUE) // initial snapshot
	{
		while (Process32Next(snapshot, &entry) == TRUE) // iterator over that list
		{
			std::wstring binaryPath = entry.szExeFile;
			if (binaryPath.find(name) != std::wstring::npos)
			{
				PID = entry.th32ProcessID; // get pid
				break;
			}
		}
	}

	CloseHandle(snapshot);
	return PID; // ret pid

}

DWORD getMyBaseAddressGMH()
{
	return (DWORD)GetModuleHandle(NULL);
}

DWORD getMyBaseAddressFS()
{
	DWORD newBase;
	__asm
	{
		MOV EAX, DWORD PTR FS : [0x30]
		MOV EAX, DWORD PTR DS : [EAX + 0x8]
		MOV newBase, EAX
	}
	return newBase;
}

DWORD getRemoteBaseAddress(HANDLE process)
{
	DWORD newBase;
	// get the address of kernel32.dll
	HMODULE k32 = GetModuleHandleA("kernel32.dll");

	// get the address of GetModuleHandle()
	LPVOID funcAdr = GetProcAddress(k32, "GetModuleHandleA");
	if (!funcAdr) funcAdr = GetProcAddress(k32, "GetModuleHandleW");

	// create the thread
	HANDLE thread = CreateRemoteThread(process, NULL, NULL, (LPTHREAD_START_ROUTINE)funcAdr, NULL, NULL, NULL);

	// let the thread finish
	WaitForSingleObject(thread, INFINITE);

	// get the exit code
	GetExitCodeThread(thread, &newBase);

	// clean up the thread handle
	CloseHandle(thread);

	return newBase;
}



void printMyBaseAddresses(HANDLE Process)
{
	DWORD base1 = getMyBaseAddressGMH();
	DWORD base2 = getMyBaseAddressFS();
	DWORD base3 = getRemoteBaseAddress(Process);
	if (base1 != base2 || base2 != base3)
		printf("Woah, this should be impossible!\n");
	else
		printf("My base address is 0x%08x\n", base1);
}


template<typename T> // read process memory
T readMemoryAPI(HANDLE process, LPVOID address)
{
	T value;
	ReadProcessMemory(process, address, &value, sizeof(T), NULL);
	return value;
}

template<typename T> // write process membory
void writeMemoryAPI(HANDLE process, LPVOID address, T value)
{
	WriteProcessMemory(process, address, &value, sizeof(T), NULL);
}


template<typename T>
DWORD protectMemory(HANDLE process, LPVOID address, DWORD prot)
{
	DWORD oldProt;
	VirtualProtectEx(process, address, sizeof(T), prot, &oldProt);
	return oldProt;
}



void readAndWriteMemoryAPI(HANDLE process, LPVOID address)
{
	DWORD value = readMemoryAPI<DWORD>(process, address);

	printf("Current mem value is %d\n", value);
	value++;

	DWORD oldProt = protectMemory<DWORD>(process, address, PAGE_READWRITE);
	writeMemoryAPI<DWORD>(process, address, value);
	protectMemory<DWORD>(process, address, oldProt);


	value = readMemoryAPI<DWORD>(process, address);

	printf("New mem value is %d\n", value);
}

template<typename T>
T readMemoryPointer(LPVOID address)
{
	return *((T*)address);
}

template<typename T>
void writeMemoryPointer(LPVOID address, T value)
{
	*((T*)address) = value;
}

template<typename T>
T* pointMemory(LPVOID address)
{
	return ((T*)address);
}
void readAndWriteMemoryMarshall(LPVOID address)
{
	DWORD value = readMemoryPointer<DWORD>(address);

	printf("Current mem value is %d\n", value);
	value++;

	writeMemoryPointer<DWORD>(address, value);
	value = readMemoryPointer<DWORD>(address);

	printf("New mem value is %d\n", value);
}

DWORD rebase(DWORD address, DWORD newBase) {
	DWORD diff = address - 0x400000;
	return diff + newBase;
}

int main()
{
    // std::cout << "Hello World!\n"; 


	HANDLE proc = OpenProcess(
		PROCESS_VM_OPERATION |
		PROCESS_VM_READ |
		PROCESS_VM_WRITE |
		PROCESS_CREATE_THREAD,
		FALSE, GetCurrentProcessId());

	if (proc == INVALID_HANDLE_VALUE) {
		printf("Failed to open PID %d, error code %d",
			GetCurrentProcessId(), GetLastError());
		exit(0);
	}


	// print base address
	printMyBaseAddresses(proc);


	/* example using memory Read and Write template API*/

	/*
	DWORD adr = 0xBADF00D;
	DWORD value = readMemoryAPI<DWORD>(proc, (void*) adr); // read
	writeMemoryAPI<DWORD>(proc, (void*) adr, value++); // increment and write
	*/


	/* example using protectMemory template API*/
	/*
	DWORD adr = 0xBADF00D;
	protectMemory<DWORD>(proc, &adr, PAGE_READWRITE);
	writeMemoryAPI<DWORD>(proc, &adr, 999999);
	*/



	/* example restore Memory protection API*/
	/*
	DWORD adr = 0xBADF00D; 
	DWORD oldProt = protectMemory<DWORD>(proc, (void*)adr, PAGE_READWRITE);
	writeMemoryAPI<DWORD>(proc, (void*)adr, 999999);
	protectMemory<DWORD>(proc, (void*)adr, oldProt);
	*/





	//----------------------------------------------------------------

	// get my PID from window
		wchar_t myTitle[1024];
	GetConsoleTitle(&myTitle[0], 1024);
	HWND myWindow = FindWindow(NULL, myTitle);

	auto myPID = getPIDFromWindow(myWindow);
	printf("My pid is %d\n", myPID);

	// get explorer PID by process name
	auto explorerPID = getPIDByName(L"explorer.exe");
	printf("Explorer pid is %d\n", explorerPID);


	// lets do some memory stuff.. to ourself
	DWORD someValue = 1234;
	readAndWriteMemoryAPI(proc, &someValue);
	readAndWriteMemoryMarshall(&someValue);

	system("pause");



	//----------------------------------------------------------------




	// closing handle
	CloseHandle(proc);


}


