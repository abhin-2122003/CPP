#include <iostream>
#include <string>
using namespace std;

class Salary {
protected:
    double bp;

public:
    Salary() {}

    void calculateTotal() {
        double da = 0.3 * bp;
        double hra = 0.1 * bp;
        double cca = 200;
        double total = 12 * (bp + da + hra + cca);
        cout << "\nTotal: " << total << endl;
    }

    void acceptData() {
        cout << "Enter Basic Pay: ";
        cin >> bp;
    }

    double getBP(){
        return bp;
    }
};

class Tax {
protected:
    string name;

public:
    Tax() {}

    void acceptData() {
        cout << "Enter Name: ";
        cin >> name;
    }

    string getName() const {
        return name;
    }
};

class Income_tax : public Salary, public Tax {
public:
    void calculateTax() {
        double yearlyIncome = 12 * (bp + 0.3 * bp + 0.1 * bp + 200);
        double taxRate = 0.0;

        if (yearlyIncome > 60000 && yearlyIncome <= 80000) {
            taxRate = 0.2;
        } else if (yearlyIncome > 80000 && yearlyIncome <= 100000) {
            taxRate = 0.3;
        } else if (yearlyIncome > 100000) {
            taxRate = 0.4;
        }

        double incomeTax = taxRate * yearlyIncome;
        cout << "\nIncome Tax: " << incomeTax << endl;
    }
};

int main() {
    Income_tax records[100];
    int count = 0;
    int choice;

    do {
        cout << "1. Add Record" << endl;
        cout << "2. Modify Record" << endl;
        cout << "3. Delete Record" << endl;
        cout << "4. Search Records" << endl;
        cout << "5. Calculate Tax" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (count < 100) {
                records[count].Salary::acceptData();
                records[count].Tax::acceptData();
                count++;
            } else {
                cout << "Array is full. Cannot add more records." << endl;
            }
            break;
        }
        case 2: {
            int index;
            cout << "Enter the index of the record to modify: ";
            cin >> index;
            if (index >= 0 && index < count) {
                records[index].Salary::acceptData();
                records[index].Tax::acceptData();
            } else {
                cout << "\nInvalid index. No record found." << endl;
            }
            break;
        }
        case 3: {
            int index;
            cout << "Enter the index of the record to delete: ";
            cin >> index;
            if (index >= 0 && index < count) {
                for (int i = index; i < count - 1; i++) {
                    records[i] = records[i + 1];
                }
                count--;
                cout << "\nRecord deleted." << endl;
            } else {
                cout << "\nInvalid index. No record found." << endl;
            }
            break;
        }
        case 4: {
            string searchName;
            cout << "Enter the name to search for: ";
            cin >> searchName;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (records[i].getName() == searchName) {
                    found = true;
                    cout<<endl<<"Name: "<<records[i].getName();
                    cout<<endl<<"Basic Pay: "<<records[i].getBP();
                    records[i].calculateTotal();
                }
            }

            if (!found) {
                cout << "\nNo record found with the given name." << endl;
            }
            break;
        }
        case 5: {
            int index;
            cout << "Enter the index of the record to calculate tax: ";
            cin >> index;
            if (index >= 0 && index < count) {
                records[index].calculateTax();
            } else {
                cout << "\nInvalid index. No record found." << endl;
            }
            break;
        }
        case 0:
            cout << "\nExiting..." << endl;
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}