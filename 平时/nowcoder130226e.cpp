#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>>b(17);
void gg(int n){
    if(n<1)return;
    if(n==1){b[n]={1};return;}
    if(n==2){b[n]={1,1};return;}
    if(n>=3){
        gg(n-1);
        b[n].clear();
        b[n].push_back(1);
        for(int i=0;i<n-2;i++){
            b[n].push_back(b[n-1][i]+b[n-1][i+1]);
        }
        b[n].push_back(1);
    }
    return;
}
int n,sum;
bool c=0;
vector <int> a,ans;
vector<bool>bb(17,0);
void dfs(int deep,int cnt){
    if(cnt>sum||c){return;}
    if(deep>n&&cnt==sum){c=1;
        if(ans.empty()){ans=a;}
        else if(a<ans)ans=a;
        return;
    }
    for(int i=1;i<=n;i++){
        if(bb[i])continue;
        bb[i]=1;
        a.push_back(i);
        dfs(deep+1,cnt+i*b[n][deep-1]);
        a.pop_back();
        bb[i]=0;
    }
    return;
}
int main(){
    gg(15);
    cin>>n>>sum;
    if(n==1){cout<<1;return 0;}
    dfs(1,0);
    for(int psy:ans){
        cout<<psy<<" ";
    }
}