#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
  double a[]={1.1,2.2,3.3,4.4};
  cout<< &a[0] << "\n" << &a[1]  << "\n" << &a[2]  << "\n" << &a[3] << endl;
  vector <double> va(a,a+4),vb(4);
  typedef vector<double>::iterator iterator;
  iterator first = va.begin();
  for(;first<va.end();first++)
  {
    cout << *first << "  " << &first <<endl;
  }
  cout << " ------ 1" << endl;
  for(--first; first>va.begin()-1;first--){
    cout<< *first << " " << &first << endl;
  } 
  cout << " ------ 2" << endl;


  std::copy(va.begin(),va.end(),ostream_iterator<double>(cout," "));
  cout<<endl;

  typedef vector<double>::reverse_iterator reverse_iterator;
  reverse_iterator last = va.rbegin();

  for(;last<va.rend();last++){
    cout<<*last<< "  " << &(*last) << "  " << &(*va.rend()) <<" " << endl;
  }

  cout << " ------ 3" << endl;

  for(--last;last>va.rbegin()-1;last--){
    cout<<*last<< "  ";
  }

  cout << " ------ 4" << endl;

  copy(va.rbegin(),va.rend(),ostream_iterator<double>(cout," "));

  cout << "====" << va.max_size() << "," << sizeof(va) << endl;



  char st[11] = "abcdefghij";
  vector <char> aufo(st,st+10);
  for(int j=0;j<10;j++){
    cout<<aufo[j]<< "  ";
  }
  cout << endl << aufo.capacity() <<"," << aufo.size()<< endl;

  aufo.pop_back();
  aufo.push_back('W');
  aufo.push_back('P');
  for(int j=0;j<aufo.size();j++){
    cout << aufo[j] << "  ";
  }

  cout << endl << aufo.capacity() <<"," << aufo.size()<< endl;

  // aufo.clear();
  // cout << aufo.empty() << endl;

  vector <char>::iterator p=aufo.begin();
  vector <char>::reverse_iterator ps;
  for(p=aufo.begin();p!=aufo.end();++p){
    cout<<&*p<<"  --  ";
  }
  cout<<endl;
  return 0;
}
