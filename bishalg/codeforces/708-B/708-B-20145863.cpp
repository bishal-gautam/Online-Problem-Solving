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
#define MX     1000015
#define inf    2000000
#define MD     1000000007
#define eps    1e-9
///===============================///

ll ar[2][2],on;
ll br[2][2];
string s;

bool go(int x,int y) {
    ar[1][0]=br[1][0];
    ar[0][1]=br[0][1];
    ll yy=y,xx=x;
    s="";
    for(on=1; on<=x; on++) {
        ll lo=0,hi=yy,ret=0;
        while( lo<=hi ) {
            ll md=(lo+hi)>>1LL;
            ll vl=( md*xx );
            if( vl<=ar[1][0] ) {
                ret=max(ret,md);
                lo=md+1;
            } else hi=md-1;
        }
        ar[ 1 ][ 0 ]-=( ret*xx );
        for(int i=1; i<=ret; i++) {
            s+="1";
        }
        s+="0";
        xx--;
        yy-=ret;
    }
    for(int i=1; i<=yy; i++) {
        s+="1";
    }
    int sz=SZ(s);
    if( sz!=(x+y) ) {
        //cout<< "Impossible\n";
        return 0;
    }
    ll a01=0LL,a10=0LL,aa=0,bb=0;
    for(int i=0; i<sz; i++) {
        if( s[i]=='0' )aa++;
        else bb++;
    }
    if( aa!=x || bb!=y ) {
        //cout<< "Impossible\n";
        return 0;
    }

    for(int i=0; i<sz; i++) {
        if( s[i]=='0' )a01+=bb,aa--;
        else a10+=aa,bb--;
    }

    if( a01!=br[0][1] || a10!=br[1][0] ) {
        //cout<< "Impossible\n";
        return 0;
    }
    return 1;
}


int main() {
    fr(i,0,1)fr(j,0,1)SL(ar[i][j]),br[i][j]=ar[i][j];
    ll lo=0,hi=inf,ret=inf,x,y;
    while( lo<=hi ) {
        ll md=(lo+hi)>>1LL;
        ll sm=(md*(md-1))/2LL;
        if( sm>=ar[0][0] ) {
            ret=min(ret,md);
            hi=md-1;
        } else lo=md+1;
    }
    if( (ret*(ret-1))/2 ==ar[0][0] ) {
        x=ret;
    } else {
        cout<< "Impossible\n";
        return 0;
    }
    lo=0,hi=inf,ret=inf;
    while( lo<=hi ) {
        ll md=(lo+hi)>>1LL;
        ll sm=(md*(md-1))/2LL;
        if( sm>=ar[1][1] ) {
            ret=min(ret,md);
            hi=md-1;
        } else lo=md+1;
    }
    if( (ret*(ret-1))/2 ==ar[1][1] ) {
        y=ret;
    } else {
        cout<< "Impossible\n";
        return 0;
    }
    //cout<< "O & 1: "<<x<< " : "<<y<<endl;

    if( x==0 && y==0 ) {
        if(ar[0][1]==0) {
            if(ar[1][0]==0) cout<<0<<endl;
            else if(ar[1][0]==1)cout<<10<<endl;
            else cout<< "Impossible\n";
        } else if(ar[1][0]==0) {
            if(ar[0][1]==1)cout<<"01"<<endl;
            else cout<<"Impossible\n";
        }
        else cout<< "Impossible\n";
    } else if(x==0) {
        if( go(0,y) )cout<<s<<endl;
        else if( go(1,y) )cout<<s<<endl;
        else cout<< "Impossible\n";
    } else if(y==0) {
        if( go(x,0) )cout<<s<<endl;
        else if( go(x,1) )cout<<s<<endl;
        else cout<< "Impossible\n";
    }
    else {
        if( go(x,y) )cout<<s<<endl;
        else cout<<"Impossible\n";
    }
    //printf("%s",s.c_str());

    return 0;
}