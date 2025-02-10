#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int pancakesMaxNumber = 31;
int pancakes[pancakesMaxNumber];
int pancakesNumber;

int readPancakes(const string &line)
{
    cout << line << endl;

    pancakesNumber = 0;
    istringstream stream(line);
    int num;

    while (stream >> num)
    {
        pancakesNumber++;
        pancakes[pancakesNumber] = num;
    }

    return 0;
}

int swapPancakes(const int &l, const int &r)
{
    int temp = pancakes[l];
    pancakes[l] = pancakes[r];
    pancakes[r] = temp;

    return 0;
}

int flip(const int &initPos, const int &maxPos, const int &printablePos)
{
    int lPointer = 1;
    int rPointer;

    if (maxPos == 1)
    {
        rPointer = initPos;
    }
    else
    {
        rPointer = maxPos;
    }

    cout << printablePos << " ";

    while (lPointer < rPointer)
    {
        swapPancakes(lPointer, rPointer);

        lPointer++;
        rPointer--;
    }

    return 0;
}

int flipPancakes()
{
    int i = 1;
    while (i <= pancakesNumber)
    {
        int revPos = pancakesNumber - i + 1;
        int max = pancakes[revPos];
        int maxPos = revPos;

        for (int j = revPos; j > 0; j--)
        {
            if (pancakes[j] > max)
            {
                max = pancakes[j];
                maxPos = j;
            }
        }

        if (pancakes[revPos] == max) 
        {
            i++;
            continue;
        }

        flip(revPos, maxPos, i);
    }
    
    cout << "0" << endl;
    
    return 0;
}

int main(int argc, char *argv[])
{
    string line;
    int first = 1;

    while (getline(cin, line))
    {
        readPancakes(line);
        flipPancakes();     
    }
}