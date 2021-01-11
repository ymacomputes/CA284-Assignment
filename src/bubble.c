#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

#define MAX_ARRAY 1000000

int* arr;

int readAll (char* filename) {
    arr = (int*) malloc (MAX_ARRAY * sizeof (int) );
    int totalNumbers = 0;

    FILE *file = fopen (filename, "rt");

    if (file != NULL) {
        while (!feof (file) && (totalNumbers < MAX_ARRAY)) {
            fscanf (file, "%d\n", &(arr[totalNumbers++]));
        }

       fclose (file);
    }
    return totalNumbers;
}

int main (int argc, char* argv[])
{
    int n = readAll (argv[1]);
    int i, j;

    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);

    for (i=0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}

/* References:
    https://www.geeksforgeeks.org/bubble-sort/
    https://www.programiz.com/c-programming/c-file-input-output
*/
