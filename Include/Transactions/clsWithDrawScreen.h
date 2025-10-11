#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsMainScreen.h"
using namespace std;


class clsWithDrawScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

    static double _ReadWithDrawAmount()
    {
        double Amount = 0;
        cout << "\nPlease enter withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();
        return Amount;
    }

public:


    static void ShowWithDrawScreen()
    {
        _DrawScreenHeader("\t   WithDraw Screen");


        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = _ReadWithDrawAmount();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.WithDraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

