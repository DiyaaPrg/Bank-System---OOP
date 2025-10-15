#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsMainScreen.h"
using namespace std;



class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber(string message)
	{
		string AccountNumber = "";
		cout << message;
		AccountNumber = clsInputValidate::Readtext();
		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			cout << message;
			AccountNumber = clsInputValidate::Readtext();
		}
		return AccountNumber;
	}

	static double _ReadWithDrawAmount(string message)
	{
		double Amount = 0;
		cout << message;
		Amount = clsInputValidate::ReadDblNumber();
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		// Client Transfer from:
		clsBankClient ClientTransferFrom = clsBankClient::Find(_ReadAccountNumber("\nPlease enter Account Number to Transfer From: "));
		_PrintClient(ClientTransferFrom);

		// Client Transfer To:
		clsBankClient ClientTransferTo = clsBankClient::Find(_ReadAccountNumber("\nPlease enter Account Number to Transfer To: "));

	    while (ClientTransferTo.AccountNumber() == ClientTransferFrom.AccountNumber())
		{
			cout << "\nYou cannot Transfer between same accounts!\n";
			ClientTransferTo = clsBankClient::Find(_ReadAccountNumber("\nPlease enter Account Number to Transfer To: "));
		}
		_PrintClient(ClientTransferTo);

		double Amount = _ReadWithDrawAmount("\nPlease enter Transfer amount: ");

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (ClientTransferFrom.Transfer(Amount, ClientTransferTo))
			{
				cout << "\nTransfer Done Successfully!\n";
			}
			else
			{
				cout << "\nTransfer has failed.\n";
			}
			_PrintClient(ClientTransferFrom);
			_PrintClient(ClientTransferTo);

		}
		else
		{
			return;
		}

	}
};


