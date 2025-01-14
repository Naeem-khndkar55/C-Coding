#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    // multple vector diclaretion;
    vector<ll> v1(n);                // a n size vactor;
    vector<ll> v2;                   // dynamic vector without size;
    vector<ll> v3(n, 0);             // vector  of n size initialized with 0;
    vector<ll> v4 = {1, 2, 3, 4, 5}; // direct vector;
    vector<ll> v5(v4);               // copy vector;
    vector<vector<ll>> v6;           // 2D vector;

    // vector operation
    for (ll i = 0; i < n; i++)
    {
        cin >> v1[i]; // vector size must be fixed
        ll x = v1[i];
        v2.push_back(x);    // for dynamic vector;
        v3.emplace_back(x); // like push__back functionality
    }
    for (auto v : v1)
    {
        cout << v << " "; // traverse and print vector
    }
    int sz = v2.size();             // calculatin of size of element;
    int cpcity = v2.capacity();     // calculate the size of capacity if a vector;
    v2.pop_back();                  // delete a element from the back of the array;
    cout << v2.at(3) << " ";        // print the specifc positions element;
    cout << v1.front() << " ";      // see the first element of the vector;
    cout << v1.back() << " ";       // see the last element of the vector;
    v3.erase(v3.begin() + 2);       // erase element of index 2;
    v3.erase(v3.begin(), v3.end()); // erage element of a particular range here it will erase all;
    v2.insert(v2.begin() + 1, 15);  // insert a value in a particular position;
    v4.clear();                     // remove all the element from the vector size will be 0;
    v2.empty();                     // check is any element exist or not in a vector, return ture 0r false;
}
