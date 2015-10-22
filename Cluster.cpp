//
// Created by Paul Brown on 9/17/15.
//

#include "Cluster.h"
#include "Point.h"
#include <cassert>

using Clustering::Point;

namespace Clustering {


    Cluster::Cluster(const Cluster &cluster) {

        m_cpy(cluster.m_Points);

    }

    Cluster &Cluster::operator=(const Cluster &cluster) {

        if (this != &cluster) {
            m_del();
            m_cpy(cluster.m_Points);
        }
        return *this;
    }

    Cluster::~Cluster() {

        m_del();

    }

    void Cluster::add(PointPtr const &ptr) {

        LNodePtr a = new LNode(ptr, nullptr);

        if (m_Points == nullptr) {
            m_Points = a;
        }
        else if (*(m_Points->p) > *ptr) {
            a->next = m_Points;
            m_Points = a;
        }
        else {
            LNodePtr c = m_Points, n = m_Points->next;
            while (true) {
                if (n == nullptr || *(n->p) > *ptr) {
                    c->next = a;
                    a->next = n;
                    break;
                }
                else {
                    c = n;
                    n = n->next;
                }
            }
        }

        m_Size++;
    }

    PointPtr const &Cluster::remove(PointPtr const &ptr) {

        LNodePtr prev = nullptr, del = nullptr;

        if (m_Points->p == ptr) {
            del = m_Points;
            m_Points = m_Points->next;
            delete del->p;
            delete del;

            m_Size--;
        }
        else {
            prev = m_Points;
            del = m_Points->next;

            while (del != nullptr) {

                if (del->p == ptr) {
                    prev->next = del->next;
                    delete del->p;
                    delete del;

                    m_Size--;

                    break;
                }

                prev = del;
                del = del->next;
            }

            return ptr;
        }

    }

//std::ostream &operator<<(std::ostream &ostream, const Cluster &cluster) {
//    return <#initializer#>;
//}
//
//std::istream &operator>>(std::istream &istream, Cluster &cluster) {
//    return <#initializer#>;
//}
//
//bool operator==(const Cluster &lhs, const Cluster &rhs){
//
//}
    bool operator!=(const Cluster &lhs, const Cluster &rhs){

    if (lhs != rhs)
        return true;
}
//
//    Cluster &Cluster::operator+=(const Cluster &rhs) {
//        return <#initializer#>;
//    }
//
//Cluster &Cluster::operator-=(const Cluster &rhs) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator+=(const Point &rhs) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator-=(const Point &rhs) {
//    return <#initializer#>;
//}
//
//const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
//
//    Cluster newCluster = Cluster();
//
//    return newCluster;
//}
//
//const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
//    return Clustering::Cluster();
//}
//
//const Cluster operator+(const Cluster &lhs, PointPtr const &rhs) {
//    return Cluster();
//}
//
//const Cluster operator-(const Cluster &lhs, PointPtr const &rhs) {
//    return Cluster();
//}*/

    void Cluster::m_del() {

        if (m_Size != 0) {
            LNodePtr c = m_Points, n = m_Points->next;
            delete c->p;
            delete c;
        }
        m_Points = nullptr;
        m_Size = 0;

    }

    void Cluster::m_cpy(LNodePtr pts) {

        LNodePtr reached = pts;
        LNodePtr curr = new LNode(reached->p, nullptr);
        m_Points = curr;
        LNodePtr prev = curr;
        reached = reached->next;

        for (; reached != nullptr; reached = reached->next) {
            curr = new LNode(reached->p, nullptr);
            prev->next = curr;
            prev = curr;
        }

    }
}
