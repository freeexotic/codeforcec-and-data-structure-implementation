
#ifndef SILAEV_V_V_23_03_QUEUELST_HPP
#define SILAEV_V_V_23_03_QUEUELST_HPP

#include <complex/complex.hpp>
#include <iostream>

struct Complex;

class Node {
public:
    Node* up;
    Complex data;
    Node() = default;
    Node(Complex data_) : data(data_), up(nullptr) {}
    ~Node() = default;
};

class Queue {
public:
    [[nodiscard]] Queue() = default;

    [[nodiscard]] Queue(const Queue&) = default;

    ~Queue() = default;

   //?????? [[nodiscard]] Queue& operator=(const Queue&) = default;

    bool IsEmpty() const noexcept; //done

    void Pop() noexcept;

    void Push(const Complex& val); // done

    Complex& Top();

    const Complex& Top() const;

    void Clear() noexcept;

    int Size() noexcept; // done

private:
    int size_ = 0; //! < количество ячеек в очереди
    Node* head = nullptr;
    Node* tail = nullptr;

};

#endif //SILAEV_V_V_23_03_QUEUELST_HPP