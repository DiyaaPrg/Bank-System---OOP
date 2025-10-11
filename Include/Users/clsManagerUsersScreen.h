#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManagerUsersScreen : protected clsScreen
{
private:

    enum _enManageUsersOptions
    {
        ListUsers = 1, Adduser = 2, Deleteuser = 3, Updateuser = 4, Finduser = 5, MainMenue = 6
    };

    static short _ReadManagerUsersOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersScreen()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Manage Users Menue...\n";
        system("pause>0");
        system("cls");
        ShowManageUsersMenueScreen();
    }

    static void _ShowListUsersScreen()
    {
        clsUsersListScreen::ShowUsersList();
    }

    static void _ShowAddUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::_ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersOptions(_enManageUsersOptions option)
    {

        system("cls");
        switch (option)
        {
        case (_enManageUsersOptions::ListUsers):
        {
            _ShowListUsersScreen();
            _GoBackToManageUsersScreen();
            break;
        }

        case (_enManageUsersOptions::Adduser):
        {
            _ShowAddUserScreen();
            _GoBackToManageUsersScreen();

            break;
        }

        case (_enManageUsersOptions::Deleteuser):
        {
            _ShowDeleteUserScreen();
            _GoBackToManageUsersScreen();
            break;
        }

        case (_enManageUsersOptions::Updateuser):
        {
            _ShowUpdateUserScreen();
            _GoBackToManageUsersScreen();
            break;
        }

        case (_enManageUsersOptions::Finduser):
        {
            _ShowFindUserScreen();
            _GoBackToManageUsersScreen();
            break;
        }

        case (_enManageUsersOptions::MainMenue):
        {

        }
        }
    }


public:

    static void ShowManageUsersMenueScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermessions::ManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tManager Users\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersOptions((_enManageUsersOptions)_ReadManagerUsersOption());
    }

};

