#pragma once
#include <iostream>
#include <vector>
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;


class clsShowFindCurrencyScreen : protected clsScreen
{
	enum enFindCurrencyOptions {eByCode =1, eByCountry};

	static clsCurrency _FindCurrencyByCodeorCountry()
	{
		cout << "Find By: [1] Code or [2] Country? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 2, "Invalid Option! Enter Again: ");

		if (enFindCurrencyOptions(choice) == enFindCurrencyOptions::eByCode)
		{
			cout << "\nPlease enter Currency Code: ";
		    clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::Readtext());
			return Currency;
		}
		else
		{
			cout << "\nPlease enter Country: ";
			clsCurrency Currency = clsCurrency::FindByCountry(clsInputValidate::Readtext());
			return Currency;
		}
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

public:

	static void ShowFindCurrencyScreen()
	{
		system("cls");
		_DrawScreenHeader("\tFind Currency Screen");

		clsCurrency Currency = _FindCurrencyByCodeorCountry();

		if (Currency.IsCurrencyExist(Currency.CurrencyCode()))
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found :-(\n";
			_PrintCurrency(Currency);
		}

		
	}

};

