#include "Plane3D.h"

namespace mygeom
{
    Plane3D::Plane3D (double A, double B, double C, double D)
    {
        norm_ = Vector3D (A, B, C).snormalize();
        if (!norm_.is_valid())
            return;
                
        D_ = D / std::sqrt(Vector3D (A, B, C).sqr());
    };

    Plane3D::Plane3D (Vector3D normal, double D)
    {
        norm_ = Vector3D (normal).snormalize();
        if (!norm_.is_valid())
            return;

        D_ = D / std::sqrt(normal.sqr());
    };

    Plane3D::Plane3D (Vector3D p1, Vector3D p2, Vector3D p3)
    {
        norm_ = vecprod (p1 - p2, p1 - p3).snormalize();
        if (!norm_.is_valid())
            return;

        D_ = -dotprod (norm_, p1);
    };

    void Plane3D::set_normal (Vector3D vec)
    {
        norm_ = vec.snormalize();
        if (!norm_.is_valid())
            return;

        D_ = D_ / std::sqrt(vec.sqr());
    }
}