#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
struct g{
    int a,b,c;
};
bool cmp(g a,g b){
    return a.a<b.a;
}
const int N=1e8+19;
const int N1=1e8+19;
int shai[N+7];
bool vis[N1+7];
int oula(int n){
    int cnt=0;
    memset(vis,0,sizeof(vis));
    memset(shai,0,sizeof(shai));
    for(int i=2;i<=n;i++){
        if(!vis[i]){shai[cnt++]=i;}
        for(int j=0;j<cnt;j++){
            if(i*shai[j]>n)break;
            vis[i*shai[j]]=1;
            if(i%shai[j]==0)break;
        }
    }
    return cnt;
}
void f(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int w;
        cin>>w;
        cout<<shai[w-1]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    //int t;cin>>t;while(t--)
    oula(N1);f();
}