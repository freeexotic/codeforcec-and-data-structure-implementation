
#ifndef SILAEV_V_V_23_03_QUEUELSTR_HPP
#define SILAEV_V_V_23_03_QUEUELSTR_HPP

class Node {
public:
    Node* up;
    float data;
    Node() = default;
    Node(float data_) : data(data_), up(nullptr) {}
    ~Node() = default;
};

class QueueLstR {
public:
    QueueLstR() = default;
    QueueLstR(const QueueLstR&) = default;
    ~QueueLstR() = default;

    void Pop() noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept;
    void Push(const float& val);

private:
    Node* head = nullptr;
    int size_ = 0;
};

#endif //SILAEV_V_V_23_03_QUEUELSTR_HPP
