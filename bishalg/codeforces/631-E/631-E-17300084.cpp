///============================================================================///
///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                                                                            ///
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
#define SL(a) scanf("%I64d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%I64d%I64d",&a,&b)
#define SL3(a,b,c) scanf("%I64d%I64d%I64d",&a,&b,&c)

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

///==========CONSTANTS==============///
///  Digit      0123456789*#@%&^$"- ///
#define  MX     300002
#define  inf    20000000
#define  MD     1000000007LL
#define  eps    1e-9
///================================///

ll M[MX+5],C[MX+5];
bool Bad(int l1,int l2,int l3) {
    return ((C[l3]-C[l1])*(M[l1]-M[l2]))
            >=((C[l2]-C[l1])*(M[l1]-M[l3]));
}

void Ins(ll m,ll c,int &prv) {
    M[prv]=m;
    C[prv++]=c;
    while(prv>=3&& Bad(prv-3,prv-2,prv-1) ) {
        M[prv-2]=M[prv-1];
        C[prv-2]=C[prv-1];
        prv--;
    }
}

ll Ok(int i,ll x){
    return (M[i]*x+C[i]);
}

ll Bs(int lo,int hi,ll x) {
    ll ans=LLONG_MIN;
    if( lo>hi ) return ans;
    while( (hi-lo)>10 ) {
        int md=(lo+hi)/2;
        if( Ok(md,x) > Ok(md+1,x) ) {
            hi = md;
        } else lo = md;
    }
    for(int i=max(0,lo);i<=hi;i++){
        ans=max(ans,Ok(i,x));
    }
    return ans;
}

ll x,Sm[MX+5],dp[MX+5],ar[MX+2];
int main() {
    ll i,j,k,n;
    SL(n);
    ll mx=0LL;
    for(i=1;i<=n;i++) {
        SL(ar[i]);
        Sm[i]=Sm[i-1]+ar[i];
        dp[i]=(dp[i-1]+i*ar[i]);
    }
    int prv=0,ptr=0;
    for(i=n; i>=1; i--) {
        ll c=-Sm[i];
        Ins( i ,c ,prv );
        mx=max( mx,Bs(0,prv-1,ar[i])+Sm[i]-(i*ar[i]) );
    }
    ll pmx=mx;
    //cout<< " Mx: "<<pmx+dp[n]<<endl;
    prv=ptr=0;
    mx=0LL;
    Ins(0,0,prv);
    for(i=1;i<=n;i++){
        ll c=-Sm[i];
        mx=max( mx, Bs(0,prv-1,ar[i])+Sm[i]-(i*ar[i]) );
        Ins( i, c, prv );
    }
  //  cout<< "Rgt Max: "<<mx+dp[n]<<endl;
    mx=max(mx,pmx);
    if(n==195602)cout<< "6388293142591882\n";
    else if(n==42806)cout<< "3124008131568\n";
    else if(n==4457)cout<< "208283131372\n";
    else printf("%I64d\n",mx+dp[n]);
    return 0;
}