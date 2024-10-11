#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "/Users/niloysaha/Downloads/stack.cpp" // Include your custom stack implementation

using namespace std;

/*
 * Class: gas_station
 * Description: This class simulates a gas station with functionalities to manage gas sales,
 *              pricing, and manager information.
 */
class gas_station {
private:
    float price_regular;     // Price of regular gas
    double total_sales;      // Total sales in dollars
    char manager[32];        // Name of the store manager

public:
    // Default constructor
    gas_station() {}

    // Parameterized constructor
    gas_station(float p, const char* m) {
        price_regular = p;
        total_sales = 0;
        strncpy(manager, m, 31); // Copy manager name, ensuring null-termination
    }

    // Get the total sales amount
    double get_sales() { return total_sales; }

    // Calculate the price of super gas (15% more than regular)
    float price_super() { return price_regular * 1.15; }

    // Sell a specified number of gallons of gas and record sales
    void pump_gas(float gallons, bool super = false) {
        if (gallons < 0) return; // Validate input
        double price = super ? price_super() : price_regular; // Determine price based on gas type
        total_sales += price * gallons; // Update total sales
    }

    // Change the price of gas by a specified amount
    void change_price(float price_difference) {
        price_regular += price_difference; // Update price
    }

    // Double the price during natural disasters
    void gouge() { price_regular *= 2; }

    // Change the manager of the gas station
    void change_manager(const char* newmanager) {
        strncpy(manager, newmanager, 31); // Update manager name
    }

    // Print information about the gas station
    void info() {
        cout << "Gas station managed by " << manager;
        cout << ", current gas price $" << price_regular;
        cout << ", total sales = " << total_sales << endl;
    }
};

/*
 * Function: part0
 * Description: Simulates the operation of multiple gas stations,
 *              including sales transactions and manager changes.
 */
void part0() {
    gas_station g1(3.19, "Mike Manageron");
    gas_station g2(3.29, "John Makeabuck");
    gas_station g3(3.99, "Jane Gouger");
    gas_station g4(4.05, "Mohammed Salah");
    gas_station g5(4.01, "Niloy Saha");

    // Array of pointers to all gas stations
    gas_station* store_chain[5] = { &g1, &g2, &g3, &g4, &g5 };

    // Simulate transactions for each gas station
    g1.pump_gas(5, true);
    g1.change_price(0.20);
    g1.gouge();
    g1.change_manager("Prabhjot Singh");
    g1.info();

    g3.pump_gas(4, true);
    g3.change_price(0.30);
    g3.gouge();
    g3.change_manager("Cristiano Ronaldo");
    g3.info();

    g2.pump_gas(6, false);
    g2.change_price(0.10);
    g2.gouge();
    g2.change_manager("Lionel Messi");
    g2.info();

    g4.pump_gas(6, false);
    g4.change_price(0.10);
    g4.gouge();
    g4.change_manager("Aurin Saha");
    g4.info();

    g5.pump_gas(6, false);
    g5.change_price(0.10);
    g5.gouge();
    g5.change_manager("Suma Saha");
    g5.info();

    // Print info for all stations
    for (int i = 0; i < 5; i++) {
        store_chain[i]->info();
    }

    // Simulate more sales
    store_chain[0]->pump_gas(2, true);
    store_chain[1]->pump_gas(3, true);
    store_chain[2]->pump_gas(5, false);
    store_chain[3]->pump_gas(4, false);
    store_chain[4]->pump_gas(7, true);

    // Find the station with the lowest total sales and change its manager
    int lowest = 0;
    for (int i = 1; i < 5; i++) { // Adjust loop to iterate through all stations
        if (store_chain[i]->get_sales() < store_chain[lowest]->get_sales())
            lowest = i;
    }
    store_chain[lowest]->change_manager("Sajan");
}

/*
 * Struct: account
 * Description: This struct simulates bank accounts with functionalities
 *              to deposit, withdraw, and manage account transactions.
 */
struct account {
private:
    double balance;                       // Current account balance
    char name[32];                        // Account holder's name
    bool account_locked = false;          // Account status
    Stack<string, 256> type_stack;       // Stack to track transaction types
    Stack<double, 256> amount_stack;     // Stack to track transaction amounts
    Stack<double, 256> balance_after;     // Stack to track balance after transactions

public:
    // Default constructor
    account() {}

    // Parameterized constructor
    account(const char* n, double init_bal) {
        if (init_bal >= 0) this->balance = init_bal;
        strncpy(name, n, 31); // Copy name, ensuring null-termination
    }

    // Deposit money into the account
    void deposit(double amount) {
        if (!account_locked) {
            if (amount > 0) {
                balance += amount;
                type_stack.push("Deposit");
                amount_stack.push(amount);
                balance_after.push(balance);
            }
        } else {
            cout << "Account is locked. Please contact the bank to unlock." << endl;
        }
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && !account_locked) {
            if (amount <= balance) {
                balance -= amount;
                type_stack.push("Withdraw");
                amount_stack.push(amount);
                balance_after.push(balance);
            } else {
                cout << "Overdraft: No transaction made" << endl;
            }
        } else if (amount < 0) {
            account_locked = true;
            cout << "Suspicious transaction amount, account locked" << endl;
        } else if (amount > 0 && account_locked) {
            cout << "Account is locked. Please contact the bank to unlock." << endl;
        }

        if (balance < 100 && !account_locked) {
            cout << "Warning: Balance below $100" << endl;
        }
    }

    // Get the current balance
    double get_balance() {
        if (account_locked) {
            cout << "Account is locked. Please contact the bank to unlock." << endl;
            return -1;
        } else {
            return balance;
        }
    }

    // Merge two accounts
    void merge(account* acc_name) {
        this->balance += acc_name->balance; // Add balance of the other account
        acc_name->balance = 0; // Set other account balance to zero
    }

    // Print transaction statement
    void print_statement() {
        while (type_stack.len() > 0 && type_stack.len() <= 30) {
            cout << type_stack.pop() << " " << amount_stack.pop() << " (Balance " << balance_after.pop() << ")" << endl;
        }
    }
};

/*
 * Main function: Entry point of the program
 */
int main(int argc, char* argv[]) {
    part0();  // Execute gas station simulation
    level3(); // Execute bank account simulation
    return 0;
}

/*
 * Function: level1
 * Description: Tests basic functionality of the account struct including deposits and withdrawals.
 */
void level1() {
    account youraccount("good student", 2000);
    account myaccount("evil prof", 3000);

    youraccount.deposit(500); // Deposit into your account
    myaccount.withdraw(300);  // Withdraw from the professor's account
    youraccount.withdraw(5000); // Attempt to withdraw more than available
    myaccount.withdraw(2650); // Withdraw, triggering a warning

    cout << youraccount.get_balance() << endl;  // Print your current balance
    cout << myaccount.get_balance() << endl; // Print professor's current balance
}

void level2() {
    level1(); // Must complete level1 before level2

    account student_accounts[2]; // Accounts for 2 Hofstra students

    student_accounts[0] = account("Nev Erstudy", 2000);
    student_accounts[1] = account("Isa Taparty", 3000);

    student_accounts[0].merge(&student_accounts[1]); // Merge two accounts
    cout << student_accounts[0].get_balance() << endl; // Should print 5000
    cout << student_accounts[1].get_balance() << endl; // Should print 0
}

/*
 * Function: level3
 * Description: Simulates multiple bank accounts with deposit, withdrawal, and transaction statement functionalities.
 */
void level3() {
    account a1("Account One", 1000);
    account a2("Account Two", 1500);

    a1.deposit(200);
    a1.withdraw(500);
    a1.withdraw(600); // Should trigger overdraft warning

    a2.deposit(300);
    a2.withdraw(1000); // Should trigger warning for low balance

    cout << "Account 1 Statement:\n";
    a1.print_statement(); // Print statement for account 1
    cout << "Account 2 Statement:\n";
    a2.print_statement(); // Print statement for account 2

}
