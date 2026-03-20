#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
struct g{
    ll a,b,c;
};
bool cmp(g a,g b){
    return a.a<b.a;
}
bool cmp1(g a,g b){
    return a.b>b.b;
}
void f(){
    int n;cin>>n;
    vector<g>a(n);
    for(int i=0;i<n;i++){cin>>a[i].a>>a[i].b;a[i].c=i;}
    ll w=0;vector<g>b(a);
    sort(all(a),cmp);
    sort(all(b),cmp1);
    map<int,int>mp;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll v=0;
        sum+=b[i].b;
        mp[b[i].c]++;
        for(int i=0;i<n;i++)
        if(mp[a[i].c]==0){
            int sum0=sum;
            if(sum>a[i].a)sum0-=a[i].a,v++;
        }
        w=max(w,v);
    }
    cout<<w<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;while(t--)
    f();
}