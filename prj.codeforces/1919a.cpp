#include <iostream>


int main() {

  int n;
  std::cin>>n;
  
  while(n--){
    int x,y;
    std::cin>>x>>y;
    int z = (x+y);
    if(z%2 == 0){
      std::cout<<"Bob"<<std::endl;
    }
    else{
      std::cout<<"Alice"<<std::endl;
    }
  }
  return 0;
}