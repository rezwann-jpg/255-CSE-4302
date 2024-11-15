#include "task 3.cpp"
#include <algorithm>

void sort_devices_by_power(SmartDevice** devices, int n) {
    std::sort(devices, devices + n, [](SmartDevice* a, SmartDevice* b) {
        return a->getPowerRating() < b->getPowerRating();
    });
}

int main() {
    ThermostatDevice* thermostat = new ThermostatDevice(1, "Nest", 50.0, 10.0, 30.0, Mode::Cooling);
    SecurityCameraDevice* camera = new SecurityCameraDevice(2, "Ring", 15.0, "1080p", 12.0);
    SmartThermostat* smartThermostat = new SmartThermostat(3, "Ecobee", 55.0, 15.0, 25.0, Mode::Heating, true);
    HybridThermostat* hybridThermostat = new HybridThermostat(4, "Nest", 60.0, 10.0, 30.0, Mode::Fan_Only, "4K", 18.0, 85.0);

    SmartDevice* devices[] = {thermostat, camera, smartThermostat, hybridThermostat};
    int n = 4;

    sort_devices_by_power(devices, n);

    std::cout << "Sorted Devices by Power Rating:\n";
    for (int i = 0; i < n; ++i) {
        devices[i]->diagnose();
        std::cout << std::endl;
    }

    std::cout << "HybridThermostat Information:\n";
    hybridThermostat->diagnose();
    std::cout << std::endl;

    delete thermostat;
    delete camera;
    delete smartThermostat;
    delete hybridThermostat;

    return 0;
}
