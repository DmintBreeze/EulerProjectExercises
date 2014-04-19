/* 
 * coins_recursive.c
 * solve problem of euler31 recursively
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
 * pence: amount of pence to be made change
 * kinds: how many kinds of coins to be used as change
 * returns: number of ways to change
 */
int ways_to_change(int pence, int kinds)
{
	if ( pence < 0 || kinds < 0)
		return 0;
	if ( pence == 0 )
		return 1;
	return ( ways_to_change( pence, kinds - 1) 
		+ ways_to_change( pence - values[kinds], kinds) );
}
