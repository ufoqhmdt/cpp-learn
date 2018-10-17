#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;


class Base
{
private:
  int x;
  const int a;
  static const int b;
  const int &r;

public:
  Base(int,int);
  void Show(){
    x = 88;
    cout << "Show:" <<x<<","<<a<<","<<b<<","<<r<<endl;
  }
  void Show() const{
    // x = 88;
    // Display();
    cout << "Show const:" <<x<<","<<a<<","<<b<<","<<r<<endl;
  }
  void Display(const double&r) const{
    cout<<r << "," << Base::r<<endl;
  }

  int getB(){
    return x;
  }

  int getB() const{
    return x;
  }
};

const int Base::b = 125;
Base::Base(int i,int j):x(i),a(j),r(x){
}

int main(int argc, char const *argv[])
{
  Base a1(104,118),a2(119,140);
  a1.Show();
  a2.Show();
  a2.Display(3.14);
  int bbb1 = a2.getB();
  bbb1 = 100;
  cout << bbb1 << "bbb1" << endl;

  Base const b1(22,33);
  b1.Show();
  int bbb2 = b1.getB();
  bbb2 = 100;
  cout << bbb2 << "bbb2" << endl;
  const Base b2(22,33);
  b2.Show();
  return 0;
}
