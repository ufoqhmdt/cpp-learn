#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;

// 被例子主要是看去掉所有的virtual运行和有virtual运行的差别，fune的运行结果不一样。

class A{
  public:
    A(){
      cout<< "A constructing:" << endl;
    }
    virtual void func(){
      cout<< "func: in A" << endl;
    }
    ~A(){
      cout<< "A destructing:" << endl;
    }

    virtual void fund(){
      cout<<"fund: in A" <<endl;
    }
};

class B:public A{
  public:
    B(){
      cout<< "B constructing:" << endl;
      func();
    }
    virtual void fune(){
      cout<< "fune:" <<endl;
      func();
    }
    ~B(){
      cout<< "B destructing:" << endl;
      fund();
    }
};

class C:public B{
  public:
    C(){
      cout<< "C constructing:" << endl;
      func();
    }
    virtual void func(){
      cout<< "func: in C" << endl;
    }
    ~C(){
      cout<< "C destructing:" << endl;
      fund();
    }
     virtual void fund(){
      cout<< "fund: in C" << endl;
    }
};

int main(int argc, char const *argv[])
{
  C c;
  c.fune();
  return 0;
}
