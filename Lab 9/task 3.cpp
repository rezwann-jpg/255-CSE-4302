#include "task 2.cpp"
#include <iostream>

class SmartThermostat : public ThermostatDevice {
private:
    bool remoteControlEnabled;

public:
    SmartThermostat(int id, std::string name, float power, float minTemperature, float maxTemperature, Mode mode, bool remote) : SmartDevice(id, name, power), ThermostatDevice(id, name, power, minTemperature, maxTemperature, mode), remoteControlEnabled(remote) {}

    void diagnose() override {
        ThermostatDevice::diagnose();
        std::cout << "Remote control is enabled: " << (remoteControlEnabled ? "Yes" : "No") << std::endl;
    }

    double calculatePowerConsumption(float hours) const override {
        return remoteControlEnabled ? (powerRating * hours * 0.9) : (powerRating * hours);
    }

};

class HybridThermostat : public ThermostatDevice, public SecurityCameraDevice {
private:
    float energySavingEfficiency;

public:
    HybridThermostat(int id, std::string name, float power, float minTemperature, float maxTemperature, Mode mode, std::string res, float hours, float efficiency) : SmartDevice(id, name, power), ThermostatDevice(id, name, power, minTemperature, maxTemperature, mode), SecurityCameraDevice(id, name, power, res, hours), energySavingEfficiency(efficiency) {}

    void diagnose() override {
        ThermostatDevice::diagnose();
        SecurityCameraDevice::diagnose();
        std::cout << "Energy saving efficiency: " << energySavingEfficiency << std::endl;
    }
    
    double calculatePowerConsumption(float hours) const override {
        return (ThermostatDevice::getPowerRating() * hours) * (1 - (energySavingEfficiency / 100));
    }
};