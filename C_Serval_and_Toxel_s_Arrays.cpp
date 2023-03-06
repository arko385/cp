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
ll nCr(ll n,ll r,ll m)
{
    if(n<r)
    return 0;
    if(r==0)
    return 1;
    vector<ll>fact(n+1,0);
    fact[0]=1;
    for(ll i=1;i<=n;i++)
    fact[i]=(fact[i-1]*i)%m;
    return ((((fact[n]%m)*inverse(fact[r],m))%m)*inverse(fact[n-r],m))%m;
}


void solve()
{
    ll n,m,x,y,ans=0,prev=0;
    cin>>n>>m;
    vector<ll>a(1+m);
    map<ll,ll>m1;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        m1[x]++;
    }
    a[0]=m1.size();
    for(ll i=1;i<=m;i++)
    {
        cin>>x>>y;
        m1[y]++;
        a[i]=m1.size();
      cout<<a[i]<<" size"<<endl;
    }
    ans=n*(m*(m+1)/2);
    for(ll i=1;i<=m;i++)
    {
       
       prev=(abs(a[i]-a[i-1])*(i))+prev;
       ans+=prev;
    }
    ll sum=0;
    for(ll i=0;i<m;i++)
    {
        for(ll j=i+1;j<=m;j++)
        {
            sum+=a[j]-a[i];
        }
    }
    cout<<"sum : "<<sum<<endl;
    cout<<ans<<endl;
    
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