#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a,i) a.begin()+i,a.end()
int mv[]={-1,0,1,0,-1};
int main(){
    int m;
    cin>>m;
    vector<pair<int,pair<int,int>>>a(m);
    for(int i=0;i<m;i++){cin>>a[i].x>>a[i].y.x>>a[i].y.y;}
    queue<pii>q;
    q.push({0,0});
    int s[307][307]={0};
    for(int i=0;i<m;i++){
        s[a[i].y.x][a[i].y.y]-=a[i].x;
        for(int j=0;j<4;j++){
            s[a[i].y.x+mv[j]][a[i].y.y+mv[j+1]]-=a[i].x;
        }
    }
    while(!q.empty()){
        
    }
}