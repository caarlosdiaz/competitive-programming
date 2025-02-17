#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    while (true)
    {
        int numA, numB;

        scanf("%d %d", &numA, &numB);

        if (numA == 0 && numB == 0) break;

        int carries = 0;

        string sA = to_string(numA);     
        string sB = to_string(numB);
        int carry = 0;

        while (sA.length() > 0 && sB.length() > 0)
        {
            int dA = atoi(&sA.back());
            int dB = atoi(&sB.back());

            sA.pop_back();
            sB.pop_back();

            int res = dA + dB + carry;

            if (res >= 10) {
                carries++;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        while (sA.length() > 0) {
            int dA = atoi(&sA.back());

            sA.pop_back();

            int res = dA + carry;

            if (res >= 10) {
                carries++;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        while (sB.length() > 0) {
            int dB = atoi(&sB.back());

            sB.pop_back();

            int res = dB + carry;

            if (res >= 10) {
                carries++;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carries == 0) {
            cout << "No carry operation." << endl;
        } else if (carries == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carries << " carry operations." << endl;
        }
    }

    return 0;
}