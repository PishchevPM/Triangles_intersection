#include "Triangle3D.h"

namespace mygeom
{
    void Triangle3D::update_plane ()
    {
        plane = Plane3D (points[0], points[1], points[2]);
        if (!plane.is_valid ())
        {
            if ((points[0] - points[2]).sqr() < (points[0] - points[1]).sqr())
                std::swap (points[1], points[2]);
            if ((points[0] - points[2]).sqr() < (points[2] - points[1]).sqr())
                std::swap (points[1], points[0]);

            return;
        }

        Vector3D mid = (points[0] + points[1] + points[2]) / 3;
        mid = vecprod (points[0] - mid, points[1] - mid);
        if (signed_distance (plane, points[0] + mid) < 0)
            std::swap (points[1], points[2]);
    }

    Triangle3D::Triangle3D (Vector3D A, Vector3D B, Vector3D C)
    {
        points[0] = A;
        points[1] = B;
        points[2] = C;
        update_plane();
    };

    bool Triangle3D::is_true_triangle () const
    {
        return plane.is_valid ();
    }

    Vector3D Triangle3D::get_vertex (int index) const
    {
        assert (index >= 0 && index <= 2);
        return (points[index]);
    }

    Vector3D Triangle3D::operator[] (int index) const
    {
        return get_vertex(index);
    }

    Plane3D Triangle3D::get_plane () const
    {
        return plane;
    }

    void Triangle3D::set_vertex (int num, Vector3D vec)
    {
        assert (num >= 0 && num <= 2);
        points[num] = vec;
        update_plane();
    }

    bool Triangle3D::operator== (Triangle3D tr) const
    {
        if (is_true_triangle())
            return (points[0] == tr.points[0]) || (points[1] == tr.points[0]) || (points[2] == tr.points[0]);

        if (points[0] == tr.points[0] && points[1] == tr.points[1])
            return true;
        if (points[0] == tr.points[1] && points[1] == tr.points[0])
            return true;
        return false;
    }
}