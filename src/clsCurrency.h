#pragma once
#include <iostream>
#include <vector>
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <fstream>
using namespace std;

class clsCurrency
{

private:
	enum enMode {EmptyMode = 1, UpdateMode = 2 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string line)
	{
		//step1:
		// create a vector of string and fill it with data from line using split
		vector <string> vDataLine = clsString::Split(line, "#//#");

		return clsCurrency(enMode::UpdateMode, vDataLine[0], vDataLine[1], vDataLine[2], stof(vDataLine[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
	{
		string DataLine;
		DataLine += currency._Country + seperator;
		DataLine += currency._CurrencyCode + seperator;
		DataLine += currency._CurrencyName + seperator;
		DataLine += to_string(currency._Rate);

		return DataLine;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrencies;

		fstream file;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);

				vCurrencies.push_back(currency);
			}
		}
		file.close();

		return vCurrencies;
	}

	void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream file;

		file.open("Currencies.txt", ios::app | ios::out);

		if (file.is_open())
		{
			for (clsCurrency currency : vCurrencies)
			{
				file << _ConvertCurrencyObjectToLine(currency) << endl;
			}
		}
		file.close();

	}

     void _Update()
	{
		//load data from file:
		vector <clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency &C : vCurrencies)
		{
			if (C.Country() == this->Country())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}

	 static clsCurrency _GetEmptyCurrencyObject()
	 {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	 }


public:

	clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate)
	{
		_Mode = mode;
		_Country = country;
		_CurrencyCode = currencyCode;
		_CurrencyName = currencyName;
		_Rate = rate;
	}

     string Country()
	 {
	 	return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCode(string Currencycode)
	{
		Currencycode = clsString::UpperText(Currencycode);

		fstream file;
		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);

				if (currency.CurrencyCode() == Currencycode)
				{
					file.close();
					return currency;
				}
			}
		}
		file.close();

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperText(Country);

		fstream file;
		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);

				if (clsString::UpperText(currency.Country()) == Country)
				{
					file.close();
					return currency;
				}
			}
		}
		file.close();

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency currency = FindByCode(CurrencyCode);
		return (!currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();
		return vCurrencies;
	}

};

