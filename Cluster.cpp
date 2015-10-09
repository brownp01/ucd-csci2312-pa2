//
// Created by Paul Brown on 9/17/15.
//

#include "Cluster.h"
#include <cassert>

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {

}

/*Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    return <#initializer#>;
}*/

Clustering::Cluster::~Cluster() {

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

//Clustering::PointPtr const &Clustering::Cluster::remove(Clustering::PointPtr const &ptr) {
//
//    LNodePtr prev = nullptr, del = nullptr;
//
//    if (m_Points == NULL){
//        assert()
//    }
//        PointPtr *delPtr = ptr.
//
//    return <#initializer#>;
//}

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
