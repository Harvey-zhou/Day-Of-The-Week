#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

class Date
{
public:
    Date(string str);
    Date();
    bool SetDate(string str);
    bool SetDate(int year, int month, int day);
    void PrintDate();
    void InitWeek();
    void InitMonth();
    void InitYear();
    string ReturnWeekDay();

private:
    int year;
    int month;
    int day;
    map<int, string> week;
    map<int, int> monthDirectory;
    map<int, int> yearDirectory;
};

int main()
{
    int year, month, day;
    cout << "�������꣺";
    cin >> year;
    cout << "�������£�";
    cin >> month;
    cout << "�������գ�";
    cin >> day;
    Date date;
    if (date.SetDate(year, month, day))
        cout << year << "-" << month << "-" << day
        << "��" << date.ReturnWeekDay() << endl
        << endl;
    else
        cout << "����������������������!" << endl
        << endl;
    return 0;
}

//1900.1.1 ������
string Date::ReturnWeekDay()
{
    int sum = 0;
    for (int i = 1900; i < year; i++)
    {
        map<int, int>::iterator iter;
        iter = yearDirectory.find(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
        sum += iter->second;
    }
    for (int i = 1; i < month; i++)
    {
        map<int, int>::iterator iter;
        iter = monthDirectory.find(i);
        sum += iter->second;
        if (i == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) //��������¼�һ��
            sum += 1;
    }
    for (int i = 1; i < day; i++)
        sum += 1;
    map<int, string>::iterator iter;
    iter = week.find(sum % 7);
    return iter->second;
}

Date::Date()
{
    InitWeek();
    InitYear();
    InitMonth();
}

bool Date::SetDate(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    if (year<1900)
        return false;
    if (month < 1 || month > 12)
        return false;
    map<int, int>::iterator iter;
    iter = monthDirectory.find(month);

    return day >= 1 && day <= iter->second;
}

void Date::InitWeek()
{
    week.insert(pair<int, string>(0, "����һ"));
    week.insert(pair<int, string>(1, "���ڶ�"));
    week.insert(pair<int, string>(2, "������"));
    week.insert(pair<int, string>(3, "������"));
    week.insert(pair<int, string>(4, "������"));
    week.insert(pair<int, string>(5, "������"));
    week.insert(pair<int, string>(6, "������"));
}

void Date::InitYear()
{
    yearDirectory.insert(pair<int, int>(0, 365));
    yearDirectory.insert(pair<int, int>(1, 366));
}

void Date::InitMonth()
{
    monthDirectory.insert(pair<int, int>(1, 31));
    monthDirectory.insert(pair<int, int>(2, 28));
    monthDirectory.insert(pair<int, int>(3, 31));
    monthDirectory.insert(pair<int, int>(4, 30));
    monthDirectory.insert(pair<int, int>(5, 31));
    monthDirectory.insert(pair<int, int>(6, 30));
    monthDirectory.insert(pair<int, int>(7, 31));
    monthDirectory.insert(pair<int, int>(8, 31));
    monthDirectory.insert(pair<int, int>(9, 30));
    monthDirectory.insert(pair<int, int>(10, 31));
    monthDirectory.insert(pair<int, int>(11, 30));
    monthDirectory.insert(pair<int, int>(12, 31));
}

