#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

string input(const int);
template <class T>
T maxufo(T m1, T m2)
{
  return (m1 > m2) ? m1 : m2;
}

template <typename T>
T max2ufo(T m1, T m2)
{
  return (m1 > m2) ? m1 : m2;
}

template <typename T>
T min2ufo(T m1, T m2)
{
  return (m1 < m2) ? m1 : m2;
}


int main(int argc, char const *argv[])
{
  // int n;
  // cout << "input n =";
  // cin >> n;
  // string str = input(n);
  // cout << str << endl;

  cout << maxufo(2, 5) << "\t" << maxufo(2.0, 5.) << "\t" << maxufo('w', 'a') << "\t" << maxufo("ABC", "ABD") << endl;
  cout << max2ufo <double> (2, 5) << "\t" << max2ufo<int>(2, 5.0) << "\t" << max2ufo<char>('a', 121.0) << "\t" << max2ufo('a', (char)121.0) << endl;
  return 0;
}

string input(const int n)
{
  string s1, s2;
  for (int i = 0; i < n; i++)
  {
    cin >> s1;
    s2 = s2 + s1 + " ";
  }
  return s2;
}

// int maxufo(int m1, int m2)
// {
//   return (m1 > m2) ? m1 : m2;
// }

// double maxufo(double m1, double m2)
// {
//   return (m1 > m2) ? m1 : m2;
// }

// char maxufo(char m1, char m2)
// {
//   return (m1 > m2) ? m1 : m2;
// }

// string maxufo(string m1, string m2)
// {
//   return (m1 > m2) ? m1 : m2;
// }