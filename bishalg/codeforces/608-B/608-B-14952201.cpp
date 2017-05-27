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
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

/**************************************************************************************
 * ///////////////////////////////////////////////////////////////////////////////////*
 *************************************************************************************/

///==========CONSTANTS==============///
///  Digit     0123456789*#@%&^$"-  ///
#define MX     2000002
#define inf    1000000009
#define MD     1000000007LL
#define eps    1e-9
///================================///

const int MAXN = (1 << 20) + 5;
const int P = 1000000007;
const int D = 4000001;

char buffer[MAXN];
char buffer1[MAXN];
char buffer2[MAXN];
pair<double, double> pa[2][MAXN * 2], res[MAXN * 2], tmp[MAXN * 2];
int org[MAXN * 2], ans[MAXN];
int len_a, n, cnt;

inline int Lowbit(int x) {
    return x & -x;
}

void Fill(pair<double, double> to[], int m, int d) {
    if (m == n) {
        to[d] = {org[cnt++], 0.};
    } else {
        Fill(to, m << 1, d);
        Fill(to, m << 1, d + m);
    }
}

void Fill2(pair<double, double> to[], int m, int d) {
    if (m == n) {
        to[d] = tmp[cnt++];
    } else {
        Fill2(to, m << 1, d);
        Fill2(to, m << 1, d + m);
    }
}

void FFT(pair<double, double> p[], double op) {
    for (int d = 0; (1 << d) < n; ++d) {
        int m = 1 << d;
        double p0 = PI / m * op;
        double sinp0 = sin(p0);
        double cosp0 = cos(p0);
        for (int i = 0; i < n; i += m << 1) {
            double sinp = 0;
            double cosp = 1;
            for (int j = 0; j < m; ++j) {
                double ta = cosp * p[i + j + m].first - sinp * p[i + j + m].second;
                double tb = cosp * p[i + j + m].second + sinp * p[i + j + m].first;
                p[i + j + m] = {p[i + j].first - ta, p[i + j].second - tb};
                p[i + j].first += ta;
                p[i + j].second += tb;
                double tsinp = sinp;
                sinp = sinp * cosp0 + cosp * sinp0;
                cosp = cosp * cosp0 - tsinp * sinp0;
            }
        }
    }
}

void Transform(pair<double, double> to[]) {
    cnt = 0;
    Fill(to, 1, 0);
    FFT(to, 1.);
}

void Mul(int t) {
    Transform(res);
    for (int i = 0; i < n; ++i) {
        tmp[i].first = res[i].first * pa[t][i].first - res[i].second * pa[t][i].second;
        tmp[i].second = res[i].first * pa[t][i].second + res[i].second * pa[t][i].first;
    }
    cnt = 0;
    Fill2(res, 1, 0);
    FFT(res, -1.);
}

void Init(char *s) {
    strcpy(buffer, s);
    len_a = strlen(buffer);
    // Find the smallest power of 2 that is greater than or equal to length of A.
    for (n = len_a; n != Lowbit(n); n += Lowbit(n));
    // Double the total length because B can be as long as A.
    n *= 2;
    for (int i = 0; i < len_a; ++i) org[i] = buffer[i] == '1';
    for (int i = len_a; i <= n; ++i) org[i] = 0;
    Transform(pa[0]);
    for (int i = 0; i < len_a; ++i)
        org[i] ^= 1;
    Transform(pa[1]);
}

ll sm;
void Work(char *s) {
    strcpy(buffer, s);
    sm = 0LL;
    int len_b = strlen(buffer);
    for (int i = 0; i < len_b; ++i) org[i] = buffer[len_b - 1 - i] == '1';
    for (int i = len_b; i <= n; ++i) org[i] = 0;
    Mul(1);
    for (int i = 0; i <= len_a - len_b; ++i)
        ans[i] = int(res[i + len_b - 1].first / n + 0.5);
    for (int i = 0; i < len_b; ++i) org[i] ^= 1;
    Mul(0);
    for (int i = 0; i <= len_a - len_b; ++i) {
        ll t = ans[i] + int(res[i + len_b - 1].first / n + 0.5);
        sm += t;
    }
    printf("%I64d\n", sm);
}

int main() {
    cin >> buffer1 >> buffer2;
    Init(buffer2);
    Work(buffer1);
    return 0;
}