//
// Created by Paul Brown on 9/17/15.
//

#include "Point.h"
#include <cmath>

Clustering::Point::Point(int initDim) {

    m_Dim = initDim;
    m_Values = new double[m_Dim];

    for (int i = 0; i < m_Dim; i++)
        m_Values[i] = 0;

}

Clustering::Point::Point(int initDim, double *initValues) : Point(initDim) {

    for (int i = 0; i < initDim; i++)
        m_Values[i] = initValues[i];

}

Clustering::Point::Point(const Clustering::Point &point) {

    m_Dim = point.m_Dim;
    m_Values = new double[m_Dim];

    for (int i = 0; i < m_Dim; i++)
        m_Values[i] = point.m_Values[i];

}

Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {

    if (this == &point)
    return *this;

    else {
        delete[] m_Values;
        m_Dim = point.m_Dim;
        m_Values = new double[m_Dim];

        for (int i = 0; i < m_Dim; i++)
            m_Values[i] = point.m_Values[i];

        return *this;
    }
}

Clustering::Point::~Point() {

    delete[] m_Values;

}

void Clustering::Point::setValue(int dim, double newValues) {

    m_Values[dim] = newValues;
}

double Clustering::Point::getValue(int dim) const {

    return m_Values[dim];
}

double Clustering::Point::distanceTo(const Clustering::Point &point) const {

    double sum = 0;

    for (int i = 0; i < m_Dim; i++)
        sum += pow( m_Values[i] - point.m_Values[i], 2);

    return sqrt(sum);
}

Clustering::Point &Clustering::Point::operator*=(double d) {

    for (int i = 0; i < m_Dim; i++)
        m_Values[i] *= d;

    return *this;
}

Clustering::Point &Clustering::Point::operator/=(double d) {

    for (int i = 0; i < m_Dim; i++)
        m_Values[i] /= d;

    return *this;
}

const Clustering::Point Clustering::Point::operator*(double d) const {

    for (int i = 0; i < m_Dim; i++)
        m_Values[i] *= d;

    return *this;
}

const Clustering::Point Clustering::Point::operator/(double d) const {

    if (d == 0)
        return *this;

    else {
        for (int i = 0; i < m_Dim; i++)
            m_Values[i] /= d;

        return *this;
    }
}

Clustering::Point &Clustering::operator+=(Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++)
        point.m_Values[i] += point1.m_Values[i];

    return point;
}

Clustering::Point &Clustering::operator-=(Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++)
        point.m_Values[i] -= point1.m_Values[i];

    return point;
}

const Clustering::Point Clustering::operator+(const Clustering::Point &point, const Clustering::Point &point1) {

    Point(p) = point;
    p += point1;

    return p;
}

const Clustering::Point Clustering::operator-(const Clustering::Point &point, const Clustering::Point &point1) {

    Point(p) = point;
    p -= point1;

    return p;
}

bool Clustering::operator==(const Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++) {
        if (point.m_Values[i] != point1.m_Values[i])
            return false;
    }
    return true;
}

bool Clustering::operator!=(const Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++) {
        if (point.m_Values[i] == point1.m_Values[i])
            return false;
    }
    return true;
}

bool Clustering::operator<(const Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++){
        if (point.m_Values[i] < point1.m_Values[i])
            return true;
    }
    return false;
}

bool Clustering::operator>(const Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++){
        if (point.m_Values[i] > point1.m_Values[i])
            return true;
    }
    return false;
}

bool Clustering::operator<=(const Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++){
        if (point.m_Values[i] <= point1.m_Values[i])
            return true;
    }
    return false;
}

bool Clustering::operator>=(const Clustering::Point &point, const Clustering::Point &point1) {

    for (int i = 0; i < point.m_Dim; i++){
        if (point.m_Values[i] >= point1.m_Values[i])
            return true;
    }
    return false;
}

std::ostream &Clustering::operator<<(std::ostream &out, const Clustering::Point &point) {

    for (int i = 0; i < point.m_Dim; i++)
        out << point.m_Values[i] << ", ";

    return out;
}

/*std::istream &Clustering::operator>>(std::istream &istream, Clustering::Point &point) {
    return <#initializer#>;
}*/
