#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    float _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string line, string seperator = "#//#")
    {
        vector <string> vClientData;

        vClientData = clsString::Split(line, seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static vector <clsBankClient> _LoadDataFromFileToVector()
    {
        fstream file;
        vector <clsBankClient> _vClients;
        string line;

        file.open("Clients.txt", ios::in); // Read Mode

        while (getline(file, line))
        {
            if (line != "")
            {
                _vClients.push_back(_ConvertLinetoClientObject(line));
            }
        }
        file.close();
        return _vClients;
    }

    static string _ConvertClientObjectToLine(clsBankClient client, string seperator = "#//#")
    {
        string line;
        line += client.FirstName + seperator;
        line += client.LastName + seperator;
        line += client.Email + seperator;
        line += client.Phone + seperator;
        line += client.AccountNumber() + seperator;
        line += client.PinCode + seperator;
        line += to_string(client.AccountBalance);

        return line;
    }

    void _LoadDataFromVectortoFile(vector <clsBankClient> vClientData)
    {
        fstream file;

        file.open("Clients.txt", ios::out);

        for (clsBankClient client : vClientData)
        {
            if (client._MarkedForDelete == false)
            {
                string line = _ConvertClientObjectToLine(client);
                file << line << endl;
            }

        }

        file.close();
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return (clsBankClient(EmptyMode, "", "", "", "", "", "", 0));
    }

    void _Update()
    {
        vector <clsBankClient> _vClients;

        _vClients = _LoadDataFromFileToVector();

        for (clsBankClient& C : _vClients)
        {
            if (C._AccountNumber == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _LoadDataFromVectortoFile(_vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }


public:

    clsBankClient(enMode mode, string firstname, string lastname, string email, string phone, string accountnumber, string pincode, double accountbalance)
        : clsPerson(firstname, lastname, email, phone)
    {
        _Mode = mode;
        _AccountNumber = accountnumber;
        _PinCode = pincode;
        _AccountBalance = accountbalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string accountNumber)
    {
        fstream file;
        file.open("Clients.txt", ios::in);

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                if (line != "")
                {
                    clsBankClient Client = _ConvertLinetoClientObject(line);
                    if (Client.AccountNumber() == accountNumber)
                    {
                        file.close();
                        return Client;
                    }
                }
            }
            file.close();

        }
        return _GetEmptyClientObject(); // Mark that object is empty

    }

    static clsBankClient Find(string accountNumber, string pincode)
    {
        fstream file;
        file.open("Clients.txt", ios::in);

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(line);
                if (Client._AccountNumber == accountNumber && Client._PinCode == pincode)
                {
                    file.close();
                    return Client;
                }
            }
            file.close();

        }
        return _GetEmptyClientObject();

    }

    static bool IsClientExist(string accountNumber)
    {
        clsBankClient client = Find(accountNumber);

        return (!client.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> vClients = _LoadDataFromFileToVector();

        for (clsBankClient& C : vClients)
        {
            if (C._AccountNumber == _AccountNumber)
            {
                C._MarkedForDelete = true;
            }
        }
        _LoadDataFromVectortoFile(vClients);

        *this = _GetEmptyClientObject();
        return true;
    }

    enum enSaveResults { SvFailedEmptyObj = 0, SvSucceded = 1, SvFailedObjectExisted = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case(enMode::EmptyMode):
            return enSaveResults::SvFailedEmptyObj;

        case(enMode::UpdateMode):

            _Update();
            return enSaveResults::SvSucceded;

        case(enMode::AddNewMode):

            if (IsClientExist(AccountNumber()))
            {
                cout << "\nThe Client is already exists\n";
                return enSaveResults::SvFailedObjectExisted;
            }

            _AddNew(); // just added filled client to file

            //change Mode to update
            _Mode = enMode::UpdateMode;

            return enSaveResults::SvSucceded;

        }


    }

    void Deposit(float amount)
    {
        _AccountBalance += amount;
        Save();
    }

    bool WithDraw(float amount)
    {
        if (amount > AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= amount;
            Save();
            return true;
        }
    }

    static clsBankClient GetAddNewClientObject(string accountNumber)
    {
        return (clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0));
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadDataFromFileToVector();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClientData = clsBankClient::GetClientsList();

        double totalbalances = 0;
        for (clsBankClient client : vClientData)
        {
            totalbalances += client.AccountBalance ;
        }

        return totalbalances;
    }
};

