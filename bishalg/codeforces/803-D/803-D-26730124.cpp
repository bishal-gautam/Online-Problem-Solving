///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
///---------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(int i=a;i<=n;i++)

#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     2000005
#define inf    100000000001.0
#define MD     1000000007
#define eps    1e-9
///===============================///
#define lm 1001

int n,k,pre[MX+2];
string s;

int Ok(int len){
    int i=0,j=0;
    int sm=0,cnt=0;
    for(i=0;i<n;i++){
        sm++;
        if( s[i]=='-' || s[i]==' '){
            if( sm>len ) return false;
            if( sm+pre[i]>len ){
                sm=0;
                cnt++;
            }
        }
    }
    if( sm>len ) return false;
    return (cnt+1<=k);
}

int main() {
    int i,j,tc;
    tc=1;
    while( tc-- ) {
        S(k);
        getchar();
        getline(cin,s);
        n=SZ(s);
        int sm=0;
        for(i=n-1;i>=0;i--){
            pre[i]=sm;
            if( s[i]=='-' || s[i]==' '){
               // cout<<i<< " => "<<sm<<endl;
                sm=0;
            }
            sm++;
        }
        int lo=1,hi=n,ret=n+1;
        while( lo<=hi ){
            int md=( lo+hi )/2;
            if( Ok(md) ){
                ret=min(ret,md);
                hi=md-1;
            }else lo=md+1;
        }
        printf("%d\n",ret);
    }
    return 0;
}