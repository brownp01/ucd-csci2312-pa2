//
// Created by Paul Brown on 9/17/15.
//

#include "Point.h"
#include <cmath>

namespace Clustering {


    Point::Point(int initDim) {

        m_Dim = initDim;
        m_Values = new double[m_Dim];

        for (int i = 0; i < m_Dim; i++)
            m_Values[i] = 0;

    }

    Point::Point(int initDim, double *initValues) : Point(initDim) {

        for (int i = 0; i < initDim; i++)
            m_Values[i] = initValues[i];

    }

    Point::Point(const Point &point) {

        m_Dim = point.m_Dim;
        m_Values = new double[m_Dim];

        for (int i = 0; i < m_Dim; i++)
            m_Values[i] = point.m_Values[i];

    }

    Point &Point::operator=(const Point &point) {

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

    Point::~Point() {

        delete[] m_Values;

    }

    void Point::setValue(int dim, double newValues) {

        m_Values[dim] = newValues;
    }

    double Point::getValue(int dim) const {

        return m_Values[dim];
    }

    double Point::distanceTo(const Point &point) const {

        double sum = 0;

        for (int i = 0; i < m_Dim; i++)
            sum += pow(m_Values[i] - point.m_Values[i], 2);

        return sqrt(sum);
    }

    Point &Point::operator*=(double d) {

        for (int i = 0; i < m_Dim; i++)
            m_Values[i] *= d;

        return *this;
    }

    Point &Point::operator/=(double d) {

        for (int i = 0; i < m_Dim; i++)
            m_Values[i] /= d;

        return *this;
    }

    const Point Point::operator*(double d) const {

        for (int i = 0; i < m_Dim; i++)
            m_Values[i] *= d;

        return *this;
    }

    const Point Point::operator/(double d) const {

        if (d == 0)
            return *this;

        else {
            for (int i = 0; i < m_Dim; i++)
                m_Values[i] /= d;

            return *this;
        }
    }

    Point &operator+=(Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++)
            point.m_Values[i] += point1.m_Values[i];

        return point;
    }

    Point &operator-=(Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++)
            point.m_Values[i] -= point1.m_Values[i];

        return point;
    }

    const Point operator+(const Point &point, const Point &point1) {

        Point(p) = point;
        p += point1;

        return p;
    }

    const Point operator-(const Point &point, const Point &point1) {

        Point(p) = point;
        p -= point1;

        return p;
    }

    bool operator==(const Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++) {
            if (point.m_Values[i] != point1.m_Values[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++) {
            if (point.m_Values[i] == point1.m_Values[i])
                return false;
        }
        return true;
    }

    bool operator<(const Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++) {
            if (point.m_Values[i] < point1.m_Values[i])
                return true;
        }
        return false;
    }

    bool operator>(const Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++) {
            if (point.m_Values[i] > point1.m_Values[i])
                return true;
        }
        return false;
    }

    bool operator<=(const Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++) {
            if (point.m_Values[i] <= point1.m_Values[i])
                return true;
        }
        return false;
    }

    bool operator>=(const Point &point, const Point &point1) {

        for (int i = 0; i < point.m_Dim; i++) {
            if (point.m_Values[i] >= point1.m_Values[i])
                return true;
        }
        return false;
    }

    std::ostream &operator<<(std::ostream &out, const Point &point) {

        for (int i = 0; i < point.m_Dim; i++)
            out << point.m_Values[i] << ", ";

        return out;
    }

//std::istream &operator>>(std::istream &istream, Point &point) {
//
//    std::string value;
//
//    int i = 1;
//    while (getline(istream, value, Point::POINT_VALUE_DELIM)){
//        double d = stod(value);
//        std::cerr << "Value: " << d << std::endl;
//        point.setValue(i++, d);
//    }
//    std::cerr << "Point: " << point << std::endl;
//
//    return istream;
//}
}
