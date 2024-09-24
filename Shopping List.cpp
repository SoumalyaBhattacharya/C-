#include <iostream>
#include <string>
using namespace std;

class ShoppingItem {
private:
    int code;
    string name;
    float price;
public:
    ShoppingItem() : code(0), name(""), price(0.0) {}
    void setData(int c, string n, float p) {
        code = c;
        name = n;
        price = p;
    }
    int getCode() const { return code; }
    float getPrice() const { return price; }
    void display() const {
        cout << "Code: " << code << ", Name: " << name << ", Price: " << price << endl;
    }
};

class ShoppingList {
private:
    ShoppingItem items[50];
    int itemCount;
public:
    ShoppingList() : itemCount(0) {}
    void addItem(int code, string name, float price) {
        items[itemCount].setData(code, name, price);
        itemCount++;
    }
    void removeItem(int code) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getCode() == code) {
                for (int j = i; j < itemCount - 1; ++j) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                break;
            }
        }
    }
    void displayItems() const {
        for (int i = 0; i < itemCount; ++i) {
            items[i].display();
        }
    }
    float calculateTotalCost() const {
        float total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i].getPrice();
        }
        return total;
    }
};

int main() {
    ShoppingList list;
    int choice;
    do {
        cout << "\nShopping List Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Items\n";
        cout << "4. Calculate Total Cost\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int code;
                string name;
                float price;
                cout << "Enter item code: ";
                cin >> code;
                cout << "Enter item name: ";
                cin.ignore(); // To ignore the newline character left by cin
                getline(cin, name);
                cout << "Enter item price: ";
                cin >> price;
                list.addItem(code, name, price);
                break;
            }
            case 2: {
                int code;
                cout << "Enter item code to remove: ";
                cin >> code;
                list.removeItem(code);
                break;
            }
            case 3:
                list.displayItems();
                break;
            case 4:
                cout << "Total Cost: " << list.calculateTotalCost() << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
