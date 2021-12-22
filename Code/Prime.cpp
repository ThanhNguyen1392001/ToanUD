

#include <stdio.h>

#define MAX 100

typedef int VECTOR[MAX];

void PrimeFactors(int n, VECTOR S, int &k);

int main()

{

    int  k;

    int F[MAX];

    int n =30;

    PrimeFactors(n, F, k);

    for (int i = 0; i<=k; i++)

        printf("%d ", F[i]);

    return 0;

}

void PrimeFactors(int n, VECTOR S, int &k)

{

    k = 0;

    S[k] = n;

    for (int i=2; i*i<=n; i++){

        while (n%i==0){

            k++;

            S[k] = i;

            n = n/i;

        }      

    }

    if (n>1) S[++k]=n;

}
