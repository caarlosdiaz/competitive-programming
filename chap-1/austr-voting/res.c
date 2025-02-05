#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int N = 20 + 1;

void calculateBallots() {
    int candidatesNumber, i;
    char candidatesNames[N][81];
    int ballots[1000][N];
    int candidatesMask[N];/*1 is true and 0 is false*/

    scanf("%d", &candidatesNumber);
    getchar();

    for(i = 1; i <= candidatesNumber; i++) {
        fgets(candidatesNames[i], sizeof(candidatesNames[i]), stdin);
        int endLinePosition = strcspn(candidatesNames[i], "\n");
        candidatesNames[i][endLinePosition] = 0;

        candidatesMask[i] = 1;
    }

    char line[100];
    int l, j;
    l = 0;
    while(fgets(line, sizeof(line), stdin) && line[0] != '\n') {
        char *c = strtok(line, " ");
        for(j = 0;j < candidatesNumber; j++) {
            ballots[l][j] = atoi(c);
            c = strtok(NULL, " ");
        }
        l++;
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