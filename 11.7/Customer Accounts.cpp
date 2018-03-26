/*
 * Write a program that uses a structure to store the following data about a 
 * customer account:
 * Name
 * Address
 * City, State, and ZIP
 * Telephone Number
 * Account Balance
 * Date of Last Payment
 * The program should use an array of at least 10 structures. 
 * It should let the user enter data into the array, change the contents
 * of any element, and display all the data stored in the array. 
 * The program should have a menu-driven user interface.
 */

/* 
 * File:   Customer Accounts.cpp
 * Author: Nicolas Zavala
 *
 * Created on March 26, 2018, 12:54 PM
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits> // for streamsize max, to flush cin buffer
#include <cctype> // for tolower

using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::vector;
using std::tolower;
using std::getline;

// helper functions to clear the cin buffer
void resetCin() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
}

struct Customer {
private:
    string name;
    string address;
    string phone;
    float  balance;
    string last_payment_date;

public:
    // default constructor uses interactive input
    Customer() {
        setName();
        setAddress();
        setPhone();
        setBalance();
        setLastPayDate();
    }

    // member mutators -- never allow members to be empty
    void setName() {
        do {
            cout << "Enter the customer's name: ";
            getline(cin, name, '\n');
        } while (name.empty());
    }
    void setAddress() {
        do {
            string line; // hold each line of input
            cout << "Enter the address (enter a blank line to finish):\n";

            // gather address one line at a time, address member will have at
            // least one newline (in all likelihood), can have many lines.
            do {
                line.clear();
                getline(cin, line, '\n');
                address.append(line);
                address.push_back('\n');
            } while ( !line.empty() );

            // remove trailing newline characters
            address = address.substr(0, address.rfind("\n"));
            address = address.substr(0, address.rfind("\n"));
        } while (address.empty());
    }
    void setPhone() {
        do {
            cout << "Enter the customer's phone number: ";
            getline(cin, phone, '\n');
        } while (phone.empty());
    }
    void setBalance() {
        balance = -1; // use bad value in case extraction fails first time
        do {
            cout << "Enter the customer's account balance "
                    "(must not be negative): $ ";
            cin >> balance;
        } while (balance < 0);
        resetCin();
    }
    void setLastPayDate() {
        do {
            cout << "Enter the date of customer's last payment: ";
            getline(cin, last_payment_date, '\n');
        } while (last_payment_date.empty());
    }

    // member accessors
    string getName()    { return name; }
    string getAddress() { return address; }
    string getPhone()   { return phone; }
    float  getBalance() { return balance; }
    string getLastPayDate() { return last_payment_date; }

    void print() {
        cout << name << "\n" << address << "\nPhone Number: " << phone
             << "\nAccount Balance: $" << balance << "\n"
             << "Date of Last Payment: " << last_payment_date << "\n";
    }
};

// define menu options
const char MENU_EXIT      = 'q';
const char MENU_ADD       = 'i';
const char MENU_EDIT      = 'e';
const char MENU_PRINT     = 'p';
const char MENU_PRINT_ALL = 'a';


char prompt() {
    char c = 'H'; // nonselection by default, in case extraction fails
    cout << "----------------------------------------------------\n"
            "I = Insert Customer | E = Edit Existing Customer    \n"
            "P = Print Customer  | A = Print All Customer Entries\n"
            "Q = Quit                                            \n"
            "----------------------------------------------------\n"
            "selection> ";
    cin >> c;
    resetCin();
    return tolower(c);
}

char edit_prompt() {
    char c = 'H'; // nonselection by default, in case extraction fails
    cout << "----------------------------------------------------\n"
            "N = Name            | A = Address | P = Phone Number\n"
            "B = Account Balance | D = Date of Last Payment      \n"
            "Q = Done Editing this Customer                      \n"
            "----------------------------------------------------\n"
            "edit> ";
    cin >> c;
    resetCin();
    return tolower(c);
}

void editCustomer(vector<Customer>& d, unsigned index) {
    if (index >= d.size() or index < 0) {
        cerr << "** bad index given to editCustomer [" << index << "]. "
                "valid range is 0 to " << d.size() - 1 << ". **\n";
        return;
    }

    cout << '\n';
    d.at(index).print(); // show the customer being edited
    for( char c = edit_prompt(); c != MENU_EXIT; c = edit_prompt()) {
        switch (c) {
            case 'n':
                d.at(index).setName();
                break;
            case 'a':
                d.at(index).setAddress();
                break;
            case 'p':
                d.at(index).setPhone();
                break;
            case 'b':
                d.at(index).setBalance();
                break;
            case 'd':
                d.at(index).setLastPayDate();
                break;
        }
        d.at(index).print();
    }

}

// contains all customer data
vector<Customer> data;

int main() {
    // set formatting for entire program
    cout << std::fixed << std::setprecision(2);
    
    for (char selection = prompt();
         selection != MENU_EXIT;
         selection = prompt())
    {
        unsigned customer_index; // used in MENU_EDIT and MENU_PRINT cases
        switch (selection) {
            case MENU_ADD:
                cout << "Adding Customer " << data.size() + 1 << ".\n";
                data.push_back(Customer());
                break;
            case MENU_EDIT:
                if (data.size() == 0) break; // don't try to edit empty data
                cout << "Enter the customer index to edit [1 to "
                     << data.size() << "]: ";
                cin >> customer_index;
                customer_index--; // actual index will be 1 lower
                editCustomer(data, customer_index);
                break;
            case MENU_PRINT:
                if (data.size() == 0) break; // don't try to display empty data
                cout << "Enter the customer index to display [1 to "
                     << data.size() << "]: ";
                cin >> customer_index;
                customer_index--;
                if (customer_index >= data.size() or customer_index < 0) {
                    cerr << "** bad index [" << customer_index << "]. "
                            "valid range is 0 to " << data.size()-1 << ". **\n";
                } else {
                    data.at(customer_index).print();
                }
                break;
            case MENU_PRINT_ALL:
                cout << '\n';
                for (unsigned i = 0; i < data.size(); i++) {
                    cout << "Customer " << i+1 << "\n"
                            "--------------\n";
                    data.at(i).print();
                    cout << '\n';
                }
                break;
        }
    }
    return 0;
}
