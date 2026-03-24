#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
int ans=INT_MAX;
int n;vector<pll>a(11);
void dfs(int deep,int s,int k){
    if(deep>n){
        if(s==1&&k==0)return;
        ans=min(abs(s-k),ans);
        return;
    }
    dfs(deep+1,s*a[deep].x,k+a[deep].y);
    dfs(deep+1,s,k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    dfs(1,1,0);
    cout<<ans<<endl;
}