#include <iostream>

class Transaction {
public:
    char type[20];
    double amount;

    Transaction() : amount(0.0) {
        for (int i = 0; i < 20; ++i) type[i] = '\0';
    }

    void setTransaction(const char* t, double a) {
        for (int i = 0; i < 20 && t[i] != '\0'; ++i) {
            type[i] = t[i];
        }
        amount = a;
    }
};

class Account {
private:
    char accountHolder[50];
    char cardPIN[5];
    double balance;
    Transaction transactions[100]; 
    int transactionCount;

public:
    Account(const char* holder, const char* pin, double initialBalance)
        : balance(initialBalance), transactionCount(0) {
        for (int i = 0; i < 50 && holder[i] != '\0'; ++i) {
            accountHolder[i] = holder[i];
        }
        for (int i = 0; i < 5 && pin[i] != '\0'; ++i) {
            cardPIN[i] = pin[i];
        }
    }

    void deposit(double amount) {
        balance += amount;
        if (transactionCount < 100) {
            transactions[transactionCount].setTransaction("Deposit", amount);
            transactionCount++;
        }
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance!" << std::endl;
            return false;
        }
        balance -= amount;
        if (transactionCount < 100) {
            transactions[transactionCount].setTransaction("Withdrawal", amount);
            transactionCount++;
        }
        return true;
    }

    bool transfer(Account &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            if (transactionCount < 100) {
                char transferType[50] = "Transfer to ";
                for (int i = 0; i < 50 && toAccount.getAccountHolder()[i] != '\0'; ++i) {
                    transferType[11 + i] = toAccount.getAccountHolder()[i];
                }
                transactions[transactionCount].setTransaction(transferType, amount);
                transactionCount++;
            }
            return true;
        }
        return false;
    }

    void printMiniStatement() const {
        std::cout << "Mini Statement for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; ++i) {
            std::cout << transactions[i].type << ": " << transactions[i].amount << "\n";
        }
        std::cout << "Current Balance: " << balance << "\n";
    }

    double getBalance() const {
        return balance;
    }

    const char* getAccountHolder() const {
        return accountHolder;
    }

    const char* getCardPIN() const {
        return cardPIN;
    }
};

int main() {
    Account account1("John Doe", "1234", 1000.0);
    Account account2("Jane Smith", "5678", 500.0);

    account1.deposit(200.0);
    account1.withdraw(150.0);
    account1.transfer(account2, 300.0);

    account1.printMiniStatement();
    account2.printMiniStatement();

    std::cout << "Account 1 PIN: " << account1.getCardPIN() << std::endl;

    return 0;
}
