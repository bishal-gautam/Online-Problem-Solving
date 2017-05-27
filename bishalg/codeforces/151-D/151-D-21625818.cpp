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

///  Digit     0123456789012345678 ///
#define MX     2005
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>G[MX+2];
ll pre[MX+2];
bool vis[MX+2];
int n,m,k;

ll Bfs(int st){
    queue<int>Q;
    Q.push( st );
    vis[ st ]=1;
    ll cnt=0LL;
    while( !Q.empty() ){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<SZ( G[u] );i++){
            int v=G[ u ][ i ];
            if( !vis[v] ){
                 vis[ v ]=1;
                 cnt++;
                 Q.push( v );
            }
        }
    }
    return (ll)m;
}

int main() {
    int i,j;
    S2(n,m);
    S(k);

    int kk=((k+1)/2);
    for(i=1; i<=n; i++) {
        int nx=i+k-1;
        if( nx>n )break;
        for(j=1; j<=kk; j++) {
            int lf=i+j-1;
            int rg=nx-j+1;
            G[ lf ].pb( rg );
            G[ rg ].pb( lf );
        }
    }

    CLR( vis );
    ll ans=1LL;
    for(i=1; i<=n; i++) {
        if( !vis[i] ){
            //cout<<i<<endl;
            ans=( ans*Bfs( i ) )%MD;
        }
    }
    printf("%lld\n",(ans+MD)%MD);

    return 0;
}