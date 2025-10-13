#pragma once
#include <iostream>
#include <vector>
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "Char.h"
using namespace std;

class clsShowCurrencyCalculatorScreen : protected clsScreen
{
	static void _PrintCurrency(clsCurrency Currency, string text)
	{
		cout << text << endl;
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

	static clsCurrency _GetCurrency(string message)
	{
		cout << message;

		clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::Readtext());

		while (Currency.IsEmpty())
		{
			cout << "\nCurrency is not Found! Choose another one: ";
			Currency = clsCurrency::FindByCode(clsInputValidate::Readtext());
		}
		return Currency;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrency(Currency1, "Convert From:");

		if (Currency1.CurrencyCode() == "USD")
		{
			cout << Amount << " " << Currency1.CurrencyCode()
				<< " = " << Currency1.ConvertFromUSD(Amount, Currency2) << Currency2.CurrencyCode() <<" \n";
			return;
		}

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrency(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'Y';
		do
		{
			system("cls");
			_DrawScreenHeader("\tFind Currency Screen");


			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");

			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");

			cout << "\nEnter Amount to Exchange: ";
			float Amount = clsInputValidate::ReadFLoat();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			Continue = Char::ReadChar("\n\nDo you want to perfrom more calculations (y/n): ");


		} while (Continue == 'y' || Continue == 'Y');



	}
};

