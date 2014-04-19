/* 
 * euler_15_naive.c
 * calculate C(2n, n)
 * @author: mintBreeze
 * @note: this file is put here just to show how BAD it is
 *        to compute combinatorial numbers naively.
 *        unsigned long long can not even hold C(40, 20)
 *        ignore those dummy ifelses...
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG

#ifdef DEBUG
#define dbg_print(x) printf x
#else
#define dbg_print(x) do {} while (0)
#endif

unsigned long long calc_paths(int);
int devide_by_2 (int*);
int devide_by_3 (int*);
int devide_by_5 (int*);

int main() 
{
    int lattice;
    unsigned long long res;
    
    printf("Enter size of the lattice:\n");
    scanf("%d", &lattice);
    res = calc_paths(lattice);
    if (res){
        printf("Total number of paths is %llu\n", res);
    }
    else
        printf("Oversize or negative size.\n");
    return EXIT_SUCCESS;   
}

unsigned long long calc_paths(int lat)
{
    unsigned long long sum1 = 1;
    unsigned long long sum2 = 1;
    unsigned long long sum; 
    int counter2_1 = 0;
    int counter2_2 = 0;
    int counter3_1 = 0;
    int counter3_2 = 0;
    int counter5_1 = 0;
    int counter5_2 = 0;    
    double  dup2, dup3, dup5, dup7;

    if (0 >= lat || lat > 20)
        return 0;
    if ( lat == 1)
        return 2;
    for(int i = 1; i <= lat; ++i){
        if(i % 2 == 0){
            int tmp = i;
            counter2_1 += devide_by_2(&tmp);
            sum1 *= tmp;
        }
        else if (i % 3 == 0){
            int tmp = i;
            counter3_1 += devide_by_3(&tmp);
            sum1 *= tmp;
        }
        else if (i % 5 == 0){
            int tmp = i;
            counter5_1 += devide_by_5(&tmp);
            sum1 *= tmp;
        }
        else {
            sum1 *= i;
        }
        if( (i + lat) % 2 == 0 ){
            int tmp = i + lat;
            counter2_2 += devide_by_2(&tmp);
            sum2 *= tmp;        
        }
        else if ((i + lat) % 3 == 0) {
            int tmp = i + lat;
            counter3_2 += devide_by_3(&tmp);
            sum2 *= tmp;
        }
        else if ((i + lat) % 5 == 0) {
            int tmp = i + lat;
            counter5_2 += devide_by_5(&tmp);
            sum2 *= tmp;
        }
        else {
            sum2 *= i + lat;
        }
    }
    dup2 = pow(2.0, (double)(counter2_2 - counter2_1));
    dup3 = pow(3.0, (double)(counter3_2 - counter3_1));
    dup5 = pow(5.0, (double)(counter5_2 - counter5_1));
    //dup7 = pow(7.0, (double)(counter7_2 - counter7_1));
    
    sum = (dup2*dup3*dup5*sum2)/sum1;
    dbg_print(("dup2:%g\n", dup2));
    dbg_print(("dup3:%g\n", dup3));
    dbg_print(("dup5:%g\n", dup5));  
    //dbg_print(("dup7:%g\n", dup7));
    
    return sum;
}

int devide_by_2 (int* pn)
{
    int count = 0;
    while(*pn % 2 == 0){
        count++;
        (*pn) >>= 1;
    }
    return count;
}

int devide_by_3 (int* pn)
{
    int count = 0;
    while(*pn % 3 == 0){
        count++;
        (*pn) /= 3;
    }
    return count;
}

int devide_by_5 (int* pn)
{
    int count = 0;
    while(*pn % 5 == 0){
        count++;
        (*pn) /= 5;
    }
    return count;
}

