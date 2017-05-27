///===========================================================================
///
///                   Bismillah ir-Rahman ir-Rahim
///
/// ==========================================================================
///
///                      JU_Back_Benchers
///
///              Team Members: Shaheen, Bishal, B'ru
/// ==========================================================================
//#include<bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <iomanip>

using namespace std;

#define LL                          long long
#define ULL                         unsigned long long

// I/O
#define I(X)                        scanf("%d",     &(X))
#define II(X, Y)                    scanf("%d%d",   &(X), &(Y))
#define III(X, Y, Z)                scanf("%d%d%d", &(X), &(Y), &(Z))

#define DI(X) int (X);              scanf("%d",     &X)
#define DII(X, Y) int X, Y;         scanf("%d%d",   &X, &Y)
#define DIII(X, Y, Z) int X, Y, Z;  scanf("%d%d%d", &X, &Y, &Z)

#define IL(x)                       scanf("%lld", &x)
#define IIL(x,y )                   scanf("%lld", &x,&y)
#define IIIL(x,y,z)                 scanf("%lld", &x,&y,&z)

#define DIL(x)       LL x;          scanf("%lld", &x)
#define DIIL(x,y)    LL x,y;        scanf("%lld", &x,&y)
#define DIIIL(x,y,z) LL x,y,z;      scanf("%lld", &x,&y,&z)

#define SS(s)                       scanf("%s",s)
#define S                           scanf
#define P                           printf

#define PI(x)                       printf("%d\n",      x)
#define PII(x,y)                    printf("%d %d\n",   x,y)
#define PIII(x,y,z)                 printf("%d %d %d\n",x,y,z)

#define PIL(x)                      printf("%lld\n",          x)
#define PIIL(x,y)                   printf("%lld %lld\n",     x,y)
#define PIIIL(x,y,z)                printf("%lld %lld %lld\n",x,y,z)

// LOOP
#define rep(i,a,b)                  for(int i=a;i<=b;i++)
#define rev(i,a,b)                  for(int i=a;i>=b;i--)
#define repv(i,a)                   for(int i=0;i<(int)a.size();i++)
#define revv(i,a)                   for(int i=((int)a.size())-1;i>=0;i--)

#define FS(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;

// array initialization
#define MEM(a,val)                  memset(a,val,sizeof(a));
#define SET(a)                      memset(a,-1,sizeof a)
#define CLR(a)                      memset(a,0,sizeof a)

// min-max
#define Max(a,b)                    (a>b?a:b)
#define _Max(a,b,c)                 Max(a,Max(b,c))
#define Min(a,b)                    (a<b?a:b)
#define _Min(a,b,c)                 Min(a,Min(b,c))
#define MAX(a)                      (*max_element(all(a)))
#define MIN(a)                      (*min_element(all(a)))

#define FastMax(x,y)                ((((y-x)>>(32-1))&(x^y))^y)
#define FastMin(x,y)                ((((y-x)>>(32-1))&(x^y))^x)

#define SQR(n)  (n*n)
#define eps     (1e-9)
#define pi      (2.0*acos(0.0)) //#define PI acos(-1.0)

#define all(a)  a.begin(),a.end()
#define pb      push_back
#define NL      puts("");
#define pline   cout << "_________________________" << endl;
// pair
#define X       first
#define Y       second
// binary search
#define LB(a,x)         (lower_bound(all(a),x)-a.begin())
#define UB(a,x)         (upper_bound(all(a),x)-a.begin())
// IO
#define READ            freopen("C:\\Users\\backbencher\\Desktop\\input.txt","r",stdin)
#define WRITE           freopen("C:\\Users\\backbencher\\Desktop\\output.txt","w",stdout)

#define _cin            ios_base::sync_with_stdio(0); cin.tie(0);

#define SI(X)           X=in<int>()
#define SII(X,Y)        X=in<int>(),Y=in<int>()
#define SIII(X,Y,Z)     X=in<int>(),Y=in<int>(),Z=in<int>()

#define SL(X)           X=in<LL>()
#define SLL(X,Y)        X=in<LL>(),Y=in<LL>()
#define SLLL(X,Y,Z)     X=in<LL>(),Y=in<LL>(),Z=in<LL>()

#define VI              vector< int >
#define VII             vector< VI >
#define VLL             vector< LL >
#define PPI             pair< int , int >
#define PPL             pair< LL , LL >
#define VPI             vector< PPI >

#define countbit(x)     __builtin_popcount(x)

#define SZ(x) (int)(x.size())

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpp make_pair

#define CPY(a,b) memcpy(a,b,sizeof(a))

#define fv(i,v)   for(int i=0;i<(int)v.size();i++)
#define fr(i,a,n) for(int i=a;i<=n;i++)
#define rf(i,n,a) for(int i=n;i>=a;i--)

#define dbg(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)

/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string

#define D double
#define sz size()
#define PB push_back
#define cp printf("***** here here here here *****\n");
#define CHR getchar()
#define SQR(n) (n*n)
#define xx first
#define yy second
#define S1(a) a=in<int>()
#define S2(a,b) a=in<int>(),b=in<int>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define SL1(a) a=in<LL>()
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define all(a) a.begin(),a.end()
#define BitCnt(a) __builtin_popcountll(a)
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#include <time.h>
//
//template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
//template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
//template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
//template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }

// mathematics
//template<typename T> T POW(T base,T power)          { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
//template<typename T> T PPOW(T B,T P)                { if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
//template<typename T> T Bigmod(T base,T power,T mod) { T ret=1; while(power)  { if(power & 1) ret=(ret*base)%mod; base=(base*base)%mod;  power>>=1; }return ret; }
//template<typename T> T ModInverse(T number,T mod)   { return Bigmod(number,mod-2,mod); }
//template<typename T> T GCD(T a,T b)                 { if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
//template<typename T> T LCM(T a,T b)                 { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
//template<typename T> T EUCLIDE(T a,T b,T &x,T &y)   { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
//template<typename T> T ABS(T a)                     { if(a<0)return -a;else return a;}

// geometry
//template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
//template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
//template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }

//double DEG(double x) { return (180.0*x)/(pi);}
//double RAD(double x) { return (x*(double)pi)/(180.0);}

// debug
//void P_ARR(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
//template<typename T> T in(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }

//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};                                    /// month
//int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };                                  /// 4 Direction
//int dir[9][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};       /// 8 direction
//int dir[9][2] = { {0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };    /// Knight Direction
//int dir[8][2] = { {0,0},{2,0},{1,1},{-1,1} ,{-2,0} , {-1,-1} ,{1,-1} };               /// Hexagonal Direction
// dir[][0] = x value, dir[][1] = y value

/// ======================================================================================================
#define  debug  0
#define  DD     if(debug)

///             0123456789
#define  MX     500007
#define  MOD    1000000007
#define  inf    1000000000

/// ================================================================================

pii nd[(4 * MX) + 2];
int ar[MX + 5], dp[MX + 5];

void Build(int id, int l, int r) {
    if(l == r) {
        nd[id] = mpp(ar[l], ar[l]);
        return;
    }
    int md = (l + r) >> 1, lft = id << 1, rgt = lft + 1;
    Build(lft, l, md);
    Build(rgt, md + 1, r);
    nd[id].X = max(nd[lft].X, nd[rgt].X);
    nd[id].Y = min(nd[lft].Y, nd[rgt].Y);
}

pii Qry(int id, int l, int r, int q1, int q2) {
    if(l == q1 && r == q2) return nd[id];
    int md = (l + r) >> 1, lft = id << 1, rgt = lft + 1;
    if( q2 <= md ) return Qry(lft, l, md, q1, q2);
    else if( q1 > md ) return Qry(rgt, md + 1, r, q1, q2);
    else {
        pii x = Qry(lft, l, md, q1, md);
        pii y = Qry(rgt, md + 1, r, md + 1, q2);
        return mpp( max(x.X, y.X), min(x.Y, y.Y) );
    }
}
int main() {
    int i, j, k, n;
    II(n, k);
    fr(i, 1, n)I(ar[i]);
    Build(1, 1, n);
    int mx = 1;
    for(i = 1; i <= n; i++) {
        ///Mx-Mn;
        int lo = i, hi = n, ret = 1;
        while(lo <= hi) {
            int md = (lo + hi) >> 1;
            pii p = Qry(1, 1, n, i, md);
            int vl = p.X - p.Y;
            if( vl <= k ) {
                ret = max(ret, md);
                lo = md + 1;
            } else hi = md - 1;
        }
        dp[i] = (ret - i + 1);
        mx = max(mx, dp[i]);
    }
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(dp[i] == mx)cnt++;
    }
    printf("%d %d\n", mx, cnt);
    for(i = 1; i <= n; i++) {
        if(dp[i] == mx) {
            printf("%d %d\n", i, i + mx - 1);
        }
    }
    return 0;
}