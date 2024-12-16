#include <iostream>
#include <cmath>
using namespace std;

class Quadratic {
private:
    double a, b, c; // Coefficients of the quadratic polynomial

public:
    // Default constructor
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    // Overloaded operator+ to add two Quadratic polynomials
    Quadratic operator+(const Quadratic& other) {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    // Overloaded >> operator to input a Quadratic polynomial
    friend istream& operator>>(istream& in, Quadratic& q) {
        cout << "Enter coefficients a, b, and c: ";
        in >> q.a >> q.b >> q.c;
        return in;
    }

    // Overloaded << operator to output a Quadratic polynomial
    friend ostream& operator<<(ostream& out, const Quadratic& q) {
        out << q.a << "x^2 ";
        if (q.b >= 0) out << "+ ";
        out << q.b << "x ";
        if (q.c >= 0) out << "+ ";
        out << q.c;
        return out;
    }

    // Function to evaluate the polynomial for a given value of x
    double eval(double x) {
        return (a * x * x) + (b * x) + c;
    }

    // Function to compute the solutions of the quadratic equation
    void computeSolutions() {
        if (a == 0) {
            if (b == 0) {
                cout << (c == 0 ? "Infinite solutions" : "No solution") << endl;
            } else {
                cout << "Linear solution: x = " << -c / b << endl;
            }
            return;
        }

        double discriminant = (b * b) - (4 * a * c);
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Two distinct real solutions: x1 = " << root1 << ", x2 = " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "One real solution: x = " << root << endl;
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Two complex solutions: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main() {
    Quadratic q1, q2;

    // Input two Quadratic polynomials
    cout << "Enter the first polynomial:\n";
    cin >> q1;
    cout << "Enter the second polynomial:\n";
    cin >> q2;

    // Display the polynomials
    cout << "\nFirst Polynomial: " << q1 << endl;
    cout << "Second Polynomial: " << q2 << endl;

    // Add the polynomials
    Quadratic sum = q1 + q2;
    cout << "\nSum of the polynomials: " << sum << endl;

    // Evaluate the first polynomial at x = 2
    double x = 2;
    cout << "\nValue of the first polynomial at x = " << x << ": " << q1.eval(x) << endl;

    // Compute solutions of the first polynomial
    cout << "\nSolutions of the first polynomial:\n";
    q1.computeSolutions();

    return 0;
}
