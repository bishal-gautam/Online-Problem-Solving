/// *********************************************** K
/// B *                                           * H
/// I *    Solved By : Bir Bahadur Khatri(B'ru)   * A
/// R *      Be Positive,be Happy.                * T
/// U *                                           * R
/// *********************************************** I

#include<bits/stdc++.h>

#define LL long long int
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define D double
#define sz size()
#define PB push_back
#define cp printf("***** here here here here *****\n");
#define NL printf("\n")
#define CHR getchar()
#define SQR(n) (n*n)
#define xx first
#define yy second
#define MEM(a,val) memset(a,val,sizeof(a))
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define S1(a) a=in<int>()
#define S2(a,b) a=in<int>(),b=in<int>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define SL1(a) a=in<LL>()
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define all(a) a.begin(),a.end()
#define BitCnt(a) __builtin_popcountll(a)
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#include <time.h>

using namespace std;
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T Dist(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T ABS(T a) {if(a<0)return -a;else return a;}
template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
int Set(int N,int pos){ return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Chkbit(int N,int pos){return (bool)(N & (1<<pos));}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
long long int toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}

///**********************************************************//


///         0123456789
#define MX  1000007
#define MOD 1000000007
#define INF 100000000
/// ==========================================////

int n,m,a[MX];
vector<int> A[MX];
vector<int> B[MX];

int ans[MX];
struct z
{
    LL cnt,vl;
};
z Tree[MX*4];

void Update(int id,int l,int r,int pos,int v)
{
    if(l==r) {
        Tree[id].vl+=v;
        if(Tree[id].vl) Tree[id].cnt=1;
        else Tree[id].cnt=0;
        return;
    }

    int mid=(l+r)/2;
    int lft=2*id;
    int rgt=lft+1;

    if(pos<=mid)        Update(lft,l,mid,pos,v);
    else                Update(rgt,mid+1,r,pos,v);
    Tree[id].vl=Tree[lft].vl+Tree[rgt].vl;
    Tree[id].cnt=Tree[lft].cnt+Tree[rgt].cnt;
    return;
}
LL q;
int Query(int id,int l,int r,LL v)
{
    //cout<<id<< " "<<l<< " "<<r<< " "<<v<<endl;
    if(l==r) {
        if(Tree[id].vl-q>=v) return l;
        return 0;
    }

    int mid=(l+r)/2;
    int lft=2*id;
    int rgt=lft+1;

    LL lfval=Tree[lft].vl-(Tree[lft].cnt*q);
    //cout<<Tree[lft].vl<< " : "<<Tree[lft].cnt<<endl;
    if(lfval>=v) {
        return Query(lft,l,mid,v);
    }
    else return Query(rgt,mid+1,r,v-lfval);
}

int main()
{

    S2(n,m);

    for(int i=1;i<=m;i++) S1(a[i]),A[ a[i] ].PB(i),Update(1,1,m,i,a[i]);
    for(int i=1;i<=n;i++) {
        int v,k;
        S2(v,k);
        B[v].PB(k),B[v].PB(i);
    }

    for(int i=0;i<=1000000;i++) {
        for(int j=0;j<A[i].sz;j++) {
            int tp=A[i][j];
            Update(1,1,m,tp,-a[tp]);
        }
        for(int j=0;j<B[i].sz;j+=2) {
            int id=B[i][j+1],tp=B[i][j];
            //cp;
            q=i;
            int kk=Query(1,1,m,tp);
            //cout<<i<< " "<<id<< " "<<tp<< " : "<<kk<<endl;
            ans[id]=kk;
        }
    }

    for(int i=1;i<=n;i++) {
        printf("%d ",ans[i]);
    }
    NL;

    return 0;
}

///============= Thank You ===================///