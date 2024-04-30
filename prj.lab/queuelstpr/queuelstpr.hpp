#pragma once
#ifndef SILAEV_QUEUELSTPR_HPP_20240324
#define SILAEV_QUEUELSTPR_HPP_20240324

#include <cstddef>

class QueueLstPr {
public:
    QueueLstPr() = default;

    QueueLstPr(const QueueLstPr&) = default;
    QueueLstPr(QueueLstPr&&) = default;

    ~QueueLstPr() = default;

    [[nodiscard]] QueueLstPr& operator=(const QueueLstPr&) = default;
    [[nodiscard]] QueueLstPr& operator=(QueueLstPr&&) = default;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const float& val);

    [[nodiscard]] float& Top();

    [[nodiscard]] const float& Top() const;

    void Clear() noexcept;

private:
    struct Node {
        float val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};

#endif