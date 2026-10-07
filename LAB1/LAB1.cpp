#include <iostream>
#include <cmath>
using namespace std;

class TaskSolver {
private:
    double a;
    double b;

    double Faktr(int n)
    {
        double f = 1.0;
        for (int i = 1; i <= n; i++)
        {
            f *= i;
        }
        return f;
    }

public:
    TaskSolver() { a = 0.0; b = 0.0; }

    void CalculateB(double x, double y, double z)
    {
        double b1 = y + atan(pow(fabs(x * x + z), 0.1));
        double b2 = 3.0 / x + pow(sin(pow(y + z, 3)), 2);
        double b3 = y * exp(-(x + z) / (y + z));

        b = x * (b1 / b2 + b3);
    }

    void CalculateA(double x, double y, double z)
    {
        double a1 = sqrt(pow(fabs(x * x - z), 0.3));
        double a2 = cbrt(fabs(y + 2 * b));
        double a3 = 1.0 + pow(x, 1) / Faktr(1) + pow(y, 2) / Faktr(2) + pow(z, 3) / Faktr(3);

        a = (a1 - a2) / a3;
    }

    double getA() { return a; }
    double getB() { return b; }
};

int main() {
    int variant = 1;

    double x = 0.48 * variant;
    double y = 0.47 * variant;
    double z = -1.32 * variant;

    TaskSolver solver;
    solver.CalculateB(x, y, z);
    solver.CalculateA(x, y, z);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "b = " << solver.getB() << endl;
    cout << "a = " << solver.getA() << endl;

    return 0;
}
