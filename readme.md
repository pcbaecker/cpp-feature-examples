# C++ feature examples

This project contains some examples of new features or c++ special things.

### Does a custom class in an STL container need a custom move constructor?

In the example StlAndMoveConstructor.cpp we can see that there is no difference between the classes with and without 
a custom move constructor. That is, because the compiler will generate a default move constructor if the user is not 
providing a custom one.