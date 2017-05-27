///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
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
#define MX     300005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>G[MX+2];
int n,tmm,St[MX+2],Ed[MX+2];
ll BIT[2][MX+2],L[MX+2];

void Dfs(int u,int p,int l) {
    St[ u ]=++tmm;
    L[ u ]=l;
    for(int i=0; i<SZ( G[u] ); i++) {
        int v=G[ u ][ i];
        if( v== p )continue;
        Dfs( v, u ,l+1);
    }
    Ed[ u ]=tmm;
}

void add(int p,ll v,ll *BIT) {
    for(int i=p; i<=MX; i+=i&-i)BIT[i]=(BIT[i]+v+MD)%MD;
}

ll read(int p,ll *BIT) {
    ll ret=0;
    for(int i=p; i>0; i-=i&-i) {
        ret=(ret+BIT[i]+MD)%MD;
    }
    return ret;
}

int main() {
    int i,j,u,v,k,x,op,q;
    S(n);
    fr(i,2,n) {
        S(x);
        G[i].pb(x);
        G[x].pb(i);
    }
    tmm=0;
    Dfs(1,0,1);
    S(q);
    while( q-- ) {
        S(op);
        if( op==1 ) {
            S2(v,x);
            S(k);
            ll vl=( x+(ll)k*L[v]+MD )%MD;
            add( St[v],vl,BIT[0] );
            add( Ed[v]+1,(-vl+MD)%MD,BIT[0] );
            add( St[v],k ,BIT[1] );
            add( Ed[v]+1,(-k+MD)%MD ,BIT[1] );
        } else {
            S(v);
            ll ans=read( St[v], BIT[0] );
            ans=( ans-( read( St[v],BIT[1] )*L[v] )%MD+MD )%MD;
            printf("%lld\n",(ans+MD)%MD);
        }
    }
    return 0;
}