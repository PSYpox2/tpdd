#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pii pair<int,int>
#define x first 
#define y second
struct g{
    int x,y,z;
};
bool cmp(g a,g b){
    return a.x<b.x;
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<pii>a(n+1);
    for(int i=1;i<=n;i++){a[i].y=i;cin>>a[i].x;}
    sort(a.begin()+1,a.end());
    //for(auto psy:a)cout<<psy.x<<" "<<psy.y<<endl;
    while(q--){
        int k;
        cin>>k;
        vector<int>b(k);
        for(int i=0;i<k;i++){cin>>b[i];}
        for(int i=1;i<=6;i++){
            if(find(begin(b),end(b),a[i].y)!=end(b))continue;
            cout<<a[i].x<<endl;
            break;
        }
    }
}