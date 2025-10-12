#pragma once
#include <iostream>
#include <vector>
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;


class clsShowUpdateRateScreen : protected clsScreen
{
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
	static void ShowUpdateRateScreen()
	{
		system("cls");
		_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nPlease Enter Currency Code: ";

		clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::Readtext());

		while (Currency.IsEmpty())
		{
			cout << "\nCurrency is not Found! Choose another one: ";
			Currency = clsCurrency::FindByCode(clsInputValidate::Readtext());
		}

		_PrintCurrency(Currency);

		cout << "\nAre you sure you want to update the rate of this country? (y/n): ";
		string answer = clsInputValidate::Readtext();

		if (answer == "Y" || answer == "y")
		{
			cout << "\n\nUpdate Currency Rate\n";
			cout << "\n___________________________\n";
			cout << "\nEntet New Rate: ";
			Currency.UpdateRate(clsInputValidate::ReadFLoat());

			cout << "\n\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);

		}
		else
			return;
	}


};

