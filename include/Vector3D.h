#pragma once

#include <cmath>
#include <cassert>

namespace mygeom
{
    const double calc_err = 1000*__DBL_EPSILON__;

    struct Vector3D
    {
        double x_, y_, z_;

        Vector3D (double xc = NAN, double yc = NAN, double zc = NAN) : x_(xc), y_(yc), z_(zc) {};
        Vector3D (const Vector3D& vec) : x_(vec.x_), y_(vec.y_), z_(vec.z_) {};

        /**
         * is vector components finite numbers?
        **/
        inline bool is_valid () const
        {
            return std::isfinite (x_) && std::isfinite (y_) && std::isfinite (z_);
        }

        Vector3D& operator+= (Vector3D vec);

        Vector3D& operator-= (Vector3D vec);

        inline Vector3D operator- () const
        {
            return Vector3D (-x_ , -y_, -z_);
        };

        Vector3D& operator*= (double scalar);

        Vector3D& operator/= (double scalar);

        /**
         * normalizing vector (depend on direction):
         * (2, 0, 0), (-2, 0, 0) must be normalized in different vectors
        **/
        Vector3D normalize () const;

        /**
         * normalizing vector (doesn't depend on direction):
         * (2, 0, 0), (-2, 0, 0) must be normalized in same vector
        **/
        Vector3D snormalize () const;

        bool operator== (Vector3D v) const;

        bool operator!= (Vector3D v) const;

        /**
         * x^2 + y^2 + z^2
        **/
        inline double sqr () const
        {
            return x_ * x_ + y_ * y_ + z_ * z_;
        }

        /**
         * sqrt(sqr())
        **/
        inline double abs () const
        {
            return std::sqrt(sqr());
        }
    };

    inline Vector3D operator+ (Vector3D vc1, Vector3D vc2)
    {
        return Vector3D (vc1.x_ + vc2.x_, vc1.y_ + vc2.y_, vc1.z_ + vc2.z_);
    };

    inline Vector3D operator- (Vector3D vc1, Vector3D vc2)
    {
        return Vector3D (vc1.x_ - vc2.x_, vc1.y_ - vc2.y_, vc1.z_ - vc2.z_);
    };

    inline Vector3D operator* (double scalar, Vector3D vec)
    {
        return Vector3D (scalar * vec.x_, scalar * vec.y_, scalar * vec.z_);
    };

    inline Vector3D operator* (Vector3D vec, double scalar)
    {
        return scalar * vec;
    };

    inline Vector3D operator/ (Vector3D vc, double scalar)
    {
        return (1 / scalar) * vc;
    };


    inline Vector3D operator/ (Vector3D vc1, Vector3D vc2)
    {
        return Vector3D (vc1.x_ / vc2.x_, vc1.y_ / vc2.y_, vc1.z_ / vc2.z_);
    };

    inline double dotprod (const Vector3D vec1, const Vector3D vec2)
    {
        return vec1.x_ * vec2.x_ + vec1.y_ * vec2.y_ + vec1.z_ * vec2.z_; 
    }

    Vector3D vecprod (const Vector3D vec1, const Vector3D vec2);

    double tripprod (const Vector3D vec1, const Vector3D vec2, const Vector3D vec3);

    inline double abs (const Vector3D vc)
    {
        return std::sqrt(vc.sqr());
    };
}