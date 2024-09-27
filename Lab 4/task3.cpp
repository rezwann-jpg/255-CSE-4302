#include <iostream>

const int year = 2024;

enum status {
    Low,
    Moderate,
    High
};

class Employee {
public:
    void FeedInfo(std::string EmpName, int ID, float baseSalary, int joiningYear) {
        this->EmpName = EmpName;
        this->ID = ID;
        this->baseSalary = baseSalary;
        this->joiningYear = joiningYear;
    }
    void ShowInfo();

private:
    std::string EmpName;
    int ID;
    float baseSalary;
    int joiningYear;
    status EmpStat;
    int age;

    float calculateTotalSalary();
    float calculateBonus();
    status getStatus();
};

void Employee::ShowInfo() {

}

float Employee::calculateTotalSalary() {
    int y = year - joiningYear;
    while (y--) {
        baseSalary += baseSalary * 0.03;
    }
    float totalSalary;
    totalSalary = baseSalary + baseSalary * 0.1 + baseSalary * 0.3 + baseSalary * 0.1;
    return totalSalary;
}

float Employee::calculateBonus() {
    EmpStat = getStatus();
    switch (EmpStat) {
        case Low:
            return 0.05;
        case Moderate:
            return 0.1;
        case High:
            return 0.15;
    }
}

status Employee::getStatus() {
    if (age <= 25) {
        if (calculateTotalSalary() <= 20000) {
            return Low;
        }
        else if (calculateTotalSalary() > 20000) {
            return Moderate;
        }
    }
    else if (age > 25) {
        if (calculateTotalSalary() <= 21000) {
            return Low;
        }
        else if (calculateTotalSalary() > 21000 && calculateTotalSalary() <= 60000) {
            return Moderate;
        }
        else if (calculateTotalSalary() > 60000) {
            return High;
        }
    }
}
