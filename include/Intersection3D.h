#pragma once

#include "Triangle3D.h"

namespace mygeom
{
    class Plane3D;
    class Triangle3D;

    inline bool is_parallel (const Vector3D& vc1, const Vector3D& vc2)
    {
        return vecprod(vc1, vc2) == Vector3D (0, 0, 0);
    }

    bool is_parallel (const Plane3D& pl1, const Plane3D& pl2);

    bool is_parallel (const Vector3D& vc, const Plane3D& pl);

    inline bool is_parallel (const Plane3D& pl, const Vector3D& vc)
    {
        return is_parallel(vc, pl);
    }

    bool is_parallel (const Triangle3D& tr1, const Triangle3D& tr2);

    bool is_parallel (const Triangle3D& tr, const Plane3D& pl);

    inline bool is_parallel (const Plane3D& pl, const Triangle3D& tr)
    {
        return is_parallel(tr, pl);
    }

    /**
     * are two triangles in the same plane?
     * @return true, if on same. false, if not 
    **/
    bool in_same_plane (const Triangle3D& tr1, const Triangle3D& tr2);

    /**
     * is plane contains this point?
     * @param pl plane
     * @param p vector of point
     * @return true, if yes. False, if not
    **/
    inline bool is_contains (const Plane3D& pl, const Vector3D& p)
    {
        return std::abs (dotprod (p, pl.get_normal()) + pl.D_) < calc_err;
    }

    /**
     * finds intersections of line segment and plane
     * @param vc1 - first end of line segment
     * @param vc2 - second end of line segment
     * @param pl - plane
     * @return if the segment lies in the plane, return vc1. 
     *         if the segment doesn't intersect plane return (NAN, NAN, NAN) vector
     *         else return point of intersection
    **/
    Vector3D intersect (const Vector3D& vc1, const Vector3D& vc2, const Plane3D& pl);

    /**
     * finds intersection of triangle and plane (triangle, line segment or point)
     * @param tr triangle
     * @param pl plane
     * @return a triangle or line segment, that lies on a plane
    **/
    Triangle3D intersect (const Triangle3D& tr, const Plane3D& pl);

    /**
     * checks if triangles intersect (not necessarily non-degenerate)
    **/
    bool is_intersect (const Triangle3D& tr1, const Triangle3D& tr2);
}