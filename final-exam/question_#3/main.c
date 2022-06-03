//
// Created by Yusuf Dede on 3.06.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "conio.h"

typedef struct {
    char name[100];
    long int code;
    long int number;
} telephone;

int search, status = 1, i, c;
char search1[50];


FILE *kp;
telephone record;

void delete(void);
void edit(void);

void delete(void) {
    int silno;
    char siltekrar, ch;

    printf("\nSilinecek Musteri Kodu : ");
    scanf("%d", &silno);

    fseek(kp, silno * sizeof(telephone), 0);
    fread(&record, sizeof(telephone), 1, kp);
    if (record.code == silno) {
        printf("\nMusteri Kodu : %d", record.code);
        printf("\nMusteri Adi : %s", record.name);
        printf("\nTelefon     : ");
        printf("%d", record.number);
        printf("\nKAYIT SILINICEK!...<E/H>");
        ch = c_getch();
    }

    if (ch == 'E' || ch == 'e') {
        strcpy(record.name, "");
        record.number = 0.0;
        fseek(kp, silno * sizeof(record), 0);
        fwrite(&record, sizeof(record), 1, kp);
        printf("\nKAYIT BASARIYLA SILINDI\n\n");
    } else {
        if (record.code != silno) {
            printf("KAYIT BULANAMADI!...");
        }
        printf("\n\nTekrar Arama Yapmak istermisiniz <E/H> ");
        siltekrar = c_getch();
        if (siltekrar == 'E' || siltekrar == 'e') {
            printf("\nSilinecek Musteri Kodu : ");
            scanf("%d", &silno);

            fseek(kp, silno * sizeof(telephone), 0);
            fread(&record, sizeof(telephone), 1, kp);
            if (record.code == silno) {
                printf("\nMusteri Kodu : %d", record.code);
                printf("\nMusteri Adi : %s", record.name);
                printf("\nTelefon     : ");
                printf("%d", record.number);
                printf("\nKAYIT SILINICEK!...<E/H>");
                ch = c_getch();
            }
            if (ch == 'E' || ch == 'e') {
                strcpy(record.name, "");
                record.number = 0.0;
                fseek(kp, silno * sizeof(record), 0);
                fwrite(&record, sizeof(record), 1, kp);
                printf("\nKAYIT BASARIYLA SILINDI\n\n");
            }
            if (record.code != silno) {
                printf("KAYIT BULANAMADI!...");
            }
        }

    }
    printf("\n\n Devam icin herhangi bir tusa basin");
    c_getch();
}

void recordAdd() {
    printf("\nMusteri Kodu :");
    scanf("%d", &record.code);
    printf("Musteri Adi  :");
    scanf("%s", &record.name);
    printf("Telefon      :");
    scanf("%d", &record.number);

    fseek(kp, record.code * sizeof(telephone), 0); // Isaretciyi en basa cek SEEK_SET
    fwrite(&record, sizeof(telephone), 1, kp);
    fflush(kp);
    //fflush(FILE *) tampon bellektekiler diske yazilacaktir....
}

void list() {
    system("CLS");//clrscr();

    fseek(kp, 0, 0);
    fread(&record, sizeof(telephone), 1, kp);
    printf("\nM.Kodu   Adi       Telefon\n==========================\n");
    while (!feof(kp)) {
        if (strcmp(record.name, "")) {
            printf("\n%ld \t %s \t   ", record.code, record.name);
            printf("%ld", record.number);
        }
        fread(&record, sizeof(telephone), 1, kp);
    }
    printf("\n\n Devam icin herhangi bir tusa basin");
    c_getch();
}

void nameSearch() {
    printf("\nAranacak Isim : ");
    scanf("%s", &search1);

    fseek(kp, 0, 0);
    fread(&record, sizeof(record), 1, kp);
    while (!feof(kp)) {
        if (!strncmp(record.name, search1, strlen(search1))) {
            printf("\nMusteri Kodu : %d", record.code);
            printf("\nMusteri Adi  : %s", record.name);
            printf("\nTelefon      : %d", record.number);
            status = 0;
        }
        fread(&record, sizeof(record), 1, kp);
    }
    if (status) {
        printf("\nKAYIT BULUNAMADI");
    }
    printf("\n\n Devam icin herhangi bir tusa basin");
    c_getch();
}

void numberSearch() {
    printf("\nAranacak Musteri Numarasi : ");
    scanf("%d", &search);

    fseek(kp, 0, 0);
    fread(&record, sizeof(telephone), 1, kp);

    while (!feof(kp)) {
        if (record.number == search) {
            printf("\nMusteri Kodu: %d", record.code);
            printf("\nMusteri Adi : %s", record.name);
            printf("\nTelefon     : %d", record.number);
            break;

        }
        fread(&record, sizeof(telephone), 1, kp);
    }
    if (record.number != search) {
        printf("\nKAYIT BULUNAMADI");
    }

    printf("\n\n Devam icin herhangi bir tusa basin");
    c_getch();

}

void edit(void) {
    int dno;
    char tekrar, ch;
    printf("\nDuzeltilecek Musteri Kodu : ");
    scanf("%d", &dno);
    fseek(kp, dno * sizeof(record), 0);
    fread(&record, sizeof(record), 1, kp);
    if (record.code == dno) {
        printf("\nMusteri Kodu: %d", record.code);
        printf("\nMusteri Adi : %s", record.name);
        printf("\nTelefon     : %d", record.number);
        printf("\nDUZELTILECEK KAYIT BU MU? <E/H>");
        ch = c_getch();
    }

    if (ch == 'E' || ch == 'e') {
        printf("\nMusteri Adi: ");
        scanf("%s", record.name);
        printf("\nTelefon    : ");
        scanf("%d", &record.number);
        fseek(kp, dno * sizeof(record), 0);
        fwrite(&record, sizeof(record), 1, kp);
        printf("\nKAYIT BASARIYLA DUZELTILDI\n\n");
    } else {
        if (record.code != dno) {
            printf("KAYIT BULANAMADI!...");
        }
        printf("\n\nTekrar Arama Yapmak isterminiz <E/H> ");
        tekrar = c_getch();
        if (tekrar == 'E' || tekrar == 'e') {
            printf("\nDuzeltilecek Musteri Kodu : ");
            scanf("%d", &dno);

            fseek(kp, dno * sizeof(record), 0);
            fread(&record, sizeof(record), 1, kp);
            if (record.code == dno) {
                printf("\nMusteri Kodu: %d", record.code);
                printf("\nMusteri Adi : %s", record.name);
                printf("\nTelefon     : %d", record.number);
                printf("\nDUZELTILECEK KAYIT BU MU? <E/H>");
                ch = c_getch();
            }
            if (ch == 'E' || ch == 'e') {
                printf("\nMusteri Adi : ");
                scanf("%s", record.name);
                printf("\nTelefon     : ");
                scanf("%d", &record.number);
                fseek(kp, dno * sizeof(record), 0);
                fwrite(&record, sizeof(record), 1, kp);
                printf("\nKAYIT BASARIYLA DUZELTILDI\n\n");
            }
            if (record.code != dno) {
                printf("KAYIT BULANAMADI!...");
            }
        } else {
            printf("KAYIT DUZELTILMEDI!... ");
        }
    }
    printf("\n\n Devam icin herhangi bir tusa basin");
    c_getch();
}

int main() {

    setlocale(LC_ALL, "turkish");

    kp = fopen("TelefonRehber.txt", "r+");

    if (kp == NULL)
        kp = fopen("TelefonRehber.txt", "w+");
    do {
        system("CLS"); // Ekranı temizler...
        printf("\n\t\t TELEFON REHBERI v1.0");
        printf("\n\t\t***********************\n\n");
        printf("ISLEMLER\n\n");
        printf("1 - Kayit Ekle\n");
        printf("2 - Telefonlari list\n");
        printf("3 - Kaydi Duzenle\n");
        printf("4 - Numara ile Kayit bul\n");
        printf("5 - Isim ile Kayit Bul\n");
        printf("6 - Kayit Sil\n");
        printf("0 - Cikis\n");

        printf("\n\n\n Secim... ");
        scanf("%d", &c);


        if (c == 1) {
            recordAdd();
        } else if (c == 2) {
            list();
        } else if (c == 3) {
            edit();
        } else if (c == 4) {
            numberSearch();
        } else if (c == 5) {
            nameSearch();
        } else if (c == 6) {
            delete();
        }
    } while (c != 0);
    fclose(kp);
}
