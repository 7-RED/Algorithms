#include <stdio.h>
#include <stdlib.h>


int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int weight[], int p[], int pw)
{
    if (pw == 0 || W == 0)
        return 0;
    if (weight[pw - 1] > W)
        return knapSack(W, weight, p, pw - 1);

    else
        return max(
            p[pw - 1]
                + knapSack(W - weight[pw - 1],
                           weight, p, pw - 1),
            knapSack(W, weight, p, pw - 1));
}


int main()
{
    int p[] = { 20, 30, 35, 12, 3 };
    int weight[] = { 2, 5, 7, 3, 1 };
    int W = 9;
    int pw = sizeof(p) / sizeof(p[0]);
    printf("%d", knapSack(W, weight, p, pw));
    return 0;
}