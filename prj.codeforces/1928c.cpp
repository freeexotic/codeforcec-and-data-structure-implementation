#include <iostream>
#include <vector>

int main() {
    #define int long long
    int count;
    std::cin>>count;
    for (;count-- > 0;){
        int x, n;
        std::cin>>n>>x;
        if (n%2!= x%2){
            std::cout<<0;
        }else{
            int c = 0;
            for (int i = 2; i < n; i++){
                if((n % (i + i - 2) == x && n % (i + i - 2) <= i) || (n % (i + i - 2) == 0 && x == 2) || (n % (i + i - 2) > i && n % (i + i - 2) - i == i - x)){
                    c++;
                    }
            }
            std::cout<<c<<"\n";
        }
    }
    return 0;
}
