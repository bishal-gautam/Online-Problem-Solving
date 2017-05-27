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

///  dp10it    0123456789012345678 ///
#define MX     5000000
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

string s[]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
ll pw[35];
int main(){
     ll i,n;
     pw[0]=1LL;
     for(i=1;i<=32;i++)pw[i]=pw[i-1]*2LL;
     cin>>n;
     ll sm=0LL,k=0;
     while(true){
        ll nw=(5LL*pw[k]);
        if( (sm+nw)>=n ){
            break;
        }
        sm+=nw;
        k++;
     }
     ll rem=(n-sm);
     ll tw=pw[k];
   //  cout<<rem<< " : "<<pw[k]<<endl;
     int id=(rem-1)/tw;
     cout<<s[id]<<endl;
     return 0;
}