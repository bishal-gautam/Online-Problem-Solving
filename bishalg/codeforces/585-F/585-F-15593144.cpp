///============================================================================///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                                                                            ///                                                                          ///
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
//template<typename T> double DIS(T a, T b) {return sqrt((double)( SQR(a.X - b.X) + SQR(a.Y - b.Y)));}
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
///int dx[] = {1, 0, -1, 0};int dy[] = {0, 1, 0, -1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

/**************************************************************************************
 * ////////////////////////////////////////////////////////////////////////////////////*
 **************************************************************************************/

///==========CONSTANTS==============///
///  Digit      0123456789*#@%&^$"- ///
#define  MX     25005
#define  inf    2000000000
#define  MD     1000000007LL
#define  eps    1e-9
///================================///

const int CHR = 10; ///Tot distinct char in a text
struct node {
    int nxt[CHR];
    node() {
        CLR(nxt);
    }
};
node T[MX];
int fl[MX];
int nw, len, val[MX];

void init() {
    CLR(T);
    CLR(fl);
    CLR(val);
    T[1] = node();
    nw = 1;
}

char s[1005], a[55], b[55];
int n, d;
void Ins(int x, int y) {
    int p = 1;
    for(int i = x; i <= y; i++) {
        int k = s[i] - '0';
        //cout << k;
        if(T[p].nxt[k] == 0) {
            T[p].nxt[k] = (++nw);
            T[nw] = node();
        }
        p = T[p].nxt[k];
    }
    // nl;
    val[ p ] = 1;
}

void fail_bfs() {
    queue<int>Q;
    Q.push(1);
    for(int i = 0; i < CHR; i++) T[0].nxt[i] = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < CHR; i++) {
            int v = T[u].nxt[i];
            if(v == 0) {
                T[u].nxt[i] = T[ fl[u] ].nxt[i];
                continue;
            }
            fl[v] = T[ fl[u] ].nxt[i];
            Q.push(v);
        }
    }
}

ll dp[25001][51][2][2][2];

ll go(int id, int p, int z, int ch, int f) {
    if(p == n) return f;
    ll &ret = dp[id][p][z][ch][f];
    if(ret != -1) return ret;
    int mx = s[p] - '0';
    if(ch)mx = 9;
    ret = 0LL;
    for(int i = 0; i <= mx; i++) {
        int nid = 1, fg = 0;
        if( z || i ) {
            nid = T[id].nxt[i];
            int tmp = nid;
            while(tmp)fg = (fg | val[tmp]), tmp = fl[tmp];
        }
        ret = (ret + go(nid, p + 1, z || i , ch || i < mx, f || fg)) % MD;
    }
    return ret;
}

ll Solve(char *str) {
    strcpy(s, str);
    //cout << "S: " << s << endl;
    n = strlen(s);
    // cout << n << endl;
    SET(dp);
    ll ans = go(1, 0, 0, 0, 0);
    //cout << " Ans: " << ans << endl;
    return ans;
}

int main() {
    int i, j, k;
    scanf("%s", s);
    scanf("%s", a);
    scanf("%s", b);
    init();
    n = strlen(s);
    d = strlen(a);
    ///Decreasing by 1 !!
    for(i = d - 1; i >= 0; i--) {
        if( a[i] != '0' ) {
            a[i]--;
            break;
        }
        a[i] = '9';
    }
    if( a[0] == '0' ) {
        for(i = 0; i <= d - 2; i++)a[i] = a[i + 1];
        a[d - 1] = '\0';
    }
    //cout << a << " -- " << b << endl;
    d /= 2;
    for(i = 0; i < n; i++) {
        int nx = i + d - 1;
        if(nx >= n)break;
        Ins(i, nx);
    }
    fail_bfs();
    printf("%lld\n", ( Solve(b) - Solve(a) + MD ) % MD);
    return 0;
}