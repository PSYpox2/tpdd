#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second
int mv1[]={1,-1,0,0};
int mv2[]={0,0,1,-1};
ll mx=LLONG_MAX;
ll n,m;
pair<ll,ll>st,en;
ll cnt=0;
vector<vector<ll>>a(11,vector<ll>(11,0));
vector<vector<vector<ll>>>bb;
void dfs(int x,int y,int step){
    if(step==0||cnt>m*n||cnt>mx)return;
    if(a[x][y]==4)step=6;
    if(bb[x][y][step]<=cnt)return;
    bb[x][y][step]=cnt;
    if(x==en.x&&y==en.y)mx=min(cnt,mx);
    else{
        for(int i=0;i<4;i++){
            st.x=x+mv1[i];
            st.y=y+mv2[i];
            if(st.x<=0||st.y<=0||st.x>n||st.y>m||a[st.x][st.y]==0)continue;
            cnt++;
            dfs(st.x,st.y,step-1);
            cnt--;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bb.assign(n+2,vector<vector<ll>>(m+2,vector<ll>(7,LLONG_MAX)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==2)st={i,j};
            if(a[i][j]==3)en={i,j};
        }
    }
    dfs(st.x, st.y, 6);
    cout<<((mx==LLONG_MAX)?-1:mx)<<endl;
}