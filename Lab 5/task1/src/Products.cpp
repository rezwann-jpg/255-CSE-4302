#include "Products.h"

Products::Products() {
    srand(static_cast<unsigned int>(time(0)));
}

Products::~Products() {}

void Products::setProductName(std::string name) {
    productName = name;
}

std::string Products::getProductName() const {
    return productName;
}

void Products::setProductCatagoryName(std::string catagoryName) {
    productCatagoryName = catagoryName;
}

std::string Products::getProductCatagoryName() const {
    return productCatagoryName;
}

void Products::setProductDescription(std::string productDesc) {
    productDescription = productDesc;
}

std::string Products::getProductDescription() const {
    return productDescription;
}

void Products::setAmount(int amount) {
    amountInStore = amount;
}

int Products::getAmount() const {
    return amountInStore;
}

void Products::setPrice(float price) {
    regularPrice = price;
}

float Products::getPrice() const {
    return regularPrice;
}

void Products::setDiscountRate(float discount) {
    discountRate = discount;
}

float Products::getDiscountRate() const {
    return discountRate;
}

void Products::PurchaseProduct(int amount) {
    if (amount > amountInStore) {
        std::cout << "Insufficient amount" << std::endl;
        return;
    }

    amountInStore -= amount;
}

void Products::RestockProduct(int amount) {
    amountInStore += amount;
}

double Products::calculateDiscount(int amountOfProducts) const {
    double calculatedDiscount = 0;
    
    if (amountOfProducts >= 5) {
        double calculatedDiscount = amountOfProducts * (discountRate / 100);
    }

    if (amountOfProducts >= 10) {
        calculatedDiscount += amountOfProducts * (3 / 100);
    }

    return calculatedDiscount;
}

float Products::netTotal(int amountOfProducts) const {
    return (amountOfProducts * regularPrice) - calculateDiscount(amountOfProducts);
}

void EditInformationByKeyboard(Products &p) {
    std::string name, catagory, description;
    int amount;
    float price, discount;

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Product Catagory: ";
    std::getline(std::cin, catagory);
    std::cout << "Enter Product Description: ";
    std::getline(std::cin, description);    
    std::cout << "Enter Amount: ";
    std::cin >> amount;    
    std::cout << "Enter Price: ";
    std::cin >> price;    
    std::cout << "Enter Discount Rate: ";
    std::cin >> discount;
    std::cin.ignore();

    p.setProductName(name);
    p.setProductCatagoryName(catagory);
    p.setProductDescription(description);
    p.setAmount(amount);
    p.setPrice(price);
    p.setDiscountRate(discount);    
}

void generateInformaiotnRandom(Products &p) {
    p.setProductName(generateRandomString(rand() % (7 - 3 + 1) + 3) + " " + generateRandomString(rand() % (7 - 3 + 1) + 3) + " " + generateRandomString(rand() % (7 - 3 + 1) + 3));
    p.setProductCatagoryName(generateRandomString(rand() % (7 - 3 + 1) + 3));
    std::string description = "";
    for (int i = 0; i < 10; i++) {
        description += generateRandomString(rand() % (7 - 3 + 1) + 3);
    }
    p.setProductDescription(description);
    p.setAmount(rand() % 150 + 1);
    p.setPrice(rand() % 100 + 1);
    p.setDiscountRate(static_cast<float>(rand() % 5 + 1));
}

void ShowAllDiscount(Products ar[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Product: " << ar[i].getProductName() << "Discount: " << ar[i].getDiscountRate() << std::endl; 
    }
}

void grossTotal(Products ar[], int size) {
    float totalSum = 0;
    for (int i = 0; i < size; i++) {
        int amountToPurchase = rand() % 20 + 1;
        std::cout << "Purchasing " << amountToPurchase << "of " << ar[i].getProductName() << std::endl;
        totalSum += ar[i].netTotal(amountToPurchase);  
    }

    std::cout << "Total Sum is: " << totalSum << std::endl;
}

void ShowAllAlphabetically(Products ar[], int size) {
    std::vector<Products> productVector(ar, ar + size);
    std::sort(productVector.begin(), productVector.end(), [](Products a, Products b) {
        return a.getProductName() < b.getProductName();
    });

    for (Products &product : productVector) {
        std::cout << "Product: " << product.getProductName() << " | Amount in store: " << product.getAmount() << std::endl;
    }
}

std::string generateRandomString(int length) {
    std::string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    // srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

double randomInRange(double min, double max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    // Generate a random double between 0 and 1
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    // Scale and shift the random value to the desired range
    return min + randomFraction * (max - min);

}
