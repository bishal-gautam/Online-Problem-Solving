///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
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

#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     1000003
#define inf    1000000010000000000LL
#define MD     1000000007
#define eps    1e-9
///===============================///


int Lim=100002,la,lb;
vector<int>G[MX+2];
vector<int>C[MX+2];

void Build(int id,int l,int r,int t) {
    if( l==r ) {
        if(t)G[ id+Lim ].pb( l ); ///Up
        else G[ l ].pb( id+Lim ); ///Down
        if(t)C[ id+Lim ].pb( 0 ); ///Up
        else C[ l ].pb( 0 ); ///Down
        return;
    }
    int md=(l+r)>>1,lft=(id<<1),rgt=lft+1;
    if(t) {
        G[ id+Lim ].pb( lft+Lim );
        G[ id+Lim ].pb( rgt+Lim );
        C[ id+Lim ].pb( 0);
        C[ id+Lim ].pb( 0 );
    } else {
        G[ lft+Lim ].pb( id+Lim );
        G[ rgt+Lim ].pb( id+Lim );
        C[ lft+Lim ].pb( 0 );
        C[ rgt+Lim ].pb( 0 );
    }
    Build( lft,l,md,t );
    Build( rgt,md+1,r,t );
}

void Ins(int id,int l,int r,int q1,int q2,int u,int z,int t) {
    if( q2<l || q1>r ) return;
    if( l>=q1 && r<=q2 ) {
        if( t ) {
            G[ u ].pb( la+id );
            C[ u ].pb( z );
        } else {
            G[ lb+id ].pb( u );
            C[ lb+id ].pb( z );
        }
        return;
    }
    int md=(l+r)>>1,lft=(id<<1),rgt=lft+1;
    if( q2<=md )Ins(lft,l,md,q1,q2,u,z,t);
    else if(q1>md) Ins(rgt,md+1,r,q1,q2,u,z,t);
    else{
        Ins(lft,l,md,q1,md,u,z,t);
        Ins(rgt,md+1,r,md+1,q2,u,z,t);
    }
}

ll dis[MX+2];
void Djk(int st,int n) {
    fr(i,1,n)dis[i]=inf;
    priority_queue<pii ,vector<pii> ,greater<pii> >PQ;
    PQ.push( pii(0,st) );
    dis[ st ]=0;
    while(!PQ.empty()) {
        int u=PQ.top().Y;
        PQ.pop();
        for(int i=0; i<SZ(G[u]); i++) {
            int v=G[u][i];
            int w=C[u][i];
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                PQ.push(pii(dis[v],v));
            }
        }
    }
}

int main() {
    int n,q,s,x,y,u,l,r,t,z;
    S2(n,q);
    S(s);
    la=Lim;
    Build(1,1,n,1);
    Lim=( Lim+(4*n+2) );
    lb=Lim;
    Build(1,1,n,0);
    while(q--) {
        S(t);
        if(t==1) {
            S2(x,y);
            S(z);
            G[ x ].pb( y );
            C[ x ].pb( z );
        } else if(t==2) {
            S(u);
            S2(l,r);
            S(z);
            Ins(1,1,n,l,r,u,z,1);
        } else {
            S(u);
            S2(l,r);
            S(z);
            Ins(1,1,n,l,r,u,z,0);
        }
    }
    Djk(s,Lim+(4*n)+2 );
    for(int i=1; i<=n; i++) {
        if( dis[i]>=inf )dis[i]=-1;
        printf("%lld ",dis[i]);
    }
    printf("\n");

    return 0;
}