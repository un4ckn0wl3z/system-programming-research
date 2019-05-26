# CPP / C++ Notes - Windows API Programming Win32

สวัสดีครับ วันนี้จะมาแปะโน็ตเกี่ยวกับ **Windows API Programming Win32**. เอาไว้บน github นะครับพอดีศึกษา c++ แบบ advance อยู่อิอิ จริงๆ อยากจะโน็ตไว้ที่ blog ส่วนตัว แต่อีกใจนึงก็ขี้เกียจ เลยโน็ตไว้ที่ github ดีฝ่า มาเริ่มกันเลยย

## Windows API Programming Win32

### Overview
Windows API ก็คือ พวก low-level function ต่างๆของ Windows ซึ่งหน้าตาการเขียนจะเหมือนกับ c++ จะแบ่งเป็น library ย่อยๆต่างๆได้แก่
***Windows Only - Microsft:***
-   [MFC](https://docs.microsoft.com/en-us/cpp/mfc/mfc-and-atl?view=vs-2017)  - Microsoft Foundation Classes
-   [ATL](https://docs.microsoft.com/en-us/cpp/atl/atl-com-desktop-components?view=vs-2017)  - Active Template Library

***Windows Only - Third party.:***
- [WTL](https://en.wikipedia.org/wiki/Windows_Template_Library) - Windows Template Library - Created by Microsft and later become opensourced at 2004.
-   [Win32++](http://win32-framework.sourceforge.net/)  - "Win32++ is a C++ library used to build windows applications. Win32++ is a free alternative to MFC. It has the added advantage of being able to run on a wide range of free compilers, including Visual Studio Community, and the MinGW compiler provided with CodeBlocks and Dev-C++."

***Cross-Platform:***
- [QT Framework](https://en.wikipedia.org/wiki/Qt_(software)) - QT is not only a cross platform GUI library, it also provides all sort of cross platform libraries for databases, sockets, text parsing, OpenGL, XML and so on
- [wxWidgets](https://en.wikipedia.org/wiki/WxWidgets) - Just a well known GUI library.
- [Poco - Framework](https://pocoproject.org/docs/) - A collection of cross-platform libraries for network: HTTP protocol, FTP, ICMP; database access - SQLite, MySQL, ODBC and MongoDB; Standardized human-readable data exchange formats - JSON and XML; Zip compression; SSL and crypto utils.

___
### Idiosincrasies (ลักษณะเฉพาะตัวของ Win32 api)
- Win32 api จะใช้  Hungarian Notation
- จะมีลักษณะเป็น Non standard types มี type ต่างๆได้แก่
  - LPSTRING, WORD, DWORD, BOOL, LPVOID …
- Paths: จะมีความต่างกับ os ตระกูล *nix ที่ path นั้น จะเป็น (/) forward slash แต่ windows api path จะเขียนด้วย backward slash (\) ต้องทำการ escaped ก่อนนำไปใช้ เช่น จาก "C:\Users\sombody\file.exe" ไปเป็น "C:\\\Users\\\sombody\\\file.exe".
- มีการใช้ Calling Convention หลายแบบเช่น 
  - **__stdcall**
  - **__cdecl**
  - **__fastcall**
- จะ support พวก Character 2 แบบ คือ ANSI และ Unicode in API. ดังนั้น function ต่างๆ จะมีให้เลือกใช้ 2 version ขึ้นอยู่กับ target Character 
  - Windows API จะใช้ ขนาดความยาว 16-bit สำหรับ Unicode wide characters (wchar_t) ซึ่งจะต่างกับพวก os ตระกูล *nix ที่ใช้ ขนาดความยาว 8 bit กับพวก Unicode  UTF-8
  - Windows API แต่ละ function จะแบ่ง ออกเป็น 2 version สำหรับ support ANSI ส่วน ใหญ่ชื่อ function จะลงท้ายลง **'A'** และ อีก version สำหรับ support wide unicode จะลงท้ายด้วย **'W'**   ตัวอย่างเช่น api ที่ชื่อ **CreateDirectory** จะ support แค่ ANSI จะต้องไปใช้ **CreateDirectoryW** จะ support พวก Unicode (พวกตัวอักษร 'ã', 'õ', 'ç', ' 我', 'Ж')
- string จะมี type แยกย่อยเยอะมากๆ
- มี C-runtimes และ entry points ที่ต่างกันหลายตัว
- Function ของ Windows api นั้น มี parameter เยอะมาก บางทีจะ สับสนได้ วิธีเดียวที่จะรู้ว่ามันทำงานยังไงคือต้องลอง compile แล้วดู
- บาง Function ไม่มีแม้แต่ document -.-4
___
### Windows API Main Header Files
header ที่ต้องเรียกใช้เมื่อต้องการ call Windows api
-   #include <windows.h>
-   #include <wchar.h> - Wide Characters - UTF16 chars
-   #include <tchar.h>
-   #include <global.h>
-   #include <nsfbd.h>
___
***Details (รายละเอียดอื่นๆ)***

**windows.h**
-   Basic header file of Windows API

**WinError.h**

-   Error codes and strings

**tchar.h**

-   Provides the macro _T(…) and TEXT(…) for Unicode/ANSI string encoding handling.

**wchar.h**

-   Wide Character - UTF16 or wchar


**global.h
ntfsb.h
Winsock2.h**
- Network sockets

**Winbase.h**

-   Windows types definitions

**WinUser.h**

-   Windows Messages

**ShellAPI.h**

-   Shell API

**ShFolder.h**

-   Folder definitions

**Commdlg.h**

-   Commom Controls (COM based)


**Dlgs.h**

-   Dialog definitions


**IUnknown.h**

-   COM header

**conio.h**

-   Console Input/Output functions - it is heritage grom MSDOS.


___

### Windows API Runtime Libraries

**kernel32.dll**

-   Low level NTDLL wrappers.

**user32.dll**

-   User interface primitives used by graphical programs with menus, toolboxes, prompts, windows ..

**shell.dll**

**gdi32.dll**

-   Basic drawing primitives.

**ole32.dll**
**MSVCRT.DLL**

-   Implementation of the C standard library stdlib.

**advapi.dll**

-   Contains functions for system-related tasks such as registry and registry handling.

**WS_32.DLL**

-   Winsock2 library contains a socket implementation.

**Ntdll.dll**

-   Interface to Kernel. Not used by Windows programs directly.

**Wininet.dll**

-   Provides high level network APIs, for instance, HttpOpenRequest, FtpGetFile …
___
### Windows Object Code Binary Format and Scripting Languages
ไฟล์รูปแบบต่างๆ บน Windows

#### Native Code

| Extension | Executable Binary Format |Description
| ------ | ----------- |-----
| .exe | PE32 or PE64 | Windows Executable
| .dll| PE32 or PE64 | Dynamic Linked Library - It can be Native PE32, PE64 or .NET/CLR DLL
| .xll | PE32 or PE64 | Excel native Addin (extension or plugin). It is a dll with .xll extension.
| .pyd | PE32 or PE64 | Python native module on Windows - DLL with .pyd extension instead of .dll.
| .cpl | PE32 or PE64 | Control Panel Applet - Also a DLL with .cpl extension.
| .sys | PE32 or PE64 | Windows device driver (akin to Linux kernel modules)
| .ocx | PE32 or PE64 | Active Control X (DLL)


#### Special Files

| Extension | Executable Binary Format |Description
| ------ | ----------- |-----
| [Ntoskrnl.exe](https://en.wikipedia.org/wiki/Ntoskrnl.exe) | PE32 or PE64 | Windows-NT Kernel image
| [hall.dll](https://en.wikipedia.org/wiki/Microsoft_Windows_library_files#Hal.dll) | PE32 or PE64 | Hardware Abstraction Layer (HAL)


#### Compilation Binary Files

| Extension | Executable Binary Format |Description
| ------ | ----------- |-----
| .obj | - | Object file -> Input to linker before building an executable.
| .pdb | - | Program Debug Database => Contains executable or DLL debugging symbols.
| .lib | - | Oject File Library or import library
| .exp | - | Exports Library File
| .RES | - | Compiled resource script


#### Source and Project Files

| Extension | Executable Binary Format |Description
| ------ | ----------- |-----
| .def | - | Export Definition File
| .sln | - | Visual Studio Solution (Project file).
| .rs | - | Resource script - for embedding files into the executable.

---
#### Scripting Languages Files

| File Extension | Interpreter | Advantage | Description
| ------ | ----------- |-----|---
|.bat|cmd.exe|Simplicity|Batch Script - Legacy technology from MSDOS, but still useful for small automation.
|.vbs or vbe|WScript.exe or cscript.exe|COM + OOP|VBScript - Visual Basic Script
|.js or jse | JScript.exe |COM + OOP|-
|.wcf |- |-|Windows Script File - Allows using many script engines iside the same file.
|.ps1 .psm1 .ps1xml |Powershell |COM + OOP + .NET + Interactive |Powershell Script
|.reg |regedit.exe| - |Windows registry script. Modify Windows registry when executed.

