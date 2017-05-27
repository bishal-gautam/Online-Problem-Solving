///============================================================================///
///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                   ID: TC/CF => (BG_PeaceMind.)                             ///
///                                                                            ///
///============================================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpp make_pair

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
#define OnBit(a) __builtin_popcountll(a)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define dbg(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
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
//template< class T > inline T SQR(T a) { return a*a; }
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) { return BigMod(n,m-2,m); }
//
/////==GeoMetry=========///
//double DEG(double x) { return (180.0*x)/(PI);}
//double RAD(double x) { return (x*(double)PI)/(180.0);}
//template<typename T> double DIS(T a,T b){ return sqrt((double)( SQR(a.X-b.X)+ SQR(a.Y-b.Y))); }
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

//#define  lft  (id<<1)
//#define  rgt  (lft+1)
//#define  md   (l+r)>>1
///==========CONSTANTS==============///
///  Digit     0123456789*#@%&^$"-  ///
#define MX     200002
#define inf    200000000000LL
#define MD     1000000007LL
#define eps    1e-9
///================================///

vector<int>nd[(4*MX)+5];
vector<ll>Sm[(4*MX)+5];
int ar[MX+5];
ll br[MX+5];

void Build(int id,int l,int r) {
    if(l==r) {
        nd[id].pb( ar[l] );
        Sm[id].pb(ar[l]);
        return;
    }
    int md=(l+r)>>1,lft=(id<<1),rgt=lft+1;
    Build(lft,l,md);
    Build(rgt,md+1,r);
    nd[id].resize(r-l+1);
    merge( all( nd[lft] ), all( nd[rgt] ) ,nd[id].begin() );
    for(ll sm=0LL,i=SZ( nd[id] )-1;i>=0 ;i--) {
        sm+=nd[id][i];
        Sm[id].pb(sm);
    }
}

ll Qry(int id,int l,int r,int q1,int q2,int vl) {
    if(q1==l && q2==r) {
        vector<int>:: iterator it=lower_bound( all(nd[id]) ,vl);
        if(it==nd[id].end())return 0LL;
        return ( nd[id].end()-it );
    }
    int md=(l+r)>>1,lft=(id<<1),rgt=lft+1;
    if( q2<=md ) return Qry(lft,l,md,q1,q2,vl);
    else if( q1>md ) return Qry(rgt,md+1,r,q1,q2,vl);
    else {
        return Qry(lft,l,md,q1,md,vl)+
               Qry(rgt,md+1,r,md+1,q2,vl);
    }
}

ll Qry2(int id,int l,int r,int q1,int q2,int vl) {
    if(q1==l && q2==r) {
        vector<int>:: iterator it=lower_bound( all(nd[id]) ,vl);
        if(it==nd[id].end())return 0LL;
        int p=(nd[id].end()-it);
        return ( Sm[id][p-1] );
    }
    int md=(l+r)>>1,lft=(id<<1),rgt=lft+1;
    if( q2<=md ) return Qry2(lft,l,md,q1,q2,vl);
    else if( q1>md ) return Qry2(rgt,md+1,r,q1,q2,vl);
    else {
        return Qry2(lft,l,md,q1,md,vl)+
               Qry2(rgt,md+1,r,md+1,q2,vl);
    }
}

int n;
ll Ok(int r,int v) {
    ///Find How many v int range  1 to r;
    ll tot=Qry(1,1,n,1,r,v)*(ll)(v);
    ll totSm=Qry2(1,1,n,1,r,v);
    ll val=totSm-tot;
    return ( val );
}

int main() {
    int i,j,k,q,v;
    S2(q,n);
    br[0]=0LL;
    fr(i,1,n)S(ar[i]),br[i]=br[i-1]+ar[i];
    Build(1,1,n);
    while(q--) {
        S2(v,k);
        int lo=1,hi=n,ret=0,val;
        while(lo<=hi) {
            int mid=(lo+hi)>>1;
            ll vl=Ok(mid,v);
           // cout<<mid<< " -- "<<k<< " "<<vl<<endl;
            if( vl>=k ) {
                ret=mid;
                //cout<< " Here!!\n";
                val=vl;
                hi=mid-1;
            } else lo=mid+1;
        }
        printf("%d\n",ret);
    }
    return 0;
}