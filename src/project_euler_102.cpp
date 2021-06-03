#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct point
{
    int x;
    int y;
};

struct triangle
{
    point p1;
    point p2;
    point p3;
};

ifstream& operator>>(ifstream &f, triangle &t)
{
    f >> t.p1.x;
    f.get();
    f >> t.p1.y;
    f.get();
    f >> t.p2.x;
    f.get();
    f >> t.p2.y;
    f.get();
    f >> t.p3.x;
    f.get();
    f >> t.p3.y;
    f.get();

    if (t.p2.x < t.p1.x)
    {
        point temp = t.p1;
        t.p1 = t.p2;
        t.p2 = temp;
    }
    if (t.p3.x < t.p2.x)
    {
        point temp = t.p2;
        t.p2 = t.p3;
        t.p3 = temp;
    }
    if (t.p2.x < t.p1.x)
    {
        point temp = t.p1;
        t.p1 = t.p2;
        t.p2 = temp;
    }
    return f;
}

double area(point p1, point p2, point p3)
{
    struct vector
    {
        int x;
        int y;
    } v1, v2;
    v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;
    v2.x = p3.x - p1.x;
    v2.y = p3.y - p1.y;

    return 0.5 * abs(v1.x * v2.y - v2.x * v1.y);
}

int main()
{
	ifstream file("./data/p102_triangles.txt");
    triangle T[1000];
    int count = 0;

    if (!file.is_open())
    {
        cout << "error opening file\n";
        return 1;
    }
    
    for (int i=0; i<1000; i++)
    {
        file >> T[i];
    }
    for (int i=0; i<1000; i++)
    {
        //cout << "(" << setw(4) << T[i].p1.x << "," << setw(4) << T[i].p1.y << "), " << "(" << setw(4) << T[i].p2.x << "," << setw(4) << T[i].p2.y << "), " << "(" << setw(4) << T[i].p3.x << "," << setw(4) << T[i].p3.y << ")\t";
        point A = T[i].p1;
        point B = T[i].p2;
        point C = T[i].p3;
        point O = {0,0};

        if ((area(A,B,C) - area(A,B,O) - area(A,C,O) - area(B,C,O)) == 0)
            count++;
    }
    cout << count << endl;
    file.close();
}