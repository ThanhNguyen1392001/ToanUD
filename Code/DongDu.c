#include <stdio.h>

int mod(int a, int m, int n) {
    if (m == 0) return 1;
    if (m == 1) return a%n;
    m % 2 == 0 ? mod(a,m/2,n) * mod(a,m/2,n) : mod(a,m-1,n) * mod(a,1,n);
}


int main() {
    printf("3^2 mod 5 %d", mod(3,2,5));
}

