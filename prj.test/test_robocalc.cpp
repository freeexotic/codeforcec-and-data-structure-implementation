//
// Created by Всеволод Силаев on 13.05.2024.
//
#include<robocalc/robocalc.hpp>
#include <iostream>

int main() {
    RoboCalc a;
    std::string com;
    double val;
    int i = 0;

    while(i != 100){
        std::cin >> com;
        std::cin >> val;
        if(com == "MUL" || com == "DIV" || com == "OUT" || com == "REV" || com == "SUB" || com == "ADD"){
            if (com == "REV"){
                int num = val;
                a.REV(num);
                continue;
            }
            else if (com == "OUT"){
                std::cout << a.OUT(val) << std::endl;
                continue;
            }
            else {
                a.Push(com, val);
            }
            i++;
        }
        else{
            std::cout << "ERROR";
            break;
        }
    }
}
