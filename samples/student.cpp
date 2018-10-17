#include "student.h"

void student::display(vector<student> &c)
{
    cout << "number:" << setw(20) << " score:" << endl;
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i].GetNum() << setw(12) << c[i].GetScore() << endl;
    }
}

void student::set(vector<student> &c)
{
    student a;
    string s;
    double b;
    while (1)
    {
        cout << "number:";
        cin >> s;
        if (s == "0")
        {
            ofstream wst("stud.txt");
            if (!wst)
            {
                cout << "ops no file!" << endl;
                return;
            }
            cout << c.size() << endl;
            for (int i = 0; i < c.size(); i++)
            {
                cout << c[i].number << endl;
                wst << c[i].number << " " << c[i].score << " ";
            }
            wst.close();
            cout << "total write:" << c.size() << "student info \n";
            return;
        }
        a.SetNum(s);
        cout << "score:";
        cin >> b;
        a.SetScore(b);
        c.push_back(a);
    }
}

void student::read()
{
    string number;
    double score;
    ifstream rst("stud.txt");
    if (!rst)
    {
        cout << "ops no rst" << endl;
        return;
    }
    cout << "number:" << setw(20) << " score:" << endl;
    while (1)
    {
        rst >> number >> score;
        if (rst.eof())
        {
            rst.close();
            return;
        }
        cout << number << setw(12) << score << endl;
    }
}

int main()
{
    vector<student> st;
    student stud;
    stud.set(st);
    cout << "显示向量数组信息如下：\n";
    stud.display(st);
    cout << "存入文件内的信息如下：" << endl;
    stud.read();
    return 0;
}