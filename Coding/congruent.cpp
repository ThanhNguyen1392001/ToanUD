#include<iostream>
#include<cmath>
using namespace std;
int modPrimePow(long a, long b, int m){
    long ret = 1;
    a %= m;
    b %= m;
    while (b > 0) //vòng lặp phân tích b thành cơ số 2
    {
        if (b % 2 > 0)  //ở vị trí có số 1 thì nhân với a^(2^i) tương ứng. Tất cả các phép nhân đều có phép mod p theo sau.
            ret = ret * a % m;
        a = a * a % m;  //tính tiếp a^(2^(i+1)), a^1 -> a^2 -> a^4 -> a^8 -> a^16 v.v...
        b /= 2;
    }
    return (int) ret;
}
int main(){
    long a, b;
    int m;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input m: ";
    cin >> m;
    cout << "a^b(mod m) = " << modPrimePow(a,b,m) << endl;

    int c = pow(a,b);
    cout << c%m<< endl;
    int d =  pow(a%m, b%m);
    cout <<d % m << endl;
}
