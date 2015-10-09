//
// Created by Paul Brown on 9/17/15.
//

#include "Cluster.h"
#include <cassert>

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {

}

Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {

    if (this != &cluster){
        m_del();
        m_cpy(cluster.m_Points);
    }
    return *this;
}

Clustering::Cluster::~Cluster() {

    m_del();

}

void Clustering::Cluster::add(Clustering::PointPtr const &ptr) {

    LNodePtr a = new LNode(ptr, nullptr);

    if (m_Points == nullptr){
        m_Points = a;
    }
    else if (*(m_Points->p) > *ptr){
        a->next = m_Points;
        m_Points = a;
    }
    else {
        LNodePtr c = m_Points, n = m_Points->next;
        while (true){
            if (n == nullptr || *(n->p) > *ptr){
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

Clustering::PointPtr const &Clustering::Cluster::remove(Clustering::PointPtr const &ptr) {

    LNodePtr prev = nullptr, del = nullptr;

    if (m_Points->p == ptr){
        del = m_Points;
        m_Points = m_Points->next;
        delete del->p;
        delete del;

        m_Size --;
    }
    else {
        prev = m_Points;
        del = m_Points->next;

        while (del != nullptr){

            if (del->p == ptr){
                prev->next = del->next;
                delete del->p;
                delete del;

                m_Size --;

                break;
            }

            prev = del;
            del = del->next;
        }

        return ptr;
    }

}

//std::ostream &Clustering::operator<<(std::ostream &ostream, const Clustering::Cluster &cluster) {
//    return <#initializer#>;
//}
//
//std::istream &Clustering::operator>>(std::istream &istream, Clustering::Cluster &cluster) {
//    return <#initializer#>;
//}
//
//bool Clustering::Cluster friend bool operator==(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs){
//
//}
//
//Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Cluster &rhs) {
//    return <#initializer#>;
//}
//
//Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Cluster &rhs) {
//    return <#initializer#>;
//}
//
//Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Point &rhs) {
//    return <#initializer#>;
//}
//
//Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Point &rhs) {
//    return <#initializer#>;
//}
//
//const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs) {
//
//    Cluster newCluster = Cluster();
//
//    return newCluster;
//}
//
//const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs) {
//    return Clustering::Cluster();
//}
//
//const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &lhs, Clustering::PointPtr const &rhs) {
//    return Clustering::Cluster();
//}
//
//const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &lhs, Clustering::PointPtr const &rhs) {
//    return Clustering::Cluster();
//}*/
void Clustering::Cluster::m_del() {

    if (m_Size != 0){
        LNodePtr c = m_Points, n = m_Points->next;
        delete c->p;
        delete c;
    }
    m_Points = nullptr;
    m_Size = 0;

}

void Clustering::Cluster::m_cpy(Clustering::LNodePtr pts) {

    LNodePtr reached = pts;
    LNodePtr curr = new LNode(reached->p, nullptr);
    m_Points = curr;
    LNodePtr prev = curr;
    reached = reached->next;

    for ( ; reached != nullptr; reached = reached->next){
        curr = new LNode(reached->p, nullptr);
        prev->next = curr;
        prev = curr;
    }

}
