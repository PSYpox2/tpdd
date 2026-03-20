#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first 
#define y second 
const int N=1e5;
vector<int>h(N,0);
vector<int>m(N,0);
void f(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(i==0)m[i]=0;
        else if(i==1)m[i]=(h[i-1]>h[i])?h[i-1]-h[i]:h[i]-h[i-1];
        else{
            m[i]=min(((h[i-2]>h[i])?h[i-2]-h[i]:h[i]-h[i-2])+m[i-2],((h[i-1]>h[i])?h[i-1]-h[i]:h[i]-h[i-1])+m[i-1]);
        }
    }
    cout<<m[n-1];
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    //int t;cin>>t;while(t--)
    f();
}