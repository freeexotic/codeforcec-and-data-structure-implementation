// 1950B масштабирование

#include <iostream>

int main(){
int t;
std::cin >> t;
for(int u = 0; u!=t; u++){
    int n;
    std::cin >> n;
    if (n%2 == 0){
        for (int i = 0; i!=(n/2); i++){
            for (int l = 0; l!=2; l++){
                for( int j = 0; j!=n/2; j++){
                    std::cout << "##..";
                }
                std::cout << std::endl;
            }
            for (int l = 0; l!=2; l++){
                for( int j = 0; j!=n/2; j++){
                    std::cout << "..##";
                }
                std::cout << std::endl;
            }
       }
    }
    else{
        for (int i = 0; i!=(n/2); i++){
            for (int l = 0; l!=2; l++){
                for( int j = 0; j!=n/2; j++){
                    std::cout << "##..";
                }
                std::cout << "##";
                std::cout << std::endl;
            }
            for (int l = 0; l!=2; l++){
                for( int j = 0; j!=n/2; j++){
                    std::cout << "..##";
                }
                std::cout << "..";
                std::cout << std::endl;
            } 
       }
       for (int l = 0; l!=2; l++){
                for( int j = 0; j!=n/2; j++){
                    std::cout << "##..";
                }
                std::cout << "##";
                std::cout << std::endl;
            }
    }
}
}