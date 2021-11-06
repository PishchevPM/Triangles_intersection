#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Intersection3D.h"

using namespace mygeom;
using namespace std;

const bool parallel_start = false;
const int parallel_count = 500000;
const int parallel_max = 100;
const bool parallel_ignore_true = true;

const bool plane_intersect_start = false;
const int plane_intersect_count = 10;
const int plane_intersect_max = 10;

const bool rand_triangle_intersect_start = false;
const int rand_triangle_intersect_count = 10;
const int rand_triangle_intersect_max = 10;

const bool triangle_intersect_start = true;

// two parallel triangles test
void parallel_test ()
{
    cout << "Starting parallel triangle test:" << endl;
    Vector3D a, b, c, n;
    Triangle3D tr1, tr2;
    for (int i = 0; i < parallel_count; i++)
    {
        a = Vector3D (rand() % parallel_max, rand() % parallel_max, rand() % parallel_max);
        b = Vector3D (rand() % parallel_max, rand() % parallel_max, rand() % parallel_max);
        c = Vector3D (rand() % parallel_max, rand() % parallel_max, rand() % parallel_max);
        n = Vector3D (rand() % parallel_max, rand() % parallel_max, rand() % parallel_max);
        tr1 = Triangle3D (a, b, c);
        if (!tr1.is_true_triangle())
        {
            cout << "parallel i = " << i << ":" << endl;
            cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
            cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
            cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
            cout << "Isn't true triangle (Line segment or point)" << endl << endl;
            continue;
        }
        if (parallel_ignore_true)
            continue;

        tr2 = Triangle3D (a + n, b + n, c + n);
        cout << "parallel i = " << i << ":" << endl;
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
        cout << "n: x = " << n.x_ << ", y = " << n.y_ << ", z = " << n.z_ << endl;
        if (is_parallel(tr1, tr2))
            cout << "{a, b, c} parallel {a + n, b + n, c + n}" << endl << endl;
        else 
            cout << "{a, b, c} not parallel {a + n, b + n, c + n}" << endl << endl;
    }
}

// intersect triangle with plane test
void plane_intersect_test ()
{
    cout << "Starting plane_intersect triangle test:" << endl;
    Vector3D a, b, c;
    Plane3D pl (0, 0, 1, 0);
    Triangle3D tr, res;

    for (int i = 0; i < plane_intersect_count; i++)
    {
        cout << "plane_intersect i = " << i << ":" << endl;
        a = Vector3D (rand() % plane_intersect_max, rand() % plane_intersect_max, rand() % plane_intersect_max) - Vector3D (0, 0, plane_intersect_max/2);
        b = Vector3D (rand() % plane_intersect_max, rand() % plane_intersect_max, rand() % plane_intersect_max) - Vector3D (0, 0, plane_intersect_max/2);
        c = Vector3D (rand() % plane_intersect_max, rand() % plane_intersect_max, rand() % plane_intersect_max) - Vector3D (0, 0, plane_intersect_max/2);
        tr = Triangle3D (a, b, c);
        res = intersect (tr, pl);
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
        if (tr.is_true_triangle())
            cout << tr.get_plane().get_normal().x_ << "x + " << tr.get_plane().get_normal().y_ << "y + " << tr.get_plane().get_normal().z_ << "z + " << tr.get_plane().D_ << endl;
        cout << "a': x = " << res[0].x_ << ", y = " << res[0].y_ << ", z = " << res[0].z_ << endl;
        cout << "b': x = " << res[1].x_ << ", y = " << res[1].y_ << ", z = " << res[1].z_ << endl;
        cout << "c': x = " << res[2].x_ << ", y = " << res[2].y_ << ", z = " << res[2].z_ << endl;
        if (res.is_true_triangle())
            cout << "n: " << res.get_plane().get_normal().x_ << "x + " << res.get_plane().get_normal().y_ << "y + " << res.get_plane().get_normal().z_ << "z = " << tr.get_plane().D_ << endl;
        cout << endl;
    }
}

// random two triangle intersection test
void rand_triangle_intersect_test ()
{
    cout << "Starting triangle intersect test:" << endl;
    Vector3D a, b, c;
    Triangle3D tr1, tr2;

    for (int i = 0; i < rand_triangle_intersect_count; i++)
    {
        cout << "triangle_intersect i = " << i << ":" << endl;
        a = Vector3D (rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max);
        b = Vector3D (rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max);
        c = Vector3D (rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max);
        cout << "Triangle 1:" << endl;
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
        tr1 = Triangle3D (a, b, c);
        a = Vector3D (rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max);
        b = Vector3D (rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max);
        c = Vector3D (rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max, rand() % rand_triangle_intersect_max);
        cout << "Triangle 2:" << endl;
        cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
        cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
        cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
        tr2 = Triangle3D (a, b, c);
        cout << "Is intersect: " << boolalpha << is_intersect (tr1, tr2) << endl << endl;
    }
}

// two triangle intersection test
void triangle_intersect_test ()
{
    cout << "Starting triangle intersect test:" << endl;
    Vector3D a, b, c;
    Triangle3D tr1, tr2;

    cin >> a.x_ >> a.y_ >> a.z_;
    cin >> b.x_ >> b.y_ >> b.z_;
    cin >> c.x_ >> c.y_ >> c.z_;
    cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
    cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
    cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
    tr1 = Triangle3D (a, b, c);
    cin >> a.x_ >> a.y_ >> a.z_;
    cin >> b.x_ >> b.y_ >> b.z_;
    cin >> c.x_ >> c.y_ >> c.z_;
    cout << "a: x = " << a.x_ << ", y = " << a.y_ << ", z = " << a.z_ << endl;
    cout << "b: x = " << b.x_ << ", y = " << b.y_ << ", z = " << b.z_ << endl;
    cout << "c: x = " << c.x_ << ", y = " << c.y_ << ", z = " << c.z_ << endl;
    tr2 = Triangle3D (a, b, c);
    cout << "Is intersect: " << boolalpha << is_intersect (tr1, tr2) << " " << is_intersect (tr2, tr1) << endl << endl;
}

int main ()
{
    srand (time (NULL));
    if (parallel_start)
        parallel_test ();
    if (plane_intersect_start)
        plane_intersect_test ();
    if (rand_triangle_intersect_start)
        rand_triangle_intersect_test();
    if (triangle_intersect_start)
        triangle_intersect_test();
}