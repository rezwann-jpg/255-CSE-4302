#include <iostream>
#include <string>

enum accountType {
    current,
    savings
};

class BankAccount {
public:
    BankAccount(int acNum, std::string acName, accountType type) : minimumBalance(100.00), interestRate(3.0), balance(0.0) {
        this->accountNumber = acNum;
        this->accountHolderName = acName;
        this->type = type;
        accountCreatedCount++;
    }
    ~BankAccount() {
        std::cout << "Account of " << accountHolderName << " with account no " << accountNumber <<" is destroyed with a balance BDT " << balance << std::endl;
        accountDestroyedCount++;
    }
    void displayDetails();
    float showBalance() const;
    void deposit(float amount);
    void withdrawal(float amount);
    void giveInterest();

    static int accountCreatedCount;
    static int accountDestroyedCount;

private:
    int accountNumber;
    std::string accountHolderName;
    accountType type;
    float balance;
    const float minimumBalance;
    float interestRate;

};

int BankAccount::accountCreatedCount = 0;
int BankAccount::accountDestroyedCount = 0;

void BankAccount::displayDetails() {
    std::cout << "Account Holder: " << accountHolderName << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Type: ";
    if (type == current) 
        std::cout << "Current" << std::endl;
    if (type == savings) 
        std::cout << "Savings" << std::endl;
    std::cout << "Account Balance: " << balance << std::endl;
}

float BankAccount::showBalance() const {
    return balance;
}

void BankAccount::deposit(float amount) {
    if (amount < 0) {
        std::cout << "Invalid amount" << std::endl;
        return;
    }
    else {
        balance += amount;
    }
}

void BankAccount::withdrawal(float amount) {
    if (amount > balance) {
        std::cout << "Insufficent balance" << std::endl;
        return;
    }
    else if (balance - amount < minimumBalance) {
        std::cout << "Cannot withdraw" << std::endl;
        return;
    }
    else {
        balance -= amount;
    }
}

void BankAccount::giveInterest() {
    float interest = (balance * interestRate) / 100;
    float sourceTax = interest * 0.1;
    float netInterest = interest - sourceTax;
    balance += netInterest;
}

void display_stat() {
    std::cout << "Total objects created: " << BankAccount::accountCreatedCount << std::endl;
    std::cout << "Total objects present: " << BankAccount::accountCreatedCount - BankAccount::accountDestroyedCount << std::endl;
}

BankAccount Larger(const BankAccount A, const BankAccount B) {
    if (A.showBalance() > B.showBalance()) {
        return A;
    }
    else {
        return B;
    }
}

int main() {
    BankAccount a1(123, "Rezwan", savings);

    a1.deposit(100);
    a1.giveInterest();

    a1.displayDetails();

    return 0;
}