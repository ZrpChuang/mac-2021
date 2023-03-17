#include <iostream>
#include <math.h>
using namespace std;

class Magic {
    double x;
public:
    Magic(double d = 0.00) :x(fabs(d)) {}
    Magic operator+ (Magic& c) {
        return Magic(sqrt(x * x + c.x * c.x));
    }
    friend ostream& operator<<(ostream& stream, Magic& c) {
        stream << c.x;
        return stream;
    }
};
void main() {
    Magic ma;
    cout << ma << ", " << Magic(2) << ", " << ma + Magic(-6) + Magic(-8) << endl;
}
