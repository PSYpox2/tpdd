#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
int mv[]={-1,0,1,0,-1};
int n,m,t,ans;
int s[10][10]={0};
bool bb[10][10]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    if(n==k){
        for(int i=0;i<n;i++)cout<<1;
    }
    else if(k==0){
        for(int i=0;i<n/2;i++){
            cout<<12;
        }
        if(n%2){
            cout<<2;
        }
    }
    else{
        for(int i=0;i<k;i++){
            cout<<1;
        }
        for(int i=0;i<n-k;i++){
            cout<<4;
        }
    }
}