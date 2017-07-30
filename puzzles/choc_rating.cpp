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
#include <time.h>

#define MIN_SAMPLES 5
#define MAX_SAMPLES 15

/** start with random value and keep increment every time **/
static int random_seed=1203343;

/* Returns an integer in the range [0, n).
 *
 * Uses rand(), and so is affected-by/affects the same seed.
 */
unsigned int randint(unsigned int limit)
{
	/* return a random number between 0 and limit inclusive.
	 *  */

	int i, stime;
	long ltime;
	int divisor = RAND_MAX/(limit+1);
	unsigned int retval;

	/* get the current calendar time */
	ltime = time(NULL);
	stime = (unsigned) ltime/2;

	/** provide new seed to rand everytime **/
	random_seed += 102341 + stime;
	srand(random_seed++);

	do 
	{ 
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

int main()
 {
	int numChocolate = 0;
	int * samples = NULL;
	int selectedSample = -1, minCost = 0, tempCost = 0; 

	/** Take random Max samples with a cap of  MAX_SAMPLES **/
	numChocolate = randint(MAX_SAMPLES);

	if (numChocolate < MIN_SAMPLES)
	{
		numChocolate = MIN_SAMPLES;
	}
	samples = (int *) malloc(numChocolate*sizeof(int));

	do
	{	
		/** malloc check **/
		if (samples == NULL)
		{
			break;
		}

		printf("Samples count  : %d \n", numChocolate);
		printf("Samples rating : ");

		/** Generate random Input samples **/
		for (int i = 0; i < numChocolate; i++)
		{
			*(samples+i) = randint(numChocolate);
			printf(" %d ", *(samples+i));
		}
		printf("\n");

		printf("Cost per samples : ");

		/** calculate the rating for each chocolate and remember the minimum cost **/
		for (int i = 0; i < numChocolate; i++)
		{
			/** Minimum one coin is required for each sample **/
			tempCost = 1;

			/** If the sample is at the begining **/
			if (i == 0)
			{
				if (*(samples+i) > *(samples+i+1))
				{
					tempCost++;
				}
			}
			/** If the sample is at the end **/
			else if (i == numChocolate - 1)
			{
				if (*(samples+i) > *(samples+i-1))
				{
					tempCost++;
				}

			}
			/** We should compare with two neighbours **/
			else
			{
				if (*(samples+i) > *(samples+i-1) || (*(samples+i) > *(samples+i+1)))
				{
					tempCost++;
				}

			}
			printf(" %d ", tempCost);

			/** If we find a sample with cost eq 1 then break. It is the min sample**/
			if (tempCost == 1)
			{
				selectedSample = i;	
				minCost = 1;
				break;
			}
			else
			{
				/** search all samples **/
				if (tempCost < minCost)
				{
					minCost = tempCost;
				}

			}

		}

		printf(" \n ");


		printf ("Result : Buy Sample #%d for cost: %d\n ", selectedSample, minCost);

		free(samples);
	} while (0);

		
}



