#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n';


inline void file() {
 
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE

}

void solve()
{
    
   int a,b;
   cin>>a>>b;
   string s;
   cin>>s;

   int l=0;
   int r=a+b-1;

   bool ok=true;

   while(l<r)
   {
     if(s[l]=='?' or s[r]=='?')
     {
        
     }
     else if(s[l]!=s[r])
     {
        ok=false;
        break;
     }
     l++;
     r--;
   }

   if(!ok)
   {
    cout<<-1<<el;
    return;
   }

   for(int i=0;i<=(a+b-1)/2;i++)
   {
     if(s[i]=='?' or s[a+b-i-1]=='?')
     {
        if(s[i]=='?' and s[a+b-i-1]=='?') continue;
        if(s[i]=='?') s[i]=s[a+b-i-1];
        else s[a+b-i-1]=s[i];
     }
   }

   int cnta=count(s.begin(),s.end(),'0');
   int cntb=count(s.begin(),s.end(),'1');

   cnta=a-cnta;
   cntb=b-cntb;

   if(cnta<0 or cntb<0 )
   {
    cout<<-1<<el;
    return;
   }
   
   int take=0;
   if(cnta%2==0 and cnta>0) take=1;
   else if(cntb%2==0 and cntb>0) take=0;
   else take=-1;

   for(int i=0;i<(a+b-1)/2;i++)
   {
     if(s[i]=='?' and s[a+b-i-1]=='?') 
     {
        if(take==1)
        {
            s[i]='0';
            s[a+b-i-1]='0';
            cnta-=2;
            if(cnta<=0) 
            {
                break;
            }
        }
        else if(take==0)
        {
            s[i]='1';
            s[a+b-i-1]='1';
            cntb-=2;
            if(cntb<=0) 
            {
                 break;
            }
        }
       
     }
   }

     if(cnta!=0 and cntb!=0)
     {
        cout<<-1<<el;
        return;
     }

     if(cnta==0) take=1;
     else if(cntb==0) take=0;
     else take=-1;

     for(int i=0;i<a+b;i++)
     {
        if(s[i]=='?')
        {
            if(take==1) s[i]='1';
            else if(take==0) s[i]='0';
        }
     }
    

   cnta=count(s.begin(),s.end(),'0');
   cntb=count(s.begin(),s.end(),'1');
   if(a==cnta and b==cntb)
   {
    cout<<s<<el;
   }
   else cout<<-1<<el;


   
   

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cin.clear(); 

    file();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

// problem link : https://codeforces.com/contest/1512/problem/C
