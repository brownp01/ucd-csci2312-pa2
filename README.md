#Programming Assignment 2 for CSCI2312

#Point class

The requirements for the Point class are as follows:

Point-s should be able to have an arbitrary number of dimensions of doubles. That is, (1, 2), (1, 2, 4), (2, 3, ..., 5, 6), etc. You need to:
Add a private dim member.
Create at least one constructor which takes an int for the dimension. Optionally, a second constructor which takes an int and an array of double-s. Of course, the array has to be at least as big as the dimension value. You will have to decide if it makes sense to have a default constructor and what initialization it should do.
Take care of all consequences of this change, including updating the distanceTo() function.
Since the dimension could be potentially very large, you have to allocate it dynamically, and take care of all cleanup. Memory leaks will be penalized.
Remember what dynamic allocation means: overload the "big three".
Point objects should be comparable. You need to:
Overload the comparison operators: ==, !=, <, >, <=, and >=. Hint: reuse the implementation of == for !=, and so on. This makes the implementation more consistent, easy to ready, and less error prone.
Assume a lexicographic order, that is, (3, 4, 5) > (1, 2, 3) > (-1, 2, 3) > (-1, 1, 3) > (-1, 1, 2), etc. In other words, compare the first dimension, then the second, and so on.
Point arithmetic should be allowed. You need to:
Overload the arithmetic operators: +, -. Addition and subtraction should be dimension-wise, that is, (1, 2, 3) + (4, 5, 6) gives (5, 7, 9). Similar with subtraction.
Create factor-wise multiplication and division: *, /. That is, if p1 is a point (1, 2, 3), then p1*4 should give a point (4, 8, 12). Similar for division. (Remember to disallow division by zero.) Factors should be doubles.
Overload the compound assignment operators according to the rules in (1) and (2) above: +=, -=, *=, and /=.
