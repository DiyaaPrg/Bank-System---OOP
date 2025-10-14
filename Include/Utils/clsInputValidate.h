#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;



class clsInputValidate
{
public:

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	template <typename T>
	static T IsNumberBetween(T num, T from, T to)
	{
		return (num >= from && num <= to);
	}

	//static bool IsNumberBetween(int number, int from, int to)
	//{
	//	return (number >= from && number <= to);
	//}

	//static bool IsNumberBetween(double number, double from, double to)
	//{
	//	return (number >= from && number <= to);
	//}

	//static bool IsNumberBetween(float number, float from, float to)
	//{
	//	return (number >= from && number <= to);
	//}

	static bool IsDateBetween(clsDate date, clsDate date1, clsDate date2)
	{
		//condition 1: date is equal or bigger than datefrom && equal or smaller than dateto
		if ((clsDate::CompareDates(date, date1) == enDateCompare::After || clsDate::CompareDates(date, date1) == enDateCompare::Equal)
			&& (clsDate::CompareDates(date, date2) == enDateCompare::Before || clsDate::CompareDates(date, date2) == enDateCompare::Equal))
		{
			return true;
		}
		
		if ((clsDate::CompareDates(date, date1) == enDateCompare::Before || clsDate::CompareDates(date, date1) == enDateCompare::Equal)
			&& (clsDate::CompareDates(date, date2) == enDateCompare::After || clsDate::CompareDates(date, date2) == enDateCompare::Equal))
		{
			return true;
		}

		else
			return false;

	}

	static string Readtext()
	{
		string text;
		getline(cin >> ws, text);
		return text;
	}

	template <typename T>
	static T ReadNumber(string warningMessage = "Invalid Number, Enter again:\n")
	{
		T number;
		cin >> number;
		while (number <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << warningMessage;
			cin >> number;
		}

		return number;
	}

	template <typename Y>
	static Y ReadNumberBetween(Y from, Y to, string warningMessage)
	{
		Y number;
		number = clsInputValidate::ReadNumber<Y>(); 
		while (cin.fail() || !IsNumberBetween(number, from, to))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << warningMessage;
			number = clsInputValidate:: ReadNumber<Y>(); 
		}

		return number;
	}

	

	static	bool IsValidDate(clsDate Date)
	{
		return (clsDate::IsValidDate(Date));
	}

};

