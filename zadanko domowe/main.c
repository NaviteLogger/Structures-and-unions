#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS 9
#define NUM_SUBJECTS 4

struct Student {
    char imieINazwisko[40];
    int grades[NUM_SUBJECTS];
    float average;
};

int main()
{
    float srednieZPrzedmiotow[NUM_SUBJECTS];

    struct Student strukturaStudent[10];

    char ImionaINazwiska[][30] = {
            {"Jane Smith"},
            {"John Doe"},
            {"Mike Williams"},
            {"Emily Johnson"},
            {"Jacob Jones"},
            {"Amanda Brown"},
            {"Jessica Garc"},
            {"Robert Miller"},
            {"Ashley Davis"},
            {"Michael Rod"}
    };

    srand(time(NULL));
    int r;

    char tekstAplikacji[][40] = {
            "Imie i nazwisko: ",
            "Oceny:     ",
            "   matematyka 1: ",
            "   matematyka 2: ",
            "   informatyka: ",
            "   j. angielski: ",
            "       srednia ucznia:     ",
            "Srednia z przedmiotu: ",
            };
    //zerowanie średnich
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        strukturaStudent[i].average = 0;
    }
    for (int i = 0; i < NUM_SUBJECTS; ++i)
    {
        srednieZPrzedmiotow[i] = 0;
    }

    //losowanie ocen
    for(int i = 0; i < NUM_STUDENTS;i++)
    {
        for (int j = 0; j < NUM_SUBJECTS;j++)
        {
            r = rand() % 4 + 2;
            strukturaStudent[i].average += (float)r;
            strukturaStudent[i].grades[j] = r;
        }
        strukturaStudent[i].average = strukturaStudent[i].average / NUM_SUBJECTS;
        strcpy(strukturaStudent[i].imieINazwisko,ImionaINazwiska[i]);
    }

    float sredniaWszystkiego = 0;

    //wyliczanie sredniej
    for(int i=0;i<NUM_SUBJECTS;i++)
    {
        for(int j=0;j<NUM_STUDENTS;j++)
        {
            srednieZPrzedmiotow[i] += (float)strukturaStudent[j].grades[i];
            sredniaWszystkiego += (float)strukturaStudent[j].grades[i];

        }
        srednieZPrzedmiotow[i] = srednieZPrzedmiotow[i] / (float)NUM_STUDENTS;
    }

    sredniaWszystkiego = sredniaWszystkiego / (float)(NUM_STUDENTS*NUM_SUBJECTS);

    //wyswietlanie struktur
    for(int i = 0; i<NUM_STUDENTS;i++) {
        int temp = 0;
        printf("%s", tekstAplikacji[temp]);
        temp++;
        printf("%s \t", strukturaStudent[i].imieINazwisko);
        printf("%s", tekstAplikacji[temp]);
        temp = +6;
        for (int k = 0; k < NUM_SUBJECTS; ++k) {
            printf("%s", tekstAplikacji[k + 2]);
            printf("%i ", strukturaStudent[i].grades[k]);
        }
        printf("%s", tekstAplikacji[temp]);
        printf("%.2f", strukturaStudent[i].average);
        printf("\n");
    }

    //wydrukowanie sredniej ocen
    for (int i = 0; i < NUM_SUBJECTS;i++)
    {
        printf("%s %s \t%.2f\n",tekstAplikacji[7],tekstAplikacji[i+2],srednieZPrzedmiotow[i]);
    }

    printf("Srednia ze wszystkich ocen to: \t\t\t%0.2f",sredniaWszystkiego);

    return 0;
}