#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    cin.ignore();
    
    while(cases--) {
        int turtlesNumber;
        cin >> turtlesNumber;
        cin.ignore();
        
        vector<string> originalNames(turtlesNumber);
        vector<string> expectedNames(turtlesNumber);
        unordered_map<string, int> positionMap;
        
        for (int i = 0; i < turtlesNumber; i++) {
            getline(cin, originalNames[i]);
            positionMap[originalNames[i]] = i;
        }
        
        for (int i = 0; i < turtlesNumber; i++) {
            getline(cin, expectedNames[i]);
        }
        
        vector<int> originalPosition(turtlesNumber);
        for (int i = 0; i < turtlesNumber; i++) {
            originalPosition[i] = positionMap[expectedNames[i]];
        }
        
        int j = turtlesNumber - 1;
        while(j > 0 && originalPosition[j - 1] < originalPosition[j])
            j--;
        
        for (int i = j - 1; i >= 0; i--) {
            cout << expectedNames[i] << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}
