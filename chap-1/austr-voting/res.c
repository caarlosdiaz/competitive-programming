#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int N = 20 + 1;

void printTie(int candidatesMask[], char candidatesNames[][100])
{
    int i, first = 1;
    for (i = 1; i < N; i++)
    {
        if (candidatesMask[i])
        {
            if (!first) {printf("\n");}
                
            printf("%s", candidatesNames[i]);
            first = 0;
        }
    }
}

/* Return the first non-eliminated candidate from the ballot */
int getVoteFromBallot(int ballot[], int mask[], int candidatesNumber)
{
    int i, vote;
    for (i = 0; i < candidatesNumber; i++)
    {
        vote = ballot[i];
        if (mask[vote])
        {
            return vote;
        }
    }

    return 0;
}

void calculateBallots()
{
    int candidatesNumber, i;
    char candidatesNames[N][100];
    int votes[N];
    int ballots[1000][N];
    int candidatesMask[N]; /*1 is true and 0 is false*/
    memset(candidatesMask, 0, sizeof(candidatesMask));

    scanf("%d", &candidatesNumber);
    getchar();

    for (i = 1; i <= candidatesNumber; i++)
    {
        fgets(candidatesNames[i], sizeof(candidatesNames[i]), stdin);
        int endLinePosition = strcspn(candidatesNames[i], "\n");
        candidatesNames[i][endLinePosition] = 0;

        candidatesMask[i] = 1;
    }

    char line[100];
    int l, j;
    l = 0;
    while (fgets(line, sizeof(line), stdin) && strlen(line) > 1)
    {
        char *c = strtok(line, " ");
        for (j = 0; j < candidatesNumber; j++)
        {
            ballots[l][j] = atoi(c);
            c = strtok(NULL, " ");
        }
        l++;
    }

    for (i = 0; i < candidatesNumber; i++)
    {
        memset(votes, 0, sizeof(votes));
        int maxVotesCandidate;
        int maxVotes = 0;
        int minVotes = N;
        for (j = 0; j < l; j++)
        {
            int vote = getVoteFromBallot(ballots[j], candidatesMask, candidatesNumber);

            votes[vote] += 1;
            if (votes[vote] > maxVotes)
            {
                maxVotes = votes[vote];
                maxVotesCandidate = vote;
            }
        }

        for (j=1; j <= candidatesNumber; j++)
        {
            if (candidatesMask[j] && votes[j] < minVotes)
            {
                minVotes = votes[j];
            }
        }

        if (maxVotes > l / 2)
        {
            printf("%s", candidatesNames[maxVotesCandidate]);
            return;
        }

        /*Tie case*/
        if (maxVotes == minVotes)
        {
            printTie(candidatesMask, candidatesNames);
            return;
        }

        for (j=1; j <= candidatesNumber; j++)
        {
            if (candidatesMask[j] && votes[j] == minVotes)
            {
                candidatesMask[j] = 0;
            }
        }
        
        maxVotes = 0;
        minVotes = N;
    }
}

int main(int argc, char *argv[])
{
    int cases, i;
    scanf("%d", &cases);
    scanf(" ");

    for (i = 0; i < cases; i++)
    {
        calculateBallots();
            printf("\n");
            if (i != cases - 1)
                printf("\n");
    }

    return 0;
}