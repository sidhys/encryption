#include <Windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
short ReadSect
(const char* _dsk,    // disk to access
    char*& _buff,         // buffer where sector will be stored
    unsigned int _nsect   // sector number, starting with 0
)
{
    DWORD dwRead;
    HANDLE hDisk = CreateFile(_dsk, GENERIC_READ, FILE_SHARE_VALID_FLAGS, 0, OPEN_EXISTING, 0, 0);
    if (hDisk == INVALID_HANDLE_VALUE) // this may happen if another program is already reading from disk
    {
        CloseHandle(hDisk);
        return 1;
    }
    SetFilePointer(hDisk, _nsect * 512, 0, FILE_BEGIN); // which sector to read

    ReadFile(hDisk, _buff, 512, &dwRead, 0);  // read sector
    CloseHandle(hDisk);
    return 0;
}

int main()
{
    char* drv = "\\\\.\\C:";
    char* dsk = "\\\\.\\PhysicalDrive0";
    int sector = 0;

    char* buff = new char[512];
    ReadSect(dsk, buff, sector);
    if ((unsigned char)buff[510] == 0x55 && (unsigned char)buff[511] == 0xaa) cout << "Disk is bootable!" << endl;


    getchar();

}