/*
 * euler351_euler_bruteforce.c
 * solve problem of euler351 with stem gcd
 * note: this solution is costful,
 *       but much faster than euler351_gcd.c
 *       result is somewhat tolerable,
 *       still it takes minutes.
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long euler(long);

int main(){
  const unsigned long long size = 100000000;
  unsigned long long sum = 0;
  for(int i = 1; i< size; ++i){
    sum += (size/i - 1)*euler(i)*6;
  }
  printf("Total number of points is %llu\n", sum);
  return EXIT_SUCCESS;
}


/*
 * Function: euler
 * Get number of lines start from center and
 * are composed by points on edges of concentric hexagons.
 * i.e. find result of euler function of a given number.
 *
 */
long euler(long input){
  long rational = input;
  long count = rational;
  for(int i = 2; i < (int)sqrt(rational*1.0)+1; ++i){
    if(rational%i == 0){
      /* deduct all possible count of this factor */
      count = count/i * (i - 1);
      /* eliminate this factor */
      while(rational % i == 0){
        rational/=i;
      }
    }
  }
  if(rational > 1){
    /* rational now is a prim number, the last factor of input */
    count = count/rational * (rational -1);
  }
  return count;
}
