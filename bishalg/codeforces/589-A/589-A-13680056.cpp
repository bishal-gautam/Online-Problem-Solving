///============================================================================///
///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                   ID: TC/CF => (BG_PeaceMind.)                             ///
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
#define MX     200002
#define inf    200000000000LL
#define MD     1000000007LL
#define eps    1e-9
///================================///

//const int N=2000005;
//char a[N];
//int b[N],c[N],d[N],e[N],sa[N],height[N],n,m;
//
//int cmp(int *r, int a, int b, int l) {
//    return r[a] == r[b] && r[a + l] == r[b + l];
//}
//
//void da() {
//    int i, j, p, *x = c, *y = d, *t;
//    for(i = 0; i < m; i++)b[i] = 0;
//    for(i = 0; i < n; i++)b[ x[i] = a[i] ]++;
//    for(i = 1; i < m; i++)b[i] += b[i - 1];
//
//    for(i = n - 1; i >= 0; i--)sa[ --b[x[i]] ] = i;
//
//    for(j = 1, p = 1; p < n; j *= 2, m = p) {
//        for(p = 0, i = n - j; i < n; i++)y[p++] = i;
//        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
//        for(i = 0; i < n; i++)e[i] = x[y[i]];
//
//        for(i = 0; i < m; i++)b[i] = 0;
//        for(i = 0; i < n; i++)b[e[i]]++;
//        for(i = 1; i < m; i++)b[i] += b[i - 1];
//
//        for(i = n - 1; i >= 0; i--)sa[--b[e[i]]] = y[i];
//
//        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
//            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
//    }
//}
//
//void callheight() {
//    int i, j, k = 0;
//    for(i = 1; i < n; i++)b[sa[i]] = i;
//    n--;
//    for(i = 0; i < n; height[b[i++]] = k)
//        for(k ? k-- : 0, j = sa[b[i] - 1]; a[i + k] == a[j + k]; k++);
//}
//
////void initrmq(int n) {
////    int i, k;
////    for(i = 2; i <= n; ++i)
////        rmq[i][0] = height[i];
////    for(k = 1; (1 << k) <= n; ++k) {
////        for(i = 2; i + (1 << k) - 1 <= n; ++i) {
////            rmq[i][k] = min(rmq[i][k - 1],
////                            rmq[i + (1 << (k - 1))][k - 1]);
////        }
////    }
////}
//
////int lcp(int aa, int bb) {
////    aa = b[aa], bb = b[bb];
////    if(aa > bb)
////        swap(aa, bb);
////    ++aa;
////    int k = (int) (log((bb - aa + 1) * 1.0) / log(2.0));
////    return min( rmq[aa][k], rmq[ bb - (1 << k) + 1 ][k] );
////}
//
//void print() {
//    int i;
//    cout << "length : " << n << endl;
//    cout << "s[n] = '$' " << endl;
//    cout << "sorted suffix index(0 based) : " << endl;
//    fr(i,0,n-1) cout << sa[i] << " , ";
//    cout << endl;
//    cout << "rank of suffix " << endl;
//    fr(i,0,n-1) cout << b[i] << " , ";
//    cout << endl;
//    cout << "LCP between i and i-1 " << endl;
//    fr(i,0,n-1) cout << height[i] << " , ";
//    cout << endl;
//}
//string s[MX+5];

string str[MX+5],s;
map<string,int>MP;

void Case(string &s) {
    for(int i=0; s[i]; i++) {
        if( isalpha( s[i] ) )s[i]=tolower( s[i] );
    }
}

string Final(string s,int p) {
    int i,j;
    string ret="";
    for(i=0; s[i]; i++)if( s[i]=='+' )break;
   // cout<<i<< " &&& "<<p<<endl;
    for(j=0; s[j]; j++) {
        if( j>=i && j<p ) continue;
        if( j<p ) {
            if(s[j]=='.'|| s[j]=='+')continue;
        }
        ret+=s[j];
    }
    return ret;
}

vector<int>v[ MX+5 ];
bool vis[MX+5];
string ss[MX+5];
int main() {
    int i,j,k,n;
    _cin;
    cin>>n;
    fr( i,1, n) cin>>str[i];
    k=1;
    fr( i,1,n ) {
        s=str[i];
        ///Change case;
        Case(s);
        for(j=0; s[j]; j++)if( s[j]=='@' ) break;
        string dmn=s.substr(j);
        if(dmn=="@bmail.com") {
            s=Final(s,j);
        }
        if( MP[s]==0 ){
            MP[ s ]=(++k);
        }
        //cout<<s<< " ???\n";
        v[ MP[s] ].pb(i);
        ss[i]=s;
    }
    int szz=SZ( MP );
    cout<<szz<<endl;
    for(i=1;i<=n;i++){
        if( vis[i]==1 )continue;
        int mp=MP[ ss[i] ];
        int sz=SZ( v[mp] );
        cout<<sz;
        for( int j=0;j<sz;j++){
             int id=v[ mp ][j];
             vis[ id ]=1;
             cout<< " "<<str[id];
        }
        cout<< "\n";
    }


    return 0;
}