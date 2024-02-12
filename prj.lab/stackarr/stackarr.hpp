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
   

   int Pop() noexcept;
   void Push( const &Complex value);
   void Clear() noexcept;
private:
   int size = 0;
   int level = -1 ;// индекс верхнего элемента (-1 - если пустой)
};

#endif 

// data null_ptr