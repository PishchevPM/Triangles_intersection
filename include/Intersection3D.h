#pragma once

#include "Vector3D.h"
#include "Plane3D.h"
#include "Triangle3D.h"

namespace mygeom
{
    class Plane3D;
    class Triangle3D;

    bool is_parallel (const Vector3D& vc1, const Vector3D& vc2);

    bool is_parallel (const Plane3D& pl1, const Plane3D& pl2);

    bool is_parallel (const Vector3D& vc, const Plane3D& pl);

    bool is_parallel (const Plane3D& pl, const Vector3D& vc);

    bool is_parallel (const Triangle3D& tr1, const Triangle3D& tr2);

    bool is_parallel (const Triangle3D& tr, const Plane3D& pl);

    bool is_parallel (const Plane3D& pl, const Triangle3D& tr);

    bool in_same_plane (const Triangle3D& tr1, const Triangle3D& tr2);

    bool is_contains (const Plane3D& pl, const Vector3D& p);

    Vector3D intersect (const Vector3D& vc1, const Vector3D& vc2, const Plane3D& pl);

    Triangle3D intersect (const Triangle3D& tr, const Plane3D& pl);

    bool is_intersect (const Triangle3D& tr1, const Triangle3D& tr2);
}