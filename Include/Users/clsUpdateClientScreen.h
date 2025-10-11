#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter first name: ";
		Client.FirstName = clsInputValidate::Readtext();

		cout << "\nEnter Last name: ";
		Client.LastName = clsInputValidate::Readtext();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::Readtext();

		cout << "\nEnter phone number: ";
		Client.Phone = clsInputValidate::Readtext();

		cout << "\nEnter Pin Code: ";
		Client.PinCode = clsInputValidate::Readtext();

		cout << "\nEnter account balance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:
	static void ShowUpdateClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermessions::UpdateClient))
		{
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

		cout << "\nEnter Account Number: ";
		string AccountNumber = clsInputValidate::Readtext();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found! Enter another: ";
			AccountNumber = clsInputValidate::Readtext();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\nUpdate Client Info:\n";
		cout << "\n-----------------------\n";

		ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResults;

		SaveResults = Client.Save();

		switch (SaveResults)
		{
		case(clsBankClient::enSaveResults::SvSucceded):
			cout << "\nAccount Updated Successfully :-)\n";
			Client.Print();
			break;

		case(clsBankClient::enSaveResults::SvFailedEmptyObj):
			cout << "\nError, account wasn't saved because it's empty :-(\n";
			break;


		}
	}

};

