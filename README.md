# Bank-System---OOP

🏦 C++ Bank Management System (OOP Version)
💻 Overview

This is a console-based Bank Management System built using Object-Oriented Programming (OOP) principles in C++.
The system simulates real-world banking operations such as client management, user management, and financial transactions — all organized into modular screen classes for scalability and maintainability.

All data (clients and users) is stored in text files to ensure persistence between program runs.

✨ Features
👥 User Management

Add, update, delete, and find users

Assign custom permissions (bitmask-based access control)

Admin user has full access (-1) by default

Prevent deletion of the main Admin account

🧾 Client Management

Add, update, delete, and find clients

Display all clients in a formatted table

Show total balances across all clients

Input validation for all client data

💳 Transactions

Deposit and withdraw money

Balance check before withdrawal

View total balances report

🔐 Permissions System

Managed through clsUser class and bitmask flags

Permissions include:

Show Client List

Add / Delete / Update / Find Clients

Perform Transactions

Manage Users

Permission checks handled by _CheckAccessRights() (in Global.h)

🧱 Object-Oriented Design
OOP Concept	Implementation
Encapsulation	Each screen (e.g., clsAddNewClientScreen, clsDepositScreen) handles its own logic
Inheritance	clsScreen serves as a base class for all screen classes
Abstraction	Shared UI and validation logic extracted into helper and utility classes
Polymorphism	Screen classes override and extend base behavior dynamically
🗂 Project Structure
📁 OOP_Applications/
│
├── 🧩 Header Files/
│   ├── clsBankClient.h           # Client data model
│   ├── clsUser.h                 # User account & permission system
│   ├── clsPerson.h               # Base class for shared person details
│   ├── clsScreen.h               # Base class for all screen classes
│   ├── clsMainScreen.h           # Main navigation menu
│
│   ├── 🔐 User Management Screens/
│   │   ├── clsAddNewUserScreen.h
│   │   ├── clsDeleteUserScreen.h
│   │   ├── clsFindUserScreen.h
│   │   ├── clsManagerUsersScreen.h
│   │   ├── clsUpdateUserScreen.h
│   │   └── clsUsersListScreen.h
│
│   ├── 👥 Client Management Screens/
│   │   ├── clsAddNewClientScreen.h
│   │   ├── clsDeleteClientScreen.h
│   │   ├── clsFindClientScreen.h
│   │   ├── clsClientListScreen.h
│   │   ├── clsUpdateClientScreen.h
│   │   └── clsTotalBalancesScreen.h
│
│   ├── 💳 Transaction Screens/
│   │   ├── clsDepositScreen.h
│   │   ├── clsWithDrawScreen.h
│   │   └── clsTransactionsScreen.h
│
│   ├── 🧰 Helpers/
│   │   ├── clsInputValidate.h
│   │   ├── clsPeriod.h
│   │   ├── clsUtil.h
│   │   └── Global.h              # Current user & access-rights checks
│
│   ├── clsLogin.h                # Login handling
│   └── main.cpp                  # Application entry point
│
└── 📂 Data/
    ├── Bank.txt                  # Stores client data
    └── Users.txt                 # Stores user credentials and permissions
