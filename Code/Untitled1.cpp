#include <stdio.h>

int timSoUoc(int n) {
	int count = 0;
	for (int i = 1 ; i <= n; i++) {
		if(n % i == 0) count++;
	}
	return count;
}

int tongCacUoc(int n) {
	int sum = 0;
	for (int i = 1 ; i <= n; i++) {
		if(n % i == 0) sum+=i;
	}
	return sum;
}
unsigned long long tichCacUoc(int n) {
	unsigned long long tich = 1;
	for (int i = 1 ; i <= n; i++) {
		if(n % i == 0) tich*=i;
	}
	return tich;
}

int main() {
	int n;
	printf("Nhap n: ");scanf("%d",&n);
	printf("%d co tich cac uoc la: %d",n,tichCacUoc(n));
}


