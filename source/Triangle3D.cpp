#include "Triangle3D.h"

namespace mygeom
{
    void Triangle3D::update_plane ()
    {
        plane_ = Plane3D (points_[0], points_[1], points_[2]);
        if (!plane_.is_valid ())
        {
            if ((points_[0] - points_[2]).sqr() < (points_[0] - points_[1]).sqr())
                std::swap (points_[1], points_[2]);
            if ((points_[0] - points_[2]).sqr() < (points_[2] - points_[1]).sqr())
                std::swap (points_[1], points_[0]);

            return;
        }

        Vector3D mid = (points_[0] + points_[1] + points_[2]) / 3;
        mid = vecprod (points_[0] - mid, points_[1] - mid);
        if (signed_distance (plane_, points_[0] + mid) < 0)
            std::swap (points_[1], points_[2]);
    }

    void Triangle3D::set_vertex (int num, Vector3D vec)
    {
        assert (num >= 0 && num <= 2);
        points_[num] = vec;
        update_plane();
    }

    bool Triangle3D::operator== (Triangle3D tr) const
    {
        if (is_true_triangle())
            return (points_[0] == tr.points_[0]) || (points_[1] == tr.points_[0]) || (points_[2] == tr.points_[0]);

        if (points_[0] == tr.points_[0] && points_[1] == tr.points_[1])
            return true;
        if (points_[0] == tr.points_[1] && points_[1] == tr.points_[0])
            return true;
        return false;
    }
}