#include <stackarrt/stackarrt.hpp>
#include <chrono>
#include <iostream>




int main(){
    std::chrono::duration<double, std::micro>;
    StackArrT<int> a;
    auto begin = std::chrono::steady_clock::now();
    for (int i=0; i!=1000000000; ++i){
        a.Push(i);
    }

    auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double, std::micro> time = end - begin;
    std::cout << "Time micro push: " << time.count()<< '\n';
    std::cout << "Time micro pop: " << time.count()<< '\n';
}
