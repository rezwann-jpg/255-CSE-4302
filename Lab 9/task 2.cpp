#include "task 1.cpp"
#include <iostream>
#include <string>

enum class Mode {
    Cooling,
    Heating,
    Fan_Only
};

std::string getModeString(Mode mode) {
    switch (mode) {
        case Mode::Cooling:
        return "Cooling";
        case Mode::Heating:
        return "Heating";
        case Mode::Fan_Only:
        return "Fan Only";
    }
}


class ThermostatDevice : virtual public SmartDevice {
private:
    float minTemperature;
    float maxTemperature;
    Mode mode;

public:
    ThermostatDevice(int id, std::string name, float power, float minTemperature, float maxTemperature, Mode mode) : SmartDevice(id, name, power), minTemperature(minTemperature), maxTemperature(maxTemperature), mode(mode) { }

    virtual double calculatePowerConsumption(float hours) const {
        return powerRating * hours;
    }
    
    void diagnose() override {
        SmartDevice::diagnose();
        std::cout << "Mode: " << getModeString(mode) << std::endl;
        std::cout << "Temprature Range: " << minTemperature << " - " << maxTemperature << "C" << std::endl;
    }

    float getPowerRating() const {
        return powerRating;
    }
};

class SecurityCameraDevice : virtual public SmartDevice {
private:
    std::string resolution;
    float recordingHours;

public:
    SecurityCameraDevice(int id, std::string name, float power, std::string resolution, float recordingHours) : SmartDevice(id, name, power), resolution(resolution), recordingHours(recordingHours) {}

    double calculateDataUsage(double days) const {
        return (recordingHours * days) * 1000;
    }

    void diagnose () override {
        SmartDevice::diagnose();
        std::cout << "Resolution: " << resolution << std::endl;
        std::cout << "Recording Hours: " << recordingHours << " hours" << std::endl;
    }

};
