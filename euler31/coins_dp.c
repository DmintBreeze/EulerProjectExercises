/* 
 * coins_recursive.c
 * solve problem of euler31 with Dynamic Programming
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>

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
 * by using certain kinds of coins, which is composite of situations
 * where the last kind is not used, and where it is used at least once.
 *
 * store results in a 2-D table, like playing with LEGO, buiding from
 * bottom to top, and you want the result at the top :)
 * 
 * pence: amount of pence to be made change
 * kinds: how many kinds of coins
 * returns: number of ways to change
 */
int ways_to_change(int pence, int kinds)
{
	int i;
	int lego[pence+1][kinds];

	/* lego[0][kinds] set to 1, only one way to chage 0 peny */
	for (i = 0; i < kinds; ++i)
	{
		lego[0][i] = 1;
	}

	for (i = 1; i < pence+1; ++i)
	{
		for (int j = 0; j < kinds; ++j)
		{
			int x, y;
			/* not including last kind of coins */
			lego[i][j] = j > 0 ? lego[i][j - 1] : 0 ;
			/* inlcuding last kind */
			lego[i][j] += (i >= values[j] )? lego[i - values[j]][j] : 0 ;
		}
	}
	return lego[pence][kinds - 1]; /* index starts at 0 */
}
