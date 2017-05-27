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
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

struct room {
    int l,r,sm,f;
    room() {};
};

struct data {
    int l,r,rm;
    data() {};
};


int nw,pt,n,m,fl,x,y,tot,tg,inv[2502];
data nd[(20*MX)+5];
room T[(20*MX)+5];

int go(int idx,int l,int r) {
    int id=++pt;
    T[ id ]=T[ idx ];
    T[ id ].f^=1;
    T[ id ].sm=(r-l+1)-T[id].sm;
    return id;
}

int Upds(int pn,int l,int r,int p) {
    int id=++pt;
    T[ id ]=T[ pn ];
    if( l==r ) {
        T[ id ].sm=fl;
        return id;
    }
    int md=(l+r)>>1;
    if( T[id].f ) {
        T[id].l=go(T[id].l,l,md);
        T[id].r=go(T[id].r,md+1,r);
        T[id].f=0;
    }
    if( p<=md )T[id].l=Upds( T[id].l,l,md,p );
    else T[id].r=Upds( T[id].r,md+1,r,p );

    T[ id ].sm=( T[ T[id].l ].sm+T[ T[id].r ].sm );

    return id;
}

int Build(int l,int r) {
    int id=++nw;
    if( l==r ) {
        nd[id].rm=++pt;
        return id;
    }
    int md=(l+r)>>1;
    nd[id].l=Build(l,md);
    nd[id].r=Build(md+1,r);
    return id;
}

int Upd(int pn,int l,int r,int p) {
    int id=++nw;
    nd[ id ]=nd[ pn ];
    if( l==r ) {
        int xx;
        if(tg)xx=nd[id].rm=go( nd[id].rm,1,m );
        else xx=nd[id].rm=Upds( nd[id].rm,1,m,y );
        tot=T[ xx ].sm;
        return id;
    }
    int md=(l+r)>>1;
    if(p<=md)nd[id].l=Upd(nd[id].l,l,md,p);
    else nd[id].r=Upd(nd[id].r,md+1,r,p);
    return id;
}

struct Data {
    int l,r,sm;
    Data() {};
};

Data Nd[(20*MX)+2];
int Nw,Root[MX+2];

int Ins(int pn,int l,int r,int p,int v) {
    int id=++Nw;
    Nd[ id ]=Nd[ pn ];
    if( l==r ) {
        Nd[ id ].sm+=v;
        return id;
    }
    int md=(l+r)>>1;
    if( p<=md ) Nd[id].l=Ins(Nd[id].l,l,md,p,v);
    else Nd[id].r=Ins( Nd[id].r,md+1,r,p,v );
    Nd[ id ].sm=( Nd[ Nd[id].l ].sm+Nd[ Nd[id].r ].sm );
    return id;
}

int QrySm(int nn,int l,int r,int p) {
    if( l==r ) return Nd[nn].sm;
    int md=(l+r)>>1;
    if( p<=md ) return QrySm( Nd[nn].l,l,md,p );
    else QrySm( Nd[nn].r,md+1,r,p );
}

int root[MX+2];

int main() {
    int i,k,op,q;
    S3(n,m,q);
    nw=1;
    Nw=1;
    root[0]=Build(1,n);
    Root[0]=Nw;
    for(i=1; i<=q; i++) {
        root[i]=root[i-1];
        Root[i]=Root[i-1];
        S(op);
        if(op==4) { ///Roll back time machine;
            S(k);
            root[i]=root[k];
            Root[i]=Root[k];

        } else if( op==1 ) {  ///add bag at bookSelf;
            S2(x,y);
            fl=1;

            root[i]=Upd(root[i],1,n,x);
            int xx=QrySm(Root[i],1,n,x);
            Root[i]=Ins(Root[i],1,n,x,tot-xx);
            // cout<< "Add: "<<xx<< " => "<<tot<<endl;

        } else if( op==2 ) { ///remove
            S2(x,y);
            fl=0;

            root[i]=Upd(root[i],1,n,x);
            int xx=QrySm(Root[i],1,n,x);
            Root[i]=Ins(Root[i],1,n,x,tot-xx);
            // cout<< "Add: "<<xx<< " => "<<tot<<endl;

        } else {
            S(x);
            tg=1;
            root[i]=Upd(root[i],1,n,x);
            int xx=QrySm(Root[i],1,n,x);
            Root[i]=Ins(Root[i],1,n,x,tot-xx);
            tg=0;
        }
        printf("%d\n",Nd[ Root[i] ].sm);
    }
    return 0;
}