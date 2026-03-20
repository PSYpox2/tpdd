#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
int sum=0;
vector<int>a(27,0);
bool g(int v){
    if(v==1)return 0;
    for(int i=2;i*i<=v;i++){
        if(v%i==0)return 0;
    }
    return 1;
}
void dfs(int w,int v,int deep){
    if(w==k){
        //cout<<v;
        if(g(v))sum++;
        return;
    }
    for(int i=deep;i<=n-k+w+1;i++){
        dfs(w+1,v+a[i],i+1);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0,1);
    cout<<sum;
}