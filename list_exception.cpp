#include "list_exception.h"
#include <iostream>
using namespace std;
 const char* EmptyList::what() const throw()
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

/*
int main (){
  try
      {
      	throw  EmptyList();
        throw  NegativeIndex();
        throw  OutOfRange();
      }
      catch ( OutOfRange& e)
      {
      	std::cout << "MyException caught" << std::endl;
          std::cout << e.what() << std::endl;
      }
}
*/
