#include <iostream>
#include <unordered_map>

int main() {
    int t;
    std::cin>> t;
    while(t--){
        int n;
        std::cin>>n;
        std::unordered_map <char, int> m;
        std::string s;
        std::cin>> s;
        for(auto c: s){
            m[c]++;
        }
        std::cout<<abs(m['+']-m['-'])<<std::endl;
    }
    return 0;
}