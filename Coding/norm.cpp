#include<iostream>
#include<math.h>

using namespace std;
class norm
{
    public:
    static float norm_p(int A[], int n, int p){
        int x = 0;
        for(int i = 0; i< n; i++){
            x += pow(A[i], p);
        }
        return pow(x, pow(p,-1));
    }
    static float norm_two(int A[], int n){
        int x = 0;
        for(int i = 0; i< n; i++){
            x += A[i]*A[i];
        }
        
        return pow(x, 0.5);
    }
    static int norm_one(int A[], int n){
        int x = 0;
         for(int i = 0; i< n; i++){
            x += A[i];
        }
        return x;
    }
    static int norm_vo_cung(int A[], int n){
        int x = INT_MIN;
         for(int i = 0; i< n; i++){
            if(x<A[i]) x = A[i];
        }
        return x;
    }
};
int main(){
    int A[] = {2,3,4,5};
    cout << norm::norm_one(A, 4) << endl;
    cout << norm::norm_two(A, 4) << endl;
    cout << norm::norm_p(A, 4, 3) << endl;
    cout << norm::norm_vo_cung(A, 4) << endl;
}