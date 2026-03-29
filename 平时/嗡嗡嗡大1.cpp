#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int mv1[]={-1,1,-1,1,-2,2,-2,2};
int mv2[]={2,2,-2,-2,1,1,-1,-1};
int main(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<ll>>dp(30,vector<ll>(30,0));
    vector<vector<ll>>mp(30,vector<ll>(30,0));
    mp[x][y]=1;
    for(int i=0;i<8;i++){
        if(x+mv1[i]<0||x+mv1[i]>n||y+mv2[i]<0||y+mv2[i]>m)continue;
        mp[x+mv1[i]][y+mv2[i]]++;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(mp[i][j])continue;
            if(i==0&&j==0)dp[i][j]=1;
            else if(i==0)dp[i][j]=dp[i][j-1];
            else if(j==0)dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][m];
}