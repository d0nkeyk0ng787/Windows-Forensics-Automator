#include<windows.h>
#include<iostream>
namespace REG
{
    class retrieve_reg
    {
        public:

            //Reusable varibales for registry gets
            HKEY HKLM = HKEY_LOCAL_MACHINE;
            HKEY HKCU = HKEY_CURRENT_USER;

            void retrievereg(int buffer, LPCSTR subkey, LPCSTR name){
                HKEY key;
                char value[255];
                DWORD Buffer = buffer;
                RegOpenKey(HKLM, subkey, &key);
                RegGetValue(HKLM, subkey, name, RRF_RT_ANY, NULL, (PVOID)&value, &Buffer);
                RegCloseKey(key);
                std::cout <<"This system is named: "<<value<<std::endl;
            }
    };
};