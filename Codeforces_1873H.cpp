                                                  //   Bismillahir Rahmanir Rahim      //
                                                 //     After hardship comes ease     //
                                                //         AUTHOR : iamarman         //

// pragmas
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimization ("strict-overflow")
 
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;

                                                    ////       TEMPLATE       ////

//---------------------------------------------------------------------------------------------------------------------------------|

typedef     vector<int> vii;
typedef     vector<long long> vll;
typedef     vector<pair<int,int> > vpi;
typedef     vector<pair<long long,long long > > vpl;

# define    el '\n'
# define    ff first
# define    ss second
# define    R0 return 0
# define    ll long long
# define    noo1 cout<<-1<<el;  
# define    ull unsigned long long                                                                                                         
# define    rep(i,a,b) for(int i=a;i<b;i++)
# define    rep_n(i,a,b) for(int i=a;i<=b;i++)
# define    test int test; cin>>test; while(test--)
# define    rep_rev(i,a,b) for(int i=b;a>=1;i--)
# define    allr(v) v.rbegin(),v.rend()
# define    all(v) v.begin(),v.end()
# define    yess cout<<"YES"<<el
# define    siz(x) (int)x.size()
# define    noo cout<<"NO"<<el
# define     yess1 cout<<1<<el
# define    pb push_back
# define    mp make_pair
# define    sp " "


constexpr ll mod=1000000000+7;
constexpr ll INF=LLONG_MAX;
constexpr double PI= acos(-1);
constexpr double eps=1e-9;

# define mem(a,b) memset(a,b,sizeof(a))
# define sqr(a) ((a)*(a))
# define lcm(a,b) (a*b)/__gcd(a,b)

# define optimise   { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
# define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
# define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

// find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
// order_of_key()  - The number of items in a set that are strictly smaller than our item 
// greater instead of less for descending order
// less_equal works as ordered multiset
// we can use pair<int,int> instead of int for pair of orderd set
// for multiset st.lower_bound(x) works as upper bound and st.upper_bound(x) works as lower bound

inline void file() {
#ifndef ONLINE_JUDGE  
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

//----------------------------------------------------------------------------------------------------------------------------------|



                                                               // DEBUGGER //


//----------------------------------------------------------------------------------------------------------------------------------|

template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")"; }
template < typename T > ostream &operator << ( ostream & os, const vector< T > &v ) { os << "{"; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", ";  os << *it; }  return os << "}";  }
template < typename T >  ostream &operator << ( ostream & os, const set< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it;  } return os << "]"; }
template < typename T > ostream &operator << ( ostream & os, const multiset< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; } return os << "]"; }
template < typename F, typename S > ostream &operator << ( ostream & os, const map< F, S > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; } return os << "]";  }
#define dbg(args...) do {cerr << #args << " : "; iamarman(args); } while(0)
void iamarman () { cerr << endl; }
template <typename T> void iamarman( T a[], int n ) {   for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;  }
template <typename T, typename ... hello>  void iamarman( T arg, const hello &... rest) {   cerr << arg << ' ';  iamarman(rest...);  }

//--------------------------------------------------------------------------------------------------------------------------------------|



                                                           /////    FUNCTIONS     /////



ll bigmod(ll base,ll power){ ll res=1; ll p=base%mod; while(power>0) { if(power%2==1) {  res=((res%mod)*(p%mod))%mod; }  power/=2; p=((p%mod)*(p%mod))%mod; } return res; }

ll inversemod(ll base) { return bigmod(base,mod-2); }

ll poww(ull a,ull b) { ull ans=1; if(!b) return 1; while(b>1) {  if(b&1) { ans=ans*a%mod; } a=a*a%mod; b/=2; }return a*ans%mod; }

int gcd(ll a,ll b) { ll rem; while(b%a!=0)  {  rem=b%a;  b=a;  a=rem; } return a; }


int dx[]={-1, 1 , 0 , 0 , -1 ,-1, 1, 1};
int dy[]={ 0, 0 ,-1 , 1 , -1 , 1,-1, 1};

// up = { -1,0 } , down = { 1,0 } , right = { 0,1 } , left = { 0,-1 }
// up-right = { -1,1 } , up-left = { -1,-1 } , down-right = { 1,1 } , down-left = { 1,-1 }




                                                   ///  ____________CODE STARTS FROM HERE____________    ///


int start_of_cycle=-1;

bool hascycle(int node,int par,vector<int> &vis,vector<int> graph[])
{
    vis[node]=1;
    for(auto child : graph[node])
    {
        if(!vis[child]){
        if(hascycle(child,node,vis,graph))
        {
            return true;
        }
        }
        else if(vis[child] and child!=par)
        {
            start_of_cycle=child;
            return true;
        }
    }

    return false;
}

void bfs(int node,vector<int>&level,vector<int> graph[])
{
    int n=siz(level);
    vector<int> vis(n+1,0);
    queue<int> q;
    q.push(node);
    vis[node]=1;
    level[node]=0;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto child : graph[node])
        {
            if(!vis[child])
            {
                vis[child]=1;
                level[child]=level[node]+1;
                q.push(child);
            }
        }
    }
}

void solve()
{

    int n,a,b;
    cin>>n>>a>>b;

    vector<int> graph[n+1];

    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    if(a==b)
    {
        cout<<"NO"<<el;
        start_of_cycle=-1;
        return;
    }

    vector<int> vis(n+1,0);
   
    hascycle(b,-1,vis,graph);

    vector<int> level(n+1,-1);

    bfs(b,level,graph);

    int  Valeriu=level[start_of_cycle];

    level.assign(n+1,-1);

    bfs(a,level,graph);

    int Marcel=level[start_of_cycle];


    if(Valeriu<Marcel)
    {
        cout<<"YES"<<el;
    }
    else cout<<"NO"<<el;




    
}
int main()
{
    optimise;
    file();

   // clock_t q= clock();

    test
    {
        solve();
    }
 //   cerr << "Run Time : " <<((double)(clock() - q) / CLOCKS_PER_SEC)<<el;
  
}