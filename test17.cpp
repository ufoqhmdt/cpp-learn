#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Sales_item
{

public:
  Sales_item(string &book, unsigned units, double price) : isbn(book), units_sold(units), revenue(price * units) {}
  Sales_item() : units_sold(0), revenue(0.0) {}

  friend ostream &operator<<(ostream &out, const Sales_item &s);
  friend istream &operator>>(istream &in, Sales_item &s);

private:
  string isbn;
  unsigned units_sold;
  double revenue;
};

ostream &operator<<(ostream &out, const Sales_item &s)
{
  out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
  return out;
}

istream &operator>>(istream &in, Sales_item &s)
{
  double price;
  in >> s.isbn >> s.units_sold >> price;

  if (in)
    s.revenue = s.units_sold * price;
  else
    s = Sales_item();

  return in;
}

int main(int argc, char const *argv[])
{
  // int a = 15;
  // bool it = 1, not1 = 0;
  // cout << showpoint << 123.0 << " " << noshowpoint << 123.0 << "  ";
  // cout << ios_base::showbase;
  // cout << a << "  " << uppercase << hex << a << "  " << nouppercase << hex << a << "  " << noshowbase << a << dec << a << endl;

  char ch[15], *p = "abcdefg";
  char data[100];
  ofstream myFile;
  myFile.open("myText.txt");
  myFile << p;
  myFile << "Goodbye!";
  myFile.close();
  ifstream getText("myText.txt", ios_base::in);
  // fstream afile;
  // afile.open("myText.txt", ios::out | ios::in);

  // ifstream infile;
  // infile.open("myText.txt");

  // cout << "Reading from the file" << endl;
  // infile >> data;

  // // 在屏幕上写入数据
  // cout << data << endl;

  // // 再次从文件读取数据，并显示它
  // infile >> data;
  // cout << data << endl;
  // infile.close();

  int i = 0;
  cout << strlen(p) << " strlen" << endl;
  for (; i < strlen(p) + 8; i++)
  {
    cout << i << endl;
    getText >> ch[i];
    // ch[i] = '\0';
    cout << ch << endl;
  }
  cout << ch;
  getText.close();

  // Sales_item item(string("0-201-78345-X"), 2, 25.00);

  // cout << item << endl;
  // cin >> item;
  // cout << item << endl;

  // system("pause");
  return 0;
}
