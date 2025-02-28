#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>

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
            getline(timeStream, s, ':');

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
    Record() : plate(""), time(Time()), io(""), location(0) {}
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

double calculateFee(int hourRates[24], int entryHour, int in, int out)
{
    return (hourRates[entryHour] * abs(in - out)) / 100.00;
}

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        int hourRates[24];
        vector<Record> records;
        map<string, double> prices;
        map<string, Record> tempRecs;
        vector<string> processedPlates;
        records.reserve(1000);


        for (int i = 0; i < 24; i++)
        {
            cin >> hourRates[i];
        }
        cin.ignore();

        string s;
        while (getline(cin, s) && !s.empty())
        {
            records.push_back(Record(s));
        }

        sort(records.begin(), records.end(), comparer);

        for (int i = 0; i < records.size(); i++)
        {
            string plate = records[i].getPlate();
            if (tempRecs.count(plate) && records[i].getIo() == "exit")
            {
                if (!prices.count(plate)){
                    prices[plate] = 2;
                    processedPlates.push_back(plate);
                }

                prices[plate] += 1 + calculateFee(
                                        hourRates,
                                        tempRecs[plate].getTime().getHour(),
                                        tempRecs[plate].getLocation(),
                                        records[i].getLocation());

                tempRecs.erase(plate);
                continue;
            }

            if (records[i].getIo() == "enter") tempRecs[plate] = records[i];

        }

        sort(processedPlates.begin(), processedPlates.end());

        for (int i = 0; i < processedPlates.size(); i++)
        {
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);
            cout << processedPlates[i] << " $" << prices[processedPlates[i]] << endl;
        }
        
        if (cases > 0) cout << endl;
    }

    return 0;
}