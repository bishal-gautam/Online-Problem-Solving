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
#define MX     300005
#define inf    2000000010
#define eps    1e-9
///===============================///

struct data {
    int nx[26];
    data() {
        CLR(nx);
    };
} T[4*MX+2];

ll Ed[4*MX+2];
int nw=0,SQ=500;
ll bs=31LL,MD=1331133113LL;
char s[MX+2];
set< pair<ll,int> >St;
ll bp[MX+2],Hs[MX + 5];

void Ins(char *s,int n,int v) {
    int p=0;
    for(int i=0; i<n; i++) {
        int k=s[i]-'a';
        if( T[p].nx[k]==0 ) {
            T[p].nx[k]=(++nw);
            T[ nw ]=data();
        }
        p=T[ p ].nx[ k ];
    }
    Ed[ p ]=v;
}

ll Srch(int i,int n) {
    int p=0;
    ll ret=0;
    for(i; i<n; i++) {
        int k=s[i]-'a';
        if( T[p].nx[k]==0 )break;
        p=T[p].nx[ k ];
        ret+=Ed[p];
    }
    return ret;
}

void BasePow( ) {
    bp[0]=1;
    for(int i=1; i<=MX; i++) {
        bp[i]=(bp[i-1]*bs)%MD;
    }
}

int HashIt(char *s,int n) {
    ll ret=0;
    for(int i=1; i<=n; i++) {
        ret=(ret*bs+(s[i-1]-'a'+1))%MD;
    }
    return ret;
}

void PreHs(char *s,int n) {
    Hs[0] = 0LL;
    for(int i = 1; i <= n; i++) {
        Hs[i]=((Hs[i-1]*bs)+(s[i-1]-'a' +1))%MD;
    }
}

ll GetHash(int l, int r) {
    return ((Hs[r+1]-(Hs[l]*bp[r-l+1]))%MD+MD)%MD;
}

int main() {
    int q,i,j,k,op,ln;
    BasePow( );
    T[0]=data();
    S(q);
    while(q--) {
        S(op);
        scanf("%s",s);
        ln=strlen(s);
        if( op==1 ) {
            ///Add;
            if( ln>=SQ ) {
                ll h=HashIt(s,ln);
                St.insert( mpp(h,ln) );
            } else {
                Ins(s,ln,+1);
            }

        } else if( op==2 ) {
            ///Remove;
            if( ln>=SQ ) {
                ll h=HashIt(s,ln);
                /// There will always be inserted String
                St.erase( mpp(h,ln) );
            } else {
                Ins(s,ln,0);
            }

        } else {
            ll cnt=0;
            if( ln>=SQ ) {
                PreHs(s,ln);
                for(set< pair<ll,int> >:: iterator it=St.begin(); it!=St.end(); it++) {
                    ll h=(*it).X;
                    int len=(*it).Y;
                    for( i=0; i<ln; i++ ) {
                        int nx=i+len-1;
                        if( nx>=ln )break;
                        ll gh=GetHash(i,nx);
                        if( gh==h )cnt++;
                    }
                }
            }
            for(i=0; i<ln; i++) {
                cnt+=(1LL*Srch(i,ln));
            }
            printf("%lld\n",cnt);
            fflush(stdout);
        }
    }
    return 0;
}