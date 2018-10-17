#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

class shape
{
public:
  virtual double area() = 0;
  // virtual double area()
  // {
  //   cout << "shape";
  //   return 0;
  // }
};

class square : public shape
{
protected:
  double H;

public:
  square(double i)
  {
    H = i;
  }
  double area()
  {
    cout << "square ";
    return H * H;
  }
};

class circle : public square
{
public:
  circle(double r) : square(r)
  {
  }
  double area()
  {
    cout << "circle ";
    return H * H * 3.14159;
  }
};

class triangle : public square
{
protected:
  double W;

public:
  triangle(double h, double w) : square(h)
  {
    W = w;
  }
  double area()
  {
    cout << "triangle ";
    return H * W * 0.5;
  }
};

class rectangle : public triangle
{
public:
  rectangle(double h, double w) : triangle(h, w)
  {
  }
  double area()
  {
    cout << "rectangle ";
    return H * W;
  }
};

double totalp(shape *s[], int n)
{
  double sum = 0.0;
  for (int i = 0; i < n; i++)
  {
    sum += s[i]->area();
  }
  return sum;
}

// double totalr(shape &s[], int n)
// {
//   double sum = 0.0;
//   for (int i = 0; i < n; i++)
//   {
//     sum += s[i].area();
//   }
//   return sum;
// }

int main(int argc, char const *argv[])
{
  shape *s[5];
  s[0] = new square(4);
  s[1] = new triangle(3, 6);
  s[2] = new rectangle(3, 6);
  s[3] = new square(6);
  s[4] = new circle(10);
  // shape s[5];
  // s[0] = square(4);
  // s[1] = triangle(3, 6);
  // s[2] = rectangle(3, 6);
  // s[3] = square(6);
  // s[4] = circle(10);
  for (int i = 0; i < 5; i++)
  {
    // cout << "s[" << i << "]=" << s[i].area() << endl;
    cout << "s[" << i << "]=" << s[i]->area() << endl;
  }
  double sum = totalp(s, 5);
  // double sum = totalr(s, 5);
  cout << "The total area is : " << sum << endl;
  return 0;
}
