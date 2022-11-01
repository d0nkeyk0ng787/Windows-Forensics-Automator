#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

class Actions {

public:

    //Reusable varibales for registry gets
    HKEY HKLM = HKEY_LOCAL_MACHINE;
    HKEY HKCU = HKEY_CURRENT_USER;

    void getHostname()
    {
        HKEY hostnameKey;
        char computername[255];
        DWORD hostBuffer = 255;
        LPCSTR subkey = "SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName";
        LPCSTR name = "ComputerName";
        RegOpenKey(HKLM, subkey, &hostnameKey);
        RegGetValue(HKLM, subkey, name, RRF_RT_ANY, NULL, (PVOID)&computername, &hostBuffer);
        RegCloseKey(hostnameKey);
        std::cout <<"This system is named: "<<computername<<std::endl;
    }

    void getUsername()
    {
        HKEY userKey;
        char username[255];
        DWORD userBuffer = 255;
        LPCSTR usernamekey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\LogonUI";
        LPCSTR usernamename = "LastLoggedOnDisplayName";
        RegOpenKey(HKLM, usernamekey, &userKey);
        RegGetValue(HKLM, usernamekey, usernamename, RRF_RT_ANY, NULL, (PVOID)&username, &userBuffer);
        RegCloseKey(userKey);
        std::cout <<"The current user is: "<<username<<std::endl;
    }
    
    void getIP()
    {
        string nothing = "placeholder";
    }
};

int main()
{   
    Actions obj1;
    obj1.getHostname();
    obj1.getUsername();
    //obj1.getIP();
    system("pause");

    return 0;
}
