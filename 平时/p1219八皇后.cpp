#include<bits/stdc++.h>
using ll=long long;
using namespace std;
vector<vector<int>>a;
vector<vector<int>>b(3,vector<int>(107,0));
int n;
void dfs(vector<int>s,int deep){
    if(s.size()==n){
        a.push_back(s);
        return;
    }    
    if(deep>n)return;
    for(int i=1;i<=n;i++){
        if(b[0][i]==1||b[1][i+deep]==1||b[2][i-deep+n]==1)continue;
        b[0][i]=1,b[1][i+deep]=1,b[2][i-deep+n]=1;
        vector<int>s0(s);s0.push_back(i);
        dfs(s0,deep+1);
        b[0][i]=0,b[1][i+deep]=0,b[2][i-deep+n]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int>s;
    dfs(s,1);
    sort(a.begin(),a.end());
    for(int i=0;i<3;i++){
        for(int psy:a[i])cout<<psy<<" ";
        cout<<endl;
    }
    cout<<a.size()<<endl;
}