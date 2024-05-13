#ifndef SILAEV_V_V_23_03_ROBOCALC_HPP
#define SILAEV_V_V_23_03_ROBOCALC_HPP

#include <stdexcept>
#include <cstddef>
#include <string>

class RoboCalc final {
public:
    RoboCalc() = default;

    ~RoboCalc() = default;

    double ADD(double &com, double &out) noexcept;
    double SUB(double &com, double &out) noexcept;
    double MUL(double &com, double &out) noexcept;
    double DIV(double &com, double &out) noexcept;
    double REV(int &num) noexcept;
    double OUT(double &out) noexcept;

    int Size() const noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;
    void Push(const std::string &com, const double &val);
    double Desk(const std::string &com, double &val, double& out);

private:

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
