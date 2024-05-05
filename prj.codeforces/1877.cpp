#include <iostream>


int main(){
   int t;
   std::cin >> t;
   while(t--){
      int n;
      std::cin >> n;
      int sum = 0;
      for(int i = 0 ;i < n-1;i++){
        int x;
        std::cin >> x;
        sum += x;
      }
      std::cout << -sum << '\n';
   }
}