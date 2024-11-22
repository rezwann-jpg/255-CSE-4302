#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class SellerActions {
private:
    
public:
    virtual void serveIceCream() = 0;
    virtual void promoteDeal() = 0;
    virtual void specialOffer() = 0;
    virtual void displayStats() = 0;
    virtual ~SellerActions() = default;

};

class BaseSeller : public SellerActions {
protected:
    std::string name;
    int sales;
    int stock;
    bool specialOfferReady;
    int salesBoost;
    int consecutiveSales;
    bool promotionActive;
    int promotionDuration;

public:
    BaseSeller(std::string sellerName, int initialStock, int salesBoost) 
        : name(sellerName), stock(initialStock), sales(0), specialOfferReady(false),
            salesBoost(salesBoost), consecutiveSales(0), promotionActive(0),
            promotionDuration(0) { }

    virtual void serveIceCream() override {
        if (stock > 0) {
            int baseSales = rand() % (30 + 1 - 8) + 8;
            int totalSales = baseSales + (promotionActive ? salesBoost : 0);

            sales += totalSales;
            stock--;
            consecutiveSales++;

            if (consecutiveSales >= 3) {
                specialOfferReady = true;
                consecutiveSales = 0;
            }

            if (promotionActive && --promotionDuration <= 0) {
                promotionActive = false;
            }

            std::cout << name << " served! Sales increased by " << totalSales
                      << ". Total Sales: " << sales << ", Stock: " << stock << std::endl;
        }
    }

    virtual void promoteDeal() override {
        if (!promotionActive) {
            promotionActive = true;
            promotionDuration = 2;
            std::cout << name << " activated a promotion!" << std::endl;
        }
    }

    virtual void specialOffer() override = 0;

    void displayStats() override {
        std::cout << "\nStats for " << name << ":\n" << " - Stock: " << stock << ", Sales: " << sales 
            << ", Special Offer Ready: " << (specialOfferReady ? "Yes" : "No") << std::endl;
    }

    int getSales() { return sales; }
    bool hasStock() { return stock > 0; }
    void addStock(int amount) { stock += amount; }
    bool isSpecialOfferReady() { return specialOfferReady; }
    void setSpecialOfferReady(bool value) { specialOfferReady = value; }
    void decreaseStock() { stock--; }
    void increaseSales(int amount) { sales += amount; }
    int getStock() { return stock; }
};

class ConeMaster : public BaseSeller {
private:
    
public:
    ConeMaster() : BaseSeller("Cone Master", 20, 10) { }

    void serveIceCream() override {
        BaseSeller::serveIceCream();

        int roll = rand() % 100 + 1;
        if (roll <= 20) {
            std::cout << "Cone Master now attempting Cone Master Challange!" << std::endl;
            int scoops = rand() % 10 + 1;
            coneStackChallange(scoops);
        }
    }

    void specialOffer() override {
        if (specialOfferReady && stock >= 3) {
            std::cout << "Cone Master uses Triple Serve special!" << std::endl;
            for (int i = 0; i < 3; ++i) {
                serveIceCream();
            }
            specialOfferReady = false;
        }
    }

    void coneStackChallange(int scoops) {
        int successRate = 100 - (scoops * 10);
        int roll = rand() % 100 + 1;

        if (roll <= successRate) {
            sales += scoops * 5;
            stock -= scoops;
            std::cout << "Cone Master successfully stacked " << scoops << " scoops!" << std::endl;
        }
        else {
            stock -= scoops;
            std::cout << "stack toppled " << scoops << " scoops";
        }
    }
};

class SundaeWizard : public BaseSeller {
private:

public:
    SundaeWizard() : BaseSeller("Sundae Wizard", 15, 20) { }

    void serveIceCream() override {
        BaseSeller::serveIceCream();

        int roll = rand() % 100 + 1;
        if (roll <= 20) {
            std::cout << "Sundae Wizard has activated layered bonus!" << std::endl;
            int layers = rand() % 10 + 1;
            layeredSundaeBonus(layers);
        }
    }

    void specialOffer() override {
        if (specialOfferReady) {
            std::cout << "Sundae Wizard uses Double Sales special!" << std::endl;
            int currentSales = sales;
            serveIceCream();
            sales = currentSales + (sales - currentSales) * 2;
            specialOfferReady = false;
        }
    }

    void layeredSundaeBonus(int layers) {
        if (stock >= layers) {
            serveIceCream();
            sales += layers * 5;
            std::cout << "Used Layerd Sundae Bonus" << std::endl;
        }
    }
};

class IceCreamTruckDriver : public BaseSeller {
private:
    
public:
    IceCreamTruckDriver() : BaseSeller("Ice Cream Truck Driver", 30, 5) { }

    void specialOffer() override {
        if (specialOfferReady) {
            std::cout << "Ice Cream Truck Driver uses Instant Restock special!" << std::endl;
            stock += 10;
            specialOfferReady = false;
        }
    }
};

class CustomerRush {
private:
    int patience;
    int salesGoal;
    int turnsLimit;
    int currentTurn;

public:
    CustomerRush() : patience(200), salesGoal(300), turnsLimit(10), currentTurn(1) { }

    bool isPatient() { return patience > 0; }
    bool isSatisfied(int totalSales) { return totalSales >= salesGoal; }
    bool hasMoreTurns() { return currentTurn <= turnsLimit; } 

    void updatePatience() {
        int decrease = rand() % (50 + 1 - 20) + 20;
        patience -= decrease;
        std::cout << "\nCustomer patience decreased by " << decrease
                  << ". Current patience: " << patience << std::endl;
    }

    void nextTurn() { currentTurn++; }
    int getCurrentTurn() { return currentTurn; }
};

class SimulationEngine {
private:
    std::vector<BaseSeller *> sellers;
    CustomerRush customerRush;

public:
    void addSeller(BaseSeller *seller) {
        sellers.push_back(seller);
    }

    void runSimulation() {
        std::cout << "Game begins! Sellers vs. Customer Rush\n\n";

        while (customerRush.hasMoreTurns() && customerRush.isPatient()) {
            std::cout << "\nTurn " << customerRush.getCurrentTurn() << ":\n";

            int totalSales = 0;

            for (const auto& seller : sellers) {
                if (seller->hasStock()) {
                    seller->serveIceCream();

                    if (rand() % 100 + 1 < 50) {
                        seller->specialOffer();
                        seller->promoteDeal();
                    }

                    totalSales += seller->getSales();
                    std::cout << "Collective totalSales: " << totalSales << std::endl;

                    if (customerRush.isSatisfied(totalSales)) {
                        std::cout << "\nCustomer Rush satisfied! Sellers win!\n";
                        return;
                    }
                }
            }

            customerRush.updatePatience();
            customerRush.nextTurn();
        }

        std::cout << "\nGame Over! ";
        if (!customerRush.isPatient()) {
            std::cout << "Customers lost patience!\n";
        } else {
            std::cout << "Failed to reach sales goal in time!\n";
        }
    }
};

int main() {
    SimulationEngine engine;

    engine.addSeller(new ConeMaster());
    engine.addSeller(new SundaeWizard());
    engine.addSeller(new IceCreamTruckDriver());

    engine.runSimulation();

    return 0;
}