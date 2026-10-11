#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
    int num, den;

    void simplify() {
        int g = gcd(num, den);
        num /= g;
        den /= g;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        num = n;
        den = d;
        simplify();
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.num >> f.den;

        if (in && f.den != 0) {
            f.simplify();
        } else if (in && f.den == 0) {
            in.setstate(ios::failbit);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    Fraction f;

    cout << "Enter numerator and denominator: ";

    if (cin >> f) {
        cout << "Simplified fraction: " << f << endl;
    } else {
        cout << "Invalid fraction input!" << endl;
    }

    return 0;
}