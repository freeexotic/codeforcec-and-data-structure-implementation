#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::vector<int> buf;
    int t;
    int key = 0;
    std::cin >> t;
    while(t-->0){
        int n;
        std::cin >> n;
        std::vector<int> arr_(n);
        for (int i = 0; i!=n; i++){
            int num;
            std::cin >> num;
            arr_[i]=num;
        }
        int index = 0;
        for (int i = 0; i!=n-1; i++){
            if (arr_[index] <= arr_[index + 1]){
                index++;
            }
            else {
                if (arr_[index] < 10){
                    if (arr_[index+1]>=10){
                        n++;
                        int first_ind = arr_[index+1]/10;
                        int second_ind = arr_[index+1]%10;
                        arr_.erase(arr_.begin() + index+1 );
                        arr_.insert(arr_.begin()+index+1, first_ind );
                        arr_.insert(arr_.begin()+index +2, second_ind );
                    }
                    else{
                        std::cout << "NO" << std::endl;
                        key++;
                        break;
                    }

                }
                else {
                    n++;
                    int first_ind = arr_[index]/10;
                    int second_ind = arr_[index]%10;
                    arr_.erase(arr_.begin() + index );
                    arr_.insert(arr_.begin()+index, first_ind );
                    arr_.insert(arr_.begin()+index +1, second_ind );
                    index--;

                }
            }
        }
        buf = arr_;
        std::sort(arr_.begin(), arr_.end());
        if (arr_ == buf){
            std::cout << "YES" << std::endl;
        }
        else if (key==0) {
            std::cout << "NO" << std::endl;
        }
    }
}