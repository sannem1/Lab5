#include <stdio.h>

/**
 printScoreCombination prints the number of touchdowns with 2-point conversions,
 touchdowns with field goals, touchdowns, 3-point field goals, and safeties.
 td2 The number of touchdowns with a 2-point conversion.
 tdfg The parameter "tdfg" represents the number of touchdowns followed by a field goal.
 td The parameter "td" represents the number of touchdowns scored.
 fg The parameter "fg" represents the number of field goals scored.
 safety The number of safeties scored by a team.
 */
void printScoreCombination(int td2, int tdfg, int td, int fg, int safety) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safety);
}

/**
  calculates all possible combinations of touchdowns, two-point
 conversions, field goals, and safeties that add up to a given total score.
  parameter: totalScore The total score is the target score that we want to find combinations for.
 */
void findScoreCombinations(int totalScore) {
    for(int td2Count = 0; td2Count <= totalScore / 8; td2Count++) {
        for(int tdfgCount = 0; tdfgCount <= (totalScore - td2Count * 8) / 7; tdfgCount++) {
            for(int tdCount = 0; tdCount <= (totalScore - td2Count * 8 - tdfgCount * 7) / 6; tdCount++) {
                for(int fgCount = 0; fgCount <= (totalScore - td2Count * 8 - tdfgCount * 7 - tdCount * 6) / 3; fgCount++) {
                    int remainingScore = totalScore - td2Count * 8 - tdfgCount * 7 - tdCount * 6 - fgCount * 3;
                    int safetyCount = remainingScore / 2;

                    if (remainingScore % 2 == 0) {
                        printScoreCombination(td2Count, tdfgCount, tdCount, fgCount, safetyCount);
                    }
                }
            }
        }
    }
}

/*
  main function prompts the user to enter an NFL score until they enter 0 or 1, and if the score
 is greater than 1, it calls the findScoreCombinations function.
 */
int main() {
    int score;
    do {
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score > 1) {
            findScoreCombinations(score);
        }
    } while (score > 1);
    return 0;
}
