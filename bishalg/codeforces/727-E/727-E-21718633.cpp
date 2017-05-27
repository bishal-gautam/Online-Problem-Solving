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
#define MX     2000002
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///


char s[MX+5],str[MX+2];
vector<int>v;
map<pll,int>Mp;
int ar[MX+2];
ll Hs[2][MX+2],bp[2][MX+2];
ll bs[2]= {31,37},mdd[2]= {1500450271,1000000103};

void PrePow( ) {
    bp[0][0]=bp[1][0]=1LL;
    for(int i=1; i<=MX; i++) {
        bp[0][i]=(bp[0][i-1]*bs[0])%mdd[0];
        bp[1][i]=(bp[1][i-1]*bs[1])%mdd[1];
    }
}

pll HashIt(char *s,int n) {
    pll ret=mpp(0LL,0LL);
    for(int i=1; i<=n; i++) {
        ret.X=(ret.X*bs[0]+(s[i-1]-'a'+1))%mdd[0];
        ret.Y=(ret.Y*bs[1]+(s[i-1]-'a'+1))%mdd[1];
    }
    return ret;
}

void PreHs(char *s,int n) {
    Hs[0][0] = 0LL;
    Hs[1][0] = 0LL;
    for(int i = 1; i <= n; i++) {
        Hs[0][i]=((Hs[0][i-1]*bs[0])+(s[i-1]-'a' +1))%mdd[0];
        Hs[1][i]=((Hs[1][i-1]*bs[1])+(s[i-1]-'a' +1))%mdd[1];
    }
}

pll GetHash(int l, int r) {
    ll x=((Hs[0][r+1]-(Hs[0][l]*bp[0][r-l+1]))%mdd[0]+mdd[0])%mdd[0];
    ll y=((Hs[1][r+1]-(Hs[1][l]*bp[1][r-l+1]))%mdd[1]+mdd[1])%mdd[1];
    return mpp( x,y );
}

map< pii,int >vis;
int Cnt[MX+2];
//set< int >G[100005];

int main() {
    int n,m,i,j,k,q;
    PrePow( );
    S2(n,k);
    m=n*k;
    scanf("%s",s);
    strcpy(str,s);
    strcat(str,s);
    m+=m;
    PreHs(str,m);
    // cout<<str<< " : "<<m<<endl;
    S(q);
    for(i=1; i<=q; i++) {
        scanf("%s",s);
        Mp[ HashIt(s,k) ]=i;
    }
    for(i=0; i<m; i++) {
        int id=Mp[ GetHash(i,i+k-1) ];
        ar[i]=id;
        //cout<<i<< " => "<<ar[i]<<endl;
    }
    int hf=m/2;
    int ok=0,id;
    for(i=0; i<m; i++) {
        if( ar[i]==0 )continue;
        if( i-hf>=0 ) {
            if( ar[i-hf]!=0 ) {
                pii p=mpp( (i-hf)%k,ar[i-hf] );
                vis[ p ]--;
                if( vis[ p ]==0 ) {
                    Cnt[ i%k ]--;
                }
            }
        }
        pii p=mpp( i%k,ar[i] );
        if( vis[ p ]==0 ) {
            Cnt[ i%k ]++;
        }
        vis[ p ]++;
        if( Cnt[(i%k)]==n ) {
            ok=1;
            id=(i%k);
            int N=n;
            j=i;
            while( N-- ) {
                v.pb( ar[j] );
                j-=k;
            }
            break;
        }
    }
    if(!ok) printf("NO\n");
    else {
        printf("YES\n");
        for(i=n-1; i>=0; i--) {
            printf("%d ",v[i]);
        }
        nl;
    }

    return 0;
}