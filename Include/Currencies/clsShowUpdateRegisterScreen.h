#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include <iomanip>
#include <vector>
#include "clsCurrency.h"

class clsShowUpdateRegisterScreen : protected clsScreen
{
    static void _PrintDataLine(clsCurrency::stUpdateCurrencyRegisterRecord record)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << record.Date;
        cout << "| " << setw(12) << left << record.CurrencyCode;
        cout << "| " << setw(10) << left << record.ValueFrom;
        cout << "| " << setw(10) << left << record.ValueTo;
    }


public:

	static void ShowUpdateRegisterScreen()
	{
		vector <clsCurrency::stUpdateCurrencyRegisterRecord> vRegister = clsCurrency::GetUpdateRegisterList();

		string Title = "\t Update Rate List Screen";
		string SubTitle = "\t    (" + to_string(vRegister.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t___________________________________________________";
        cout << "_____________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "Currency Code";
        cout << "| " << left << setw(10) << "Old Rate";
        cout << "| " << left << setw(10) << "New Rate";

        cout << setw(8) << left << "" << "\n\t___________________________________________________";
        cout << "_____________\n" << endl;

        if (vRegister.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";


        for (clsCurrency::stUpdateCurrencyRegisterRecord record : vRegister)
        {
            _PrintDataLine(record);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t___________________________________________________";
        cout << "_____________\n" << endl;
	}



};

