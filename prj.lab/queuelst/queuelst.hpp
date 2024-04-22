#ifndef SILAEV_V_V_23_03_QUEUELST_HPP
#define SILAEV_V_V_23_03_QUEUELST_HPP

#include <complex/complex.hpp>
#include <iostream>
#include <cstddef>

class QueueLst final {
public:
    QueueLst() = default;

    QueueLst(const QueueLst& qul);

    QueueLst(QueueLst&& qul) noexcept;

    ~QueueLst() = default;

    QueueLst& operator=(const QueueLst& qul);

    QueueLst& operator=(QueueLst&& qul) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& data);

    [[nodiscard]] Complex& Top() &;

    [[nodiscard]] const Complex& Top() const &;

    void Clear() noexcept;

private:
    struct Node {
        Complex val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

#endif //SILAEV_V_V_23_03_QUEUELST_HPP
