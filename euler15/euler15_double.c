/* 
 * euler_15_float.c
 * calculate C(2n, n)
 * @author: mintBreeze
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double calc_paths(int);

int main() 
{
    int lattice;
    long double res;
    
    printf("Enter size of the lattice:\n");
    scanf("%d", &lattice);
    res = calc_paths(lattice);
    if (res){
        printf("Total number of paths is %Lg\n", res);
    }
    else
        printf("Oversize or negative size.\n");
    return EXIT_SUCCESS;   
}

long double calc_paths(int lat)
{
    long double sum1 = 1;
    long double sum2 = 1;
    long double sum; 
        
    if (0 >= lat || lat > 20)
        return 0;
    if ( lat == 1)
        return 2;
    for(int i = 1; i <= lat; ++i){
        sum1 *= i;
        sum2 *= i + lat;
    }
    dbg_print((" sum1:%Lg; sum2:%Lg;\n ", sum1, sum2));
    
    sum = sum2/sum1;   
    return sum;
}

