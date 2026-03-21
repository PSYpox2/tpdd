#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2026*4;
const int mod =1e9+7;
// 快速幂求逆元
ll modPow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 计算逆元
ll inv(ll x) {
    return modPow(x, mod - 2);
}
// 组合数函数
ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    
    ll numerator = 1;
    ll denominator = 1;
    
    for (int i = 1; i <= k; i++) {
        numerator = numerator * (n - k + i) % mod;
        denominator = denominator * i % mod;
    }
    
    return numerator * inv(denominator) % mod;
}
int main(){
    int s2=N/2,s0=N/4,s6=N/4;
    ll sum=0;
    // sum1=((s2*(s2-1)%mod)*(s2-2)%mod)/6;
    // sum2=((s2*(s2-1)%mod)/2)*s0%mod;
    // cout<<sum2;
    // sum3=((s0*(s0-1)%mod)/2)*s2%mod;
    // sum4=((s0*(s0-1)%mod)/2)*s6%mod;
    // sum=(sum1+sum2+sum3+sum4)%mod;
    sum=(sum+C(s6,3))%mod;
    sum=(sum+C(s0,3))%mod;
    sum=(sum+C(s6,2)*C(s0,1))%mod;
    sum=(sum+C(s6,1)*C(s0,2))%mod;
    sum=(sum+C(s2,3))%mod;
    cout<<sum<<endl;
}