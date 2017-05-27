///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
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
using namespace std;
typedef long long ll;

///  Digit     0123456789012345678 ///
#define MX     100000
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int dp[MX+5];
int pre[MX+5];
int gr[MX+5];
int main() {
    int n;
    S(n);
    dp[1]=dp[2]=0;
    pre[1]=pre[2]=0;
    for(int i=3; i<=n; i++) {
        for(int p=2; p<=i; p++) {
            int psm=(p*(p-1))/2;
            int rem=(i-psm);
            if( rem<=0 )break;
            if( rem && (rem%p)==0 ) {
                int bg=rem/p;
                int ed=bg+p-1;
                int x=( pre[ ed ]^pre[ bg-1 ] );
                gr[ x ]=i;
            }
        }
        int ans=0;
        while( true ) {
            if( gr[ ans ]!=i )break;
            ans++;
        }
        dp[ i ]=ans;
       // cout<<i<< " => "<<dp[i]<<endl;
        pre[i]=pre[i-1]^ans;
    }
//    if( dp[n] ) printf("Winner\n");
//    else printf("Looser\n");

    int k=-1;
    for(int p=2; p<=n; p++) {
        int psm=(p*(p-1))/2;
        int rem=(n-psm);
        if( rem<=0 )break;
        if( rem && rem%p==0 ) {
            int bg=rem/p;
            int ed=bg+p-1;
            if( !(pre[ ed ]^pre[ bg-1 ]) ){
                k=p;
                break;
            }
        }
    }
    printf("%d\n",k);
    return 0;
}