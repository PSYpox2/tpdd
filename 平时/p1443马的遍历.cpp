#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pii pair<int,int>
#define x first 
#define y second
pii mv[]={{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,-2},{-1,2}};
int main(){
    int n,m,x1,y1;
    cin>>n>>m>>x1>>y1;
    vector<vector<int>>s(n+7,vector<int>(m+7,-1));
    s[x1-1][y1-1]=0;
    queue<pii>q;
    q.push({x1-1,y1-1});
    while(!q.empty()){
        int x0=q.front().x,y0=q.front().y;
        q.pop();
        for(int i=0;i<8;i++){
            if(x0+mv[i].x<0||x0+mv[i].x>=n
             ||y0+mv[i].y<0||y0+mv[i].y>=m)continue;
            if(s[x0+mv[i].x][y0+mv[i].y]!=-1||
                (x0+mv[i].x==x1-1&&y0+mv[i].y==y1-1))continue;
            q.push({x0+mv[i].x,y0+mv[i].y});            
            s[x0+mv[i].x][y0+mv[i].y]=s[x0][y0]+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<'\n';
    }
}