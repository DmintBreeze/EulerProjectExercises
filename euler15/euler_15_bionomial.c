/* 
 * euler_15_bionomial.c
 * calculate C(2n, n) by factorial formula
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int size = 20;
    long paths = 1;
    for (int i = 0; i < size; i++) {
        paths *= (2 * size) - i;
        /* paths is assured integer
         * as it is C(i, 2n)
         */
        paths /= i + 1;  
    }
    printf("Total number of path is:%ld\n", paths);
    return EXIT_SUCCESS;
}

