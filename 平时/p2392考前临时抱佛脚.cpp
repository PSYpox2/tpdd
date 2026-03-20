#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//dp
// int ans=0;
// int dp[5000];
// int main(){
//     vector<int>a(30);
//     int a0[5]={0};
//     for(int i=1;i<=4;i++)cin>>a0[i];
//     for(int i=1;i<=4;i++){
// 		int sum=0;
//         for(int j=1;j<=a0[i];j++){
//             cin>>a[j];
// 			sum+=a[j];
//         }
// 		for(int j=1;j<=a0[i];j++)for(int k=sum/2;k>=a[j];k--)dp[k]=max(dp[k],dp[k-a[j]]+a[j]);
// 		ans+=sum-dp[sum/2];
// 		for(int j=1;j<=sum/2;j++)dp[j]=0;
// 	}
//     cout<<ans;
// }

//dfs
int ans=0,an=0;
vector<int>a(30,0);
void dfs(int deep,int l,int r,int w){
    if(deep>=w){
        an=min(max(l,r),an);
        return;
    }
    l+=a[deep];
    dfs(deep+1,l,r,w);
    l-=a[deep];
    r+=a[deep];
    dfs(deep+1,l,r,w);
    r-=a[deep];
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a0[4];
    for(int i=0;i<4;i++)cin>>a0[i];
    for(int i=0;i<4;i++){
        for(int j=0;j<a0[i];j++){
            cin>>a[j];
        }
        an=INT_MAX;
        dfs(0,0,0,a0[i]);
        ans+=an;
              
    }
    cout<<ans;
}