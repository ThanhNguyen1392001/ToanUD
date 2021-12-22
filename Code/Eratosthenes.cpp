#include <stdio.h>

int prime(int n);

void sieveOfEratosthenes(int n);

int main()

{

    int n = 20;

    sieveOfEratosthenes(n);

    return 0;

}

void sieveOfEratosthenes(int n)

{

    int a_prime[n];

    for (int i =0; i<n; i++) {

        a_prime[i] = 0;

    }

    for (int i = 2; i*i<=n; i++) {

        if (a_prime[i]==0) {

            for (int j = i*2; j<=n; j+=i) {

               a_prime[j] = 1;

            }

        }

    }

    for (int i=2; i<=n; i++) {

        if (a_prime[i]==0) {

            printf("%d ",i);

        }

    }

}

int prime(int n)

{

    for (int i =2; i*i<n; i++) {

        if (n%i ==0) {

            return 0;

        }

    }

    return 1;

}
