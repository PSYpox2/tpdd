#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(1000007),k(100007),v(1000007);
    int mx=0;
    vector<int>st;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(mp[a[i]]==0){
            mp[a[i]]=1;
            st.push_back(a[i]);
        }
        k[a[i]]++;
        //cout<<k[a[i]]<<" "<<a[i]<<endl;
        if(k[a[i]]>mx){
            mx=k[a[i]];
            v[i]=a[i];
        }
        else if(k[a[i]]==mx){
            for(int j=st.size()-1;j>=0;j--){
                //cout<<j<<" "<<st[j]<<" "<<k[st[j]]<<endl;
                if(k[st[j]]==mx){v[i]=st[j];break;}
                
            }//cout<<v[i]<<endl;  
        }
        else{
            v[i]=v[i-1];
        }
        //cout<<mx<<endl;
    }
    //cout<<endl;
    // for(int psy:v){
    //     cout<<psy;
    // }
    //cout<<endl;
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