#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll> v0;
        ll count0=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                count0++;
            }
        }
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='0'){
                v0.push_back(n-i);
            }
        }
        ll prev=0;
        for(ll i=1;i<=count0;i++){
            prev+=abs(v0[i-1]-i);
            cout<<prev<<" ";
        }
        for(ll i=1;i<=(n-count0);i++){
            cout<<"-1 ";
        }
        cout<<endl;
    }
    return 0;
}