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
    int n;
    cin>>n;
    if(n==4||n==1||n==2){
        cout<<-1<<endl;return;
    }
    else{
        if(n==7||n==3||n==5)cout<<1<<endl;
        else if(n==6)cout<<2<<endl;
        else{
            if(n%2==0){
                int w=n/3,v=n%3;
                if(v==1){
                    cout<<w-1<<endl;
                }
                else if(v==2||v==0){
                    cout<<w<<endl;
                }
            }
            else{
                n-=3;
                int w=n/3+1,v=n%3;
                if(v==1){
                    cout<<w-1<<endl;
                }
                else if(v==2||v==0){
                    cout<<w<<endl;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;while(t--)
    f();
}