/* 
 * coins_dp_opt.c
 * solve problem of euler31 with DP optimized space consumption
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int values[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int ways_to_change(int, int);

int main()
{
	const int sum = 200;
	printf("Total ways of making change is %d\n", ways_to_change(200, 8));
	return EXIT_SUCCESS; 
}

/* 
 * Function: ways_to_change
 *
 * computes number of ways to change for a certain amount of pence
 * by using certain kinds of coins.
 *
 * store results in a vector, this time only store those essentials:
 *     in each for loop of certain kinds k, vector[p] is number of 
 *     solutions for ways_to_change(k, p)
 * 
 * pence: amount of pence to be made change
 * kinds: how many kinds of coins
 * returns: number of ways to change
 */
int ways_to_change(int pence, int kinds)
{
	int vector[pence + 1];

	memset(vector, 0, sizeof vector);
	vector[0] = 1;

	for (int i = 0; i < kinds; ++i)
	{
		for (int j = values[i]; j < pence + 1; ++j)
		{
			/* add solutions for the new kind,
			 * which is already updated, 
			 * starting from vector[value[i]]
			 */
			vector[j] += vector[j - values[i]];
		}
	}
	return vector[pence];	
}
