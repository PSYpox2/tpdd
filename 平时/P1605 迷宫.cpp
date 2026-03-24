#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
int mv[]={-1,0,1,0,-1};
int n,m,t,ans;
int s[10][10]={0};
bool bb[10][10]={0};
int x0,y0,x1,y1;
void dfs(int x,int y){
    if(x==x1&&y==y1){ans++;return;}
    for(int i=0;i<4;i++){
        int x2=x+mv[i],y2=y+mv[i+1];
        if(x2<1||x2>n||y2<1||y2>m||bb[x2][y2]||s[x2][y2]==-1){
            continue;
        }
        bb[x2][y2]=1;
        dfs(x2,y2);
        bb[x2][y2]=0;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>t>>x0>>y0>>x1>>y1;
    while(t--){
        int w,v;cin>>w>>v;
        s[w][v]=-1;
    }
    bb[x0][y0]=1;
    dfs(x0,y0);cout<<ans<<endl;
    return 0;
}