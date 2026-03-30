#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int main(){
    int n,s,mx;
    cin>>n>>s>>mx;
    vector<int>a(n+7);
    for(int i=1;i<=n;i++){cin>>a[i];}
    vector<vector<int>>dp(n+7,vector<int>(mx+7,0));
    dp[0][s]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=mx;j++){
            if(dp[i-1][j]&&j+a[i]<=mx)dp[i][j+a[i]]=1;
            if(dp[i-1][j]&&j-a[i]>=0)dp[i][j-a[i]]=1;
        }
    }
    for(int i=mx;i>=0;i--){
        if(dp[n][i]){cout<<i;return 0;}
    }
    cout<<-1;
}