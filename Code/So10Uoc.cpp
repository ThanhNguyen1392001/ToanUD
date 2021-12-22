#include <stdio.h>
#include <conio.h> 

bool so10Uoc(int n) {
	int tich = 1;
	for(int i = 2; i <= n; i++){
        int mu = 0;
        while(n % i == 0){
            ++mu;
            n /= i;
        }
        tich *= (mu+1);
    }
    return tich == 10;
}

int main() {
	int n = 1;
	bool check =false;
	while (!check) {
		if(so10Uoc(n)) {
			printf("So co 10 uoc nho nhat: %d ",n);
			check = true;
		}
		n++;
	}
}
