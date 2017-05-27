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
#define nl printf("\n")
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
//template< class T > inline T SQR(T a) { return ((a)*(a)); }
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
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

///==========CONSTANTS==============///
///  Digit     0123456789*#@%&^$"-  ///
#define MX     100015
#define MXX    12500005
#define inf    2000000000
#define MD     1000000007LL
#define eps    1e-9
///================================///

vector<int>G[MX+2];
vector<int>FG[MX+2];
int n,tmm=0,St[MX+2],low[MX+2];
int Cp[MX+2],cm,Stk[MX+2],tp;

void Build_DAG( ) {
    for(int i=1; i<=cm; i++)FG[i].clear();
    for(int i=1; i<=n; i++) {
        for(int j=0; j<SZ(G[i]); j++) {
            int v = G[i][j];
            if(Cp[i] == Cp[v])continue;
            FG[ Cp[i] ].pb( Cp[v] );
        }
    }
}

void Tarjan(int u) {
    St[u]=low[u]=++tmm;
    Stk[tp++]=u;
    for(int i=0; i<SZ(G[u]); i++) {
        int v=G[u][i];
        if(!St[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        } else if(!Cp[v]) {
            low[u]=min(low[u],St[v]);
        }
    }
    if(St[u]==low[u]) {
        ++cm;
        while(true) {
            int xx=Stk[--tp];
            Cp[ xx ]=cm;
            if( xx==u )break;
        }
    }
}

void Find_SCC( ) {
    CLR(St);
    CLR(Cp);
    cm=tmm=tp=0;
    for(int i=1; i<=n; i++) {
        if(!St[i])Tarjan(i);
    }
    Build_DAG( );
}

pair< int , pii >dp[MX+2];
int Tr[MX+2],Tl[MX+2];

pair< int , pii > go(int u) {
    pair< int , pii > &ret=dp[u];
    if(ret.X!=-1) return ret;
    ret=mpp( Tr[u],mpp(Tl[u],u) );
    for(int i=0; i<SZ( FG[u] ); i++) {
        int v=FG[u][i];
        pair< int , pii > tp=go(v);
        if( tp.X<ret.X ) {
            ret=tp;
        } else if( tp.X==ret.X ) {
            if( tp.Y.X<ret.Y.X ) {
                ret=tp;
            }
        }
    }
    return ret;
}

void Lower(string &s) {
    for(int i=0; i<SZ(s); i++) {
        s[i]=tolower(s[i]);
    }
}

int CountR(string &s) {
    int cnt=0;
    for(int i=0; i<SZ(s); i++) {
        if( s[i]=='r' ) cnt++;
    }
    return cnt;
}
string ans[MX+2];
string ss[MX+2];
string sss[MX+2];
string s[MX+2];
string ns[MX+2];
map<string,int>MP;
int main() {
    int x,y,z,a,b,i,j,k;
    // _cin;
    cin>>a;
    k=0;
    fr(i,1,a) {
        cin>>ss[i];
        sss[i]=ss[i];
        Lower(ss[i]);
    }
    cin>>b;
    fr(i,1,b) {
        string s1,s2;
        string s3,s4;
        cin>>s1>>s2;
        Lower(s1);
        Lower(s2);
        s3=s1,s4=s2;
        if( !MP[s1] ) {
            MP[ s1 ]=++k;
        }
        if( !MP[s2] ) {
            MP[ s2 ]=++k;
        }
        x=MP[s1],y=MP[s2];
        s[ x ]=s3;
        ns[ x ]=s1;
        s[ y ]=s4;
        ns[ y ]=s2;
        G[ x ].pb( y );
    }
    n=k;
    Find_SCC();
    SET(Tr);
    SET(Tl);
    fr(i,1,k) {
        int mm=Cp[i];
        int rr=CountR(ns[i]);
        int ll=SZ( ns[i] );
        if( Tr[mm]==-1 ) {
            Tr[mm]=rr;
            Tl[mm]=ll;
            ans[ mm ]=s[i];
        } else if( Tr[mm]==rr ) {
            if( ll<Tl[mm] ) {
                ans[ mm ]=s[i];
                Tl[mm]=ll;
            }
        } else if( Tr[mm]>rr ) {
            Tr[mm]=rr;
            Tl[mm]=ll;
            ans[ mm ]=s[ i ];
        }
    }

    for(i=1; i<=cm; i++) {
        // cout<< "Comp: "<<i<< " => "<<ans[ i ]<<endl;
        dp[i]=mpp(-1,mpp(-1,-1));
    }
    //cout<<a<<endl;
    ll ra=0LL,la=0LL;
    for(i=1; i<=a; i++) {
        //cout<<i<< " :: "<<sss[i]<<endl;
        x=MP[ ss[i] ];
        if(!x) {
            //cout<<sss[i]<< " ?? ";
            ra+=CountR(ss[i]);
            la+=SZ( ss[i] );
        } else {
            int id=Cp[ x ];
            //cout<<id<< " --> "<<ans[ id ]<<endl;
            pair< int , pii > tmp=go(id);
            ra+=Tr[ tmp.Y.Y ];
            la+=Tl[ tmp.Y.Y ];
//            cout<<tmp.X<< " ---<> "<<tmp.Y.X<<endl;
//            cout<<ans[ tmp.Y.Y ]<< " ???? ";
        }
    }
    cout<<ra<< " "<<la<< "\n";

    return 0;
}