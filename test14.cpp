#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

class str
{
private:
  char *st;

public:
  str(char *S);
  str(str &s);
  str &operator=(str &a);
  str &operator=(char *s);
  void print()
  {
    cout << st << endl;
  }
  ~str()
  {
    delete st;
  }
};

str::str(char *s)
{
  cout << "---1:" << s << endl;
  st = new char[strlen(s) + 1];
  strcpy(st, s);
}

str::str(str &a)
{
  cout << "---2:" << &a << ":" << a.st << endl;
  st = new char[strlen(a.st) + 1];
  strcpy(st, a.st);
}

str &str::operator=(str &a)
{
  cout << "---3:" << &a << endl;
  if (this == &a)
  {
    return *this;
  }
  delete st;
  st = new char[strlen(a.st) + 1];
  strcpy(st, a.st);
  return *this;
}

str &str::operator=(char *s)
{
  cout << "---4:" << s << endl;
  delete st;
  st = new char[strlen(s) + 1];
  strcpy(st, s);
  return *this;
}

int main(int argc, char const *argv[])
{
  str s1("We"), s2("They"), s3(s1);
  s1.print();
  s2.print();
  s3.print();
  s2 = s1 = s3;
  // s2.operator=((s1).operator=(s3));
  s3 = "Go home";
  s3 = s3;
  // s3.operator=(s3);
  s1.print();
  s2.print();
  s3.print();
}
