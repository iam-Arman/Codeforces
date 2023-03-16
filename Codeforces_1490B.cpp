                                          //   Bismillahir Rahmanir Rahim      //
                                         //      SHAHRIAR MAHMUD ARMAN        //
                                        //         AUTHOR : iamarman         //


#include<bits/stdc++.h>

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
ll mod=10000000+7;

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
    p=(p%mod)*(p%mod);
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

int gcd(int a,int b)
{
  int rem;
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
    if(a.first>b.first) return true;
    else if(a.first==b.first)
    {
        return a.second<b.second;
    }
    else return false;
}



                                                    ///  CODE STARTS FROM HERE    ///


bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
   if(a.first<b.first) return true;
    else if(a.first==b.first)
    {
        return a.second>=b.second;
    }
    else return false;
}

bool issquare(int x)
{
    int y=sqrt(x);

    return y*y==x;
}

void solve()
{
    int n;
  cin>>n;

  vector<int> vec(n);
    map<int ,int> mp;
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
    mp[vec[i]%3]++;
  }
  int extra0=0;
  int extra1=0;
  int extra2=0;
  if(mp[0]>n/3) extra0=mp[0]-n/3;
  if(mp[1]>n/3) extra1=mp[1]-n/3;
  if(mp[2]>n/3) extra2=mp[2]-n/3;

  int ans=0;

  if(extra0)
  {
     if(mp[1]<n/3)
     {
        int x=n/3-mp[1];
        int y=min(x,extra0);
        ans+=y;
        extra0-=y;
        mp[1]+=y;
        mp[0]-=y;
     }
     if(mp[2]<n/3)
     {
        int x=n/3-mp[2];
        int y=min(x,extra0);
        ans+=2*y;
        extra0-=y;
        mp[2]+=y;
        mp[0]-=y;
     }
  }

  if(extra1)
  {
    if(mp[2]<n/3)
    {
        int x=n/3-mp[2];
        int y=min(x,extra1);
        ans+=y;
        extra1-=y;
        mp[2]+=y;
        mp[1]-=y;
    }
    if(mp[0]<n/3)
    {
        int x=n/3-mp[0];
        int y=min(x,extra1);
        ans+=2*y;
        extra1-=y;
        mp[0]+=y;
        mp[1]-=y;
    }
}
  if(extra2)
  {
    if(mp[0]<n/3)
    {
        int x=n/3-mp[0];
        int y=min(x,extra2);
        ans+=y;
        extra2-=y;
        mp[0]+=y;
        mp[2]-=y;
    }
    if(mp[1]<n/3)
    {
        int x=n/3-mp[1];
        int y=min(x,extra2);
        ans+=2*y;
        extra2-=y;
        mp[1]+=y;
        mp[2]-=y;
    }
  }
  cout<<ans<<el;
  
  
  
  
}

int main()
{
    optimise;
    file();
   test{

    solve();

  }

    

}

// problem link : https://codeforces.com/contest/1490/problem/B