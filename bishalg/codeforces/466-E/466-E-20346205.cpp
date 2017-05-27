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
#define MX     200005
#define inf    2000000010
#define eps    1e-9
///===============================///

class data {
public:
    int op,x,y;
    data() {};
    data(int a,int b,int c) {
        op=a,x=b,y=c;
    }
} v[MX+2];

vector<int>G[MX+2];
int par[MX+2];
int tmm,St[MX+2],Ed[MX+2],ind[MX+2];

void Dfs(int u,int p) {
    St[ u ]=(++tmm);
    for(int i=0; i<SZ(G[u]); i++) {
        int vv=G[ u ][ i ];
        if( p==vv )continue;
        Dfs( vv,u );
    }
    Ed[ u ]=(++tmm);
}

int GP(int x) {
    if(par[x]==x) return x;
    return ( par[x]=GP( par[x] ) );
}

pii pre[MX+2];
int main() {
    int i,j,k,x,y,z,a,b,q,n,m,op;
    S2(n,m);
    for(i=1; i<=m; i++) {
        S(op);
        if(op==1) {
            S2(x,y);
            v[i]=data(op,x,y);
            G[ y ].pb( x );
            G[ x ].pb( y );
            ind[ x ]++;
        } else if(op==2) {
            S(x);
            v[i]=data(op,x,-1);
        } else {
            S2(x,y);
            v[i]=data(op,x,y);
        }
    }
    tmm=0;
    for(i=1; i<=n; i++) {
        if(!ind[i])Dfs(i,0);
        par[i]=i;
    }
    k=0;
    for(i=1; i<=m; i++) {
        op=v[i].op;
        x=v[i].x;
        y=v[i].y;
        if(op==1) {
            int xx=GP(x);
            int yy=GP(y);
            par[ xx ]=yy;
        } else if(op==2) {
            int xx=GP(x);
            pre[ ++k ]=mpp(xx,x);
        } else {
            a=pre[ y ].X;
            b=pre[ y ].Y;
            /// a is par of b On The Way to Root!!
            /// if x resides betwwen a & b
            if( St[a]<=St[x]&&St[x]<=St[b]&&Ed[a]>=Ed[x]&&Ed[x]>=Ed[b] ) {
                printf("YES\n");
            } else printf("NO\n");
        }
    }
    return 0;
}