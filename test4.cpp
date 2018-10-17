#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

class Point
{
private:
  int x, y;
  int *ptr;

public:
  Point(const Point &obj);
  Point(int = 2, int = 2);
  ~Point(); 
  void Setxy(int a, int b);
  void Move(int a, int b);

  void Display()
  {
    cout << Getx() << "," << Gety() << endl;
  };
  int Getx();
  int Gety();
};

Point::~Point(void)
{
    cout << "释放内存" << x << "::" << y << endl;
}

Point::Point(int a, int b) : x(a), y(b)
{
  cout << "Init default2:" << a << "," << b << endl;
}

Point::Point(const Point& t){
   cout << "调用拷贝构造函数" << endl;
  x=t.x+1;
  y=t.y+1;
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

void disp(Point &p)
{
  p.Display();  
}

void display(Point p)
{
  p.Display();  
}

Point fun(){
  Point A(101,202);
  return A;
}

int main(int argc, char const *argv[])
{
  Point obj1(333,222);
  Point obj3(888,999);
  obj3 =  fun();
  display(obj3);
  // Point obj2(obj1);
  // obj1.Setxy(555,666);
  // obj1.Display();
  // obj2.Display();

  // Point *ptr1 = new Point[2];
  // delete []ptr1;

  // display(obj1);
  // display(obj1);
  // disp(obj1);

  return 0;
}
