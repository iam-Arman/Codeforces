                                          //   Bismillahir Rahmanir Rahim      //
                                         //      SHAHRIAR MAHMUD ARMAN        //
                                        //         AUTHOR : iamarman         //


#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<map>
                                             ////       MACROS       ////

//---------------------------------------------------------------------------------------------------------------------------------|

# define ll long long                                                                                                              
# define test int test; cin>>test; while(test--)
# define rep(i,a,b) for(int i=a;i<b;i++)
# define rep_n(i,a,b) for(int i=a;i<=b;i++)
# define rep_rev(i,a,b) for(int i=b;a>=1;i--)
# define pb push_back
# define el "\n"
# define optimise   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cin.clear(); 
# define R0 return 0
# define all(v) v.begin(),v.end()
# define srt(vvv) sort(vvv.begin(),vvv.end())
# define sp " "
# define vii vector<int>
# define vll vector<long long>
# define yess cout<<"YES"<<el
# define noo cout<<"NO"<<el
# define PI 2*acos(0.0)
ll mod=1000000000+7;

//----------------------------------------------------------------------------------------------------------------------------------|


//                                             ///      NAMESPACE     ///

using namespace std;


                     /// THIS IS FOR GIVING INPUT AND GETTING OUTPUT IN A FILE INSTEAD OF TERMINAL OR CONSOLE   ///


inline void file() {

#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}


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
  int arr[n+1];
  memset(arr,0,sizeof(arr));

  priority_queue<pair<int,int> > pq;
  pq.push({n,-1});
  int cnt=1;
  while(!pq.empty())
  {
    pair<int,int> p;
    p=pq.top();
    int l=p.second*-1;
    int len=p.first;
    int r=l+len-1;
    int mid=0;
    if(len%2)
    {
        mid=(l+r)/2;
    }
    else
    {
        mid=(l+r-1)/2;
    }
    arr[mid]=cnt;
    cnt++;
    pq.pop();
    int l1,r1,l2,r2;

    l1=l;
    r1=mid-1;
    l2=mid+1;
    r2=r;
    if(l1<=r1)
    {
        pq.push({r1-l1+1,-l1});
    }
    if(l2<=r2)
    {
        pq.push({r2-l2+1,-l2});
    }

  }

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<sp;
    }
    cout<<el;

}
int main()
{
    optimise;
    file();
   test{

    solve();

 }


    

}


