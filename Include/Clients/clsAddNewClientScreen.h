#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::Readtext();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::Readtext();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::Readtext();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::Readtext();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::Readtext();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFLoat();
    }

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

public:

    static void ShowAddNewClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermessions::AddNewClient))
        {
            return;
        }

        _DrawScreenHeader("\t Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::Readtext();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::Readtext();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::SvSucceded:
        {
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::SvFailedEmptyObj:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::SvFailedObjectExisted:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }



};

