#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

// typu tablicy znakow o maksymalnej długości 20 znaków.
typedef struct User2{
    char username[20];
    char password[20];
    float bmi;
    char date[20]
};
//Uwierzytelnianie uzytkownika na podstawie wprowadzonej nazwy uzytkownika i hasla
int loggedInUserIndex = -1;

    int authenticateUser(char username[], char password[], struct User2* users2) {
    for (int i = 0; i < sizeof(users2[0])/ sizeof(users2); ++i) {
//Dokonuje się porownanie nazwy uzytkownika i hasla z danymi przechowywanymi w strukturze User
        if (strcmp(&users2[i].username, username) == 0 && strcmp(&users2[i].password, password) == 0) { //strmp sluzy do porownywania ciagu znakow
            loggedInUserIndex = i;
            return 1; // Uzytkownik uwierzytelniony
        }
    }

    return 0; // Blad uwierzytelnienia
}

int login(struct User2* users2, char user[]) {
    char username[20];
    char password[20];
    FILE *fptr;
    printf("Podaj login: ");
    scanf("%s", username);

    printf("Podaj haslo: ");
    scanf("%s", password);

    loadFromFile(fptr, users2);

    if (authenticateUser(username, password, users2)) {
        printf("Zalogowano jako: %s\n", username);
        strcpy(user, username);
        return 1; // Zalogowano pomyslnie
    } else {
        printf("Blad logowania. Sprobuj ponownie.\n");
        printf("1. Sprobuj ponownie\n");
        printf("2. Dodaj uzytkownika\n");

        int opcja;
        scanf("%d", &opcja);

        switch (opcja) {
            case 1:
                login(&users2, user); // Powrót do menu logowania
            case 2:
                registerUser();
                return 1; // Powrót do menu logowania
            default:
                printf("Niepoprawny wybor. Sprobuj ponownie.\n");
                login(&users2, user); // Powrót do menu logowania
        }
    }
}

    void registerUser(struct User2* users2) {
    char newUsername[20];
    char newPassword[20];

    printf("Podaj nowy login: ");
    scanf("%s", newUsername);

    printf("Podaj nowe haslo: ");
    scanf("%s", newPassword);

    // Sprawdzanie, czy uzytkownik juz istnieje
    for (int i = 0; i < sizeof(users2) / sizeof(users2[0]); ++i) {
        if (strcmp(users2[i].username, newUsername) == 0) {
            printf("Uzytkownik o podanym loginie juz istnieje. Wybierz inny login.\n");
            return;
        }
    }

    // Dodawanie nowego uzytkownika: User o nazwie newUser.
    //Kopiuje nazwe użytkownika i haslo z podanych zmiennych newUsername i newPassword,
    //a nastepnie dodaje strukture do tablicy uzytkownikow users
    //User newUser;

        for (int i = 0; i < sizeof(users2) / sizeof(users2[0]); ++i) {
        if (strcmp(users2[i].username, '\0') == 0) {
                strcpy(users2[i].username, newUsername);
                strcpy(users2[i].password, newPassword);
            return;
        }
    }


    printf("Utworzono nowe konto dla: %s\n", newUsername);
}
    int loadFromFile(FILE *fptr, struct User2* users2) {

    fptr = fopen("progress2.txt", "r");  // czytanie z txt
    if (fptr == NULL) {
    printf("Nie mozna otworzyc pliku progress.txt\n");
    return -1;
    }

  rewind(fptr);

    // czytanie struktury
    int i = 0;
    while (fscanf(fptr, "%s %s %f %s",
            &users2[i].username,
            &users2[i].password,
            users2[i].bmi,
            &users2[i].date) == 10)

        ++i;



fclose(fptr);
return 0;
    }
