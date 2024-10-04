#ifndef PRODUCTS_H
#define PRODUCTS_H

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

class Products {
public:
    Products();
    ~Products();

    void setProductName(std::string name);
    std::string getProductName() const;
    void setProductCatagoryName(std::string catagoryName);
    std::string getProductCatagoryName() const;
    void setProductDescription(std::string productDesc);
    std::string getProductDescription() const;
    void setAmount(int amount);
    int getAmount() const;
    void setPrice(float price);
    float getPrice() const;
    void setDiscountRate(float discount);
    float getDiscountRate() const;

    void PurchaseProduct(int amount);
    void RestockProduct(int amount);

    double calculateDiscount(int amountOfProducts) const;
    float netTotal(int amountOfProducts) const;

private:
    std::string productName;
    std::string productCatagoryName;
    std::string productDescription;
    int amountInStore;
    float regularPrice;
    float discountRate;

};

void EditInformationByKeyboard(Products &p);
void generateInformaiotnRandom(Products &p);
void ShowAllDiscount(Products ar[], int size);
void grossTotal(Products ar[], int size);
void ShowAllAlphabetically(Products ar[], int size);
std::string generateRandomString(int length);
int randomInRange(int min, int max);
double randomInRange(double min, double max);

#endif