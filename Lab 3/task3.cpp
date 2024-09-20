#include <iostream>
#include <string>

enum accountTypeE {
    Current,
    Savings
};

const std::string accountTypeName[2] = {
    "Current",
    "Savings"
};

class BankAccount {
private:
    std::string customerName;
    int accountNumber;
    accountTypeE acType;
    float balanceAmmout;

public:
    // BankAccount(std::string customerName, int accountNumber, accountTypeE type);
    void customerDetails(std::string customerName, int accountNumber);
    void accountType(accountTypeE type);
    void balance();
    void deposit(float amount);
    void withdraw(float amount);
    void display();
};

void BankAccount::customerDetails(std::string customerName, int accountNumber) {
    this->customerName = customerName;
    this->accountNumber = accountNumber;
    balanceAmmout = 0;
}

void BankAccount::accountType(accountTypeE type) {
    acType = type;
}

// BankAccount::BankAccount(std::string customerName, int accountNumber, accountTypeE type) {
//     customerDetails(customerName, accountNumber);
//     accountType(type);
//     balanceAmmout = 0.0f;
// }

void BankAccount::balance() {
    std::cout << "Balance: " << balanceAmmout << std::endl;
}

void BankAccount::deposit(float amount) {
    if (amount < 0) {
        std::cout << "Invalid amount" << std::endl;
        return;
    }
    else {
        balanceAmmout += amount;
    }
}

void BankAccount::withdraw(float amount) {
    if (amount > balanceAmmout) {
        std::cout << "Insufficent balance" << std::endl;
        return;
    }
    else {
        balanceAmmout -= amount;
    }
}

void BankAccount::display() {
    std::cout << "Customer Name: " << customerName << std::endl;
    std::cout << "Account numbber: " << accountNumber << std::endl;
    std::cout << "Accout type: " << accountTypeName[acType] << std::endl;
}

int main() {
    BankAccount customer1;
    customer1.customerDetails("Rezwan", 1234);
    customer1.accountType(Savings);

    customer1.balance();
    customer1.deposit(500);
    customer1.balance();
    customer1.withdraw(300);
    customer1.balance();

    customer1.display();

    return 0;
}