#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
void f(){
    int n;
    cin>>n;
    vector<ll>a(n);
    map<ll,ll>mp;
    for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;}
    sort(all(a));
    vector<pii>b;
    for(auto psy:mp){
        if(psy.second>1){
            b.push_back({psy.x,psy.y-1});
        }
    }
    ll sum=0;
    for(pii p:b){
        ll cnt=1;
        while(p.y--){
            while(mp[p.x+cnt]>0)cnt++;
            sum+=cnt;
            mp[p.x+cnt]++;
        }
    }
    cout<<sum<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;while(t--)
    f();
}