//
// Created by Paul Brown on 9/17/15.
//

#include "Point.h"
#include "Cluster.h"
#include <cassert>


using namespace std;
using namespace Clustering;

int main(){

    //Test constructors

    double pArray[4] = {1, 2, 3, 4};
    Point p1(4, pArray);
    Point p2(p1);
    Point p3(4);
    double distance = 0;



    cout << "p1 = " << p1;
    cout << endl;

    cout << "p2 = " << p2;
    cout << endl;

    //Test setValue function

    p3.setValue(0, 4);
    p3.setValue(1, 5);
    p3.setValue(2, 6);
    p3.setValue(3, 7);

    //Test getValue function

    cout << "p3 = ";

    for (int i = 0; i < 4; i++)
        cout << p3.getValue(i) << " ";
    cout << endl;


    //Test distanceTo function

    distance = p3.distanceTo(p1);
    cout << "Distance from P3 to P1 = " << distance;
    cout << endl;

    //Test *=, /=, += and -= operators

    p1 *= 3;
    cout << "p1 *= 3 is " << p1;
    cout << endl;

    p1 /= 2;
    cout << "p1 /= 2 is " << p1;
    cout << endl;

    p1 += p2;
    cout << "p1 += p2 is " << p1;
    cout << endl;

    p1 -= p2;
    cout << "p1 -= p2 is " << p1;
    cout << endl;

    // Test *, /, +, and - operators

    p1 * 2;
    cout << "p1 * 2 is " << p1;
    cout << endl;

    p1 / 3;
    cout << "p1 / 3 is " << p1;
    cout << endl;

    p3 = p1 + p2;
    cout << "p1 + p2 is " << p3;
    cout << endl;

    p1 = p3 - p2;
    cout << "p3 - p2 is " << p1;
    cout << endl;

    //Test the boolean operators

    assert(p2 == p1);
    assert(p3 != p1);
    assert(p2 < p3);
    assert(p3 > p2);
    assert(p2 <= p3);
    assert(p1 >= p2);

    cout << "assert testing of boolean operators complete" << endl;

    Cluster c1;
    Cluster c2;




    return 0;
};