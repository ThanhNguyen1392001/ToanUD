#include <iostream>
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
float delta(float A[][100], int n)
{
    int i, j, k, dem = 0, kt;
    float B[100], h, det = 1;
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
                        float temp = A[k][i];
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
float adjuct_matrix(float A[][100], int n, int h, int c)
{
    float B[100][100];
    int i, j, x = -1, y;
    for (i = 0; i < n; i++)
    {
        if (i == h)
            continue;
        x++;
        y = -1;
        for (j = 0; j < n; j++)
        {
            if (j == c)
                continue;
            y++;
            B[x][y] = A[i][j];
        }
    }
    if ((h + c) % 2 == 0)
        return delta(B, n - 1);
    return -delta(B, n - 1);
}
void reverseMatrix(float A[][100], int n)
{
    float b[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = adjuct_matrix(A, n, i, j);
        }
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            float t = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = t;
        }
    float k = delta(A, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] /= k;
    if (k == 0)
        cout << "There's no reverse matrix!" << endl;
    else
        outputMatrix(b, n);
}

int main()
{
    float A[100][100];
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << "Input the matrix: " << endl;
    inputMatrix(A, n);
    cout << "Inputed matrix:" << endl;
    outputMatrix(A, n);
    cout << "Delta of matrix: " << delta(A, n) << endl;
    cout << "Reverse matrix: " << endl;
    float b[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = adjuct_matrix(A, n, i, j);
        }
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            float t = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = t;
        }
    float k = delta(A, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] /= k;
    if (k == 0)
        cout << "There's no reverse matrix!" << endl;
    else
        outputMatrix(b, n);
    return 0;
}