#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "regretrieve.h"
using namespace std;
using namespace REG;

class writeReport {

public:
    
    void writereport()
    {
        string nothing = "placeholder";
    }

};

int main()
{   
    retrieve_reg rr;
    rr.retrievereg(255, "SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName", "ComputerName");
    rr.retrievereg(255, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\LogonUI", "LastLoggedOnDisplayName");
    system("pause");
    return 0;
}
