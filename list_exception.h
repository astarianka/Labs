#ifndef LIST_EXCEPTION_INCLUDED
#define LIST_EXCEPTION_INCLUDED
#include <exception>
class EmptyList: public std::exception
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

#endif // LIST_EXCEPTION_INCLUDED
