#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

// #if !defined(DEBUG)
  #define DEBUG fasle

  #if !defined(DEBUG)
  #endif

class Point
{
private:
  int x, y;

public:
  Point(int = 0, int = 0);
  Point(const Point &p);
  void Setxy(int a, int b);
  void Move(int a, int b);

  void show()
  {
    cout << "x=" << x << "y=" << y << endl;
  };
  int Getx();
  int Gety();
  ~Point(){
    cout<< "delete:::" << x << "," << y << endl;
  }; 
};

// Point::~Point(void)
// {
//     cout << "释放内存" << x << "::" << y << endl;
// }

Point::Point(int a, int b) : x(a), y(b)
{
  cout << "Init default2:" << a << "," << b << endl;
}

Point::Point(const Point& t){
   cout << "copy init:::" << endl;
  x=t.x;
  y=t.y;
};

void Point::Setxy(int a, int b)
{
  this->x = a;
  this->y = b;
}
void Point::Move(int a, int b)
{
  this->x = x + a;
  this->y = y + b;
}

inline int Point::Getx()
{
  return x;
}

int Point::Gety()
{
  return y;
}

void disp(Point &p)
{
  p.show();  
}

void display(Point p)
{
  p.show();  
}

Point fun(){
  Point A(101,202);
  return A;
}

class Empty{

};

int main(int argc, char const *argv[])
{
  Point A(111,222);
  Point B(A);
  Point C(333,444);
  cout << "called dispaly(B)" << endl;
  display(B);
  cout<<"Next..." <<endl;
  cout<< "called disp(B)" << endl;
  disp(B);
  cout << "call C= fun()" <<endl;
  C = fun();
  cout<< "called disp(c)" <<endl;
  disp(C);
  cout<<"out..."<<endl;

  Empty object;
  return 0;
}
