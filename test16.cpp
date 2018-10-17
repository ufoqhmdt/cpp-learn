#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
  int a = 15;
  bool it = 1, not1 = 0;
  cout << showpoint << 123.0 << " " << noshowpoint << 123.0 << "  ";
  cout << ios_base::showbase;
  cout << a << "  " << uppercase << hex << a << "  " << nouppercase << hex << a << "  " << noshowbase << a << dec << a << endl;
  return 0;
}
