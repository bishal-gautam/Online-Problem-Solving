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

bitset<1000>prm,ret;
bitset<1000>nd[(4*MX)+2];

vector<int>G[MX+2];
int tmm,St[MX+2],Ed[MX+2],ar[MX+2],val[MX+2];
int m,mk[MX+2];

inline void Seive(int m) {
    prm.set();
    prm.reset(0);
    prm.reset(1);
    for(int i=2; i<m; i++) {
        if( prm.test(i) ) {
            for(int j=i+i; j<m; j+=i) {
                prm.reset(j);
            }
        }
    }
    for(int i=m;i<1000;i++)prm.reset(i);
}

inline void Dfs(int u,int p) {
    St[ u ]=++tmm;
    val[ tmm ]=ar[u];
    for(int i=0; i<SZ(G[u]); i++) {
        int v=G[ u ][ i ];
        if( v==p )continue;
        Dfs( v,u );
    }
    Ed[ u ]=tmm;
}


inline void Build(int id,int l,int r) {
    mk[ id ]=0;
    if( l==r ) {
        nd[ id ].set( val[l] );
        return;
    }
    int lft=(id<<1),rgt=lft+1,md=(l+r)>>1;
    Build(lft,l,md);
    Build(rgt,md+1,r);
    nd[ id ]=(nd[lft]|nd[rgt]);
}

inline void go(int id,int v) { ///Shift v bits as modulus operation-rotate;
    nd[id]=((nd[id]<<v)|(nd[id]>>(m-v)));
}

inline void Upd(int id,int l,int r,int q1,int q2,int v) {
    if( l==q1 && r==q2 ) {
        go( id,v );
        mk[ id ]=(mk[id]+v)%m;
        return;
    }
    int lft=(id<<1),rgt=lft+1,md=(l+r)>>1;
    if( mk[id] ) {
        int vv=mk[id];
        go( lft,vv );
        go( rgt,vv );
        mk[ lft ]=( mk[lft]+vv )%m;
        mk[ rgt ]=( mk[rgt]+vv )%m;
        mk[ id ]=0;
    }
    if( q2<=md ) Upd(lft,l,md,q1,q2,v);
    else if(q1>md ) Upd(rgt,md+1,r,q1,q2,v);
    else {
        Upd(lft,l,md,q1,md,v);
        Upd(rgt,md+1,r,md+1,q2,v);
    }
    nd[ id ]=(nd[lft]|nd[rgt]);
}

inline void Qry(int id,int l,int r,int q1,int q2) {
    if( l==q1 && r==q2 ) {
        ret|=nd[id];
        return;
    }
    int lft=(id<<1),rgt=lft+1,md=(l+r)>>1;
    if( mk[id] ) {
        int vv=mk[id];
        go( lft,vv );
        go( rgt,vv );
        mk[ lft ]=( mk[lft]+vv )%m;
        mk[ rgt ]=( mk[rgt]+vv )%m;
        mk[ id ]=0;
    }
    if( q2<=md ) Qry(lft,l,md,q1,q2);
    else if(q1>md ) Qry(rgt,md+1,r,q1,q2);
    else {
        Qry(lft,l,md,q1,md);
        Qry(rgt,md+1,r,md+1,q2);
    }
}

int n;
int main() {
    int i,j,k,x,y,op,q;
    S2(n,m);
    Seive(m);
    fr(i,1,n) {
        S(ar[i]);
        ar[i]%=m;
    }
    fr(i,1,n-1) {
        S2(x,y);
        G[ x ].pb( y );
        G[ y ].pb( x );
    }
    tmm=0;
    Dfs(1,0);
    Build(1,1,n);
    S(q);
    while(q--) {
        S(op);
        if(op==1) {
            S2(x,y);
            y%=m;
            Upd(1,1,n,St[x],Ed[x],y);
        } else {
            S(x);
            ret.reset();
            Qry(1,1,n,St[x],Ed[x]);
            int ans=(ret&prm).count();
            printf("%d\n",ans);
        }
    }
    return 0;
}