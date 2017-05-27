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
#define nl printf("\n")
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

#define MD 1000000007
#define MX 300005
typedef long long ll;

ll ar[MX+5],br[MX+5],BITL[MX+5],BITR[MX+5],L[MX+5],R[MX+5];
ll MP[MX+5],ans[MX+5];
ll ans2[MX+2];
void add(ll p,ll v,ll *BIT) {
    for(ll i=p; i<=MX; i+=i&-i)BIT[i]+=v;
}

ll read(ll p,ll *BIT) {
    ll ret=0;
    for(int i=p; i>0; i-=i&-i)ret+=BIT[i];
    return ret;
}

map<ll,ll>rev;

int main() {
    ll n,x,i;
    scanf("%lld",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld",&x);
        ar[i]=x;
        br[i]=x;
    }
    sort( br,br+n );
    for(i=0; i<n; i++) {
        ll xx=(lower_bound(br,br+n,ar[i])-br)+1;
        rev[ xx ]=ar[i];
        ar[i]=xx;
        // cout<<ar[i]<< " ";
    }
    // cout<<endl;
    MP[ ar[0] ]=1LL;
    add( ar[0],+1,BITL );
    add( ar[0],+1,BITR );

//    cout<<read(MX,BITL)<<endl;
//    cout<<read(MX,BITR)<<endl;
    L[ ar[0] ]=1,R[ ar[0] ]=2*MX;
    for(i=1; i<n; i++) {
        x=ar[i];
        ll res=0;
        ll xx=read( x ,BITR );
        int ok=1;
        if( xx==0 ) ok=0;
        else {
            ll lo=1,hi=x,par=0;
            while(lo<=hi) {
                int md=(lo+hi)/2;
                if( read(md,BITR) >=xx ) {
                    par=md;
                    hi=md-1;
                } else lo=md+1;
            }
            //cout<< " par-> "<<par<<endl;
            if( x>=L[par] && x<=R[par] ) {
                res=par;
                MP[ x ]=( MP[ par ]*2 +1 )%MD;
                L[x]=par,R[x]=R[ par ];
                add( par,-1,BITR );
                add( x,+1,BITL );
                add( x,+1,BITR );
            } else ok=0;
        }
        if( ok==0 ) {
            xx=read(x,BITL);
            int yy=read(MX,BITL);
            xx++;
            // cout<< " Here: "<<xx<<endl;
            //cout<< " Here: "<<yy<<endl;
            //yy=read( MX,BITL );
            ll lo=x,hi=MX,par=0;
            while(lo<=hi) {
                int md=(lo+hi)/2;
                if( read(md,BITL)>=xx ) {
                    par=md;
                    hi=md-1;
                } else lo=md+1;
            }
            res=par;
            //cout<< " PP: "<<par<<endl;
            MP[ x ]=( MP[ par ]*2 )%MD;
            L[x]=1,R[x]=par;
            add( par,-1,BITL );
            add( x,+1,BITL );
            add( x,+1,BITR );
        }
        ans2[i]=rev[ res ];
        //cout<<x<< " = "<<MP[x]<<endl;
    }
    for(int i=1; i<n; i++) {
        if(i==0)printf("%lld",ans2[i]);
        else printf("%lld ",ans2[i]);
    }
    printf("\n");
    return 0;
}