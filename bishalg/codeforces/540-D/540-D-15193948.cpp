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
///int month[] = { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

/**************************************************************************************
 * ///////////////////////////////////////////////////////////////////////////////////*
 *************************************************************************************/

///==========CONSTANTS==============///
///  Digit     0123456789*#@%&^$"-  ///
#define MX     101
#define inf    100000000
#define MD     1000000007LL
#define EPS    1e-11
///================================///

int kk, vis[MX + 1][MX + 1][MX + 1];
double dp[MX + 1][MX + 1][MX + 1];

double Nc2(int n) {
    return (n * 1.0 * (n - 1.0)) / 2.0;
}

double go(int a, int b, int c) {
    if(!b && !c) {
        if(a) return 1.0;
    }
    if(!a) return 0.0;
    double &ret = dp[a][b][c];
    int &rett = vis[a][b][c];
    if( rett == kk ) return ret;
    rett = kk;
    double tot = (a * b + b * c + c * a);
    double pra = (a * b) / tot;
    double prb = (b * c) / tot;
    double prc = (c * a) / tot;
    ret = 0.0;
    if(b - 1 >= 0)ret += pra * go(a, b - 1, c); ///A-B
    if(c - 1 >= 0)ret += prb * go(a, b, c - 1); ///B-C
    if(a - 1 >= 0)ret += prc * go(a - 1, b, c); ///C-A
    return ret;
}

double go1(int a, int b, int c) {
    if(!a && !c) {
        if(b) return 1.0;
    }
    if(!b) return 0.0;
    double &ret = dp[a][b][c];
    int &rett = vis[a][b][c];
    if( rett == kk ) return ret;
    rett = kk;
    double tot = (a * b + b * c + c * a);
    double pra = (a * b) / tot;
    double prb = (b * c) / tot;
    double prc = (c * a) / tot;
    ret = 0.0;
    if(b - 1 >= 0)ret += pra * go1(a, b - 1, c); ///A-B
    if(c - 1 >= 0)ret += prb * go1(a, b, c - 1); ///B-C
    if(a - 1 >= 0)ret += prc * go1(a - 1, b, c); ///C-A
    return ret;
}

double go2(int a, int b, int c) {
    if(!b && !a) {
        if(c) return 1.0;
    }
    if(!c) return 0.0;
    double &ret = dp[a][b][c];
    int &rett = vis[a][b][c];
    if( rett == kk ) return ret;
    rett = kk;
    double tot = (a * b + b * c + c * a);
    double pra = (a * b) / tot;
    double prb = (b * c) / tot;
    double prc = (c * a) / tot;
    ret = 0.0;
    if(b - 1 >= 0)ret += pra * go2(a, b - 1, c); ///A-B
    if(c - 1 >= 0)ret += prb * go2(a, b, c - 1); ///B-C
    if(a - 1 >= 0)ret += prc * go2(a - 1, b, c); ///C-A
    return ret;
}

int main() {
    int i, j, k, n, tc;
    //_cin;
    kk = 1;
    double a, b, c;
    while( cin >> a >> b >> c ) {
        cout << fixed << setprecision(12) << go(a, b, c) << " ";
        kk++;
        cout << fixed << setprecision(12) << go1(a, b, c) << " ";
        kk++;
        cout << fixed << setprecision(12) << go2(a, b, c) << " ";
        kk++;
        cout<< "\n";
    }
    return 0;
}