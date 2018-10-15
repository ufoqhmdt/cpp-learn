#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
typedef double array2[12];

int result(int, int);
int max(int, int);
int max(int, int, int);
void avecount(array2 &, int);
void swap1(string *, string *);
void swap2(string &, string &);
void Display(string s1, string s2 = "s2---", string s3 = "");
void change(const string &);

int &index(int i);   // 返回引用函数
float *input(int &); // 指针函数

int returnRef[] = {2, 4, 6, 8, 10, 12};
const int k = 2;
const int k2(3l);
double *p;

struct Point
{
  int x, y;
};

int main(int argc, char const *argv[])
{
  int z(0), b(50);
  p = new double[3];
  Point a;

  for (int i = 0; i < 3; i++)
  {
    *(p + i) = i;
  }
  for (int i = 0; i < 3; i++)
  {
    cout << "----:::----" << *(p + i) << "---" << (p + i) << endl;
  }

  delete p;

  int *p1;
  int ufo = 66;
  int &ufo1 = ufo;
  int &ufo2 = ufo1;

  p1 = &ufo;

  // int  && ufo3 = ufo;  // xxxxxx
  int *&p2 = p1; // 对指针引用
  // int * & p3 = &ufo;
  // int * & p4 = ufo;
  int *p5 = &ufo1;

  cout << "*****" << p1 << " ** " << &p1 << " ** " << &ufo << " ** " << p2 << endl;

  typedef double array[8];
  array ar1 = {1, 2, 3, 4, 5, 6, 7, 8};
  array &ar2 = ar1;

  cout << "input two int";
  // cin >> a.x >> a.y;
  z = (a.x + a.y) * k2;
  z = result(z, b);
  cout << "result:::" << endl;
  cout << "((" << a.x << "+" << a.y << ")*" << k << ")+" << b << "=" << z << endl;
  cout << "result2:::" << max(1, 2, 9) << endl;
  cout << &k << endl;
  cout << "-----p:" << &p << "------" << p << endl;

  char aa1[] = "wearehere!", bb2[11];
  reverse(aa1, aa1 + 10);
  copy(aa1, aa1 + 10, ostream_iterator<char>(cout));
  cout << "===" << aa1 << setw(20) << "===" << bb2 << endl;

  string str1("now"), str2("past");
  swap1(&str1, &str2);
  cout << "---111return :str1 = " << str1 << "  str2 = " << str2 << endl;

  string str3("now"), str4("past");
  swap2(str3, str4);
  cout << "---222return :str3 = " << str3 << "  str4 = " << str4 << endl;

  array2 bb3 = {12, 34, 56, 33, 99, 100, 89, 90, 55, 89};
  array2 &aa3 = bb3;
  avecount(aa3, 12);
  cout << "平均成绩为：" << aa3[10] << " 不及格：" << int(aa3[11]) << endl;

  string str11("now"), str22("past"), str33("future");
  Display(str11);
  Display(str11, str22, str33);
  Display(str33, str11);
  Display(str22, str33);

  string str44("Can you change it?");
  change(str44);
  cout << str44 << endl;

  index(3) = 16;
  cout << index(3) << endl;

  int num;
  float *data;
  data = input(num);
  if(data){
    for(int i=0;i<num;i++){
      cout<<data[i]<<" ";
    }
    delete data;
  }

  return 0;
}

float *input(int &n)
{
  cout << "input num:";
  cin >> n;
  if (n < 0)
  {
    return NULL;
  }
  float *buf = new float[n];
  if (buf == 0)
  {
    return NULL;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> buf[i];
  }
  return buf;
}

int &index(int i)
{
  return returnRef[i];
}

void change(const string &s)
{
  string s2 = s + "no !!!";
  cout << s2 << endl;
}

void swap1(string *s1, string *s2)
{
  string temp = *s1;
  *s1 = *s2;
  *s2 = temp;
  cout << "swap :str1 = " << *s1 << "  str2 = " << *s2 << endl;
}

void swap2(string &s1, string &s2)
{
  string temp = s1;
  s1 = s2;
  s2 = temp;
  cout << "swap :str1 = " << s1 << "  str2 = " << s2 << endl;
}

void avecount(array2 &b, int n)
{
  double ave(0);
  int count(0);

  for (int j = 0; j < n - 2; j++)
  {
    ave = ave + b[j];
    if (b[j] < 60)
    {
      count++;
    }
  }
  b[n - 2] = ave / (n - 2);
  b[n - 1] = count;
}

int result(int a, int b)
{
  return a + b;
}

int max(int m1, int m2)
{
  return (m1 > m2) ? m1 : m2;
};
int max(int m1, int m2, int m3)
{
  int t = max(m1, m2);
  return max(t, m3);
};

void Display(string s1, string s2, string s3)
{
  if (s2 == "" && s3 == "")
  {
    cout << s1 << endl;
  }
  else if (s3 == "" && s2 != "")
  {
    cout << s1 << s2 << endl;
  }
  else
  {
    cout << s1 << s2 << s3 << endl;
  }
}