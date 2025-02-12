#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;
    cin.ignore();

    while (cases--)
    {
        string originalNames[200];
        int originalPosition[200]; // being i the target pos, originalPosition[i] is the original pos

        int turtlesNumber;
        cin >> turtlesNumber;
        cin.ignore();

        string buffer;

        for (int i = 0; i < turtlesNumber; i++)
        {
            getline(cin, buffer);
            originalNames[i] = buffer;
        }
        
        for (int i = 0; i < turtlesNumber; i++)
        {
            getline(cin, buffer);
            for (int j = 0; j < turtlesNumber; j++)
            {
                if (originalNames[j] == buffer)
                {
                    originalPosition[i] = j;
                    break;
                }
            }
        }

        int i;
        
        for (i = turtlesNumber - 1; i >= 0; i--)
        {
            if (i == 0 || originalPosition[i] < originalPosition[i - 1])
            {
                i--;
                break;
            }
        }

        while (i >= 0)
        {
            int ogPos = originalPosition[i];
            cout << originalNames[ogPos] << endl;
            i--;
        }

        if (cases > 0) cout << endl;
    }
}