#include <iostream>
using namespace std;

// Base class
class Convert {
protected:
    double val1; // Initial value
    double val2; // Converted value

public:
    // Constructor
    Convert(double initial = 0) : val1(initial), val2(0) {}

    // Function to get initial value
    double getInit() const {
        return val1;
    }

    // Function to get converted value
    double getConv() const {
        return val2;
    }

    // Pure virtual function to perform conversion
    virtual void compute() = 0;

    // Virtual destructor
    virtual ~Convert() {}
};

// Derived class: Celsius to Fahrenheit conversion
class CelsiusToFahrenheit : public Convert {
public:
    CelsiusToFahrenheit(double celsius) : Convert(celsius) {}

    void compute() override {
        val2 = (val1 * 9.0 / 5.0) + 32;
    }
};

// Derived class: Kilometers to Miles conversion
class KilometersToMiles : public Convert {
public:
    KilometersToMiles(double kilometers) : Convert(kilometers) {}

    void compute() override {
        val2 = val1 * 0.621371;
    }
};

int main() {
    double value;

    // Celsius to Fahrenheit conversion
    cout << "Enter temperature in Celsius: ";
    cin >> value;
    CelsiusToFahrenheit tempConverter(value);
    tempConverter.compute();
    cout << "Temperature in Fahrenheit: " << tempConverter.getConv() << endl;

    // Kilometers to Miles conversion
    cout << "\nEnter distance in Kilometers: ";
    cin >> value;
    KilometersToMiles distanceConverter(value);
    distanceConverter.compute();
    cout << "Distance in Miles: " << distanceConverter.getConv() << endl;

    return 0;
}
