import java.util.*;

public class Main {
    static int candidatesNumber;
    static String[] candidatesNames;
    static int[][] ballots;
    static int[] votes;
    static boolean[] candidatesMask;

    static void countVotes(int voters) {
        Arrays.fill(votes, 0);
        for (int i = 0; i < voters; i++) {
            for (int j = 0; j < candidatesNumber; j++) {
                int candidate = ballots[i][j];
                if (candidatesMask[candidate]) {
                    votes[candidate]++;
                    break;
                }
            }
        }
    }

    static int getMinVotes() {
        int minVotes = Integer.MAX_VALUE;
        for (int i = 0; i < candidatesNumber; i++) {
            if (candidatesMask[i] && votes[i] < minVotes) {
                minVotes = votes[i];
            }
        }
        return minVotes;
    }

    static int[] getMaxVotes() {
        int maxVotes = 0;
        int candidate = -1;
        for (int i = 0; i < candidatesNumber; i++) {
            if (candidatesMask[i] && votes[i] > maxVotes) {
                maxVotes = votes[i];
                candidate = i;
            }
        }
        return new int[]{maxVotes, candidate};
    }

    static boolean isTie(int minVotes) {
        for (int i = 0; i < candidatesNumber; i++) {
            if (candidatesMask[i] && votes[i] != minVotes) {
                return false;
            }
        }
        return true;
    }

    static void eliminateCandidates(int minVotes) {
        for (int i = 0; i < candidatesNumber; i++) {
            if (candidatesMask[i] && votes[i] == minVotes) {
                candidatesMask[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = Integer.parseInt(scanner.nextLine().trim());
        scanner.nextLine();
        
        boolean first = true;

        while (cases-- > 0) {
            if (!first) System.out.println();
            first = false;

            candidatesNumber = Integer.parseInt(scanner.nextLine().trim());
            candidatesNames = new String[candidatesNumber];
            candidatesMask = new boolean[candidatesNumber];
            Arrays.fill(candidatesMask, true);
            votes = new int[candidatesNumber];
            ballots = new int[1000][candidatesNumber];

            for (int i = 0; i < candidatesNumber; i++) {
                candidatesNames[i] = scanner.nextLine().trim();
            }

            int voters = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine().trim();
                if (line.isEmpty()) break;
                String[] tokens = line.split(" ");
                for (int i = 0; i < candidatesNumber; i++) {
                    ballots[voters][i] = Integer.parseInt(tokens[i]) - 1;
                }
                voters++;
            }

            while (true) {
                countVotes(voters);
                int[] maxVotesResult = getMaxVotes();
                int maxVotes = maxVotesResult[0];
                int maxCandidate = maxVotesResult[1];

                if (maxVotes > voters / 2) {
                    System.out.println(candidatesNames[maxCandidate]);
                    break;
                }

                int minVotes = getMinVotes();
                if (isTie(minVotes)) {
                    for (int i = 0; i < candidatesNumber; i++) {
                        if (candidatesMask[i]) {
                            System.out.println(candidatesNames[i]);
                        }
                    }
                    break;
                }

                eliminateCandidates(minVotes);
            }
        }
        scanner.close();
    }
}
