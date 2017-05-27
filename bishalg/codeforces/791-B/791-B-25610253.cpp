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
#define MX     500005
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int n,m;
int par[MX+2],eg[MX+2],Sz[MX+2];

int GP(int x){
    if(x==par[x]) return x;
    return par[x]=GP( par[x] );
}

vector<int>v;
int mark[MX+2];
int main(){
    int i,j,k,x,y;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)par[i]=i,eg[i]=0,Sz[i]=1;

    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);

        int xx=GP(x);
        int yy=GP(y);
        if( xx==yy ){
            eg[ xx ]++;
        }
        else{
            par[xx]=yy;
            Sz[ yy ]=Sz[ xx ]+Sz[ yy ];
            eg[ yy ]=eg[ xx ]+eg[ yy ]+1;
        }
    }

    bool f=1;
    for(i=1;i<=n;i++){
        int rt=GP(i);
        if( rt==i ){
            ll sz=Sz[ i ];
            ll ed=eg[ i ];
            ll tot=( sz*(sz-1) )/2LL;
            if( ed!=(tot) ){
                f=0;
                break;
            }
        }
    }

    if( f ) printf("YES\n");
    else printf("NO\n");

    return 0;
}