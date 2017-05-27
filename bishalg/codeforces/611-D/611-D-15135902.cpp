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
int month[] = { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

/**************************************************************************************
 * ///////////////////////////////////////////////////////////////////////////////////*
 *************************************************************************************/

///==========CONSTANTS==============///
///  Digit     0123456789*#@%&^$"-  ///
#define MX     5001
#define inf    100000000
#define MD     1000000007LL
#define EPS    1e-9
///================================///

int n, dp[MX + 2][MX + 2], dpp[MX + 2][MX + 2];
char s[MX + 5];
ull b = 31, bp[MX + 2], Hs[MX + 2];

void Pre( ) {
    bp[0] = 1ULL;
    for(int i = 1; i <= MX; i++) {
        bp[i] = (bp[i - 1] * b);
    }
    for(int i = 1; i <= n; i++) {
        Hs[i] = (Hs[i - 1] * b + (s[i] - '0' + 1));
    }
}

ull Hv(int l, int r) {
    return (Hs[r] - (Hs[l - 1] * bp[r - l + 1]));
}

int Less(int x, int y, int l) {
    if( x <= 0 ) return 1;
    int lo = 1, hi = l, id = 0;
    if( Hv(x, x + l - 1) == Hv(y, y + l - 1) ) return 0;
    while(lo <= hi) {
        int md = (lo + hi) / 2LL;
        if( Hv(x, x + md - 1) == Hv(y, y + md - 1) ) {
            id = max(id, md);
            lo = md + 1;
        } else {
            hi = md - 1;
        }
    }
    return ( s[x + id] < s[y + id] );
}


int main() {
    int i, j, k, x;
    S(n);
    scanf("%s", s + 1);
    Pre( );
    for(i = 1; i <= n; i++)dp[1][i] = 1; ///Ending in i starting from 1
    for(i = 1; i <= n; i++) {
        for(j = 2; j <= i ; j++) {
            ///Last String S[j---i];
            if( s[j] == '0' ) continue;
            int ln = (i - j + 1);
            /// LastLast;
            int x = j - ln;
            if( x >= 1 && Less(x, j, ln) ) {
                //cout << " ??\n";
                dp[j][i] = (dp[j][i] + dp[x][j - 1]) % MD;
            }
            x = max(x, 0);
           // for(k=x+1;k<=j-1;k++)dp[j][i]=(dp[j][i]+dp[k][j-1])%MD;
            dp[j][i] = ( dp[j][i] + dpp[x+1][j - 1] ) % MD;
        }
        dpp[i][i]=dp[i][i];
        for(j = i-1; j >=1 ; j--)dpp[j][i] = ( dpp[j + 1][i] + dp[j][i] ) % MD;
    }
    int sm=0;
    for(i=1;i<=n;i++)sm=(sm+dp[i][n])%MD;
   // printf("%d\n", dpp[n][n]);
    printf("%d\n", sm);
    return 0;
}