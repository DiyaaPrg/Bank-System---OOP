#pragma once
#include <iostream>
#include <vector>
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsShowCurrenciesListScreen.h"
#include "clsShowFindCurrencyScreen.h"
#include "clsShowUpdateRateScreen.h"
#include "clsShowCurrencyCalculatorScreen.h"
using namespace std;


class clsShowCurrenciesScreen : protected clsScreen
{
private:
    enum enCurrencyMenueOptions {eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5 };

    static short _ReadCurrenciesMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrenciesScreen()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Currencies Menue...\n";
        system("pause>0");
        system("cls");
        ShowCurrenciesScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsShowCurrenciesListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsShowFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsShowUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsShowCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyOptions(enCurrencyMenueOptions option)
    {
  
        switch (option)
        {
        case (enCurrencyMenueOptions::eListCurrencies):
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrenciesScreen();
            break;
        }

        case (enCurrencyMenueOptions::eFindCurrency):
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesScreen();
            break;
        }

        case (enCurrencyMenueOptions::eUpdateRate):
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrenciesScreen();
            break;
        }

        case (enCurrencyMenueOptions::eCurrencyCalculator):
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesScreen();
            break;
        }

        case (enCurrencyMenueOptions::eMainMenue):
        {

        }
        };
    }



public:

    static void ShowCurrenciesScreen()
    {
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "=============================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "=============================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "=============================================\n";

        _PerformCurrencyOptions(enCurrencyMenueOptions(_ReadCurrenciesMenueOption()));
    }
};

