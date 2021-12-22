#include <iostream>
#include <math.h>

using namespace std;
class norm
{
public:
    static int ferobinus_norm(int A[3][3], int n, int m)
    {
        int x = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x += A[i][j]*A[i][j];
            }
        }
        return x;
    
    }
    static int norm_one(int A[3][3], int n, int m)
    {
        int max = INT_MIN;
        int x = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                x += A[i][j];
            }
            if (x > max)
            {
                max = x;
            }
            x = 0;
        }

        return max;
    }
    static int norm_vo_cung(int A[3][3], int n, int m)
    {
        int max = INT_MIN;
        int x = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x += A[i][j];
            }
            if (x > max)
            {
                max = x;
            }
            x = 0;
        }
        return max;
    }
};
int main()
{
    int A[3][3] = {2, 3, 4, 5, 4, 5, 2, 1, 4};
    cout << norm::ferobinus_norm(A, 3,3) << endl;
    cout << norm::norm_one(A, 3,3) << endl;
    cout << norm::norm_vo_cung(A, 3,3) << endl;
}