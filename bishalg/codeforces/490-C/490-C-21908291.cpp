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
#define MX     1000005
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int a,b,dp1[MX+2],dp2[MX+2];
char s[MX+2];
int main() {
    int n,i,j,k,x,y;
    scanf("%s",s);
    S2(a,b);
    n=strlen(s);
    int nm1=0,nm2=0;
    for(i=0;i<n;i++){
        nm1=(nm1*10+s[i]-'0')%a;
        dp1[i]=nm1;
    }
    int tn=1;
    for(i=n-1;i>=0;i--){
        nm2=(nm2+( s[i]-'0' )*tn )%b;
        dp2[i]=nm2%b;
        tn=(tn*10)%b;
    }
    int md=-1;
    for(i=0;i<n-1;i++){
        if( dp1[i]==0 ){
            if( dp2[i+1]==0 && s[i+1]!='0' ){
                md=i;
                break;
            }
        }
    }
    if(md==-1)printf("NO\n");
    else {
        printf("YES\n");
        for(i=0;i<=md;i++)printf("%c",s[i]);
        nl;
        for(i=md+1;i<n;i++)printf("%c",s[i]);
        nl;
    }
    return 0;
}