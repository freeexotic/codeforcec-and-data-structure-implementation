#pragma once
#ifndef QUEUELSTPR
#define QUEUELSTPR

#include <cstddef>
#include <memory>

class QueueLstPr {
public:
  QueueLstPr() = default;

  QueueLstPr(const QueueLstPr&);
  QueueLstPr(QueueLstPr&&);

  ~QueueLstPr();

  [[nodiscard]] QueueLstPr& operator=(const QueueLstPr&);
  [[nodiscard]] QueueLstPr& operator=(QueueLstPr&&) noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const float& val);

  [[nodiscard]] float& Top();

  [[nodiscard]] const float& Top() const;

  void Clear() noexcept;

  int Size() { return size_; }
private:
  struct Node {
    Node(const float& v, std::shared_ptr<Node>n) : val(v) { next = n; }
    float val;
    std::shared_ptr<Node> next = nullptr;
  };

  std::shared_ptr<Node> head_ = nullptr;
  std::shared_ptr<Node> tail_ = nullptr;
  int size_ = 0;
};

#endif