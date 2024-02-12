#ifndef STACKARR_H_240210
#define STACKARR_H_240210


#include <iosfwd>

class StackArr {
public:
   [[nodiscard]] StackArr() = default;
   [[nodiscard]] StackArr(const StackArr&) = default;
   [[nodiscard]] StackArr(int size_) : size(size_) {}
   ~StackArr() = default; 

   [[nodiscard]] StackArr& operator= (const StackArr&) = default;
   

   int pop(){

}
   void push(){

}
private:
   int size;
   int level; 
};

#endif 

// data null_ptr