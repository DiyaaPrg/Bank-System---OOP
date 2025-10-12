#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsString.h"
#include <iomanip>

using namespace std;

class clsShowTransferLogListScreen : protected clsScreen
{
private:
    static void _PrintDataLine(clsBankClient::stTransferLogRecord record)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << record.DateTime;
        cout << "| " << setw(10) << left << record.UserName;
        cout << "| " << setw(10) << left << record.dAccount;
        cout << "| " << setw(10) << left << record.Amount;
        cout << "| " << setw(10) << left << record.sBalance;
        cout << "| " << setw(10) << left << record.dBalance;
        cout << "| " << setw(10) << left << record.sAccount;
    }

public:

    static void ShowTransferLogListScreen()
    {
        vector < clsBankClient::stTransferLogRecord> vTransferRegister = clsBankClient::GetTransferLogRecord();

        string Title = "\t Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferRegister.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t___________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t___________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        if (vTransferRegister.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord record : vTransferRegister)
            {
                _PrintDataLine(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t___________________________________________________";
        cout << "_____________________________________________________________\n" << endl;


    }


};