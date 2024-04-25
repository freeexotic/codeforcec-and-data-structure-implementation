//
// Created by Всеволод Силаев on 25.04.2024.
//
#include <iostream>
#include <string>

int main() {
    int a, b, x;
    std::cin >> a >> b >> x;
    std::string s;
    bool turn = a > b;
    while (x >= 0) {
        if (turn) {
            if (a > 0) {
                s += "0";
                a--;
            }
        } else {
            if (b > 0) {
                s += "1";
                b--;
            }
        }
        turn = !turn;
        x--;
    }
    while (a > 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                s.insert(i, 1, '0');
                break;
            }
        }
        a--;
    }
    while (b > 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                s.insert(i, 1, '1');
                break;
            }
        }
        b--;
    }
    std::cout << s << "\n";
    return 0;
}