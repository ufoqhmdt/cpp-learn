#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

class base
{
public:
  virtual void print()
  {
    cout << "In Base: " << endl;
  };
};

class derived : public base
{
public:
  void print()
  {
    cout << " In derived:" << endl;
  }
};

void display(base *pb, void (base::*pf)())
{
  (pb->*pf)();
}

int main(int argc, char const *argv[])
{
  derived d;
  base *pb = &d;
  void (base::*pf)();
  pf = base::print;
  display(pb, pf);

  // base b;
  // derived d2;
  // display(&b, base::print);
  // display(&d),base::print);
  return 0;
}
