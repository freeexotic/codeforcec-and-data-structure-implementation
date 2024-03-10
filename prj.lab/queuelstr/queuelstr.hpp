#ifndef SILAEV_V_V_23_03_QUEUELSTR_HPP
#define SILAEV_V_V_23_03_QUEUELSTR_HPP

class Node {
public:
    Node* up = nullptr;
    float data = 1.5;
    Node() = default;
    Node(float data_) : data(data_), up(nullptr) {}
    ~Node() = default;
};

class QueueLstR {
public:
    QueueLstR() = default;
    QueueLstR(const QueueLstR&) = default;
    ~QueueLstR() = default;

    float Top() noexcept;
    void Pop() noexcept;
    int Size() noexcept;
    bool IsEmpty() const noexcept;
    void Push(const float& val);

private:
    Node* head;
    int size_ = 0;
};

#endif //SILAEV_V_V_23_03_QUEUELSTR_HPP
