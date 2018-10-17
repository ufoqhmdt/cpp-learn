#if !defined(STUDENT_H)
#define STUDENT_H
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class student
{
    string number;
    double score;

  public:
    void SetNum(string s)
    {
        number = s;
    }
    void SetScore(double s)
    {
        score = s;
    }
    string GetNum()
    {
        return number;
    }
    double GetScore()
    {
        return score;
    }
    void set(vector<student> &);
    void display(vector<student> &);
    void read();
};

#endif