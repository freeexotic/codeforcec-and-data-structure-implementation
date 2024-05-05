#include <chrono>
#include <stackarrt/stackarrt.hpp>
#include <iostream>



int main(){
    std::chrono::duration<double, std::micro>;
    StackArr a;
    auto begin = std::chrono::steady_clock::now();
    for (int i=0; i!=100000000; ++i){
        arr.Push(Complex(i,i));
    }

    auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double, std::micro> time = end - begin;
    std::cout << "Time micro push: " << time.count()<< '\n';
    std::cout << "Time micro pop: " << time.count()<< '\n';
}
