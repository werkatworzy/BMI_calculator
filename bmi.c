
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmi.h"
#include "login.h"
#include "displayCalories.h"


typedef struct {
    char username[20];
    float height, weight, bmi;
} UserData;

typedef struct User2{
    char username[20];
    char password[20];
    float bmi;
    char date[20]
};
//Interpretacja wynikow BMI zdefiniowane w BMI.h
void interpretBMI(float bmi) {
    if (bmi < UNDERWEIGHT) {
        printf("Wyglodzenie");
    } else if (bmi < SEVERE_UNDERWEIGHT) {
        printf("Wychudzenie");
    } else if (bmi < UNDERWEIGHT_RANGE) {
        printf("Niedowaga");
    } else if (bmi <= NORMAL_WEIGHT_RANGE_UPPER) {
        printf("Waga prawidlowa");
    } else if (bmi <= OVERWEIGHT_RANGE_UPPER) {
        printf("Nadwaga");
    } else if (bmi <= OBESITY_I_RANGE_UPPER) {
        printf("Otylosc I stopnia");
    } else if (bmi <= OBESITY_II_RANGE_UPPER) {
        printf("Otylosc II stopnia");
    } else if (bmi >= OBESITY_III) {
        printf("Otylosc III stopnia");
    } else {
        printf("Nieprawidlowe dane. Sprawdz wartosci i popraw.\n");
    }
}



    void calcBmi(float height, float weight, FILE *fptr, struct User2* users2, char user[]) {
    float lbmi;

    printf("Podaj swoja wage (kg): ");
    scanf("%f", &weight);
    printf("Podaj swoja wzrost (m): ");
    scanf("%f", &height);

    lbmi = weight / (height * height);

    printf("Twoj wskaznik BMI wynosi: %.2f \n", lbmi);
    interpretBMI(lbmi);

    char date[20];
    printf("\nPodaj date pomiaru (dd/mm/yyyy): ");
    scanf("%s", date);

    saveBMI(lbmi, &date, fptr, &users2, user);
}

    void calcBmiWhtoutLogin(float height, float weight, FILE *fptr) {
    UserData user;

    printf("Podaj swoja wage (kg): ");
    scanf("%f", &weight);
    printf("Podaj swoja wzrost (m): ");
    scanf("%f", &height);

    user.bmi = weight / (height * height);

    printf("Twoj wskaznik BMI wynosi: %.2f \n", user.bmi);
    interpretBMI(user.bmi);

    }

        void saveBMI(float pbmi, char date[], FILE *progress, struct User2* users2, char user[]) {

        int i= 0;
        while(strcmp(&users2[i].username, user) == 0)
        {
            i++;
        }
        progress = fopen("progress2.txt", "w");  // w - write zapisywanie danych w pliku txt
        if (progress == NULL) {
                        printf("Nie mozna otworzyc pliku progress.txt\n");
        return -1;
    }
        users2[i].bmi = pbmi;
        strcpy(&users2[i].date, date);
        fwrite(&users2, sizeof( users2[0]), 1, progress);
        fclose(progress);
}




