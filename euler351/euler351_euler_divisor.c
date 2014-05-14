/*
 * euler351_euler_divisor.c
 * solve problem of euler351 with bruteforce euler function
 * by dynamically construct values of euler function
 * note: this solution is fast
 *       and it is based on divisor sum of euler function
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* macro must be used for Mac OS X */
#define SIZE_N (100000000)
#define SIZE (50000001)
int euler[SIZE];

int main(){
  clock_t start, end;
  long sum = 0;

  start = clock();
  for(int i = 1; i < SIZE; ++i){
    euler[i] = i;
  }
  for(int i = 1; i < SIZE; ++i){
    sum += (SIZE_N/i - 1)*euler[i];
    /*
     * Euler divisor sum:
     * n = sum of euler(d) for d in divisors of n
     * deduct euler(i) for multiples of i
     */
    for(int j = i*2; j < SIZE; j += i){
      euler[j] -= euler[i];
    }
  }
  sum *= 6;
  end = clock();

  printf("Total number of points is %ld,\n", sum);
  printf("Elasped time: %10.3f seconds.\n", (end-start)*1.0/CLOCKS_PER_SEC );
  return EXIT_SUCCESS;
}
