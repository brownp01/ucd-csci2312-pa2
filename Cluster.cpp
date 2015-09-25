//
// Created by Paul Brown on 9/17/15.
//

#include "Cluster.h"

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {

}

/*Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    return <#initializer#>;
}*/

Clustering::Cluster::~Cluster() {

}

void Clustering::Cluster::add(Clustering::PointPtr const &ptr) {

    //1. Find the right spot in the chain
    //2. Create a new node
    // assign ptr
    //3. insert into the chain
    //c1.add(&p);
    //points == head (data structures)

    if (size == 0)
        points = new LNode(ptr, nullptr);

    else{
        LNodePtr c = points, n = points->next, a = new LNode(ptr, nullptr);
    }

    for (LNodePtr curr = points; curr != nullptr; curr = curr->next){

    }

}

/*Clustering::PointPtr const &Clustering::Cluster::remove(Clustering::PointPtr const &ptr) {
    return <#initializer#>;
}

std::ostream &Clustering::operator<<(std::ostream &ostream, const Clustering::Cluster &cluster) {
    return <#initializer#>;
}

std::istream &Clustering::operator>>(std::istream &istream, Clustering::Cluster &cluster) {
    return <#initializer#>;
}

bool Clustering::Cluster friend bool operator==(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs){

}

Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Cluster &rhs) {
    return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Cluster &rhs) {
    return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Point &rhs) {
    return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Point &rhs) {
    return <#initializer#>;
}

const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs) {

    Cluster newCluster = Cluster();

    return newCluster;
}

const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs) {
    return Clustering::Cluster();
}

const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &lhs, Clustering::PointPtr const &rhs) {
    return Clustering::Cluster();
}

const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &lhs, Clustering::PointPtr const &rhs) {
    return Clustering::Cluster();
}*/
