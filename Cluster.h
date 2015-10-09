//
// Created by Paul Brown on 9/17/15.
//

#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

//    struct LNode;
//    typedef LNode *LNodePtr;

    struct LNode {
        PointPtr p;
        LNodePtr next;
        LNode(PointPtr pt, LNodePtr n) : p(pt), next(n) {}
    };

    class Cluster {
        int m_Size;
        LNodePtr m_Points;
        bool m_Release_points;
        bool m_Greedy;

        void m_del();
        void m_cpy(LNodePtr pts);

    public:
        Cluster() : m_Size(0), m_Points(nullptr), m_Release_points(false), m_Greedy(false) {};
        Cluster(bool rp, bool gdy) : m_Size(0), m_Points(nullptr), m_Release_points(rp), m_Greedy(true) {};
        Cluster (bool rp, bool gdy) : m_Size(0), m_Points(nullptr), m_Release_points(rp), m_Greedy(gdy) {};

        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);
        //Cluster &operator=(const Cluster &);
        ~Cluster();

        // Set functions: They allow calling c1.add(c2.remove(p));
        void add(const PointPtr &);
        /*const PointPtr &remove(const PointPtr &);

        // Overloaded operators

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &);

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        // - Members
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference

        Cluster &operator+=(const Point &rhs); // add point
        Cluster &operator-=(const Point &rhs); // remove point

        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);*/

    };

}
#endif //CLUSTERING_CLUSTER_H


