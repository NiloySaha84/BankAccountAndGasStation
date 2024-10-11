# Gas Station and Bank Account Simulation

## Overview

This project simulates the operations of a gas station and a banking system, showcasing object-oriented programming principles in C++. It includes functionality for managing gas prices, sales, and bank account transactions with methods for deposits, withdrawals, and transaction tracking.

## Features

- **Gas Station Simulation:**
  - Manage gas prices for regular and super grades.
  - Track total sales and sales by manager.
  - Change gas prices and managers.
  - Simulate pumping gas and calculate total sales.

- **Bank Account Simulation:**
  - Create and manage bank accounts with deposit and withdrawal functionalities.
  - Lock accounts for suspicious activities.
  - Print transaction statements for accounts.
  - Merge two accounts.

## Structure

### Classes

1. **`gas_station`**
   - **Attributes:**
     - `float price_regular`: Price of regular gas.
     - `double total_sales`: Total sales in dollars.
     - `char manager[32]`: Name of the store manager.
   - **Methods:**
     - `void pump_gas(float gallons, bool super=0)`: Sell gas and record sales.
     - `void change_price(float price_difference)`: Change the price of gas.
     - `void gouge()`: Double the gas price during natural disasters.
     - `void change_manager(const char* newmanager)`: Change the store manager.
     - `void info()`: Display gas station information.

2. **`account`**
   - **Attributes:**
     - `double balance`: Account balance.
     - `char name[32]`: Name of the account holder.
     - `bool account_locked`: Indicates if the account is locked.
   - **Methods:**
     - `void deposit(double amount)`: Deposit money into the account.
     - `void withdraw(double amount)`: Withdraw money from the account.
     - `double get_balance()`: Retrieve the account balance.
     - `void merge(account* acc_name)`: Merge balances of two accounts.
     - `void print_statement()`: Print transaction history.

### Main Functions

- **`part0`**: Demonstrates gas station functionalities.
- **`level1`**: Simulates basic bank account operations.
- **`level2`**: Merges two bank accounts and handles suspicious transactions.
- **`level3`**: Prints transaction statements for bank accounts.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/gas-station-bank-simulation.git
