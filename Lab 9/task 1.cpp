#include <iostream>

class SmartDevice {
protected:
    int deviceID;
    std::string brandName;
    float powerRating;

public:
    SmartDevice(int id, std::string name, int power) : deviceID(id), brandName(name), powerRating(power) {}
    SmartDevice() {}
    virtual void diagnose() = 0;

    float getPowerRating() {
        return powerRating;
    }

};

void SmartDevice::diagnose() {
    std::cout << "Device ID: " << deviceID << std::endl;
    std::cout << "Brand Name: " << brandName << std::endl;
    std::cout << "Power Rating: " << powerRating << " W" << std::endl;
}