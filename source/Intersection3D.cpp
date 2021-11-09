#include "Intersection3D.h"

namespace mygeom
{
    bool is_parallel (const Vector3D& vc1, const Vector3D& vc2)
    {
        return vecprod(vc1, vc2) == Vector3D (0, 0, 0);
    }

    bool is_parallel (const Plane3D& pl1, const Plane3D& pl2)
    {
        if (pl1.is_valid() && pl2.is_valid())
            return pl1.get_normal () == pl2.get_normal ();
        else
            return false;
    }

    bool is_parallel (const Vector3D& vc, const Plane3D& pl)
    {
        if (pl.is_valid() && vc.is_valid())
            return std::abs (dotprod (pl.get_normal(), vc)) < calc_err;
        else
            return false;
    }

    bool is_parallel (const Plane3D& pl, const Vector3D& vc)
    {
        return is_parallel(vc, pl);
    }

    bool is_parallel (const Triangle3D& tr1, const Triangle3D& tr2)
    {
        bool tt1 = tr1.is_true_triangle(), tt2 = tr2.is_true_triangle();
        if (tt1 && tt2)
            return is_parallel(tr1.get_plane (),tr2.get_plane ());
        else if (tt1 & !tt2) 
            return is_parallel(tr1.get_plane(), tr2[2] - tr2[0]);
        else if (!tt1 & tt2) 
            return is_parallel(tr2.get_plane(), tr1[2] - tr1[0]);
        else 
            return is_parallel(tr2[2] - tr2[0], tr1[2] - tr1[0]);
    }

    bool is_parallel (const Triangle3D& tr, const Plane3D& pl)
    {
        if (tr.is_true_triangle())
            return is_parallel(tr.get_plane (), pl);
        else
            return is_parallel((tr[2] - tr[0]), pl);
    }

    bool is_parallel (const Plane3D& pl, const Triangle3D& tr)
    {
        return is_parallel(tr, pl);
    }

    bool in_same_plane (const Triangle3D& tr1, const Triangle3D& tr2)
    {
        bool tt1 = tr1.is_true_triangle(), tt2 = tr2.is_true_triangle();
        if (tt1)
            return distance (tr1.get_plane(), tr2[0]) < calc_err &&
                   distance (tr1.get_plane(), tr2[1]) < calc_err &&
                   distance (tr1.get_plane(), tr2[2]) < calc_err;
        if (tt2)
            return distance (tr2.get_plane(), tr1[0]) < calc_err &&
                   distance (tr2.get_plane(), tr1[1]) < calc_err &&
                   distance (tr2.get_plane(), tr1[2]) < calc_err;

        return std::abs(tripprod(tr1[2] - tr1[0], tr2[2] - tr2[0], tr2[0] - tr1[0])) < calc_err;
    }

    bool is_contains (const Plane3D& pl, const Vector3D& p)
    {
        return std::abs (dotprod (p, pl.get_normal()) + pl.D_) < calc_err;
    }

    Vector3D intersect (const Vector3D& vc1, const Vector3D& vc2, const Plane3D& pl)
    {
        if (signed_distance (pl, vc1) * signed_distance (pl, vc2) > calc_err)
            return Vector3D();

        if (distance (pl, vc1) < calc_err && distance (pl, vc2) < calc_err)
            return vc1;

        return vc1 + (pl.D_ + dotprod (vc1, pl.get_normal ())) / dotprod (vc2 - vc1, pl.get_normal ()) * (vc1 - vc2);

    }

    Triangle3D intersect (const Triangle3D& tr, const Plane3D& pl)
    {
        Vector3D inters[3];

        for (unsigned i = 0; i < 3; i++)
            inters[i] = intersect (tr[i % 3], tr[(i + 1) % 3], pl);

        for (unsigned i = 0; i < 3; i++)
            if (!inters[i].is_valid())
                inters[i] = (inters[(i + 1) % 3] + inters[(i + 2) % 3]) / 2;

        return Triangle3D (inters[0], inters[1], inters[2]);
    }

    bool is_point_in_triangle (const Vector3D vc, const Triangle3D& tr)
    {
        Vector3D vect[3];
        for (int i = 0; i < 3; i++)
            vect[i] = vc - tr[i];

        double prods[3];
        for (int i = 0; i < 3; i++)
            prods[i] = tripprod (vect[i % 3], vect[(i + 1) % 3], tr.get_plane().get_normal());

        if (prods[0] > -calc_err && prods[1] > -calc_err && prods[2] > -calc_err)
            return true;
        if (prods[0] < calc_err && prods[1] < calc_err && prods[2] < calc_err)
            return true;

        return false;
    }

    bool is_intersect_on_plane(const Triangle3D& tr, const Vector3D& vc1, const Vector3D& vc2)
    {
        Vector3D vcpr[3][2];
        Vector3D trs[3];
        Vector3D vcs;

        for (int i = 0; i < 3; i++)
        {
            vcpr[i][0] = vecprod (tr[i], vc1);
            vcpr[i][1] = vecprod (tr[i], vc2);
        }

        for (int i = 0; i < 3; i++)
            trs[i] = vecprod (tr[i % 3], tr[(i + 1) % 3]);
        vcs = vecprod(vc1, vc2);
        for (int i = 0; i < 3; i++)
            if (dotprod (vcpr[i % 3][0] - vcpr[(i + 1) % 3][0] - trs[i], vcpr[i % 3][1] - vcpr[(i + 1) % 3][1] - trs[i]) < calc_err &&
                dotprod (vcpr[i % 3][1] - vcpr[i % 3][0] - vcs, vcpr[(i + 1) % 3][1] - vcpr[(i + 1) % 3][0] - vcs) < calc_err)
                return true;

        if (tr.is_true_triangle())
            return is_point_in_triangle(vc1, tr);

        return false;
    }

    bool is_intersect_on_plane(const Triangle3D& tr1, const Triangle3D& tr2)
    {
        Vector3D vcpr[3][3];
        Vector3D tr1s[3];
        Vector3D tr2s[3];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                vcpr[i][j] = vecprod (tr1[i], tr2[j]);

        for (int i = 0; i < 3; i++)
        {
            tr1s[i] = vecprod (tr1[i % 3], tr1[(i + 1) % 3]);
            tr2s[i] = vecprod (tr2[i % 3], tr2[(i + 1) % 3]);
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (dotprod (vcpr[i % 3][j % 3] - vcpr[(i + 1) % 3][j % 3] - tr1s[i % 3], vcpr[i % 3][(j + 1) % 3] - vcpr[(i + 1) % 3][(j + 1) % 3] - tr1s[i % 3]) < calc_err &&
                    dotprod (vcpr[i % 3][(j + 1) % 3] - vcpr[i % 3][j % 3] - tr2s[j % 3], vcpr[(i + 1) % 3][(j + 1) % 3] - vcpr[(i + 1) % 3][j % 3] - tr2s[j % 3]) < calc_err)
                    return true;

        if (is_point_in_triangle (tr1[0], tr2) || is_point_in_triangle (tr2[0], tr1))
            return true;

        return false;
    }

    bool is_intersect (const Triangle3D& tr1, const Triangle3D& tr2)
    {
        bool tt1 = tr1.is_true_triangle(), tt2 = tr2.is_true_triangle();
        if (!tt1 && !tt2)
        {
            if (in_same_plane(tr1, tr2))
                return is_intersect_on_plane(tr1, tr2[0], tr2[2]);
            else return false;
        }
        else if (tt1 & !tt2)
        {
            Triangle3D tmp = intersect (tr2, tr1.get_plane());
            return is_intersect_on_plane (tr1, tmp[0], tmp[2]);
        }
        else if (!tt1 & tt2)
        {
            Triangle3D tmp = intersect (tr1, tr2.get_plane());
            return is_intersect_on_plane (tr2, tmp[0], tmp[2]);
        }
        else
        {
            Triangle3D tmp = intersect (tr1, tr2.get_plane());
            if (tmp.is_true_triangle())
                return is_intersect_on_plane (tr1, tr2);
            else
                return is_intersect_on_plane (tr2, tmp[0], tmp[2]);
        }
    }
}