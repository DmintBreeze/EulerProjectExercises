/*
 * euler70_divisor_map.c
 * solve problem of euler70 with euler's dividor sum
 * problem 70: Find the value of n, 1 < n < 10^7,
 *             for which φ(n) is a permutation of n
 *             and the ratio n/φ(n) produces a minimum.
 * answer: 8319823
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000
int euler[SIZE];

int is_permutation(int, int);

int main()
{
  clock_t start, end;
  float min = SIZE;
  int result;
  start = clock();

  for(int i = 2; i < SIZE; ++i){
    euler[i] = i - 1;
  }

  for(int i = 2; i < SIZE; ++i){
    int phi = euler[i];
    if(is_permutation(i, phi) && i*1.0/phi < min){
      min = i*1.0/phi;
      result = i;
    }
    for(int j = 2*i; j < SIZE; j += i){
      euler[j] -= euler[i];
    }
  }
  end = clock();
  printf("Result is %d\nRatio is %10.3f\n", result, min);
  printf("Elasped time: %10.3f seconds.\n", (end-start)*1.0/CLOCKS_PER_SEC );
  return EXIT_SUCCESS;
}




/*
 * Function: is_permutation
 * check whether phi is a permutation of n
 * returns: 1 if it is. 0 if not.
 */
int is_permutation(int n, int phi)
{
  int map_n[10] = {0}, map_phi[10] = {0};
  while(n){
    map_n[n % 10]++;
    n /= 10;
  }
  while(phi){
    map_phi[phi % 10]++;
    phi /= 10;
  }
  for(int i = 0; i<10; ++i){
    if (map_n[i] != map_phi[i])
      return 0;
  }
  return 1;
}
