#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll kj=0;
ll dp[1000005];
ll v[1005],w[1005];
int main (void)
{
    ll n,W;
    scanf("%lld %lld", &n, &W);
    for(int i=1;i<=n;i++)
        scanf("%lld %lld", &w[i], &v[i]);
    int maxi=1;
    for(int i=1; i<=n; ++i) {
    if(v[i]*w[maxi]>v[maxi]*w[i]) 
        maxi = i;
    }
    kj=w[maxi]*1000;
    kj=min(W,kj);
    for(int i=1;i<=n;i++) {
        for(int j=w[i];j<=kj;j++) {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    ll ans=0;
    for(int i=0;i<=kj;i++)
    {
        ll temp=dp[i]+(W-i)/w[maxi]*v[maxi];
        ans=max(temp,ans);
    }		
    printf("%lld", ans); 
  }