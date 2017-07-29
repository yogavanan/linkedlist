/*

Problem Statement:

There are N chocolate types. Each chocolate has a rating. You have to pay for each chocolate with coins subjected to the following requirements:
1. Each chocolate must be given at least one coin.
2. Chocolates with a higher rating must get more coins than their neighbors.

What is the minimum coins you must give?

Example:
Lets say there are are 5 chocolates with rating 5, 2, 7, 1, 9.
In this case the coins for each of the chocolates would be 2, 1, 2, 1, 2.

either chocolate #2 or #4 is the result
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SAMPLES 100

/* Returns an integer in the range [0, n).
 *
 * Uses rand(), and so is affected-by/affects the same seed.
 */
unsigned int randint(unsigned int max)
{
	int r;
	r = rand();

	return (r % max);
}

int main()
{
	/** Take random Max samples with a cap of  MAX_SAMPLES **/
	int numChocolate = randint(MAX_SAMPLES);
	int * samples = (int *) malloc(numChocolate*sizeof(int));
	int minCost = 0;

	printf("Samples count: %d \n", numChocolate);
	printf("Samples : ");
	int a[10];

	for (int i = 0; i < 10; i++)
	{
		a[i] =  rand() % 10;
		printf("%d\n", a[i]);
	}

	/** Generate random Input samples **/
	for (int i = 0; i < numChocolate; i++)
	{
		*(samples+i) = randint(numChocolate);
		printf(" %d ", *(samples+i));
	}
	printf("\n");

	/** calculate the rating for each chocolate and remember the minimum cost **/

	free(samples);

		
}



