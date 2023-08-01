                                          //   Bismillahir Rahmanir Rahim      //
                                         //     After hardship comes ease     //
                                        //         AUTHOR : iamarman         //


#include<bits/stdc++.h>
using namespace std;

                                             ////       TEMPLATE       ////

//---------------------------------------------------------------------------------------------------------------------------------|

typedef vector<int> vii;
typedef vector<long long> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long,long long > > vpl;

# define ll long long
# define ull unsigned long long                                                                                                           
# define test int test; cin>>test; while(test--)
# define rep(i,a,b) for(int i=a;i<b;i++)
# define rep_n(i,a,b) for(int i=a;i<=b;i++)
# define rep_rev(i,a,b) for(int i=b;a>=1;i--)
# define pb push_back
# define el '\n'
# define R0 return 0
# define all(v) v.begin(),v.end()
# define srt(vvv) sort(vvv.begin(),vvv.end())
# define sp " "
# define vii vector<int>
# define vll vector<long long>
# define yess cout<<"YES"<<el
# define noo cout<<"NO"<<el
# define ff first
# define ss second
# define mp make_pair
# define sz(x) (int)x.size()

ll mod=1000000000+7;
const double PI= acos(-1);
const double eps=1e-9;

# define mem(a,b) memset(a,b,sizeof(a))
# define sqr(a) ((a)*(a))
# define lcm(a,b) (a*b)/__gcd(a,b)

# define optimise   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
# define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);

typedef vector<int>::iterator vit;
typedef vector<ll>::iterator vlt;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;


inline void file() {
 
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE

}

//----------------------------------------------------------------------------------------------------------------------------------|



                                                   // DEBUGGER //


//-----------------------------------------------------------------------------------------------------------------------------------|

template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")"; }
 
template < typename T > ostream &operator << ( ostream & os, const vector< T > &v ) { os << "{"; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", ";  os << *it; }  return os << "}";  }
 
template < typename T >  ostream &operator << ( ostream & os, const set< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it;  } return os << "]"; }
 
template < typename T > ostream &operator << ( ostream & os, const multiset< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; } return os << "]"; }
 
template < typename F, typename S > ostream &operator << ( ostream & os, const map< F, S > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; } return os << "]";  }
 
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
 
void faltu () { cerr << endl; }
 
template <typename T> void faltu( T a[], int n ) {   for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;  }
 
template <typename T, typename ... hello>  void faltu( T arg, const hello &... rest) {   cerr << arg << ' ';  faltu(rest...);  }

//--------------------------------------------------------------------------------------------------------------------------------------|




                                                    /////    FUNCTIONS     /////



// ll bigmod(ll base,ll power){ ll res=1; ll p=base%mod; while(power>0) { if(power%2==1) {  res=((res%mod)*(p%mod))%mod; }  power/=2; p=((p%mod)*(p%mod))%mod; } return res; }

// ll poww(ll a,ll b) { ll ans=1; if(!b) return 1; while(b>1) {  if(b&1) { ans=ans*a%mod; } a=a*a%mod; b/=2; }return a*ans%mod; }

// int gcd(ll a,ll b) { ll rem; while(b%a!=0)  {  rem=b%a;  b=a;  a=rem; } return a; }


int dx[]={-1, 1 , 0 , 0 , -1 ,-1, 1, 1};
int dy[]={ 0, 0 ,-1 , 1 , -1 , 1,-1, 1};


                                                    ///  CODE STARTS FROM HERE    ///

void solve()
{
   int n,m;
   cin>>n>>m;

   char arr[n+2][m+2];
   int cnt=0;
   bool has0=false;

   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         cin>>arr[i][j];
         if(arr[i][j]=='1') cnt++;
         if(arr[i][j]=='0') has0=true;
      }
   }

   bool ok=false;
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)
     {
        if(arr[i][j]=='0')
        {
           for(int k=0;k<4;k++)
           {
             int ni=i+dx[k];
              int nj=j+dy[k];
              if(ni>=1 and ni<=n and nj>=1 and nj<=m and arr[ni][nj]=='0')
              {
                 ok=true;
                 break;
              }
           }
        }
        int c=0;
        if(arr[i][j]=='1')
        {
          for(int k=0;k<4;k++)
          {
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=1 and ni<=n and nj>=1 and nj<=m and arr[ni][nj]=='0')
            {
              c++;
            }
          }
          int a1=i-1,b1=j;
          int a2=i+1,b2=j;
          if(a1>=1 and a1<=n and b1>=1 and b1<=m and arr[a1][b1]=='0' and arr[a2][b2]=='0')
          {
            c--;
          }
          a1=i,b1=j-1;
          a2=i,b2=j+1;
          if(a1>=1 and a1<=n and b1>=1 and b1<=m and arr[a1][b1]=='0' and arr[a2][b2]=='0')
          {
            c--;
          }
          if(c>=2)
            {
              ok=true;
              break;
            }
        }
        if(ok) break;
     }
      if(ok) break;
   }

   if(ok)
   {
     cout<<cnt<<el;
     return;
   }
   if(has0)
   {
      cout<<cnt-1<<el;
   }
   else
   {
    cout<<cnt-2<<el;
   }


}


int main()
{
    optimise;
    file();
    test
    {
      solve();
    }
  
}
