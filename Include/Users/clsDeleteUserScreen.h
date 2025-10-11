#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    
    static void _ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t Delete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::Readtext();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Don't Exist! Choose another one: ";
            UserName = clsInputValidate::Readtext();
        }

        clsUser User = User.Find(UserName);

        _PrintUser(User);

        string answer;
        cout << "Are you sure you want to delete this user? (y/n): ";
        cin >> answer;

        if (answer == "Y" || answer == "y")
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError! User Wasn't Deleted\n";
            }

        }

        _PrintUser(User);

    }



};

