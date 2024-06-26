#include <queuelstpr/queuelstpr.hpp>
#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& other) {
  if (other.head_ != nullptr)
  {
    head_ = std::make_shared<Node>(Node(other.head_->val, nullptr));
    std::shared_ptr<Node> a = head_;
    std::shared_ptr<Node> b = other.head_->next;
    while (b != nullptr)
    {
      std::shared_ptr<Node> tmp = std::make_shared<Node>(Node(b->val, nullptr));
      a->next = tmp;
      a = tmp;
      b = b->next;
    }
    tail_ = a;
    size_ = other.size_;
  }
}

QueueLstPr::QueueLstPr(QueueLstPr&& rhs)
  : head_(rhs.head_), tail_(rhs.tail_), size_(rhs.size_)
{
  rhs.head_ = rhs.tail_ = nullptr;
  rhs.size_ = 0;
}

QueueLstPr::~QueueLstPr() {
  while (head_ != nullptr) {
    std::shared_ptr<Node> tmp = head_->next;
    head_.reset();
    head_ = tmp;
  }
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
  if (rhs.head_ != nullptr) {
    std::shared_ptr<Node> a = head_;
    if (a == nullptr)
    {
      a = std::make_shared<Node>(Node(float(), nullptr));
      head_ = a;
      tail_ = a;
    }
    std::shared_ptr<Node> b = rhs.head_;
    while (b != rhs.tail_) {
      if (a == tail_)
      {
        a->next = std::make_shared<Node>(Node(float(), nullptr));
        tail_ = a->next;
      }
      a->val = b->val;
      a = a->next;
      b = b->next;
    }
    a->val = b->val;
    while (a->next != nullptr)
    {
      std::shared_ptr<Node> tmp = a->next;
      a->next = a->next->next;
      tmp.reset();
    }
    tail_ = a;
  }
  else {
    while (head_ != nullptr) {
      std::shared_ptr<Node> tmp = head_->next;
      head_.reset();
      head_ = tmp;
    }
    tail_ = nullptr;
  }
  size_ = rhs.size_;
  return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept
{
  std::swap(head_, rhs.head_);
  std::swap(tail_, rhs.tail_);
  std::swap(size_, rhs.size_);
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void QueueLstPr::Pop() noexcept {
  if (!IsEmpty()) {
    std::shared_ptr<Node> tmp = head_->next;
    head_.reset();
    head_ = tmp;
    if (head_ == nullptr)
      tail_ = nullptr;
    
    size_--;
  }
}

void QueueLstPr::Push(const float& val) {
  if (tail_ == nullptr)
  {
    tail_ = std::make_shared<Node>(Node(val, nullptr));
    head_ = tail_;
    size_ = 1;
  }
  else
  {
    std::shared_ptr<Node> node = head_;
    std::shared_ptr<Node> pred_node = nullptr;
    while (node != tail_ && node->val < val)
    {
      pred_node = node;
      node = node->next;
    }

    if (node != tail_)
    {
      if (node == head_)
      {
        std::shared_ptr<Node> tmp = std::make_shared<Node>(Node(val, head_));
        head_ = tmp;
      }
      else
      {
        std::shared_ptr<Node> tmp = std::make_shared<Node>(Node(val, node));
        pred_node->next = tmp;
      }
    }
    else
    {
      if (val < tail_->val)
      {
        std::shared_ptr<Node> tmp = std::make_shared<Node>(Node(val, tail_));
        if (pred_node != nullptr) pred_node->next = tmp;
        else head_ = tmp;
      }
      else
      {
        std::shared_ptr<Node> tmp = std::make_shared<Node>(Node(val, nullptr));
        tail_->next = tmp;
        tail_ = tmp;
      }
    }

    ++size_;
  }
}

float& QueueLstPr::Top() {
  if (head_ == nullptr)
    throw std::out_of_range("Queue is empty");

  return head_->val;
}

const float& QueueLstPr::Top() const {
  if (head_ == nullptr)
    throw std::out_of_range("Queue is empty");

  return head_->val;
}

void QueueLstPr::Clear() noexcept {
  while (head_ != nullptr) {
    std::shared_ptr<Node> tmp = head_->next;
    head_.reset();
    head_ = tmp;
  }
  tail_ = nullptr;
  size_ = 0;
}