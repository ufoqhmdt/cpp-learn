#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

const double PI = 3.14159;

class Point{
  private:
    double x,y;
  public:
    Point(double i, double j){
      x=i;y=j;
    }
    virtual double area(){
      return 0;
    }
};

class Circle:public Point{
  private:
    double radius;
  public:
    Circle(double a,double b,double r):Point(a,b){
      radius = r;
    }
    double area(){
      return PI*radius*radius;
    }
};

void display(Point *p){
  cout<< p->area() << endl;
}
void display(Point &a){
  cout << a.area() << endl;
}

int main(int argc, char const *argv[])
{
  Point a(1.5,6.7);
  Circle c(1.5,6.7,2.5);
  cout << "area of Point is "<<a.area() << endl;
  cout << "area of Circle is "<<c.area() << endl;
  Point *p = &c;
  cout << "area of Circle is "<<p->area() << endl;
  Point &rc = c;
  cout << "area of Circle is "<<rc.area() << endl;

  display(a);
  display(p);
  display(rc);
  return 0;
}
