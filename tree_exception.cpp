#include "tree_exception.h"
#include <iostream>
using namespace std;
 const char* EmptyTree::what() const throw()
{
 return "List is empty";
}
const char* NegativeIndex::what() const throw()
{
return "Negative index was passed";
}
const char* OutOfRange::what() const throw()
{
return "Element is out of range";
}


