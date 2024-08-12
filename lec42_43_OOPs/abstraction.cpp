#include <iostream>
using namespace std;

class Car {
public:
    void start() {
        ignition();
        fuelInjection();
        crankEngine();
    }

private:
    void ignition() {
        cout << "Ignition started." << endl;
    }

    void fuelInjection() {
        cout << "Fuel injected." << endl;
    }

    void crankEngine() {
        cout << "Engine cranked." << endl;
    }
};

int main() {
    
    Car myCar;
    myCar.start();  // The user only needs to know how to start the car, not how ignition, fuel injection, or cranking works.

    return 0;
}
