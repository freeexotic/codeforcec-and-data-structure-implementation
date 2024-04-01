#include <iostream>


int main(){
    int t,n;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n;
        int v[n];
        int sl=INT_MAX,tl=INT_MAX,i,count=0;
        for(i=0;i<n;i++)
        {
            std::cin>>v[i];
            if(sl>tl)
            std::swap(sl,tl);
            if(v[i]<=sl)
            sl=v[i];
            else if(v[i]<=tl)
            tl=v[i];
            else 
            {
                sl=v[i];
                count++;
            }
        }
        std::cout<<count<<std::endl;
    }
    return 0;
}