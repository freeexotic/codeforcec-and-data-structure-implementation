#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while(t--){
        int n , k, sum;
        sum = 0;
        std::cin >> n >> k;
        std::vector<int> ships (n);
        for (int i = 0; i != n ; i ++){
            std::cin >> ships[i];
        }
        int pos = 0;
        int last = n-1;
        for (int i = 0 ; i !=k ; i ++){
            if (ships.size() == 0){
                break;
            }
            if (pos == 0){
                ships[0]--;
                if (ships[0] == 0){
                    ships.erase(ships.begin());
                    sum++;
                    last--;
                }
                pos = 1;
            }
            else if (pos == 1){
                ships[last]--;
                if (ships[last] == 0){
                    ships.erase(ships.begin() + last);
                    sum++;
                    last--;
                }
                pos = 0;
            }
        }
        std::cout << sum << std::endl;
    }
}
