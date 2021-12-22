#include <iostream>
#include <cmath>
using namespace std;

void inputMatrix(float A[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}
void outputMatrix(float A[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void L(float A[][100], int n)
{
    float B[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                float sum = 0;
                for (int k = 0; k < j - 1; k++)
                {
                    sum+=pow(B[i][k], 2);
                }
                B[i][j] = sqrt(A[i][j]-sum);
            }
            else{
                float sum = 0;
                for(int k = 0;  k< j-1; k++){
                    sum+=B[i][k] * B[j][k];
                }
                B[i][j] = (1.0/B[j][j])*(A[i][j]-sum);
            } 
        }
    }
    outputMatrix(B, n);
}
bool checkIfSymmetricMatrix(float A[][100], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(A[i][j] != A[j][i]) return false;
        }
    }
    return true;
}
bool checkIfSquareMatrix(float A[][100], int n){
    for(int i =0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(A[i][j] == 0) count++;
        }
        if(count==n) return false;
    }
    return true;
}
int main()
{   int n;
    float A[100][100];
    while (true)
    {
            cout << "Input n: ";
            cin >> n;
            cout << "Input the matrix: " << endl;
            inputMatrix(A, n);
            if(checkIfSquareMatrix(A, n) && checkIfSymmetricMatrix(A,n)){
                break;
            }
            else if(!checkIfSquareMatrix(A,n)){
                cout << "PLEASE INPUT THE SQUARE MATRIX" << endl;
            }
            else if(!checkIfSymmetricMatrix(A,n)){
                cout << "PLEASE INPUT THE SYMMETRIC MATRIX" << endl;
            }
            //Kiem tra ma tran xac dinh duong
    }
    
    cout << "Inputed matrix:" << endl;
    outputMatrix(A, n);
    cout << "Ma tran L:" << endl;
    L(A, n);

    return 0;
}