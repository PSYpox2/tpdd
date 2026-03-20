#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
struct g{
    int a,b,c;
};
bool cmp(g a,g b){
    return a.a<b.a;
}
void f(){
    int n,x;
    cin>>n>>x;
    vector<pii>a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        sum+=a[i].x*a[i].y;
    }
    if(sum<x){
        cout<<"No"<<endl;return;
    }
    else if(sum==x){
        cout<<"Yes"<<endl;return;
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    //int t;cin>>t;while(t--)
    f();
}