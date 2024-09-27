#include <iostream>
#include <string>

class Product {
public:
    Product(std::string name, int id, float price, int quantity, int maxQuantity);
    ~Product();
    void addToInventory(int addedQuantity);
    void purchase(int purchasedQuantity);
    void updatePrice(int discountPercent);
    void displayInventoryValue();
    void displayDetails();
    static void displayTotalInventoryValue();
    
    static float totalInventoryValue;
private:
    bool isAvailable();

    std::string productName;
    int productID;
    float price;
    int quantity;
    int maxQuantity;

};

float Product::totalInventoryValue = 0;

Product::Product(std::string name, int id, float price, int quantity, int maxQuantity) {
    this->productName = name;
    this->productID = id;
    this->price = price;
    this->quantity = quantity;
    this->maxQuantity = maxQuantity;

    totalInventoryValue += quantity * price;
}

Product::~Product() {
    std::cout << "The destructor for the object Product is called." << std::endl;
}

void Product::addToInventory(int addedQuantity) {
    if (quantity + addedQuantity > maxQuantity) {
        std::cout << "Cant add more than " << maxQuantity << std::endl;
    }
    else {
        quantity += addedQuantity;
        totalInventoryValue += ((quantity * price) - totalInventoryValue);
    }
}

bool Product::isAvailable() {
    return quantity > 0;
}

void Product::purchase(int purchasedQuantity) {
    if (isAvailable() && purchasedQuantity <= quantity) {
        quantity -= purchasedQuantity;
        totalInventoryValue -= (totalInventoryValue - (quantity * price));
    }
    else {
        std::cout << "Insufficient Product" << std::endl;
    }
}

void Product::updatePrice(int discountPercent) {
    price -= price * (discountPercent / 100.00);
}

void Product::displayInventoryValue() {
    std::cout << "Inventory Value for " << productName << " " << "is: " << quantity * price << std::endl;
}

void Product::displayDetails() {
    std::cout << "Product Name: " << productName << std::endl; 
    std::cout << "Product ID: " << productID << std::endl; 
    std::cout << "Price: " << price << std::endl; 
    std::cout << "Quantity: " << quantity << std::endl; 
    std::cout << "Available?: " << (isAvailable() ? "Yes" : "No") << std::endl; 
}

void Product::displayTotalInventoryValue() {
    std::cout << "Total Inventory Value: " << totalInventoryValue << std::endl;
}

int main() {
    Product p1("Fruit Loops", 321, 10, 10, 500);

    p1.addToInventory(10);
    p1.purchase(10);
    p1.updatePrice(10);

    p1.displayInventoryValue();
    p1.displayDetails();

    Product p2("Dr Pepper", 425, 10, 10, 600);
    Product p3("Iced tea", 526, 10, 10, 400);

    Product::displayTotalInventoryValue();

    return 0;
}