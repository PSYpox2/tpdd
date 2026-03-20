#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--){
        int n,m;cin>>n>>m;
        vector<int> a(n),b(m);
        for(int& x:a)cin>>x;
        for(int& x:b)cin>>x;
        int g=a[0];
        for(int x:a)g=gcd(g,x);
        vector<int> c;
        for(int i=1;i*i<=g;++i)if(g%i==0){
            c.push_back(i);
            if(i!=g/i)c.push_back(g/i);
        }
        vector<unordered_map<int,int>> d(n);
        for(int i=0;i<n;++i){
            unordered_map<int,int> mp;
            queue<int> q;
            mp[a[i]]=0;
            q.push(a[i]);
            while(!q.empty()){
                int x=q.front();q.pop();
                int st=mp[x];
                for(int j=0;j<m;++j){
                    int y=gcd(x,b[j]);
                    if(y<x && !mp.count(y)){
                        mp[y]=st+1;
                        q.push(y);
                    }
                }
            }
            d[i]=move(mp);
        }
        int ans=1e9;
        for(int v:c){
            int sum=0,ok=1;
            for(int i=0;i<n;++i){
                auto it=d[i].find(v);
                if(it==d[i].end()){ok=0;break;}
                sum+=it->second;
            }
            if(ok)ans=min(ans,sum);
        }
        cout<<(ans==1e9?-1:ans)<<'\n';
    }
    return 0;
}