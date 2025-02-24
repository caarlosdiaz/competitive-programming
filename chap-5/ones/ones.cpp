#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int num;

    while (cin >> num) {
        int counter = 1;
        int computedMod = 1 % num;

        while (computedMod != 0) {
            computedMod = (computedMod * 10 + 1) % num;
            counter++;
        }

        cout << counter << endl;
        
        if (cin.eof()) break;
    }

    return 0;
}