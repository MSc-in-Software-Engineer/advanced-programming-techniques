//
// Created by Yusuf Dede on 29.05.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

const char menuDescription[] = "=============================================================\n"
                               "\t\t\t\t\t\t\t MENU\n"
                               "=============================================================\n\n"
                               "[  1  ]  -> Fibonacci dizimi hesaplama\n"
                               "[  2  ]  -> n!(n-1)!/(n+1)! hesaplama \n"
                               "[  3  ]  -> Formül hesaplama\n"
                               "[ -1  ]  -> cikis..\n\n"
                               "==============================================================\n"
                               "Seciminizi giriniz: ";

bool digitCheck(char key[]) {
    for (int i = 0; i < strlen(key); i++) {
        if (isdigit(key[i]) == 0) { // isdigit check int or char value
            return false;
        }
    }
    return true;
}

void fibonacciSequenceCalculate() {
    char oddOrEvenNumberinput[255];
    int numberValue = 0;
    int n1, n2;
    n1 = 0;
    n2 = 1;
    int count = 0;

    printf("Lütfen bir adet tam sayi giriniz: ");
    scanf("%s", &oddOrEvenNumberinput);

    while (!digitCheck(oddOrEvenNumberinput)) {
        printf("Lutfen tam sayi olarak giriş yapiniz!! : ");
        scanf("%s", &oddOrEvenNumberinput);
    }
    numberValue = atoi(oddOrEvenNumberinput); // char value covert to int

    while (numberValue <= 0) {
        printf("Lutfen POZITIF tam sayi olarak giriş yapiniz!! : ");
        scanf("%s", &oddOrEvenNumberinput);
        numberValue = atoi(oddOrEvenNumberinput); // char value covert to int
    }

    if (numberValue == 1) {
        printf("\n\nFibonacci dizisi kadar %d : %d\n\n", numberValue, n1);
    } else {
        while (count < numberValue) {
            printf("%d\n", n1);
            int nth = n1 + n2;
            n1 = n2;
            n2 = nth;
            count += 1;
        }
    }
}

void fibonacciCalculate() {
    printf("fibonacciCalculate");
}

void fibonacciFormulaCalculate() {
    printf("fibonacciFormulaCalculate");
}

void menu() {
    int choice = 0;

    while (choice != 4) {
        fflush(stdin);

        printf("%s", menuDescription);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fibonacciSequenceCalculate();
                choice = 0;
                break;
            case 2:
                fibonacciCalculate();
                choice = 0;
                break;
            case 3:
                fibonacciFormulaCalculate();
                choice = 0;
                break;
            case -1:
                printf("Programdan cikiş yapildi!");
                exit(1);
            default:
                printf("\nLuften seceneklerden birini seciniz !!!!!!\n\n");
                choice = 0;
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    menu();
    return 0;
}
