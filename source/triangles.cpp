#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include "Intersection3D.h"

using namespace mygeom;
using namespace std;

struct TriangleWrapper
{
    unsigned long id;
    Triangle3D tr;
    Vector3D max_cords;
    Vector3D min_cords;
};


Triangle3D read_triangle ()
{
    Vector3D a, b, c;
    cin >> a.x_ >> a.y_ >> a.z_;
    cin >> b.x_ >> b.y_ >> b.z_;
    cin >> c.x_ >> c.y_ >> c.z_;
    return Triangle3D (a, b, c);
}

TriangleWrapper make_trianglewrapper (unsigned long id)
{
    TriangleWrapper temp;
    temp.id = id;
    temp.tr = read_triangle ();
    temp.max_cords.x_ = max ({temp.tr[0].x_, temp.tr[1].x_, temp.tr[2].x_});
    temp.max_cords.y_ = max ({temp.tr[0].y_, temp.tr[1].y_, temp.tr[2].y_});
    temp.max_cords.z_ = max ({temp.tr[0].z_, temp.tr[1].z_, temp.tr[2].z_});
    temp.min_cords.x_ = min ({temp.tr[0].x_, temp.tr[1].x_, temp.tr[2].x_});
    temp.min_cords.y_ = min ({temp.tr[0].y_, temp.tr[1].y_, temp.tr[2].y_});
    temp.min_cords.z_ = min ({temp.tr[0].z_, temp.tr[1].z_, temp.tr[2].z_});
    return temp;
}

void update_max (Vector3D& glmax, Vector3D vec)
{
    if (vec.x_ > glmax.x_)
        glmax.x_ = vec.x_;
    if (vec.y_ > glmax.y_)
        glmax.y_ = vec.y_;
    if (vec.z_ > glmax.z_)
        glmax.z_ = vec.z_;
}

void update_min (Vector3D& glmin, Vector3D vec)
{
    if (vec.x_ < glmin.x_)
        glmin.x_ = vec.x_;
    if (vec.y_ < glmin.y_)
        glmin.y_ = vec.y_;
    if (vec.z_ < glmin.z_)
        glmin.z_ = vec.z_;
}

int main ()
{
    unsigned long count;
    const double divk = 1;
    vector<TriangleWrapper> triangles;
    Vector3D global_max;
    Vector3D global_min;
    cin >> count;
    for (unsigned long i = 0; i < count; i++)
    {
        triangles.push_back (make_trianglewrapper(i));
        if (i == 0)
        {
            global_max = triangles[0].max_cords;
            global_min = triangles[0].min_cords;
        }
        update_max (global_max, triangles[i].max_cords);
        update_min (global_min, triangles[i].min_cords);
    }
    unsigned long n = cbrt ((double)count);
    Vector3D div = divk * (global_max - global_min) / n;
    if (div.x_ < calc_err) div.x_ = 1;
    if (div.y_ < calc_err) div.y_ = 1;
    if (div.z_ < calc_err) div.z_ = 1;
    vector<vector<TriangleWrapper*>> cells (count);
    for (unsigned long i = 0; i < count; i++)
    {
        Vector3D rel_min = (triangles[i].min_cords - global_min) / div; 
        Vector3D rel_max = (triangles[i].max_cords - global_min) / div; 
        unsigned long xlim = static_cast<unsigned long>(rel_max.x_) + 1;
        if (xlim > n) xlim--;
        unsigned long ylim = static_cast<unsigned long>(rel_max.y_) + 1;
        if (ylim > n) ylim--;
        unsigned long zlim = static_cast<unsigned long>(rel_max.z_) + 1;
        if (zlim > n) zlim--;
        for (unsigned long j = rel_min.x_; j <  xlim; j++)
            for (unsigned long k = rel_min.y_; k < ylim; k++)
                for (unsigned long l = rel_min.z_; l < zlim; l++)
                    cells[n*n*j + n*k + l].push_back (&(triangles[i]));
    }

    set<unsigned long> answers;
    for (unsigned long i = 0; i < n*n*n; i++)
        for (unsigned long j = 0; j < cells[i].size(); j++)
            for (unsigned long k = j + 1; k < cells[i].size(); k++)
                if (is_intersect (cells[i][j]->tr, cells[i][k]->tr))
                    answers.insert({cells[i][j]->id, cells[i][k]->id});

    for (auto i : answers)
        cout << i << endl;
}