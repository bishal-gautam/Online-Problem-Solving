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
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     200005
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

char s[MX+2];
int Z[MX+5];
void Zalgo(char *s) {
    int i,j,k,L=0,R=0,n=strlen(s);
    for(i=1; i<n; i++) {
        if(i>R) {
            L=R=i;
            while(s[R-L]==s[R] && R<n )R++;
            Z[i]=R-L;
            R--;
        } else {
            if( Z[i-L]< R-i+1 ) Z[i]=Z[i-L];
            else {
                L=i;
                while( s[R-L]== s[R] && R<n )R++;
                Z[i]=R-L;
                R--;
            }
        }
    }
    Z[0]=n;
}

int dp[MX+5];
int MP[MX+2];
int main() {
    gets(s);
    int i,n=strlen(s);
    Zalgo(s);
    int cnt=1;
    for(i=1; i<n; i++) {
        if( Z[i]==(n-i) ) {
            MP[ Z[i] ]=1;
            cnt++;
        }
        dp[1]+=1;
        dp[ Z[i]+1 ]-=1;
    }
    for(i=1;i<=n;i++){
        dp[i]+=dp[i-1];
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++){
        if( MP[i] ){
            printf("%d %d\n",i,dp[i]+1);
        }
    }
    printf("%d %d\n",n,1);

    return 0;
}