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
    int n,x;
    cin>>n>>x;
    vector<int> vec(n);

    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    ll sum=accumulate(all(vec),0LL);

    vector<int> a;

    bool ok=true;

    for(int i=0;i<n;i++)
    {
        if(vec[i]%x==0)
        {
            a.pb(vec[i]/x);
        }
        else 
        {
            ok=false;
            break;
        }
    }
    
    for(int i=0;i<a.size();i++)
    {
        sum+=1LL*a[i]*x;
    }

    if(ok==false)
    {
        cout<<sum<<el;
        return;
    }

    vector<int> b;
    ll c=x*x;
    while(1)
    {
         b.clear();
         if(a.size()==0) break;
         for(int i=0;i<a.size();i++)
         {
            if(a[i]%x==0)
            {
                b.pb(a[i]/x);
            }
            else 
            {
                ok=false;
                break;
            }
         }
         for(int i=0;i<b.size();i++)
         {
            sum+=1LL*b[i]*c;

         }
         c=c*x;
         a.clear();
         a=b;
         if(ok==false) break;
    }

    cout<<sum<<el;


   
}


int main()
{
    optimise;
    file();
   test{

    solve();

  }

    

}





// problem link: https://codeforces.com/problemset/problem/1471/B