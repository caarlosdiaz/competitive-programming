#include <stdio.h>
#include <string.h>

static const int N = 20 + 1;

void calculateBallots() {
    int candidatesNumber, i;
    char candidatesNames[N][81];
    int ballots[1000][N];


    scanf("%d", &candidatesNumber);

    for(i = 1; i < N; i++) {
        fgets(candidatesNames[i], sizeof(candidatesNames[i]), stdin);
        int endLinePosition = strcspn(candidatesNames[i], "\n");
        candidatesNames[i][endLinePosition] = 0;
        
    }


}

int main(int argc, char *argv[]) {
    int cases, i;
    scanf("%d", &cases);
    scanf(" ");

    for(i = 0; i < cases; i++) {
        calculateBallots();
    }

    return 0;
}