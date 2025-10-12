#pragma once
#include <iostream>
#include <vector>
#include "Char.h"
using namespace std;


class clsString
{

	string _Value;

public:
	clsString() {
		_Value = "";
	}

	clsString(string value) {
		this->_Value = value;
	}

	void SetValue(string value)
	{
		this->_Value = value;
	}

	string getValue()
	{
		return this->_Value;
	}

	__declspec(property(get = getValue, put = SetValue)) string value;


	static string UpperText(string text)
	{
		for (char& letter : text)
		{
			if (letter != ' ')
			{
				letter = toupper(letter);
			}
		}
		return text;
	}

	void UpperText()
	{
		_Value = (UpperText(this->_Value));
	}

	static string LowerText(string text)
	{
		for (char& letter : text)
		{
			if (letter != ' ')
			{
				letter = tolower(letter);
			}

		}
		return text;
	}

	void LowerText()
	{
		_Value = (LowerText(this->_Value));
	}

	static string LowerFirstLetters(string text)
	{
		bool isFirstLetter = true;
		for (char& letter : text)
		{
			if (letter != ' ' && isFirstLetter)
			{
				letter = tolower(letter);
			}
			isFirstLetter = (letter == ' ') ? true : false;
		}
		return text;

	}

	void LowerFirstLetters()
	{
		_Value = (LowerFirstLetters(_Value));
	}

	static string UpperFirstLetters(string text)
	{
		bool isFirstLetter = true;
		for (char& letter : text)
		{
			if (letter != ' ' && isFirstLetter)
			{
				letter = toupper(letter);
			}
			isFirstLetter = (letter == ' ') ? true : false;
		}
		return text;

	}

	void UpperFirstLetters()
	{
		_Value = (UpperFirstLetters(_Value));
	}

	static string InvertString(string text)
	{
		for (char& letter : text)
		{
			letter = Char::InvertLetter(letter);
		}
		return text;
	}

	void InvertString()
	{
		_Value = (InvertString(_Value));
	}

	static int CountCapitalLetters(string text)
	{
		int count = 0;
		for (char& letter : text)
		{
			if (letter != ' ')
			{
				if (isupper(letter))
					++count;
			}
		}
		return count;
	}

	int CountCapitalLetters()
	{
		return (CountCapitalLetters(_Value));
	}

	static int CountSmallLetters(string text)
	{
		int count = 0;
		for (char& letter : text)
		{
			if (letter != ' ')
			{
				if (islower(letter))
					++count;
			}
		}
		return count;
	}

	int CountSmallLetters()
	{
		return (CountSmallLetters(_Value));
	}

	enum enWhattoCount { SmallLetter = 1, CapitalLetters = 2, Allletters = 3 };

	static int Countstring(string text, enWhattoCount what = enWhattoCount::Allletters)
	{
		int count = 0;
		if (what == enWhattoCount::Allletters)
			return text.length();

		if (what == enWhattoCount::CapitalLetters)
			count = CountCapitalLetters(text);
		else
			count = CountSmallLetters(text);

		return count;
	}

	int Countstring()
	{
		return (Countstring(_Value));
	}

	static void PrintWordsfromText(string text)
	{
		string delimeter = " ";
		string word;
		int pos = 0;

		while ((pos = text.find(delimeter)) != string::npos) // while there are spaces inside the text
		{
			word = text.substr(0, pos);

			if (word != "")
			{
				cout << word << endl;
			}

			text.erase(0, pos + delimeter.length()); // adding delimeter length to pos is important to remove spaces
		}

		if (text != "")
		{
			cout << text << endl;  //printing last word, because if there's no space after it, it will not enter while loop
		}
	}

	void PrintWordsfromText()
	{
		PrintWordsfromText(_Value);
	}

	static short CountWordsInstring(string text) // "Mohammed Abu-Hadhoud @ProgrammingAdvices"
	{
		short count = 0;
		string delimeter = " ";
		int pos = 0;
		while ((pos = text.find(delimeter)) != string::npos)
		{
			string word = text.substr(0, pos); // Mohammed

			if (word != "")
			{
				++count;
			}
			text.erase(0, pos + delimeter.length());

		}
		if (text != "")
		{
			++count;
		}
		return count;
	}

	short CountWordsInstring()
	{
		return CountWordsInstring(_Value);
	}

	static string TrimLeft(string text)
	{

		for (short i = 0; i < text.length(); ++i)
		{
			if (text.at(i) != ' ')
			{
				return (text.substr(i));
			}

		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string text)
	{
		for (short i = text.length() - 1; i >= 0; --i)
		{
			if (text.at(i) != ' ')
			{
				return (text.substr(0, i + 1));
			}

		}
		return "";
	}

	void TrimRight()
	{
		_Value= TrimRight(_Value);
	}

	static string Trim(string text)
	{
		return TrimRight(TrimLeft(text));
	}

	string Trim()
	{
		_Value = (Trim(_Value));
	}

	static string RemovePunctiation(string text)
	{
		string textwithoutpunct;
		for (int i = 0; i < text.length(); ++i)
		{
			if (!ispunct(text.at(i)))
			{
				textwithoutpunct += text.at(i);

			}
		}
		return textwithoutpunct;
	}

	string RemovePunctiation()
	{
		_Value = (RemovePunctiation(_Value));
	}

	static int CountVowels(string text)
	{
		int counter = 0;
		for (char& letter : text)
		{
			if (Char::isVowel(letter))
			{
				++counter;
			}
		}
		return counter;
	}

	int CountVowels()
	{
		return (CountVowels(_Value));
	}

	static short Length(string text)
	{
		return (text.length());
	}

	short Length()
	{
		return (Length(_Value));
	}

	static char InvertLetter(char letter)
	{
		return (isupper(letter)) ? tolower(letter) : toupper(letter);
	}

	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}

	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static vector<string> Split(string S1, string Delim)
	{
		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerText(s) == LowerText(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}

	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string EncryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

};
