#include<stdio.h>
bool check(int n){
int sum = 0;
for(int i=1;i<=n/2;i++){
if(n%i==0)
sum+=i;
}
if(sum==n) return true;
return false;
}	
int main(){
int n;
printf("Nhap n: ");
scanf("%d",&n);
int i;
for(i=1;i<=n;i++) {
if(check(i)) printf("%d\n",i);
}
return 0;
}
