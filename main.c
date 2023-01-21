#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Funzione algoritmo bubbleSort
void bubblesort(int v[])
{
    int i, k;
    int temp;
    int n = 5;

    for (i = 0; i < n - 1; i++)
    {
        for (k = 0; k < n - 1 - i; k++)
        {
            if (v[k] > v[k + 1])
            {
                temp = v[k];
                v[k] = v[k + 1];
                v[k + 1] = temp;
            }
        }
    }
}

// Funzione del stupidSort
void stupidSort(int myNumbers[], int myNumbersRandom[], int size_t)
{
    int i = 0;

    for (i = 0; i < size_t; i++) {
        int r = rand() % 40;
        myNumbersRandom[i] = r;
    }
}

// Funzione per comparare gli array
int compareArrays(int myNumbers[], int myNumbersRandom[], int size_t)
{
    int i = 0;
    int uguali = 0;
    long tentativi = 0;

    while (uguali == 0) {
        for (i = 0; i < size_t; i++) {
            if (myNumbers[i] != myNumbersRandom[i]) {
                stupidSort(myNumbers, myNumbersRandom, size_t);
                tentativi = tentativi + 1;
                i = -1;
            } else {
                uguali = 1;
            }
        }
    }

    printf("I due array sono finalmente uguali! Ci sono stati %ld tentativi!\n", tentativi);
    printf("%d %d %d %d %d\n", myNumbers[0], myNumbers[1], myNumbers[2], myNumbers[3], myNumbers[4]);
    printf("%d %d %d %d %d\n", myNumbersRandom[0], myNumbersRandom[1], myNumbersRandom[2], myNumbersRandom[3], myNumbersRandom[4]);
    
    return 1;
}

// PROGRAMMA MAIN ----------------------------------------------

int main()
{
    int myNumbers[5];
    int myNumbersRandom[5];
    int num = 0;
    int i = 0;
    int tentativi = 0;
    int size_t = sizeof(myNumbers) / sizeof(int);
    srand(time(0));

    // Inserimento dati
    for (i = 0; i < size_t; i++)
    {
        printf("Inserisci il valore dell'array nella posizione %d: ", i);
        scanf("%d", &num);
        myNumbers[i] = num;
    }

    // Inizializazzione delle funzioni, ergo start del programma
    bubblesort(myNumbers);
    stupidSort(myNumbers, myNumbersRandom, size_t);
    compareArrays(myNumbers, myNumbersRandom, size_t);
    
    return 0;
}
