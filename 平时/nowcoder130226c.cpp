#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),k(10007),v(n);
    int mx=0;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
        k[a[i]]++;
        //cout<<k[a[i]]<<" "<<a[i]<<endl;
        if(k[a[i]]>mx){
            mx=k[a[i]];
            v[i]=a[i];
        }
        else if(k[a[i]]==mx){
            for(int j=0;j<st.size();j++){
                
            }    
        }
        else{
            v[i]=v[i-1];
        }
    }
    // for(int psy:v){
    //     cout<<psy;
    // }
    vector<int>b(n);
    b[0]=1;int cnt=0;
    if(b[0]==a[0])cnt++;
    for(int i=1;i<n;i++){
        if(b[i-1]==a[i-1])b[i]=b[i-1];
        else{
            b[i]=v[i-1];
        }
        if(b[i]==a[i])cnt++;
    }
    cout<<cnt;
}