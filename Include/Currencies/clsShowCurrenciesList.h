
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrency.h"
using namespace std;


class clsShowCurrenciesListScreen : protected clsScreen
{
    static void _PrintDataLine(clsCurrency record)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << record.Country();
        cout << "| " << setw(8) << left << record.CurrencyCode();
        cout << "| " << setw(45) << left << record.CurrencyName();
        cout << "| " << setw(10) << left << record.Rate();
    }

public:

    static void ShowCurrenciesList()
    {
        vector <clsCurrency> vCurrenciesList = clsCurrency::GetCurrenciesList();

        string Title = "\t Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrenciesList.size()) + ") Currency(ies).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrenciesList.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency record : vCurrenciesList)
            {
                _PrintDataLine(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

