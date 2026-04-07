#include <cstdio>
#include <iostream>
#include <cstring> 
#include <cmath> 
#include <vector>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
using ll=long long;
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first 
#define y second
vector<pdd>a(17);
vector<vector<double>>b(17,vector<double>(17,0));
vector<vector<double>>dp(18,vector<double>(32777,INT_MAX));
double g(int x,int y){
    return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
    a[0].x=a[0].y=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        b[i][j]=g(i,j);
        b[j][i]=b[i][j];
    }
    for(int i=1;i<=n;i++){
        dp[i][(1<<(i-1))]=b[0][i];
    }
    for(int l=1;l<(1<<n);l++){
        for(int i=1;i<=n;i++){
            if((l&(1<<(i-1)))==0)continue;
            for(int j=1;j<=n;j++){
                if(i==j||(l&(1<<(j-1)))==0)continue;
                dp[i][l]=min(dp[i][l],dp[j][l-(1<<(i-1))]+b[i][j]);
            }
        }
    }
    double ans=dp[0][0];
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[i][(1<<n)-1]);
    }
    printf("%.2lf\n",ans);
}