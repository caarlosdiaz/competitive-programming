#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string addBigNumbers(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }
    
    return result;
}

int main(int argc, char *argv[])
{
    vector<string> fibs = {"1", "2"};
    int i = 2;

    while (fibs.back().length() <= 100)
    {
        fibs.push_back(addBigNumbers(fibs[i - 1], fibs[i - 2]));
        i++;
    }

    cout << "{" << endl;
    
    for (int i = 0; i < fibs.size(); i++)
    {
        cout << "\"" << fibs[i] << "\"," << endl;
    }

    cout << "}";
    

    return 0;
}