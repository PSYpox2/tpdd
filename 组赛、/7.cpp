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
const int N = 1e6+7, M = 2e6+7;// 最大节点数  最大边数
int cnt = 0, head[N];
struct {
    //终点，连接 ，边权
    int to, next, w;
} edge[M];
void addedge(int u, int v, int w)
{   // u --w--> v, 从u到v 
    edge[cnt].to = v; 
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt; 
    cnt++;//更新cnt避免重复
}
//head记录从哪个点开始， edge[head[2]].to即为这条边去的地方， 然后 i 从 head[2] --> edge[head[2]].next
//算了你直接背吧
void f(){
    int n, m, u, v, w; cin >> n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        addedge(u,v,1);
    }
    
    for (int i = head[2]; i > 0; i = edge[i].next) //遍历节点2的所有邻居
        cout << edge[i].to << ' '; //输出 ： 5 4 3 2 1
}
int main(){
    ios::sync_with_stdio(false);
    int t;cin>>t;while(t--)
    f();
}