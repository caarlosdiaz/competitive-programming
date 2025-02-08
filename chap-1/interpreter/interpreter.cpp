#include <iostream>
#include <string>

using namespace std;

static const int registerNumber = 10;
static const int wordsNumber = 1000;
int registers[registerNumber];
int words[wordsNumber][3];

int readWords() {

}

int main() {
    int cases;
    cin >> cases;
    cin.ignore();

    for (int i = 0; i < cases; i++)
    {
        string line;        

        getline(cin, line); // Read blank line

        memset(words, 0, sizeof(words));
        memset(registers, 0, sizeof(registers));
        
        int wordCounter = 0;
        
        while (getline(cin, line))
        {
            for (int j = 0; j <  3; j++) {
                char c = line[j];
                words[wordCounter][j] = atoi(&c);
            }

            wordCounter++;
        }
    }
    
    return 0;
}