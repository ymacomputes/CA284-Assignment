#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
{
    int n = readAll (argv[1]);
    int i, currentNumber, j;

    for (i = 1; i < n; i++) { 
        currentNumber = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > currentNumber) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = currentNumber; 
    }

    for (i=0; i < n; i++) 
        printf("%d\n", arr[i]);
    return 0;
}

/* References:
    https://www.geeksforgeeks.org/insertion-sort/
    https://www.programiz.com/c-programming/c-file-input-output
*/
