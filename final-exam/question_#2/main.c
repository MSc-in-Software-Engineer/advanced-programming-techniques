//
// Created by Yusuf Dede on 2.06.2022.
//
#include <stdio.h>
#include <stdlib.h>

/* BASE DEFINITIONS - BEGIN */

#define ROW_COUNT 5 // student count
#define COLUMN_COUNT 2 // physics & math column
#define PHYSICS 1
#define MATH 2

/* BASE DEFINITIONS - END */


int binarySearch(int nums[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return low;
}

void findKClosestElements(int nums[], int target, int n) {
    int i = binarySearch(nums, n, target);
    int k = 3;

    int left = i - 1;
    int right = i;

    while (k-- > 0) {
        if (left < 0 || (right < n && abs(nums[left] - target) > abs(nums[right] - target))) {
            right++;
        } else {
            left--;
        }
    }

    int highCloseScore = 0;

    left++;
    while (left < right) {
        highCloseScore = nums[left];
        break;
        left++;
    }

    printf("Ortalamaya en yakin ogrencinin matamatik notu: %d\n", highCloseScore);
}

void isPhysicsOrMathInputPrint(int index) {
    if (index == PHYSICS) { printf("Ogrenci Fizik Notu : "); }
    else if (index == MATH) { printf("Ogrenci Matematik Notu : "); }
}

void getInputPhysicsMath(int examScores[ROW_COUNT][COLUMN_COUNT]) {
    int row, column, index;
    for (row = 0; row < ROW_COUNT; row++) {
        index = 0;
        printf("%d. Ogrenci\n\n", row + 1);
        for (column = 0; column < COLUMN_COUNT; column++) {
            index += 1;
            isPhysicsOrMathInputPrint(index);
            scanf("%d", &examScores[row][column]);
        }
        printf("\n");
    }
}

int printScores(int scores[ROW_COUNT]) {
    int averageResult = 0;
    for (int i = 0; i < ROW_COUNT; ++i) {
        averageResult += scores[i] / ROW_COUNT;
        printf("%d", scores[i]);
        if (i == ROW_COUNT - 1) { printf("]"); }
        else { printf(", "); }
    }
    return averageResult;
}

void printSortingScores(int scores[ROW_COUNT]) {
    int temp;
    for (int i = 0; i < ROW_COUNT; ++i) {
        for (int j = i + 1; j < ROW_COUNT; ++j) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
    printScores(scores);
}

int printFindHighPhysicsMathScore(int scores[ROW_COUNT]) {
    int *tempScores;
    tempScores = scores;

    int index = ROW_COUNT;
    for (int i = 1; i < ROW_COUNT; ++i) {

        if (tempScores[0] < tempScores[i]) {
            tempScores[0] = tempScores[i];
            index -= 1;
        }

    }
    printf("Fizik Dersinden En yuksek Not: %d", tempScores[0]);
    return index;
}


void calculateOptionsExecute(int examScores[ROW_COUNT][COLUMN_COUNT]) {
    int physicsScores[ROW_COUNT];
    int mathScores[ROW_COUNT];
    int originalMathScores[ROW_COUNT];

    int averagePhysicsResult, averageMathResult;

    int row, column, index;

    for (row = 0; row < ROW_COUNT; row++) {
        index = 0;
        for (column = 0; column < ROW_COUNT; column++) {
            index += 1;
            if (index == PHYSICS) { physicsScores[row] = examScores[row][column]; }
            else if (index == MATH) {
                mathScores[row] = examScores[row][column];
                originalMathScores[row] = examScores[row][column];
            }
        }
    }

    printf("========================================================================\n"
           "Fizik & Matematik Dersi Not Ortalamasi Sonuclari\n"
           "========================================================================\n\n");
    printf("Fizik ders notları: [");
    averagePhysicsResult = printScores(physicsScores);
    printf(" - Fizik Ortalama: %d\n", averagePhysicsResult);

    printf("Matematik ders notları: [");
    averageMathResult = printScores(mathScores);
    printf(" - Matematik Ortalama: %d\n\n", averageMathResult);


    printf("========================================================================\n"
           "Fizik & Matematik Dersi Notlarinin Azalan Sira Sonuclari\n"
           "========================================================================\n\n");
    printf("Fizik ders notları azalan sira: [");
    printSortingScores(physicsScores);
    printf("\n");

    printf("Matematik ders notlari azalan sira: [");
    printSortingScores(mathScores);
    printf("\n");

    printf("\n========================================================================\n"
           "Fizik dersinden en yuksek not alan ogrencinin matematik dersi notu\n"
           "========================================================================\n\n");

    int highPhysicsScoreStudentIndex = printFindHighPhysicsMathScore(physicsScores);
    printf("\nOgrencinin Matematik Notu: %d\n", originalMathScores[highPhysicsScoreStudentIndex]);

    printf("\n========================================================================\n"
           "Matematik not ortalamasina en yakın notu olan ogrencinin Matematik notu\n"
           "========================================================================\n\n");

    printf("Matamatik not otalamasi: %d\n", averageMathResult);
    findKClosestElements(mathScores, averageMathResult, ROW_COUNT);
}


int main(int argc, char *argv[]) {
    int examScores[ROW_COUNT][COLUMN_COUNT] ;
    getInputPhysicsMath(examScores);
    calculateOptionsExecute(examScores);
}
