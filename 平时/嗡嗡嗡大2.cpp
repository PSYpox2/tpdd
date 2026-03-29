#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<vector<int>>a(n);
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++){
        int w,v,u;
        cin>>w>>v>>u;
        a[w].push_back(v);
        a[v].push_back(w);
        mp[{w,v}]=min(u,mp[{w,v}]);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({s,0});
    while(!q.empty()){
        int x=q.top().x;
        q.pop();
    }
}