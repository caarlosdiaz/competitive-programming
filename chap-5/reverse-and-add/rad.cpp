#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(long long &num) {
    string numS = to_string(num);
    int len = numS.length();

    int lPointer = 0;
    int rPointer = len - 1;

    for (int i = 0; i < len / 2; i++)
    {
        char lC = numS[lPointer];
        char rC = numS[rPointer];

        if (lC != rC) return false;

        lPointer++;
        rPointer--;
    }
    
    return true;
}

long long reverseAdd(long long &num) {
    string numS = to_string(num);
    reverse(numS.begin(), numS.end());
    
    long long revNum = stoll(numS);

    return num + revNum;
}

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        int counter = 0;
        long long num;
        cin >> num;

        while(!isPalindrome(num)) {
            num = reverseAdd(num);
            counter++;
        }

        cout << counter << " " << num << endl;
    }

    return 0;
}