#include "Products.h"

int main() {
    Products products[100];
    const int SIZE = 100;

    EditInformationByKeyboard(products[0]);
    EditInformationByKeyboard(products[1]);

    for (int i = 2; i < SIZE; i++) {
        generateInformaiotnRandom(products[i]);
    }

    ShowAllDiscount(products, SIZE);

    grossTotal(products, SIZE);

    ShowAllAlphabetically(products, SIZE);

    return 0;
}