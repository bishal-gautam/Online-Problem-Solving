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
#define MX     1000103
#define inf    1000001
#define MD     1000000007
#define eps    1e-9
///===============================///

string ss[MX+2];
string tt[MX+2];
int n,len;

int Solve(string s) {
    int i,j,k;
    int ret=0;
    for(j=1; j<n; j++) {
        int cnt=0;
        for(i=0; i<len; i++) {
            //cout<<cnt<< " "
            if( ss[j]==s ){
                ret+=cnt;
                break;
            }
            string tp="";
            for(k=1; k<len; k++) {
                tp+=ss[ j ][ k ];
            }
            tp+=ss[ j ][ 0 ];
            ss[ j ]=tp;
            cnt++;
        }
        if(i==len) return inf;
    }
    return ret;
}

int main() {
    int i,j,k;
    while( S(n)==1 ) {
        for(i=0; i<n; i++) {
            cin>>ss[i];
            tt[i]=ss[i];
        }
        len=SZ( ss[0] );

        int cnt=0,mn=inf;
        for(i=0; i<len; i++) {
            for(j=1;j<n;j++)ss[j]=tt[j];
            int res=Solve( ss[0] );
            mn=min( mn, cnt+res );
           // cout<<cnt<< " => "<<res<<endl;
            string tp="";
            for(j=1; j<len; j++) {
                tp+=ss[0][j];
            }
            tp+=ss[0][0];
            ss[ 0 ]=tp;
            cnt++;
        }
        if( mn>=inf ) mn=-1;

        printf("%d\n",mn);
    }

    return 0;
}