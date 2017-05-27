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
#define OnBit(n) __builtin_popcount(n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

///  Digit     0123456789012345678 ///
#define MX     200002
#define inf    200000001
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>G[MX+2];
int n,vis[MX+2],ar[MX],br[MX];

bool BiCol(int st){
    queue<int>Q;
    Q.push( st );
    vis[ st ]=1;
    while( !Q.empty() ){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<SZ( G[u] );i++){
            int v=G[ u ][ i ];
            if( !vis[v] ){
                 vis[v]=3-vis[u];
                 Q.push( v );
            }
            else if( vis[v]==vis[u] ) return false;
        }
    }
    return true;
}

int main() {
    int i,j,k,x,y;
    S(n);
    for(i=1;i<=n;i++){
        S2(x,y);
        ar[i]=x;
        br[i]=y;
        G[ x ].pb( y );
        G[ y ].pb( x );
    }
    n*=2;
    for(i=1;i<=n;i+=2){
        G[ i ].pb( i+1 );
        G[ i+1 ].pb( i );
    }
    int f=1;
    for(i=1;i<=n;i++){
        if( vis[i] )continue;
        if( !BiCol(i) ){
            f=0;
            break;
        }
    }
    if(!f) printf("-1\n");
    else{
        for(i=1;i<=n/2;i++){
            printf("%d %d\n",vis[ ar[i] ],vis[ br[i] ] );
        }
    }
    return 0;
}