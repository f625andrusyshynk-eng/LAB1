#include <iostream>
#include <cmath>
using namespace std;
class ZavdClass {
private: double a; double b;
       double Faktr(int n)
       {
           double f = 1.0;
           for (int i = 1; i <= n; i++)
           {
               f *= i;
           }
           return f;
       }
public: ZavdClass() 
       { 
       a = 0.0;
       b = 0.0; 
       }
      void Fn_b(double x, double y, double z)
      {
          double b1 = x * x + tan(pow(y + z, 2));
          double b2 = 0.345 * y * pow(sin(x * x), 2);
          double b3 = exp(-(x + y) / z);

          b = y * (b1 / b2 + b3);
      }

      void Fn_a(double x, double y, double z)
      {
          double a1 = pow(x + y, 2);
          double a2 = (x + y * y) * pow(b * b + z, 0.3);
          double a3 = x / Faktr(2) + exp(z - 2) + y * y / Faktr(3);

          a = a1 * a2 / a3;
      }

      double getA()
      {
          return a;
      }

      double getB()
      {
          return b;
      }
};
int main() {
    int variant = 1;
    double x = 0.48 - variant;
    double y = 0.47 - variant;
    double z = -1.32 - variant;

    ZavdClass zavd;
    zavd.Fn_b(x, y, z);
    zavd.Fn_a(x, y, z);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "b = " << zavd.getB() << endl;
    cout << "a = " << zavd.getA() << endl;

    return 0;
}
