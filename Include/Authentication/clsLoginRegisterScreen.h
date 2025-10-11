#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsString.h"
#include <iomanip>
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
    static void _PrintDataLine(clsUser::stLoginRegister record)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << record.DateTime;
        cout << "| " << setw(20) << left << record.UserName;
        cout << "| " << setw(15) << left << record.Password;
        cout << "| " << setw(10) << left << record.Permissions;
    }

public:

    static void ShowRegisterList()
    {
        if (!_CheckAccessRights(clsUser::enPermessions::ShowLoginRegister)) // this function is in a header but why it work well although I didn't include that header
        {
            return;
        }
        
        vector <clsUser::stLoginRegister> vLoginRegister = clsUser::GetRegisterList();

        string Title = "\t Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegister.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(10) << "Permessions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegister.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegister record : vLoginRegister)
            {
                _PrintDataLine(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};


