#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
#include <fstream>

class clsLogin : protected clsScreen
{
private:

	static bool _Login()
	{
        bool LoginFaild = false;
        short trials = 3;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                trials -= 1;
                cout << "You have " << trials << " Trials to Login!\n\n";
            }

            if (trials < 1 )
            {
                cout << "\n\nYou are Locked after 3 failed trials\n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();

	}




public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");

        return _Login();
	}


};

