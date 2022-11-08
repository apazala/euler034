#include <stdio.h>

int digfactorials[10];
int solutionsSum;

void depth_search(int ndig, int num, int sumDigFact)
{
    if(ndig == 0){
        if(num==sumDigFact){
            printf("%d\n", num);
            solutionsSum+=num;
        }
            
        return;
    }

    num = num*10;
    ndig--;
    for(int d = (num==0); d <= 9; d++){
        depth_search(ndig, num + d, sumDigFact + digfactorials[d]);
    }
}

void init()
{
    digfactorials[0] = 1;
    digfactorials[1] = 1;
    for(int i = 2; i <= 9; i++){
        digfactorials[i] = digfactorials[i-1]*i;
    }
}

int main()
{
    init();


    for(int ndig = 2; ndig < 8; ndig++)
    {
        depth_search(ndig, 0, 0);
    }

    printf("%d\n", solutionsSum);

    /* Snippet to check maximum digits to consider: with 8 digits 10^7>8*9! */
    /*
    int minNum = 1;
    int maxFactorial;
    for(int ndig = 1; ndig <= 8; ndig++){
        maxFactorial = digfactorials[9]*ndig;
        printf("ndig: %d. minNum: %10d. maxFactorial: %10d\n", ndig, minNum, maxFactorial);
        minNum *= 10;
    }
    */

}