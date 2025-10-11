#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDate.h"


class clsUtil
{
public:

	enum enCharType { Small_letter = 1, Capital_letter = 2, Digit = 3, MixChars = 4, Special_Character = 5	};

	static string GetTime()
	{
		string Time = "";

		time_t t = time(0);

		tm* now = localtime(&t);

		Time += to_string(now->tm_hour);
		Time += ":";
		Time += to_string(now->tm_min);
		Time += ":";
		Time += to_string(now->tm_sec);

		return Time;

	}

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int randnum = rand() % (To - From + 1) + From;
		return randnum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case (enCharType::Small_letter):
			return char(RandomNumber(97, 122));

		case (enCharType::Capital_letter):
			return char(RandomNumber(65, 90));

		case (enCharType::Special_Character):
			return char(RandomNumber(33, 47));

		case (enCharType::Digit):
			return char(RandomNumber(48, 57));

		case(enCharType::MixChars):
			return char(RandomNumber(33, 122));
		}
		return '\0';

	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string word = "";
		for (short z = 1; z <= Length; ++z)
		{
			word = word + GetRandomCharacter(CharType);
		}

		return word;

	}

    static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key += GenerateWord(CharType, 4) + '-';
		Key += GenerateWord(CharType, 4) + '-';
		Key += GenerateWord(CharType, 4) + '-';
		Key += GenerateWord(CharType, 4);

		return Key;

	}

	static void GenerateKeys(short Generation_times, enCharType CharType)
	{
		cout << endl;
		for (short i = 1; i <= Generation_times; ++i)
		{

			cout << "Key [" << i << "]: " << GenerateKey(CharType) << endl;

		}
	}

	static void FillArrayWithRandomNumbers(int arr[], int arr_length, int from, int to)
	{
		for (int i = 0; i < arr_length; ++i)
		{
			arr[i] = RandomNumber(from, to);
		}

	}

	static void FillArrayWithRandomWords(string arr[], int arr_length, enCharType type, short wordLength)
	{
		for (int i = 0; i < arr_length; ++i)
		{
			arr[i] = GenerateWord(type, wordLength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[], int arr_length, enCharType type)
	{
		for (int i = 0; i < arr_length; ++i)
		{
			arr[i] = GenerateKey(type);
		}
	}

	static void Swap(int& num1, int& num2)
	{
		int  temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void Swap(double& double1, double& double2)
	{
		double  temp = double1;
		double1 = double2;
		double2 = temp;
	}

	static void Swap(char& char1, char& char2)
	{
		char  temp = char1;
		char1 = char2;
		char2 = temp;
	}

	static void Swap(bool& val1, bool& val2)
	{
		bool  temp = val1;
		val1 = val2;
		val2 = temp;
	}

	static void Swap(string& str1, string& str2)
	{
		string  temp = str1;
		str1 = str2;
		str2 = temp;
	}

	static void Swap(clsDate& date1, clsDate& date2)
	{
		clsDate::SwapDates(date1, date2);
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	
	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string NumberToText(int number)
	{
		if (number == 0)
		{
			return "";
		}

		if (number >= 1 && number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[number] + " ";
		}

		if (number >= 20 && number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[number / 10] + " " + NumberToText(number % 10);
		}

		if (number >= 100 && number <= 999)
		{
			return NumberToText(number / 100) + " Hundereds " + NumberToText(number % 100);
		}

		if (number >= 1000 && number <= 999999)
		{
			return NumberToText(number / 1000) + " Thousands " + NumberToText(number % 1000);
		}

		if (number >= 1000000 && number <= 999999999)
		{
			return NumberToText(number / 1000000) + " Millions " + NumberToText(number % 1000000);
		}

		else
			return NumberToText(number / 1000000000) + " Billions " + NumberToText(number % 1000000000);
	}



};

