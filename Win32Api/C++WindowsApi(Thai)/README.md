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
- บาง Function ไม่มีแม้แต่ document -.-