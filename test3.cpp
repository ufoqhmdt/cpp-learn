#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

class Point
{
private:
  int x, y;

public:
  void Setxy(int a, int b);
  void Move(int a, int b);
  void Display(){
    cout << Getx() << "," << Gety() << endl;
  };
  int Getx();
  int Gety();
};

void Point::Setxy(int a, int b)
{
  x = a;
  y = b;
}
void Point::Move(int a, int b)
{
  x = x + a;
  y = y + b;
}

inline int Point::Getx()
{
  return x;
}

int Point::Gety()
{
  return y;
}

int main(int argc, char const *argv[])
{
  return 0;
}
