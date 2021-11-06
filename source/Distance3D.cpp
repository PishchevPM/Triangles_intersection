#include "Distance3D.h"

namespace mygeom

{
    double distance (const Vector3D vec1, const Vector3D vec2)
    {
        return sqrt((vec1 - vec2).sqr());
    }

    double signed_distance (const Plane3D pl, const Vector3D vec)
    {
        return dotprod (vec, pl.get_normal()) + pl.D_;
    }

    double distance (const Plane3D pl, const Vector3D vec)
    {
        return std::abs (signed_distance (pl, vec));
    }
}