/*****************************************************************
 *                       BY THE NAME OF GOD                      *
 *                   BISMILLAHIR RAHMANIR RAHIM                  *
 *                           JU_Circavex                         *
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
using namespace std;

#define S scanf
#define P printf

#define LL long long int
#define ULL unsigned long long int
#define ll long long int
#define ull unsigned long long int
#define D double

#define all(a) a.begin(),a.end()
#define X  first
#define Y  second
#define MP make_pair
#define NL P("\n")

#define PB(x)      push_back(x)
#define PS(x)      push(x)
#define sz()       size()
#define SZ(x)      (int)(x.size())
#define UB         upper_bound
#define LB         lower_bound
#define countbit(x) __builtin_popcount(x)

#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)

#define inf (1<<30)
#define linf (1LL<<62)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define aov(a) a.begin(),a.end()
#define pb push_back
#define xx first
#define yy second
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define mpr make_pair
#define endl '\n'
#define dbg(x) cerr<<#x<<" : "<<x<<endl
#define mpp make_pair
#define fr(i,a,n) for(int i=a;i<=n;i++)

template <class T> inline T BigMod(T p,T e,T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T POW(T p,T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T> inline T ModInv(T a,T M) {
    return BigMod(a,M-2,M);   // M is prime
}
template <class T> inline T gcd(T a,T b) {
    if(b==0)return a;
    return gcd(b,a%b);
}
template <typename T> LL isLeft(T a,T b,T c) {
    return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);
}

int    Set(int N,int pos) {
    return N=N | (1<<pos);
}
int  Reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >
#define pll pair< ll , ll >
#define pii pair< int , int >


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

///         0123456789
#define MOD 1000000007LL
#define MD  1000000007LL
//#define MX  100007
#define eps 1e-9
#define M   100005

int ts, kk = 1;

#define  MX     1048577 // (2^20+1) for fft
struct cpx {
    long double real, imag;
    inline cpx() {
        real=imag=0.0;
    }
    inline cpx(long double x) {
        real=x,imag=0.0;
    }
    inline void clr() {
        real=imag=0.0;
    }
} a[MX+2], b[MX+2];

void fft(cpx* a, int n, bool inv) {
    for (int i=1, j=0; i<n; ++i) {
        int bit = (n >> 1);
        for (; j>=bit; bit>>=1)j -= bit;
        j += bit;
        if (i < j) swap (a[i], a[j]);
    }
    for(int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (inv ? -1 : 1);
        double cs = cos(ang);
        double sn = sin(ang);
        for(int i=0; i<n; i+=len) {
            ll hlen = (len >> 1);
            double wreal = 1;
            double wimag = 0;
            cpx u;
            cpx* pa1 = a + i;
            cpx* pa2 = a + i + hlen;
            for(int j=0; j<hlen; ++j) {
                cpx& a1 = *pa1++;
                cpx& a2 = *pa2++;
                u = a1;
                double vreal = a2.real * wreal - a2.imag * wimag;
                double vimag = a2.real * wimag + a2.imag * wreal;
                a1.real += vreal;
                a1.imag += vimag;
                a2.real = u.real - vreal;
                a2.imag = u.imag - vimag;
                double wreal2 = wreal;
                wreal = wreal * cs - wimag * sn;
                wimag = wreal2 * sn + wimag * cs;
            }
        }
    }
    if (inv)
        for (int i= n; i >= 0; --i) a[i].real /= n;
}

inline cpx multiply(const cpx& Lf, const cpx& Rg) {
    cpx res;
    res.real = Lf.real * Rg.real - Lf.imag * Rg.imag;
    res.imag = Lf.real * Rg.imag + Lf.imag * Rg.real;
    return res;
}

ll res[MX+2];
void Mul(int sa,int sb) {
    int n=1 , mx=max(sa,sb);
    while (n <  mx )  n <<= 1;
    n<<=1;
    fft(a, n, false),fft(b, n, false);
    for(int i=0; i<n; i++) a[i] = multiply(a[i], b[i]);
    fft(a, n, true);
    for(int i = 0 ; i < n ; ++ i ) {
        res[i] = (ll)( round( a[i].real ) );
        a[i].clr(),b[i].clr();///Clear a,b
    }
//    int c=0;
//    for(int i=0; <n;++i){res[i]+=c;c=res[i]/10;res[i]%=10;}
}

ll dp[MX+2];
char ar[MX],br[MX];
void Solve(int x,int n,int k) {
    for(int i=0; i<n; i++) {
        if( (ar[i]-'0')==x ) a[i].real=1.0;
        else a[i].real=0.0;
    }
    for(int i=0; i<k; i++) {
        if( (br[i]-'0')==(!x) ) b[k-i-1].real=1.0;
        else b[k-i-1].real=0.0;
    }
    Mul(n,k);
    int sz=n+k-1;
    for(int i=0; i<=sz; i++) {
        dp[i]+=(res[i]);
        //if( i>=k-1 )cout<<i<< " => "<<res[i]<<endl;
    }
}

int main() {
    int n,k;
    scanf("%s",br);
    scanf("%s",ar);
    n=strlen(ar);
    k=strlen(br);
    for(int i=0;i<=1;i++)Solve(i,n,k);
    ll sm=0LL;
    for(int i=k-1;i<=n-1;i++){
        //cout<<i<< " ====> "<<dp[i]<<endl;
        sm+=dp[ i ];
    }
    printf("%lld\n",sm);
    return 0;
}