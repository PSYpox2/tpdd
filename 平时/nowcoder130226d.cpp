#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k;string s;
    cin>>n>>k>>s;
    map<string,int>mp;
    string s0;
    for(int i=0;i<n;i++){
        if(i<k){
            s0+=s[i];
        }
        else{
            mp[s0]++;
            s0.erase(0,1);
            s0+=s[i];
        }
    }
    int cnt=0;
    for(auto psy:mp){
        if(psy.second>1)cnt++;
    }
    cout<<cnt;
}