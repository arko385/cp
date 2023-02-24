#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define nl "\n"
#define py cout << "YES" << nl;
#define pn cout << "NO" << nl;
#define PI 3.141592653589793238
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ff first
#define ss second
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll MOD = 1e9 + 7;
ll MOD1 = 998244353;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << x << nl;
#else
#define debug(x)
#endif
void printarr(vector<ll> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << nl;
}
ll power(ll n, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    if (p % 2 == 0)
    {
        ll smallans = power(n, p / 2);
        return (smallans * smallans);
    }
    else
    {
        ll smallans = power(n, p / 2);
        return ((smallans * smallans) * n);
    }
}
// (a^b)%m here m=modulo
//(a#b)%m=((a%m)#(b%m))%m  #-> (+ or *)
// (a-b)%m=((a%m)-(b%m)+m)%m
//(a/b)%m=((a%m)*(inverse(b,m)))%m

/*
    // 1 2 4 5 5 5 7 8 25
   // lower_bound(5)= index 3 if the ele present then first occurance
   // lower_bound(6)= index 6 if not present then the value greater than that present on the array
   // upper_bound(5)= index 6 the value which is greater than the element present on the array
   // upper_bound(6)=index 6
  //  it1=lower_bound(v.begin(),v.end(),7);
   // it2=upper_bound(v.begin(),v.end(),7);
   // cout<<(it1-v.begin())<<endl;
   // cout<<(it2-v.begin())<<endl;
*/

ll powermod(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}

// (1/a)%m
ll inverse(ll a, ll MOD)
{
    return powermod(a, MOD - 2, MOD);
}

ll GCD(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    return GCD(b % a, a);
}
// calculate how many set bit in n
int cal_setbit(int n)
{
    int c = 0, x;
    while (n > 0)
    {
        x = n & (-n); // This calculate the  right most set bit
        c++;
        n = n - x;
    }
    return c;
}


void solve()
{
    ll n,ans,x,l,val;
    cin>>n;
    vector<ll>a(n),b(n),pref(n,0),freq(n+1,0),rem(n+1,0);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];   
    }
      for(ll i=0;i<n;i++)
    {
        cin>>b[i];
        if(i==0)
        pref[i]=b[i];
        else
         pref[i]=b[i]+pref[i-1];
    }
    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
          val=a[i];
         
        }
        else
        {
        val=a[i]+pref[i-1];
        }
        l=upper_bound(pref.begin(),pref.end(),val)-pref.begin();
      
       
        if(l==0)
        {
        rem[l]+=val;
        }
        else
        {
         freq[l-1]++;
         rem[l]+=val-pref[l-1];
        }
      
        
        //cout<<" try "<<i+1<<" "<<l<<endl;
        
    }
  
    for(ll i=n-1;i>=0;i--)
    {
        freq[i]+=freq[i+1];
    }

    for(ll i=0;i<n;i++)
    {
        x=freq[i]-n+(i+1);
        //cout<<" v "<<x<<" "<<b[i]<<endl;
        ans=(x*b[i])+rem[i];
        cout<<ans<<" ";
    }
    cout<<endl;
   

}
int main()
{
    fastio();
    cout << setprecision(12) << fixed;

    int t;
    cin>>t;
    while(t--)
    {

    solve();
    }
}