#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Vector3D.h"

using namespace mygeom;
using namespace std;

const bool baccab_start = false;
const int baccab_count = 3;
const int baccab_max = 100;

const bool tripprod_start = false;
const int tripprod_count = 3;
const int tripprod_max = 100;

const bool costh_start = true;
const int costh_count = 3;
const int costh_max = 100;

// [a, [b, c]] == b (a, c) - c (a, b) formula test
void baccab_test ()
{
    cout << "Starting baccab vector test:" << endl;
    Vector3D a, b, c, v1, v2;
    for (int i = 0; i < baccab_count; i++)
    {
        cout << "baccab i = " << i << ":" << endl;
        a = Vector3D (rand() % baccab_max, rand() % baccab_max, rand() % baccab_max);
        b = Vector3D (rand() % baccab_max, rand() % baccab_max, rand() % baccab_max);
        c = Vector3D (rand() % baccab_max, rand() % baccab_max, rand() % baccab_max);
        v1 = vecprod (a, vecprod (b, c));
        v2 = b * dotprod (a, c) - c * dotprod (a, b);
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
        cout << "[a, [b, c]]: x = " << v1.x_ << ", y = " << v1.y_ << ", z = " << v1.z_ << endl;
        cout << "b (a, c) - c (a, b): x = " << v2.x_ << ", y = " << v2.y_ << ", z = " << v2.z_ << endl;
        cout << "[a, [b, c]] == b (a, c) - c (a, b): " << (v1 == v2) << endl << endl;
    }
}

// (a, [b, c]) == (a, b, c) formula test
void trprod_test ()
{
    cout << "Starting tripprod vector test:" << endl;
    Vector3D a, b, c;
    double v1, v2;

    for (int i = 0; i < tripprod_count; i++)
    {
        cout << "tripprod i = " << i << ":" << endl;
        a = Vector3D (rand() % tripprod_max, rand() % tripprod_max, rand() % tripprod_max);
        b = Vector3D (rand() % tripprod_max, rand() % tripprod_max, rand() % tripprod_max);
        c = Vector3D (rand() % tripprod_max, rand() % tripprod_max, rand() % tripprod_max);
        v1 = tripprod (a, b, c);
        v2 = dotprod (a, vecprod (b, c));
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
        cout << "(a, b, c) = " << v1 << endl;
        cout << "(a, [b, c]) = " << v2 << endl;
        cout << "(a, b, c) == (a, [b, c]): " << (v1 == v2) << endl << endl;
    }
}

// cos theorem formula test
void costh_test ()
{
    cout << "Starting cos theorem vector test:" << endl;
    Vector3D a, b;
    double k1, k2;
    for (int i = 0; i < costh_count; i++)
    {
        cout << "costh i = " << i << ":" << endl;
        a = Vector3D (rand() % costh_max, rand() % costh_max, rand() % costh_max);
        b = Vector3D (rand() % costh_max, rand() % costh_max, rand() % costh_max);
        k1 = rand() % costh_max, k2 = rand() % costh_max;
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "k1 = " << k1 << ", k2 = " << k2 << endl;
        cout << "cos(phi) = " << dotprod (a, b) / (abs(a) * b.abs()) << endl;
        cout << "|k1 * a + k2 * b| = " << (k1 * a + k2 * b).abs() << endl;
        cout << "|k1 * a + k2 * b| = " << sqrt(k1 * k1 * a.sqr() + k2 * k2 * dotprod (b, b) + 2 * k1 * k2 * dotprod (a, b)) << endl << endl;
    }
}

int main ()
{
    srand (time (NULL));
    if (baccab_start)
        baccab_test ();
    if (tripprod_start)
        trprod_test ();
    if (costh_start)
        costh_test ();
}