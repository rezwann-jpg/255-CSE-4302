#include <iostream>
#include <string>

class Person {
public:
    Person(std::string name) : name(name) { }
    virtual void display() {
        std::cout << "Name: " << name << std::endl;
    }

protected:
    std::string name;
};

class Employee : public Person {
public:
    Employee(std::string name, int id, float salary) : Person(name), employeeId(id), salary(salary) { }
    void display() override {
        std::cout << "Name: " << name << "\nID: " << employeeId << "\nSalary: " << salary << std::endl;
    }

protected:
    float salary;

private:
    int employeeId;
};

class Intern : private Employee {
public:
    Intern(std::string name, int id, float salary, std::string schoolName) : Employee(name, id, salary) , schoolName(schoolName) { }
    void display() override {
        Employee::display();
        std::cout << "School Name: " << schoolName << std::endl;
    }

private:
    std::string schoolName;
};

class Manager : protected Employee {
public:
    Manager(std::string name, int id, float salary, std::string dept) : Employee(name, id, salary), department(dept) { }
    void display() override {
        Employee::display();
        std::cout << "Department: " << department << std::endl;
    }

private:
    std::string department;
};

class Director : public Manager {
public:
    Director(std::string name, int id, float salary, std::string dept, float bonus) : Manager(name, id, salary, dept), bonus(bonus) { }
    void display() override {
        Manager::display();
        std::cout << "Bonus: " << bonus << std::endl;
    }

private:
    float bonus;
};

int main() {
    Person *p = new Person("John Doe");
    Employee *e = new Employee("Jane Smith", 101, 50000);
    Intern *i = new Intern("Alice Brown", 102, 30000, "XYZ University");
    Manager *m = new Manager("Bob White", 103, 70000, "Sales");
    Director *d = new Director("Mary Green", 104, 120000, "Marketing", 15000);

    std::cout << "Person details:\n";
    p->display();
    std::cout << std::endl;

    std::cout << "Employee details:\n";
    e->display();
    std::cout << std::endl;

    std::cout << "Intern details:\n";
    i->display();
    std::cout << std::endl;

    std::cout << "Manager details:\n";
    m->display();
    std::cout << std::endl;

    std::cout << "Director details:\n";
    d->display();
    std::cout << std::endl;

    delete p;
    delete e;
    delete i;
    delete m;
    delete d;

    return 0;
}
