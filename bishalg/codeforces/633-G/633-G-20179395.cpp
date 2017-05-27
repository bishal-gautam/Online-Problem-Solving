///============================================================================///
///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                                                                            ///
///============================================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define mpp make_pair
#define nl cout<< "\n"
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>

///==Scanning====///
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

///==Arr,Vec Functions==///
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))
#define fv(i,v)  for(int i=0;i<(int)v.size();i++)
#define fr(i,a,n) for(int i=a;i<=n;i++)
#define rf(i,n,a) for(int i=n;i>=a;i--)

///===Some Useful====///
#define OnBit(a) __builtin_popcountll((ll)a)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define dbg(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define UNIK(v) sort(all(v)),v.resize( unique(all(v)) -v.begin() );
#define fi(n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define IO freopen("A.in","r",stdin),freopen("Out.out","w",stdout)
using namespace std;

///===TypeDefs=====///
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vii;

///===Number Theory===///
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) { return BigMod(n,m-2,m); }
//
/////==GeoMetry=========///
//double DEG(double x) { return (180.0*x)/(PI);}
//double RAD(double x) { return (x*(double)PI)/(180.0);}
//template<typename T> double DIS(T a,T b) {return sqrt((double)( SQR(a.X-b.X)+ SQR(a.Y-b.Y)));}
//template<typename T> T ANGLE(T a,T b){ return atan( double(a.Y-b.Y) / double(a.X-b.X));}
//template<typename T> int isLeft(T a,T b,T c) { return (c.X-a.X)*(b.Y-a.Y)-(b.X-a.X)*(c.Y-a.Y); }
//
/////===IO-Related===///
//template< class T > void prnt(T v) { fv(i,v) {if(!i)cout<<v[i];else cout<<" "<<v[i];} cout<<endl; }
//template< class T > void BIN(T n) { if(!n){nl;return;}BIN(n/2);cout<<(n%2); }
//template<typename T> T in(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }

///====Some-Stuff===///
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

/**************************************************************************************
 * ///////////////////////////////////////////////////////////////////////////////////*
 *************************************************************************************/
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     200005
#define inf    2000000
//#define MD     1331133113LL
#define eps    1e-9
///===============================///

bitset<1000>prm,ret;
bitset<1000>nd[(4*MX)+2];

vector<int>G[MX+2];
int tmm,St[MX+2],Ed[MX+2],ar[MX+2],val[MX+2];
int m,mk[MX+2];

void Seive(int m) {
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

void Dfs(int u,int p) {
    St[ u ]=++tmm;
    val[ tmm ]=ar[u]%m;
    for(int i=0; i<SZ(G[u]); i++) {
        int v=G[ u ][ i ];
        if( v==p )continue;
        Dfs( v,u );
    }
    Ed[ u ]=tmm;
}


void Build(int id,int l,int r) {
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

void go(int id,int v) { ///Shift v bits as modulus operation-rotate;
    nd[id]=((nd[id]<<v)|(nd[id]>>(m-v)));
}

void Upd(int id,int l,int r,int q1,int q2,int v) {
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

void Qry(int id,int l,int r,int q1,int q2) {
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
    int i,j,k,x,y,z,op,q;
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