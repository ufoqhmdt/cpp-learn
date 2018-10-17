#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

template <class T>
class TAnyTemp{
  T x,y;
  public:
  TAnyTemp(T X, T Y):x(X),y(Y){

  }
  T getx(){return x;}
  T gety(){return y;}
};


class Point{
  int x,y;
  public:
  Point(int a,int b){
    x=a;
    y=b;
  }
  void display(){
    cout<<x<<","<<y<<endl;
  }
};

template <typename T>
class PointT{
  T x,y;
  public:
  PointT(T a,T b){
    x=a;
    y=b;
  }
  void display(){
    cout<<x<<","<<y<<endl;
  }
};

template <typename T>
class Line:public Point{
  T x2,y2;
  public:
   Line(int a,int b, T c, T d):Point(a,b){
     x2=c;
     y2=d;
   }
   void display(){
     Point::display();
     cout<<x2<<","<<y2<<endl;
   }
};


template <typename T>
class LineT:public PointT<T>{
  T x2,y2;
  public:
   LineT(T a,T b, T c, T d):PointT<T>(a,b){
     x2=c;
     y2=d;
   }
   void display(){
     PointT<T>::display();
     cout<<x2<<","<<y2<<endl;
   }
};

template <class T, int size =4>
class Max4{
    T a,b,c,d;
    T m[size];
    T Max2(T a, T b){
      return (a>b)?a:b;
    }
  public:
    // Max4(T,T,T,T);
    T Max2(void);
    // {
    //   return Max2(Max2(a,b),Max2(c,d));
    // };
    Max4(T a,T b, T c, T d){
      m[0]=a;
      m[1]=b;
      m[2]=c;
      m[3]=d;
      a=a;
      b=b;
      c=c;
      d=d;
    }
    T S(){
      return m[0] +m[1]+m[2]+m[3];
    }
};

// template <class T>
// Max4<T>::Max4(T x1,T x2,T x3, T x4):a(x1),b(x2),c(x3),d(x4){

// }

template <class T, int size>
T Max4<T,size>::Max2(void){
  return Max2(Max2(a,b),Max2(c,d));
}


int main(int argc, char const *argv[])
{
  TAnyTemp <int> iObj1(333,444);
  TAnyTemp <double> iObj2(3.14,6.66);
  Max4<char> C('W','w','a','A');
  Max4<int> A(2,3,-100,200);
  Max4<double> B(1.25,3.5,-9.8,3.1);
  cout<< C.Max2() << ":::" << A.Max2() << ":::" << B.Max2() << endl; 

  Max4<int,4> num1(-23,5,8,-2);
  cout<<":::"<<num1.S()<<endl;

  Point a(3,9);
  a.display();
  Line <int> ab(4,5,6,7);
  ab.display();
  Line <double> ad(4,5,3.3,4.4);
  ad.display();


  PointT <double> at(3.2,9.9);
  at.display();
  LineT <int> abt(4,5,6,7);
  abt.display();
  LineT <double> adt(4.3,5.4,3.3,4.4);
  adt.display();

  vector <int> Bv(20);
  vector <int> Cv(19);
  vector <char> Dv(19,'a');

  Bv = Cv;

  cout << Bv.size() << "," << Cv.size() << "," << Dv.size() << endl;
  
  return 0;
}
