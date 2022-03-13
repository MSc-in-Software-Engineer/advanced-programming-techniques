//
// Created by Yusuf Dede on 12.03.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

const char menuDescription[] = "=============================================================\n"
                               "\t\t\t\t\t\t\t MENU\n"
                               "=============================================================\n\n"
                               "[  1  ]  -> Girilen sayinin tek Yada cift Oldugunu Bulma\n"
                               "[  2  ]  -> Girilen 3 sayiyi buyukten kucuge siralama \n"
                               "[  3  ]  -> Girilen Sayinin Asal sayi olup olmadigini bulma\n"
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


void oddOrEvenNumberTest() {
    char oddOrEvenNumberinput[255];
    int numberValue;

    printf("Tek yada cift sayi giriniz: ");
    scanf("%s", &oddOrEvenNumberinput);

    while (!digitCheck(oddOrEvenNumberinput)) {
        printf("Lutfen sayi olarak giriş yapiniz!! : ");
        scanf("%s", &oddOrEvenNumberinput);
    }
    numberValue = atoi(oddOrEvenNumberinput); // char value covert to int

    if (numberValue % 2 == 0) {
        printf("\n[ %d ] -> girilen sayi ciftir!\n\n", numberValue);
    } else {
        printf("\n[ %d ] -> girilen sayi tektir!\n\n", numberValue);
    }
}

void threeNumberSortingTest() {
    char inputNumber[255];
    int numberValue, temp = 0;
    int inputNumberArrayLength = 3;
    int inputNumberArray[inputNumberArrayLength];

    for (int i = 1; i <= inputNumberArrayLength; ++i) {
        printf("%d. sayiyi giriniz: ", i);
        scanf("%s", &inputNumber);

        while (!digitCheck(inputNumber)) {
            printf("Lutfen sayi olarak giriş yapiniz!! : ");
            scanf("%s", &inputNumber);
        }

        numberValue = atoi(inputNumber); // char value covert to int
        inputNumberArray[i - 1] = numberValue;
    }


    for (int i = 0; i < inputNumberArrayLength; i++) {
        for (int j = i + 1; j < inputNumberArrayLength; j++) {
            if (inputNumberArray[i] < inputNumberArray[j]) {
                temp = inputNumberArray[i];
                inputNumberArray[i] = inputNumberArray[j];
                inputNumberArray[j] = temp;
            }
        }
    }

    printf("\nBuyukten kucuge siralanmis sayilarin sonucu: [");
    for (int i = 0; i < inputNumberArrayLength; ++i) {
        printf("%d", inputNumberArray[i]);

        if (i + 1 != inputNumberArrayLength) {
            printf(" - ");
        }
    }
    printf("]\n\n");
}

void primeNumberTest() {
    char inputNumber[255];
    int inputNumberValue, i, controlVariable = 0;

    printf("Lutfen bir sayı giriniz: ");
    scanf("%s", &inputNumber);

    while (!digitCheck(inputNumber)) {
        printf("Lutfen sayi olarak giriş yapiniz!! : ");
        scanf("%s", &inputNumber);
    }
    inputNumberValue = atoi(inputNumber); // char value covert to int

    for (i = 2; i < inputNumberValue; i++) {
        if (inputNumberValue % i == 0) {
            printf("\n[%d] -> Girilen sayı asal değildir.\n\n", inputNumberValue);
            controlVariable = 1;
            break;
        }
    }
    if (controlVariable == 0) {
        printf("\n[%d] -> Girilen sayı asaldır.\n\n", inputNumberValue);
    }
}


void menu() {
    int choice = 0;

    while (choice != 4) {
        fflush(stdin);

        printf("%s", menuDescription);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                oddOrEvenNumberTest();
                choice = 0;
                break;
            case 2:
                threeNumberSortingTest();
                choice = 0;
                break;
            case 3:
                primeNumberTest();
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
