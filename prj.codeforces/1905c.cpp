#include <iostream>
#include <vector>
#include<string>
#include <map>

int main()
{
    int tc;
    std::cin>>tc;
    std::map <long,long> mp;
    while(tc--)
    {
        long n,c=0,i,j;
        std::cin>>n;
        std::string s,p;
        std::cin>>s;
        p=s;
        std::sort(p.begin(),p.end());
        if(s==p){
            std::cout<<0<<std::endl;
            continue;
        }
        char cc=s[n-1],l;
        std::vector<long>v;
        std::string ss;
        for(i=n-1; i>=0; i--)
        {
            if(s[i]>=cc)
            {
                v.push_back(i);
                ss+=s[i];
                cc=s[i];
            }
        }
        long cnt=0;
        for(i=ss.size()-1;i>=0;i--){
                if(ss[i]==ss.back())cnt++;
                else break;
        }
        std::reverse(ss.begin(),ss.end());
        for(i=0; i<ss.size(); i++)
        {
            s[v[i]]=ss[i];
        }
        if(std::is_sorted(s.begin(),s.end()))
            std::cout<<ss.size()-cnt<<std::endl;
        else std::cout<<-1<<std::endl;
    }
}