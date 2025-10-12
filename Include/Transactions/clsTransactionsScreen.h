#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogListScreen.h";
using namespace std;



class clsTransactionsScreen : protected clsScreen
{
    enum _enTransactionsOptions
    {
        _Desposit = 1, _Withdraw = 2, _TotalBalances = 3, _Transfer = 4 , _TransferLog = 5, _MainMenueOption = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToTransactionsScreen()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Transactions Menue...\n";
        system("pause>0");
        system("cls");
        ShowTransactionsScreen();
    }

    static void _ShowDespositScreen()
    {
        clsDepositScreen::ShowDepositScreen();

    }

    static void _ShowWithdrawScreen()
    {
        clsWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalances()
    {
        clsTotalBalancesScreen::ShowTotalBalances();

    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogListScreen()
    {
        clsShowTransferLogListScreen::ShowTransferLogListScreen();
    }


    static void _PerformTransactionOptions(_enTransactionsOptions option)
    {
        system("cls");
        switch (option)
        {
        case (_enTransactionsOptions::_Desposit):
        {
            _ShowDespositScreen();
            _GoBackToTransactionsScreen();
            break;
        }

        case (_enTransactionsOptions::_Withdraw):
        {
            _ShowWithdrawScreen();
            _GoBackToTransactionsScreen();
            break;
        }

        case (_enTransactionsOptions::_TotalBalances):
        {
            _ShowTotalBalances();
            _GoBackToTransactionsScreen();
            break;
        }

        case (_enTransactionsOptions::_Transfer):
        {
            _ShowTransferScreen();
            _GoBackToTransactionsScreen();
            break;
        }

        case (_enTransactionsOptions::_TransferLog):
        {
            _ShowTransferLogListScreen();
            _GoBackToTransactionsScreen();
            break;
        }

        case (_enTransactionsOptions::_MainMenueOption):
        {

        }
        };
    }

public:
    static void ShowTransactionsScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermessions::Transactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionOptions((_enTransactionsOptions)_ReadTransactionsMenueOption());
    }



};

