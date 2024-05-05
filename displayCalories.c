#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "displayCalories.h"

void displayCalories()
{

    float height, weight, ppm;
    int age;
    char gender;



    // Wprowadzanie danych
    printf("Podaj swoja wage (kg): ");
    scanf("%f", &weight);
    printf("Podaj swoja wzrost (m): ");
    scanf("%f", &height);
    printf("Podaj wiek: ");
    scanf("%d", &age);
    printf("Podaj plec wpisujac 'm' lub 'k': ");
    scanf(" %c", &gender);// Pobierz pojedynczy znak

    //Obliczanie PPM - podstawowej przemiany materii
    switch(gender)
    {
        //dla mezczyzny
        case 'm':
                ppm = 66.47 + (13.75 * weight) + (500 * height) - (6.75 * age);
                printf("Twoja podstawowa przemiana materii wynosi [kcal]:  %.2f \n", ppm);
                break;
        //dla kobiety
        case 'k':
            ppm = 665.09 + (9.56 * weight) + (185 * height) - (4.67 * age);
            printf("Twoja podstawowa przemiana materii wynosi [kcal]:  %.2f \n", ppm);
            break;

        default:
            printf("Nieprawidlowa litera\n");
            break;
    }


/*Macierz skladajacy sie z 5 wierszy i 4 kolumn, wartosci sa punktacja do testu na aktywnosc fizyczna
To pomoze nam w obliczeniu CPM - calkowitej przemiany materii*/

  float arr[5][4] = {
      {1.4, 1.5, 1.6, 1.7},
      {1.5, 1.6, 1.7, 1.8},
      {1.6, 1.7, 1.8, 1.9},
      {1.7, 1.8, 1.9, 2.1},
      {1.9, 2.0, 2.2, 2.3}
      };

  float score, totalScore;
  char answer1, answer2, answer3;
  int i,j;

//Pytania pomagajace okreslic aktywnosc fizyczna uzytkownika

    printf("************** Poznalas/es swoja Podstawowa Przemiane Materii! Teraz ocen swoja aktywnosc fizyczna. ************** \n"
    "\n"
    "W tym celu odpowiedz na 2 pytania.\n"
    "\n"
    "\n"
                "1. Aktywnosc fizyczna w pracy:\n"
                "\n"
                "[A] Bardzo lekka, np. siedze przed komputerem wieksza czesc dnia lub jestem kierowca\n"
                "[B] Lekka, np. lekka praca przemys³owa, sprzedaz lub praca biurowa obejmujaca lekkie czynnosci.\n"
                "[C] Umiarkowana, np. sprzatanie, praca w kuchni lub dostarczanie poczty pieszo lub rowerem\n"
                "[D] Ciezka, np. ciezka praca przemyslowa, prace budowlane lub rolnictwo.\n"
                "\n"
                "Wpisz literke  A,B,C lub D: ");

    scanf(" %c", &answer1);


                printf("\n2. Aktywnosc fizyczna w czasie wolnym: \n"
                "\n"
                "[A] Bardzo lekka, np. nie jestem aktywny fizycznie w wolnym czasie \n"
                "[B] Lekka, np. raz w tygodniu spaceruje, sporadycznie jezdze na rowerze, pracuje w ogrodku \n"
                "[C] Umiarkowana, np. Regularnie cwicze przynajmniej raz tygodniu: spaceruje 10-30 min.,jezdze na rowerze \n"
                "[D] Duza np. Regularnie cwicze wiecej niz raz w tygodniu\n"
                "[E] Intensywna np. ciezka aktywnosc fizyczna kilka razy w tygodniu \n"

                "Wpisz literke  A,B,C lub D: ");

    scanf(" %c", &answer2);


//Jesli odpowiedzia na pytanie 1 bedzie A = [0][0], B[0][1] itd.
    if (answer1 == 'A') {
        i = 0;
        j = 0;
    } else if (answer1 == 'B') {
        i = 0;
        j = 1;
    } else if (answer1 == 'C') {
        i = 0;
        j = 2;
    } else if (answer1 == 'D') {
        i = 0;
        j = 3;
    } else {
        printf("Nieprawidlowa litera dla pytania 1\n");
        return 1; // Zwracamy 1, aby wskazac blad
    }

    // W zaleznosci od odpowiedzi drugiego pytania, wyswietlamy wynik
            if (answer2 == 'A') {
                score = arr[i][j] * ppm;
                printf("\nTwoj wynik to: %.2f punktow (%.2f%%)\n", score, arr[i][j]);
            } else if (answer2 == 'B') {
        // Wybieramy inny indeks w macierzy, np. [0][1]
                score = arr[i][j + 1] * ppm;
                printf("\nTwoj wynik to: %.2f punktow (%.2f%%)\n", score, arr[i][j + 1]);
            } else if (answer2 == 'C') {
                score = arr[i][j + 2] * ppm;
                printf("\nTwoj wynik to: %.2f punktow (%.2f%%)\n", score, arr[i][j + 2]);
            } else if (answer2 == 'D') {
                score = arr[i][j + 3] * ppm;
                printf("\nTwoj wynik to: %.2f punktow (%.2f%%)\n", score, arr[i][j + 3]);
            } else if (answer2 == 'E') {
                score = arr[i][j + 4] * ppm;
                printf("\nTwoj wynik to: %.2f punktow (%.2f%%)\n", score, arr[i][j + 4]);
            } else {
                printf("Nieprawidlowa litera dla pytania 2\n");
                return 1; // Zwracamy 1, aby wskazac blad
            }
    /*Na tym etapie znamy wartosc calkowitej przemiany materii uzytkownika

     Teraz uzytkownik wylicza ilosc kcal, jakiej potrzebuje by (wg wlasnego wyboru): schudnac/utyc/utzymac wage*/

            printf("\n************** Chcesz: utrzymac wage wybierz: '1', schudnac wybierz: '2', przybrac na wadze: '3' ************** \n");
            scanf(" %d", &answer3);


            if (answer3 == 1) {
                printf("Nie przekraczaj swojej dziennej przemiany materii: %.2f\n", score);
                return 1; // Zwracamy 1, aby wskazac blad

            } else if (answer3 == 2) {
        //Obliczanie i wyswietlanie ile powinno spozywac sie kalorii, zeby schudnac
                score-=500;
                printf("\nJesli chcesz schudnac dostarczaj od %.2f kcal \n", score);
                score-=700;
                printf("\do %.2f kcal dziennie", score);

            } else if (answer3 == 3) {
        //Obliczanie i wyswietlanie ile powinno spozywac sie kalorii, zeby przybrac na wadze
                score+=500;
                printf("\nJesli chcesz przybrac na wadze dostarczaj od %.2f kcal \n", score);
                score+=700;
                printf("\do %.2f kcal dziennie", score);


            } else {
                printf("Nieprawidlowa cyfra dla pytania\n");
                return 1; // Zwracamy 1, aby wskazac blad
                }





    return 0;
}





