#include <iostream>
#include <cstring>
#include <string>

using namespace std;

static const int registerNumber = 10;
static const int wordsNumber = 1000;
int registers[registerNumber];
int words[wordsNumber][3];

int calculateMod(int x)
{
    return x % wordsNumber;
}

int setRam(int address, string value)
{
    for (int j = 0; j < 3; j++)
    {
        char c = value[j];
        words[address][j] = c - '0';
    }

    return 0;
}

int main()
{
    int cases;
    string line;

    cin >> cases;
    cin.ignore();
    getline(cin, line); // Read blank line

    for (int i = 0; i < cases; i++)
    {
        fill(&words[0][0], &words[0][0] + wordsNumber * 3, 0);
        fill(registers, registers + registerNumber, 0);

        int wordCounter = 0;

        while (getline(cin, line))
        {
            if (line.empty())
            {
                break;
            }
            setRam(wordCounter, line);

            wordCounter++;
        }

        int instructionCounter = 0;
        int address = 0;
        while (address < wordsNumber)
        {
            int instruction = words[address][0];
            int firstArg = words[address][1];
            int secondArg = words[address][2];

            instructionCounter++;

            switch (instruction)
            {
            case 1:
            {
                address = wordsNumber;
                break;
            }

            case 2:
            {
                registers[firstArg] = secondArg;
                break;
            }

            case 3:
            {
                int res = registers[firstArg] + secondArg;
                registers[firstArg] = calculateMod(res);
                break;
            }

            case 4:
            {
                int res = registers[firstArg] * secondArg;
                registers[firstArg] = calculateMod(res);
                break;
            }

            case 5:
            {
                registers[firstArg] = registers[secondArg];
                break;
            }

            case 6:
            {
                int res = registers[firstArg] + registers[secondArg];
                registers[firstArg] = calculateMod(res);
                break;
            }

            case 7:
            {
                int res = registers[firstArg] * registers[secondArg];
                registers[firstArg] = calculateMod(res);
                break;
            }

            case 8:
            {
                int ramDir = registers[secondArg];
                string ramVal =
                    to_string(words[ramDir][0]) + to_string(words[ramDir][1]) + to_string(words[ramDir][2]);

                registers[firstArg] = stoi(ramVal);
                break;
            }

            case 9:
            {
                int ramDir = registers[secondArg];
                string ramVal = to_string(registers[firstArg]);
                while(ramVal.size() < 3)
                {
                    ramVal = "0" + ramVal;
                }
                setRam(ramDir, ramVal);
                break;
            }

            case 0:
            {
                if (registers[secondArg] != 0)
                {
                    address = registers[firstArg];
                    continue;
                }
                break;
            }

            default:
                break;
            }

            address++;
        }

        if (i != 0)
        {
            // Set blank line.
            cout << endl;
        }

        cout << instructionCounter << endl;
    }

    return 0;
}