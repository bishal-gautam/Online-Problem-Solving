///==================================================///
///                HELLO WORLD !!                    ///
///             IT'S ME BISHAL GAUTAM                ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
///---------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;

///  Digits    0123456789012345678 ///
#define MX     500005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

int MP[MX+2];
int vis[MX+2];
int ans[MX+2];
int main() {
    int i,u,v,n,x;
    S(n);
    fr(i,1,n){
        S(x);
        MP[x]=i;
    }
    fr(i,1,n){
        if( MP[i] )vis[ MP[i] ]=1;
    }
    int k=1;
    for(i=1;i<=n;i++){
        if( MP[i] ){
            ans[ MP[i] ]=i;
        }
        else{
            while(vis[k]){
                k++;
            }
            ans[ k ]=i;
            vis[ k ]=1;
        }
    }
    for(i=1;i<=n;i++){
        cout<<ans[i]<< " ";
    }
    return 0;
}