#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;


class object
{
private:
  int val;

public:
  object():val(0){
    cout << "constructor for object (default)" << val << endl;
  }

  object(int i):val(i){
    cout << "constructor for object" << val << endl;
  }

  ~object(){
    cout << "destructor for object" << val << endl;
  }
};

class container
{
private:
  object one;
  object two;
  int data;
  const int num;
  static int static1;

public:
  container():data(0),num(0){
    cout << "constructor for container (default)" << data << endl;
  }

  container(int i,int j, int k, int l, int s):two(i),one(j),num(l){
    data = k;
    static1 = s;
    container::static1 = s;
    // num = l;
    cout << "constructor for container" << data << endl;
  }

  static int staticf1(){
    // Getstatic();
    return static1;
  }
  
  static void sstaticf2(container &c1 , int a){
    c1.static1 = a;
    // data = a;
  }

  int Getstatic(){
    return static1;
  }

  ~container(){
    cout << "destructor for container" << data << endl;
  }
};

int container::static1 = 22;

int main(int argc, char const *argv[])
{
  container obj , anObj(5,6,10,3,100);

  cout << obj.staticf1() << endl;
  cout << anObj.staticf1() << endl;
  obj.sstaticf2(anObj, 59);
  cout << anObj.Getstatic() << endl;
  cout << anObj.staticf1() << endl;
  cout << obj.staticf1() << endl;
  return 0;
}
