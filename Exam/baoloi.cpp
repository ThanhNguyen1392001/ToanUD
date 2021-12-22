#include <iostream>
#define N 500
using namespace std;
typedef struct 
{
	double x;
	double y;
} point;

double dinhthuc(point &p, point &q, point &r) 
{
	double d1, d2;
	d1 = q.x * r.y + p.x * q.y + p.y * r.x;
	d2 = q.x * p.y + p.x * r.y + r.x * q.y;
	return d1 - d2;
}

void baoloi(point *a, const int &n)
{
	int i,j,j1,j2,n2;
	point tg,Lup[N],Llow[N];
	cout<<"\nDiem dau vao : \n";
	for(i=1;i <= n;i++) cout<<"("<<a[i].x <<","<<a[i].y <<") \t";cout<<endl;
	for( i=1; i<= n-1;i++)
	for( j= n-1; j>= i; j--)
	if ( (a[j].x > a[j+1].x) || ((a[j].x == a[j+1].x) && (a[j].y > a[j+1].y)))
	{
		tg = a[j];
		a[j] = a[j+1];
		a[j+1] = tg;
	}
	Lup[1] = a[1];
	Lup[2] = a[2];
	j1 =2;
	for( i = 3 ;i <= n; i++){
		j1++;
		Lup[j1] = a[i];
		while ((j1>2) && (dinhthuc(Lup[j1-2], Lup[j1-1], Lup[j1]) > -0.0001))
		{
			Lup[j1-1] = Lup[j1];
			j1--;
		}
	}
	Llow[1] = a[n];
	Llow[2] = a[n-1];
	j2= 2;
	for(i= n-2; i>=1 ;i--) {
		j2++;
		Llow[j2] = a[i];
		while((j2>2) && (dinhthuc(Llow[j2-2],Llow[j2-1],Llow[j2]) > -0.0001))
		{
			Llow[j2 -1] = Llow[j2];
			j2--;
		}
	}
	for(i=1; i<= j2 -2; i++) Lup[j1 + i] = Llow[i +1];
	n2 = j1 + j2 -2;
	cout<< "\nVecto bao loi\n";
	for(i=1; i<=n2;i++) 
		cout<< "(" << Lup[i].x << "," << Lup[i].y << ")\t";
	cout<<endl;
}
int main () {
	int n;
	cout<< "Nhap so diem = "; cin>>n;
	point a[N];
	for(int i=1 ; i<= n ; i++) {
		cout<<"Nhap diem thu " << i << endl;
		cin >>  a[i].x >>a[i].y;
	}
	baoloi(a,n); system("pause");
	return 0;
}
