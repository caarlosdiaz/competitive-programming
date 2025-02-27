#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Time
{
private:
    int day;
    int hour;
    int min;

public:
    Time() : day(0), hour(0), min(0) {}
    Time(string timeString)
    {
        istringstream timeStream(timeString);
        string s;

        for (int i = 0; i < 4; i++)
        {
            if (!getline(timeStream, s, ':'))
            {
                throw invalid_argument("Formato de tiempo incorrecto: " + timeString);
            }

            if (i == 0)
                continue;
            if (i == 1)
                day = stoi(s);
            if (i == 2)
                hour = stoi(s);
            if (i == 3)
                min = stoi(s);
        }
    }

    int getDay()
    {
        return day;
    }

    int getHour()
    {
        return hour;
    }

    int getMin()
    {
        return min;
    }

    bool isBiggerThan(Time t)
    {
        if (day > t.getDay())
            return true;
        if (day < t.getDay())
            return false;
        if (hour > t.getHour())
            return true;
        if (hour < t.getHour())
            return false;
        if (min > t.getMin())
            return true;
        if (min < t.getMin())
            return false;

        return false;
    }
};

class Record
{
private:
    string plate;
    Time time;
    string io;
    int location;

public:
    Record(string line)
    {
        istringstream lineStream(line);
        string s;

        lineStream >> plate;
        lineStream >> s;
        time = Time(s);

        lineStream >> io;

        lineStream >> s;
        location = stoi(s);
    }

    string getPlate()
    {
        return plate;
    }

    Time getTime()
    {
        return time;
    }

    string getIo()
    {
        return io;
    }

    int getLocation()
    {
        return location;
    }

    bool isBiggerThan(Record r)
    {
        return time.isBiggerThan(r.getTime());
    }
};

// True if r1 < r2
bool comparer(Record r1, Record r2)
{
    return r2.isBiggerThan(r1);
}

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        int hourRates[24];
        vector<Record> records;
        records.reserve(1000);

        for (int i = 0; i < 24; i++)
        {
            cin >> hourRates[i];
        }
        cin.ignore();

        string s;
        while (getline(cin, s) && s != "\n")
        {
            records.push_back(Record(s));
        }

        sort(records.begin(), records.end(), comparer);

        for (int i = 0; i < records.size(); i++)
        {
            cout << records[i].getPlate() << " " << records[i].getTime().getDay() << ":" << records[i].getTime().getHour() << ":" << records[i].getTime().getMin() << endl;
        }
    }

    return 0;
}