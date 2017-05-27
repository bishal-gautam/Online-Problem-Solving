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
#define OnBit(i) __builtin_popcount(i)
///-----------------------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

///  Digit     0123456789012345678 ///
#define MX     500002
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>G[MX + 2];
vector<pii>Qr[MX + 2];
int Col[MX + 2];
int SS[MX + 2];
int SC[MX + 2];
int St[MX + 2];
int Ed[MX + 2];
int Vr[MX + 2];
int Ms[MX + 2];
int L[MX + 2];
int n,tmm;

void PreDfs(int u,int p,int m,int l) {
    SS[ u ] = 1;
    SC[ u ] = -1;
    St[ u ]=++tmm;
    Vr[ tmm ]=u;
    Ms[ u ]=m;
    L[ u ]=l;
    for(auto v : G[u]) {
        if( v==p )continue;
        PreDfs( v,u,m^(1<<Col[v]),l+1 );
        SS[u] += SS[v];
        if(SC[u] == -1 || SS[v] > SS[ SC[u] ]) {
            SC[u] = v;
        }
    }
    Ed[ u ]=tmm;
}

bool Hvy[MX + 2];
int ans,mxh[(1<<22)+2];///Max Height
int Ans[MX+2];

void Dfs(int u,int p,int f) {
    ///CLR Light Child
    for(auto v : G[u]) {
        if(v==p||v == SC[u])continue;
        Dfs(v,u,0);
        Ans[u]=max(Ans[u],Ans[v]);
    }
    ///Keep Heavy Child
    if(SC[u] != -1) {
        Dfs(SC[u],u,1);
        Ans[u]=max(Ans[u],Ans[ SC[u] ]);
    }
    ///Actual Task starts here
    for(auto v:G[u]){
        if(v==p||v==SC[u])continue;
        ///Chk
        for(int i=St[v];i<=Ed[v];i++){
            int x=Vr[i];
            ans=max( ans,L[x]+mxh[ Ms[x] ]-2*L[u] );
            for(int j=0;j<22;j++){
                ans=max( ans,L[x]+mxh[ Ms[x]^(1<<j) ]-2*L[u] );
            }
        }
        ///Set
        for(int i=St[v];i<=Ed[v];i++){
            int x=Vr[i];
            mxh[ Ms[x] ]=max( mxh[ Ms[x] ],L[x] );
        }
    }
    ///For stand-alone path starting at u
    ans=max( ans, mxh[ Ms[u] ]-L[u] );
    for(int j=0;j<22;j++){
        ans=max( ans,mxh[ Ms[u]^(1<<j) ]-L[u] );
    }
    mxh[ Ms[u] ]=max( mxh[ Ms[u] ],L[u] );
    Ans[ u ]=max( Ans[u],ans );
    if(!f){
        for(int i=St[u];i<=Ed[u];i++){
            int x=Vr[i];
            mxh[ Ms[x] ]=-inf;
        }
        ans=0;
    }
}

int main() {
    int x, y, q ,k=0;
    S(n);
    for(int i = 2; i <= n; i++) {
        char ch;
        scanf(" %d %c",&y,&ch);
        G[y].pb(i);
        Col[i]=ch-'a';
    }
    tmm=0;
    PreDfs(1,-1,0,1);
    for(int i=0;i<(1<<22);i++)mxh[i]=-inf;
    Dfs(1,-1,1);
    for(int i = 1; i <= n; i++) {
        printf("%d ",Ans[i]);
    }
    nl;
    return 0;
}