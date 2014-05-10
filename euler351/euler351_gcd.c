/*
 * euler351_gcd.c
 * solve problem of euler351 with stem gcd
 * note: this solution is extremly costful
 *       and only used for testing input of 1000
 *       the result of which is 1177848
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

long gcd(long a, long b);
long euler(long);

int main(){
  const long size = 1000;
  long sum = 0;
  for(int i = 1; i< size; ++i){
    sum += (size/i - 1)*euler(i)*6;
  }
  printf("Total number of points is %ld\n", sum);
  return EXIT_SUCCESS;
}


/*
 * Function: euler
 * Get number of lines start from center and
 * are composed by points on edges of concentric hexagons.
 * i.e. find result of euler function of a given number.
 * @returns result of euler function on rational.
 */
long euler(long rational){
  long count = rational - 1;
  if(rational == 1) return 1;
  for(long factor = 2; factor < rational; ++factor){
    if(gcd(rational, factor) != 1){
      count--;
    }
  }
  return count;
}

/*
 * Function: gcd
 * Calculate gcd with stem method.
 */
long gcd(long a, long b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), MIN(a, b));
}
