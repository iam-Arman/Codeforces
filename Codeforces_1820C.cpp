                                          //   Bismillahir Rahmanir Rahim      //
                                         //      SHAHRIAR MAHMUD ARMAN        //
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

# define optimise   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cin.clear(); 
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

 
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}
 
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}
 
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
 
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
 
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}
 
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
 
void faltu () {
            cerr << endl;
}
 
template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}
 
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}


//--------------------------------------------------------------------------------------------------------------------------------------|




                                                    /////    FUNCTIONS     /////



ll bigmod(ll base,ll power)
{
  ll res=1;
  ll p=base%mod;
  while(power>0)
  {
    if(power%2==1)
    {
      res=((res%mod)*(p%mod))%mod;
      //res*=p;
    }
    power/=2;
    p=((p%mod)*(p%mod))%mod;
  }
  return res;
}


long long LOG(long long base, long long n)
{  
  long long cnt=0;
while(n>0)
{
 n=n/base;
 cnt++;
}
return (cnt-1);
}


ll poww(ll a,ll b)
{
  ll ans=1;
  if(!b) return 1;
  while(b>1)
  {
    if(b&1)
    {
      ans=ans*a%mod;
    }
    a=a*a%mod;
    b/=2;
  }
  return a*ans%mod;
}

int gcd(ll a,ll b)
{
  ll rem;
  while(b%a!=0)
  {
    rem=b%a;
    b=a;
    a=rem;
  }
  return a;
}


int GCD(ll a,ll b)
{
  if(a==b) return a;
  else if(b==0) return a;
  else return GCD(b,a%b);
}

bool sort_by_sec(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first==b.first)
    { 
      if(a.second>b.second) return true;
      else return false;
    }
    return true;
}



                                                    ///  CODE STARTS FROM HERE    ///


bool is_mountain(vector<int> &vec)
{
   bool ok=false;
   for(int i=0;i<vec.size()-1;i++)
   {
    if(!ok)
    {
      if(vec[i]>vec[i+1]) 
     {
        ok=true;
      }
    }
    if(ok)
    {
       if(vec[i]<vec[i+1])
       {
        return false;
       }
    }
   }
   return true;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> vec(n);
   set<int> st;
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        st.insert(vec[i]);
        mp[vec[i]]++;
    }

    if(n==1)
    {
      if(vec[0]==0) cout<<"NO"<<el;
      else cout<<"YES"<<el;
        return;
    }



    int mex=0;
    bool ok=true;

    for(int i=0;i<n;i++)
    {
       if(st.count(i)==0)
       {
            mex=i;
            ok=false;
            break;
       }
    }

    if(ok) 
    {
        cout<<"NO"<<endl;
        return;
    }


    if(n==2)
    {
        cout<<"YES"<<el;
        return;
    }

    if(mp[mex+1]==0 or mp[mex+1]==1)
    {
        cout<<"YES"<<endl;
        return;
    }

    priority_queue<pair<int,int> > pq;

    for(int i=0;i<n;i++)
    {
        if(vec[i]==mex+1)
        {
            pq.push({vec[i],i});
        }
    }

    int last=pq.top().second;
    pq.pop();
    int first=0;

    while(!pq.empty())
    {
        first=pq.top().second;
        pq.pop();
    }
        

    for(int i=first;i<=last;i++)
    {
        mp[vec[i]]--;;
    }
    

     ok=true;

    for(int i=0;i<mex;i++)
    {
        if(mp[i]==0)
        {
            ok=false;
            break;
        }
    }

    if(ok) cout<<"YES"<<el;
    else cout<<"NO"<<el;







    




  
}
int main()
{
    optimise;
    file();
   test{

    solve();

 }


    

}


// problem link: https://codeforces.com/contest/1820/problem/C