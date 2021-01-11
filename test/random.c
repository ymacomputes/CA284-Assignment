#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * fp;
	int i;
	fp = fopen("numbersrandom.txt","w");

	for (int i = 0; i < 10000; i++)
	{
		fprintf(fp, "%d\n", i);
	}
	fclose(fp);
	return 0;
}

/* References:
	https://www.zentut.com/c-tutorial/c-write-text-file/
*/