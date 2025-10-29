#include <iostream>
#include <cmath>
using namespace std;

const double Phi = 3.1416;

// a) Distance antara dua titik (x1,y1) dan (x2,y2)
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// b) Radius untuk panggil distance antara pusat (xc,yc) dan titik pada lingkaran (xp,yp)
double radius(double xc, double yc, double xp, double yp)
{
    return distance(xc, yc, xp, yp);
}

// c) Keliling (circumference) = 2πr
double circumference(double r)
{
    return 2.0 * Phi * r;
}

// d) Luas (area) = πr^2
double area(double r)
{
    return Phi * r * r;
}

int main()
{
    // Input satu persatu
    double x1, y1, x2, y2;

    cout << "Masukkan x1 (pusat): ";
    cin >> x1;
    cout << "Masukkan y1 (pusat): ";
    cin >> y1;
    cout << "Masukkan x2 (titik pada lingkaran): ";
    cin >> x2;
    cout << "Masukkan y2 (titik pada lingkaran): ";
    cin >> y2;

    // Hitung radius dari pusat ke titik pada lingkaran
    double r = radius(x1, y1, x2, y2);

    // Output
    cout << "Radius = " << r << '\n';
    cout << "Diameter = " << 2.0 * r << '\n';
    cout << "Circumference = " << circumference(r) << '\n';
    cout << "Area = " << area(r) << '\n';

    return 0;
}