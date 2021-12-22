#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
//FIND CLOSEST PAIR OF POINTS O(nlog(n))
/*
    Input: n điểm bất kỳ trong không gian
    Output: khoảng cách ngắn nhất giữa 2 điểm và cho biết tọa đổ 2 điểm đó
    Yêu cầu: độ phức tạp ( n log n)
*/
/*
    Thuat toan su dung de quy chia khong gian duoc sap xep theo toa do X, thanh 2 phan right & left, 
    Tim khoang cach nho nhat dmin, 
    Tim cac diem o giua cach mid 1 khoang < dmin

*/
struct Point
{
    double x, y;
};

// sort by x
inline int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// sort by y
inline int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

inline double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(Point P[], int n, Point &p1, Point &p2)
{
    double min = __DBL_MAX__;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
            {
                min = dist(P[i], P[j]);
                p1.x = P[i].x, p1.y = P[i].y;
                p2.x = P[j].x, p2.y = P[j].y;
            }
    return min;
}

inline double min(double x, double y)
{
    return (x < y) ? x : y;
}

double stripPoints(Point strip[], int size, double d, Point &p1, Point &p2)
{
    double min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
            {
                min = dist(strip[i], strip[j]);
                p1.x = strip[i].x, p1.y = strip[i].y;
                p2.x = strip[j].x, p2.y = strip[j].y;
            }

    return min;
}

double closest(Point P[], Point strip[], int n, Point &p1, Point &p2)
{
    static Point ptemp1, ptemp2, ptemp3, ptemp4;

    if (n <= 3)
        return bruteForce(P, n, ptemp1, ptemp2);

    int mid = n / 2;
    Point midPoint = P[mid];

    double dl = closest(P, strip, mid, ptemp1, ptemp2);
    double dr = closest(P + mid, strip, n - mid, ptemp3, ptemp4);

    if (dl < dr)
    {
        p1.x = ptemp1.x;
        p1.y = ptemp1.y;
        p2.x = ptemp2.x;
        p2.y = ptemp2.y;
    }
    else
    {
        p1.x = ptemp3.x;
        p1.y = ptemp3.y;
        p2.x = ptemp4.x;
        p2.y = ptemp4.y;
    }

    double dmin = min(dl, dr);

    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < dmin)
            strip[j++] = P[i];

    double dmin_strip = stripPoints(strip, j, dmin, ptemp1, ptemp2);
    double final_min = dmin;
    if (dmin_strip < dmin)
    {
        p1.x = ptemp1.x;
        p1.y = ptemp1.y;
        p2.x = ptemp2.x;
        p2.y = ptemp2.y;
        final_min = dmin_strip;
    }
    return final_min;
}

int main()
{

    // Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    Point P[] = {{0,0}, {-2,0}, {4,0}, {1,1}, {3,3}, {-2,2}, {5,2}};
    Point p1 = {__DBL_MAX__, __DBL_MAX__}, p2 = {__DBL_MAX__, __DBL_MAX__};

    int n = sizeof(P) / sizeof(P[0]);
    qsort(P, n, sizeof(Point), compareX);

    Point *strip = new Point[n];

    cout << "The closest distance is " << closest(P, strip, n, p1, p2) << endl;
    cout << "Between (" << p1.x << "," << p1.y << ") and ("
         << p2.x << "," << p2.y << ")" << endl;

    delete[] strip;

    return 0;
}