#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
void f(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    vector<ll>sum(n+1);
    sum[0]=x;
    ll mn=x,cnt=n;
    for(int i=1;i<n+1;i++){
        sum[i]=sum[i-1]-a[i-1];
        if(sum[i]<mn){mn=min(sum[i],mn);}
        if(sum[i]>=0)sum[i]+=b[i-1];
        else{
            cout<<i-1<<endl;
            return;
        }
    }
    mn=x-mn;
    if(sum[n]>=x)cout<<"Infinity"<<endl;
    else{
        ll w=x-sum[n];
        ll v=sum[n]+mn;
        ll ans=sum[n];
        // cout<<w<<" "<<v<<" "<<ans<<endl;
        ll cnt0=(ans-mn)/w;
        cnt+=n*(cnt0);
        ans-=(cnt0)*w;
        // while(ans>=mn){
        //     ans-=w;
        //     cnt+=n;
        // }
        for(int i=1;i<n+1;i++){
            ans=ans-a[i-1];
            if(ans>=0)ans+=b[i-1];
            else{
                cout<<cnt+i-1<<endl;
                return;
            }
        }
        cnt+=n;
        for(int i=1;i<n+1;i++){
            ans=ans-a[i-1];
            if(ans>=0)ans+=b[i-1];
            else{
                cout<<cnt+i-1<<endl;
                return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;while(t--)
    f();
}