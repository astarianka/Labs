#ifndef TREE_EXCEPTION_INCLUDED
#define TREE_EXCEPTION_INCLUDED
#include <exception>
class EmptyTree: public std::exception
 {
 public:
   virtual const char* what() const throw();
};
class NegativeIndex: public std::exception
 {
 public:
   virtual const char* what() const throw();
};
class OutOfRange: public std::exception
 {
 public:
   virtual const char* what() const throw();
};

#endif // TREE_EXCEPTION_INCLUDED
