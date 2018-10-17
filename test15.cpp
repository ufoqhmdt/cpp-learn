#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

class complex
{
private:
  double real, image;

public:
  complex(double r = 0, double i = 0)
  {
    real = r;
    image = i;
  }
  friend complex operator+(complex, complex);
  void show()
  {
    cout << real << "+" << image << "i";
  }
};

complex operator+(complex a, complex b)
{
  cout << a.real << "::" << b.real << endl;
  cout << a.image << "::" << b.image << endl;
  double r = a.real + b.real;
  double i = a.image + b.image;
  return complex(r, i);
}

int main(int argc, char const *argv[])
{
  complex x(5, 3), y, ufo(9, 9);
  y = x + ufo;
  y = 7 + y;
  y.show();
  cout << endl;

  // char *p = new char[5];
  // for (int i = 0; i < 4; i++)
  // {
  //   cin >> *(p + i);
  // }
  // p[4] = '\ 0';
  // cout << p << endl;

  char b2[3], c;
  cin >> b2 >> c;

  b2[5] = '\0';
  cout << b2 << "::" << c << endl;
  return 0;
}
