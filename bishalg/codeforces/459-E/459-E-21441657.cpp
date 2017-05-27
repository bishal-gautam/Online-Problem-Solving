/*****************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                  *
 *                         JU_Circavex                           *
 *****************************************************************/

#include<bits/stdc++.h>

//#include<algorithm>
//#include<cstdio>
//#include<sstream>
//#include<cstdlib>
//#include<cctype>
//#include<cmath>
//#include<set>
//#include<queue>
//#include<stack>
//#include<list>
//#include<iostream>
//#include<fstream>
//#include<numeric>
//#include<string>
//#include<vector>
//#include<cstring>
//#include<map>
//#include<iterator>
//#include<deque>
//#include<climits>
//#include<complex>

#define S scanf
#define P printf

#define LL long long int
#define ULL unsigned long long int
#define D double

#define all(a) a.begin(),a.end()
#define X  first
#define Y  second
#define MP make_pair
#define NL P("\n")

#define PB(x)      push_back(x)
#define PS(x)      push(x)
#define sz()       size()
#define UB         upper_bound
#define LB         lower_bound
#define countbit(x) __builtin_popcount(x)

#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)

using namespace std;


#define ll long long int
#define ull unsigned long long int
//#define inf (1<<30)
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define aov(a) a.begin(),a.end()
#define pb push_back
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define pll pair< ll , ll >
#define pii pair< int , int >
#define mpr make_pair
#define xx first
#define yy second
#define nl puts("")
#define endl '\n'
#define dbg(x) cerr<<#x<<" : "<<x<<endl
#define mpp make_pair
#define SZ(x) (int)(x.size())
#define fr(i,a,n) for(int i=a;i<=n;i++)


//template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
//template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }
//template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
//template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
//template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
//template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}
//
//int    Set(int N,int pos){ return N=N | (1<<pos);}
//int  Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >


/// Hashing Bases & MOD
///           0123456789
#define Base1 10000019ULL
#define Base2 10000079ULL
#define Base3 10000103ULL
#define MOD1  1000000007ULL
#define MOD2  1000000009ULL
#define MOD3  1000000021ULL
#define LOGX  17
#define FCIN  ios_base::sync_with_stdio(0); cin.tie(0)

///int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,+1,0,1,0,-1}; // Hexagonal Direction   **
///int dy[]={-1,+1,1,0,-1,0}; //                       *#*
///                                                     **
///int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction

int ts, kk = 1;

///          0123456789
#define MX   300002
#define inf  10000005
#define MOD  1000000007
#define eps  1e-9

int n,m,dp[MX+5];
pair<int, pii >pp[MX+2];
int lst[MX+2];
vector< pii >v[MX+2];

int main() {
    int i,j,k,x,y,z;
    S2(n,m);
    for(i=1; i<=m; i++) {
        S2(x,y);
        S(z);
        pp[i]=mpp(z,mpp(x,y));
    }
    for(i=1; i<=n; i++) {
        v[ i ].pb( mpp(0,0) ); ///time,dp value;
    }
    CLR(dp);
    sort( pp+1,pp+m+1 );
    for(i=1; i<=m;  ) {
        int x=pp[i].X;
        int id=i;
        while( pp[i].X==x ) {
            lst[ i ]=id;
            i++;
        }
    }
    int mx=1;
    for(i=1; i<=m; i++) {
        z=pp[i].X;
        x=pp[i].Y.X;
        y=pp[i].Y.Y;
        int lb=lower_bound( all( v[x] ), mpp( lst[i],-inf ) )-v[ x ].begin()-1;
        dp[ y ]=max( dp[y], v[ x ][ lb ].Y+1 );
        v[ y ].pb( mpp(i,dp[y] ) );
        mx=max( mx,dp[y] );
    }
    printf("%d\n",mx);

    return 0;
}