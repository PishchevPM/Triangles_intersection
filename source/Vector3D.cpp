#include "Vector3D.h"

namespace mygeom
{
    bool Vector3D::is_valid () const
    {
        return std::isfinite (x_) && std::isfinite (y_) && std::isfinite (z_);
    }

    Vector3D& Vector3D::operator+= (Vector3D vec)
    {
        x_ = x_ + vec.x_;
        y_ = y_ + vec.y_;
        z_ = z_ + vec.z_;
        return *this;
    };

    Vector3D operator+ (Vector3D vc1, Vector3D vc2)
    {
        return Vector3D (vc1.x_ + vc2.x_, vc1.y_ + vc2.y_, vc1.z_ + vc2.z_);
    };

    Vector3D& Vector3D::operator-= (Vector3D vec)
    {
        x_ = x_ - vec.x_;
        y_ = y_ - vec.y_;
        z_ = z_ - vec.z_;
        return *this;
    };

    Vector3D operator- (Vector3D vc1, Vector3D vc2)
    {
        return Vector3D (vc1.x_ - vc2.x_, vc1.y_ - vc2.y_, vc1.z_ - vc2.z_);
    };

    Vector3D Vector3D::operator- () const
    {
        return Vector3D (-x_ , -y_, -z_);
    };

    Vector3D operator* (double scalar, Vector3D vec)
    {
        return Vector3D (scalar * vec.x_, scalar * vec.y_, scalar * vec.z_);
    };

    Vector3D operator* (Vector3D vec, double scalar)
    {
        return scalar * vec;
    };

    Vector3D& Vector3D::operator*= (double scalar)
    {
        x_ *= scalar;
        y_ *= scalar;
        z_ *= scalar;
        return *this;
    };

    Vector3D operator/ (Vector3D vc, double scalar)
    {
        return (1 / scalar) * vc;
    };

    Vector3D& Vector3D::operator/= (double scalar)
    {
        x_ /= scalar;
        y_ /= scalar;
        z_ /= scalar;
        return *this;
    };

    Vector3D Vector3D::normalize () const
    {
        double absval = std::sqrt(x_*x_ + y_*y_ + z_*z_);
        if (absval < calc_err)
            return Vector3D ();

        return Vector3D (x_ / absval, y_ / absval, z_ / absval);
    }

    Vector3D Vector3D::snormalize () const
    {
        Vector3D vec = normalize();

        if (std::abs (vec.x_) > calc_err)
            return std::signbit(vec.x_) ? -vec : vec;
        else if (std::abs (vec.y_) > calc_err)
            return std::signbit(vec.y_) ? -vec : vec;
        else
            return std::signbit(vec.z_) ? -vec : vec;
    };

    bool Vector3D::operator== (Vector3D v) const
    {
        return (std::abs(x_ - v.x_) < calc_err) && 
               (std::abs(y_ - v.y_) < calc_err) && 
               (std::abs(z_ - v.z_) < calc_err);
    }

    bool Vector3D::operator!= (Vector3D v) const
    {
        return (std::abs(x_ - v.x_) > calc_err) && 
               (std::abs(y_ - v.y_) > calc_err) && 
               (std::abs(z_ - v.z_) > calc_err);;
    }

    double Vector3D::sqr () const
    {
        return x_ * x_ + y_ * y_ + z_ * z_;
    }

    double Vector3D::abs () const
    {
        return std::sqrt(sqr());
    }

    double dotprod (const Vector3D vec1, const Vector3D vec2)
    {
        return vec1.x_ * vec2.x_ + vec1.y_ * vec2.y_ + vec1.z_ * vec2.z_; 
    }

    Vector3D operator/ (Vector3D vc1, Vector3D vc2)
    {
        return Vector3D (vc1.x_ / vc2.x_, vc1.y_ / vc2.y_, vc1.z_ / vc2.z_);
    }

    Vector3D vecprod (const Vector3D vec1, const Vector3D vec2)
    {
        Vector3D tmp (0, 0, 0);
        tmp.x_ = vec1.y_*vec2.z_ - vec1.z_*vec2.y_;
        tmp.y_ = vec1.z_*vec2.x_ - vec1.x_*vec2.z_;
        tmp.z_ = vec1.x_*vec2.y_ - vec1.y_*vec2.x_;
        return tmp;
    }

    double tripprod (const Vector3D vec1, const Vector3D vec2, const Vector3D vec3)
    {
        double res = 0;
        res += vec3.x_ * (vec1.y_*vec2.z_ - vec1.z_*vec2.y_);
        res += vec3.y_ * (vec1.z_*vec2.x_ - vec1.x_*vec2.z_);
        res += vec3.z_ * (vec1.x_*vec2.y_ - vec1.y_*vec2.x_);
        return res;
    }

    double abs (const Vector3D vc)
    {
        return std::sqrt(vc.sqr());
    }
}