#include <iostream>

int main(){
    int t;
    std::cin >> t;
    for (int i = 0; i != t ; ++i){
        int n,k;
        std::cin >> n >> k;
        int o = n-k;
        for (int p =o; p!=0; --p){
            std::cout << p << " ";
        }
        for (int u = o +1 ; u!=n+1; ++u){
            std::cout << u << " ";
        }
    }
}