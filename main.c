#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "displayCalories.h"
#include "bmi.h"
#include "login.h"

int progress(FILE *fptr);

typedef struct User2{
    char username[20];
    char password[20];
    float bmi;
    char date[20]
};
//Przykladowy uzytkownik do zalogowania: user1 password1
int main()
{
    struct User2 users2[100];
    int menu;
    bool wantToLogin, openExit = true;
    FILE *fptr;
    saveToFile(fptr);
    float height = 0.0, weight = 0.0, bmi = 0.0;  // Inicjalizowanie zmiennych
    int i = 0;
    printf("Czy chcesz sie zalogowac? (1 - Tak, 0 - Nie): ");
    scanf("%d", &wantToLogin);

    //zapisanie przykladowych danych do pliku
    char user[20];

    if (wantToLogin) {
        if (login(&users2, &user)) {
            do {
                // Uruchomienie menu po pomyslnym zalogowaniu
                printf("\n*************************************************** MENU *************************************************** \n"
                       "\n"
                       "Co chcesz zrobic?\n"
                       "[1] Oblicz swoje BMI\n"
                       "[2] Oblicz swoje zapotrzebowanie kaloryczne\n"
                       "[3] Przejdz do historii BMI\n"
                       "[4] Wyjdz z programu\n"
                       "Wybierz 1-4: ");
                scanf(" %d", &menu);

                switch (menu) {
                    case 1:
                        calcBmi(height, weight, fptr, users2, &user);
                        break;
                    case 2:
                        displayCalories();
                        break;
                    case 3:
                        while(strcmp(users2[i].username,user))
                              {
                                i++;
                              }
                        printf("Username: %s bmi: %f date: %s", &users2[i].username, users2[i].bmi, &users2[i].date);
                        break;
                    case 4:
                        openExit = false;
                        break;
                    default:
                        printf("\nZla liczba.\n");
                        break;
                }
            } while (openExit);
        }
    } else {
        do {
            // Uruchomienie menu bez logowania
            printf("\n*************************************************** MENU *************************************************** \n"
                   "\n"
                   "Co chcesz zrobic?\n"
                   "[1] Oblicz swoje BMI\n"
                   "[2] Oblicz swoje zapotrzebowanie kaloryczne\n"
                   "[4] Wyjdz z programu\n"
                   "Wybierz 1, 2 lub 4: ");
            scanf(" %d", &menu);

            switch (menu) {
                case 1:
                    calcBmiWhtoutLogin(height, weight, bmi, fptr);
                    break;
                case 2:
                    displayCalories();
                    break;
                case 4:
                    openExit = false;
                    break;
                default:
                    printf("\nZla liczba.\n");
                    break;
            }
        } while (openExit);
    }

    return 0;
}

int progress(FILE *fptr) {
    char user[15];
    float valueBmi;
    char date[10];

    fptr = fopen("progress.txt", "a");  // Dopisywanie ,,a" append wartosci do pliku txt
    if (fptr == NULL) {
        printf("Nie mozna otworzyc pliku progress.txt\n");
        return -1;
    }

    printf("Podaj nazwe uzytkownika: \n");
    scanf("%s", user);
    fprintf(fptr, "User= %s\n", user);
    printf("Podaj nazwe date w formacie dd/mm/rrrr: \n");
    scanf("%s", date);
    fprintf(fptr, "Date= %s\n", date);
    fclose(fptr);

    return 0;
}


    int saveToFile(FILE *fptr) {

    fptr = fopen("progress2.txt", "w");  // w - write
    if (fptr == NULL) {
        printf("Nie mozna otworzyc pliku progress.txt\n");
        return -1;
    }
// Przykladowi uzytkownicy
    struct User2 users2[] = {
    {"user1", "password1", 191.2, "21.01.2023"},
    {"user2", "password2", 37, "12.02.2023"}
};

     fwrite(&users2, sizeof( users2), 1, fptr);


     fclose(fptr);
return 0;
    }


