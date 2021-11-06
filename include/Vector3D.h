#pragma once

#include <cmath>
#include <cassert>

namespace mygeom
{
    const double calc_err = 1000*__DBL_EPSILON__;

    struct Vector3D
    {
        double x_ = NAN, y_ = NAN, z_ = NAN;

        Vector3D () {};
        Vector3D (double xc, double yc, double zc) : x_(xc), y_(yc), z_(zc) {};
        Vector3D (const Vector3D& vec) : x_(vec.x_), y_(vec.y_), z_(vec.z_) {};

        bool is_valid () const;

        Vector3D& operator+= (Vector3D vec);

        Vector3D& operator-= (Vector3D vec);

        Vector3D operator- () const;

        Vector3D& operator*= (double scalar);

        Vector3D& operator/= (double scalar);

        Vector3D normalize () const;

        Vector3D snormalize () const;

        bool operator== (Vector3D v) const;

        bool operator!= (Vector3D v) const;

        double sqr () const;

        double abs () const;
    };

    Vector3D operator+ (Vector3D vc1, Vector3D vc2);

    Vector3D operator- (Vector3D vc1, Vector3D vc2);

    Vector3D operator* (Vector3D vec, double scalar);

    Vector3D operator* (double scalar, Vector3D vc);

    Vector3D operator/ (Vector3D vc, double scalar);

    Vector3D operator/ (Vector3D vc1, Vector3D vc2);

    double dotprod (const Vector3D vec1, const Vector3D vec2);

    Vector3D vecprod (const Vector3D vec1, const Vector3D vec2);

    double tripprod (const Vector3D vec1, const Vector3D vec2, const Vector3D vec3);

    double abs (const Vector3D vc);
}