#ifndef SILAEV_V_V_23_03_ROBOCALC_HPP
#define SILAEV_V_V_23_03_ROBOCALC_HPP

#include <stdexcept>
#include <cstddef>
#include <string>

class RoboCalc final {
public:
    RoboCalc() = default;

    ~RoboCalc();

    void ADD(double &com, double &out) noexcept;
    void SUB(double &com, double &out) noexcept;
    void MUL(double &com, double &out) noexcept;
    void DIV(double &com, double &out) noexcept;
    void REV(double &com, double &out) noexcept;
    double OUT(double &out) noexcept;

    int Size() const noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

private:
    void Pop() noexcept;
    void Push(const std::string &com, const double &val);

    struct Node {
        std::string data_com;
        double data_val;
        Node* next = nullptr;
    };

    int size_ = 0;
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

#endif //SILAEV_V_V_23_03_ROBOCALC_HPP
