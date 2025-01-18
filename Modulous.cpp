#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M = 100000000 + 7;
int power(ll a, ll p, ll m) // binary exponentiation
{
    ll res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            res = (res * a) % m;
            p--;
        }
        else
        {
            a = (a * a) % m;
            p = p / 2;
        }
    }
    return res % m;
}
int main()
{
    ll a;
    ll b;
    cin >> a >> b;
    ll m = 100000000 + 7;
    //(a+b)%m= ((a%m)+(b%m))%m; -------for addition;
    //(a*b)%m= ((a%m)*(b%m))%m; -------for multiplication;
    // for (-ve) ans=(-a%m+m)%m;
    // get the mod of a big number;
    string x = "1111222121345353546453143567567";
    ll ans = 0;
    for (ll i = 0; i < x.size(); i++)
    {
        ans = ans * 10 + (x[i] - '0'); // converting char into intiger;
        ans = ans % m;
    }
    cout << ans % m << endl;
    // inverse modulo;
    //(a/b)%m=(a*1/b)%m=(a*b^-1)%m=(a*X)%m-----whwere X==b^-1==1/b;
    // using farmats little theorem {  x^(m-1)%m=1}
    // so b^-1 =b^(m-2);
    // so (b^-1)%m==(b^(m-2))%m;

    // the final theorem for invrse modulo is ------(a/b)%m===(a*b^(m-2))%m-------==multiplication modulo theorem;
    // code
    ll c = power(b, m - 2, m); // c should compute with binary exponentiation
    ll div = ((a % m) * (c % m)) % m;
    cout << div << endl;
}
