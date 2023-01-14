// #include <stdio.h>

// typedef union PrzechowalniaDanych
// {
//     char imie[20];
//     char nazwisko[30];
//     char rodzajDokumentuTozsamosci;
//     int numerDokumentuTozsamosci[10];
// } PrzechowalniaDanych;

// int main()
// {
//     PrzechowalniaDanych uniaTestowa;
//     printf("Podaj swoje imie: ");
//     scanf("%s", &uniaTestowa.imie);
//     printf("Podaj swoje nazwisko: ");
//     scanf("%s", &uniaTestowa.nazwisko);
//     printf("Podaj swoj rodzaj dokumentu: ");
//     fflush(stdin);
//     scanf("%c", &uniaTestowa.rodzajDokumentuTozsamosci);
//     fflush(stdin);
//     printf("Podaj swoj numer dokumentu: ");
//     scanf("%i", &uniaTestowa.numerDokumentuTozsamosci);

//     printf("Imie: %s, nazwisko: %s, rodzaj dokumentu tozsamosci: %c, numer dokumentu tozsamosci: %i", uniaTestowa.imie, uniaTestowa.nazwisko, uniaTestowa.rodzajDokumentuTozsamosci, uniaTestowa.numerDokumentuTozsamosci);
//     return 0;
// }

#include <stdio.h>

typedef struct PrzechowalniaDanych
{
    char imie[20];
    char nazwisko[30];
    char rodzajDokumentuTozsamosci;
    int numerDokumentuTozsamosci[10];
} PrzechowalniaDanych;

int main()
{
    PrzechowalniaDanych struktura;
    PrzechowalniaDanych strukturaKopia;

    strukturaKopia = struktura;
    // str copy
    // dla prostych danych zwykłe "="

    char tablicaWyrazow[][30] =
        {
            "Dane osoby: ",
            "Nazwisko: ",
            "Imie: ",
            "Rodzaj dokumentu:",
            "oznaczenia: ",
            "P-Paszport",
            "D-Dowod osobisty",
            "K-Karta pobytu"
            "Numer dokumentu"};

    printf("Podaj swoje imie: ");
    scanf_s("%s", &struktura.imie);
    printf("Podaj swoje nazwisko: ");
    scanf_s("%s", &struktura.nazwisko);
    printf("Podaj swoj rodzaj dokumentu: ");
    fflush(stdin);
    scanf_s("%c", &struktura.rodzajDokumentuTozsamosci);
    fflush(stdin);
    printf("Podaj swoj numer dokumentu: ");
    scanf_s("%i", &struktura.numerDokumentuTozsamosci);

    printf("%s", tablicaWyrazow[0]);

    printf("Imie: %s, nazwisko: %s, rodzaj dokumentu tozsamosci: %c, numer dokumentu tozsamosci: %i", struktura.imie, struktura.nazwisko, struktura.rodzajDokumentuTozsamosci, struktura.numerDokumentuTozsamosci);

    return 0;
}