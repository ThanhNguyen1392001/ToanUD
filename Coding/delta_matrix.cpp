#include <iostream>
using namespace std;

void inputMatrix(int A[][100], int n)
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
void outputMatrix(int A[][100], int n)
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
int delta(int A[][100], int n)
{
    int i, j, k, dem = 0, kt;
    int B[100], h, det = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (A[i][i] == 0)
        {
            kt = 0;
            for (j = 0; j < n; j++)
                if (A[i][j] != 0)
                {
                    for (k = 0; k < n; k++)
                    { // Doi cot j voi cot i
                        int temp = A[k][i];
                        A[k][i] = A[k][j];
                        A[k][j] = temp;
                    }
                    dem++; // dem so lan doi cot
                    kt++;  // Kiem tra xem co so 0 o dong i cot j
                    break;
                }
        }
        if (kt == 0)
            return 0;
        B[i] = A[i][i];
        for (j = 0; j < n; j++)
            A[i][j] = A[i][j] / B[i]; //tao so 1 o dong i,cot i
        for (j = i + 1; j < n; j++)
        {
            h = A[j][i];
            for (k = 0; k < n; k++)
                A[j][k] = A[j][k] - h * A[i][k]; //lay dong thu j-h*dong i
        }
    }
    B[n - 1] = A[n - 1][n - 1];
    for (i = 0; i < n; i++)
        det = det * B[i]; // Nhan cac so da lay ra ngoai dinh thuc
    if (dem % 2 == 0)
        return det;
    else
        return -det;
}
int main()
{
    int A[100][100];
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << "Input the matrix: " << endl;
    inputMatrix(A, n);
    cout << "Inputed matrix:" << endl;
    outputMatrix(A, n);
    cout << "Delta of matrix: " << delta(A, n) << endl;
    return 0;
}