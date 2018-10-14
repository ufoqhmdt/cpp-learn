#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
int result(int, int);
int max(int, int);
int max(int, int, int);
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
    reverse(aa1,aa1+10);
    copy(aa1, aa1 + 10, ostream_iterator<char>(cout));
    cout << "===" << aa1<< setw(20) << "===" << bb2 << endl;
    return 0;
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