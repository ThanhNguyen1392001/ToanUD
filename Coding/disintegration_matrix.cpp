#include <cmath>
#include <iostream>
using namespace std;
void inputMatrix(float A[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}
void outputMatrix(float A[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
float *triRieng(float A[2][2])
{
    static float B[2];
    float a = 1;
    float b = -A[0][0] - A[1][1];
    float c = A[0][0] * A[1][1] - A[1][0] * A[0][1];
    float delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        B[0] = ((-b + sqrt(delta)) / (2 * a));
        B[0] = roundf(B[0] * 100) / 100;
        B[1] = ((-b - sqrt(delta)) / (2 * a));
        B[1] = roundf(B[1] * 100) / 100;
    }
    else if (delta == 0)
    {
        B[0] = -b / 2 * a;
        B[1] = 0;
    }
    else
    {
        B[0] = B[1] = 0;
    }
    return B;
}
float *vectoRieng(float A[2][2], float x)
{
    static float B[2];
    B[1] = (A[0][0] - x - A[1][0]) / (A[1][1] - x - A[0][1]);
    B[0] = 1;
    return B;
}
float delta(float A[2][2], int n)
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
float adjuct_matrix(float A[2][2], int h, int c)
{
    float B[2][2];

    int i, j, x = -1, y;
    for (i = 0; i < 2; i++)
    {
        if (i == h)
            continue;
        x++;
        y = -1;
        for (j = 0; j < 2; j++)
        {
            if (j == c)
                continue;
            y++;
            B[x][y] = A[i][j];
        }
    }
    if ((h + c) % 2 == 0)
        return delta(B, 2 - 1);
    return -delta(B, 2 - 1);
}
void phanRaMaTran(float A[2][2], float B[2][2])
{
    //ABA^-1
    float D[2][2] = {A[0][0]*B[0][0], A[0][1]*B[1][1], A[1][0]*B[0][0], A[1][1]*B[1][1]};
    float C[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = adjuct_matrix(A, i, j);
        }
    }
    for (int i = 0; i < 2 - 1; i++)
        for (int j = i + 1; j < 2; j++)
        {
            float t = C[i][j];
            C[i][j] = C[j][i];
            C[j][i] = t;
        }
    float k = delta(A, 2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] /= k;
    float result[2][2];
    cout << "Ma tran phan ra: " << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k)
                result[i][j] = result[i][j] + (D[i][k] * C[k][j]);
            printf("%f ", result[i][j]);
        }

        printf("\n");
    }
}
int main()
{
    //float A[2][2] = {0.96, 0.01, 0.04, 0.99};
    float A[2][2] = {1, 2, 3, 4};
    float *tR;
    tR = triRieng(A);
    cout << "Cac tri rieng la: " << endl;
    cout << tR[0] << endl;
    cout << tR[1] << endl;
    cout << "Cac vecto rieng la: " << endl;
    float *vectoRieng1;
    vectoRieng1 = vectoRieng(A, tR[0]);
    float x1 = vectoRieng1[0];
    float x2 = vectoRieng1[1];
    cout << vectoRieng1[0] << ", " << vectoRieng1[1] << endl;
    float *vectoRieng2;
    vectoRieng2 = vectoRieng(A, tR[1]);
    cout << vectoRieng2[0] << ", " << vectoRieng2[1] << endl;

    float mtV[2][2] = {x1, vectoRieng2[0], x2, vectoRieng2[1]};
    cout << "Ma Tran V: " << endl;
    outputMatrix(mtV);
    float diag[2][2] = {tR[0], 0, 0, tR[1]};
    cout << "Ma Tran Duong Cheo" << endl;
    outputMatrix(diag);

    phanRaMaTran(mtV, diag);
    return 0;
}