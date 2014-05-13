/*
 * euler351_euler_bruteforce.c
 * solve problem of euler351 with bruteforce euler function
 * note: this solution is costful,
 *       but much faster than euler351_gcd.c
 *       result is somewhat tolerable,
 *       still it takes minutes.
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int euler(int);

int main(){
  clock_t start, end;
  const long size = 100000000;
  long sum = 0;
  start = clock();
  for(int i = 1; i< size; ++i){
    sum += (size/i - 1)*euler(i);
  }
  sum *= 6;
  end = clock();

  printf("Total number of points is %ld,\n", sum);
  printf("Elasped time: %10.3f seconds.\n", (end-start)*1.0/CLOCKS_PER_SEC );
  return EXIT_SUCCESS;
}


/*
 * Function: euler
 * Get number of lines start from center and
 * are composed by points on edges of concentric hexagons.
 * i.e. find result of euler function of a given number.
 *
 */
int euler(int input){
  int rational = input;
  int count = rational;
  for(int i = 2; i*i < rational+1; ++i){
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
