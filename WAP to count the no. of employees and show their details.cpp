#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    float salary;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cout << "Enter Name: ";
        cin.ignore(); // To ignore the newline character left by cin
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "Employee ID: " << empID << "\nName: " << name << "\nSalary: " << salary << endl;
    }
};

int main() {
    int numEmployees;
    
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee employees[numEmployees]; // Array of Employee objects

    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        employees[i].getData();
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < numEmployees; ++i) {
        employees[i].display();
        cout << endl;
    }

    cout << "Total number of employees: " << numEmployees << endl;

    return 0;
}
