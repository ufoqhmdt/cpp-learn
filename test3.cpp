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

// Point::Point(int a, int b) : x(0), y(0)
// {
//   cout << "Init default1:" << endl;
// }

// Point::Point(const Point &obj)
// {
//     cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
//     ptr = new int;
//     *ptr = *obj.ptr; // 拷贝值
// }
 
Point::~Point(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}

Point::Point(int a, int b) : x(a), y(b)
{
  cout << "Init default2:" << a << "," << b << endl;
}

Point::Point(const Point& t){
   cout << "调用拷贝构造函数" << endl;
  x=t.x;
  y=t.y;
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

Point ufo(99, 89);
int main(int argc, char const *argv[])
{
  Point A, B;
  Point *p = &A;
  Point &R = B;
  A.Setxy(23, 99);
  B.Setxy(231, 991);
  p->Display();
  R.Display();

  Point A2;
  A2.Display();
  Point B2(22, 33);
  B2.Display();
  Point C[2];
  cout << "-------";
  Point D[4] = {Point(5, 7), Point(8, 12)};
  ufo.Display();

  Point *pp1 = new Point();
  Point *pp2 = new Point(4, 9);

  delete pp1;
  delete pp2;
  // pp1.Display();
  // pp2.Display();

  Point obj1(333,222);
  Point obj2(obj1);
  obj2.Display();


  return 0;
}
