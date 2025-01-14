// here all kind of stl function in stack queue and pair;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // pair
    //  its to pair up two or multiple element like int,string,vector etc;
    ll n;
    cin >> n;
    pair<ll, string> p;
    vector<pair<ll, string>> v;
    for (ll i = 0; i < n; i++)
    { // get input of pair and push it into vector;
        ll a;
        string b;
        cin >> a >> b;
        p.first = a;
        p.second = b;
        v.push_back(p);
    }
    for (auto i : v)
    { // output system
        ll x = i.first;
        string y = i.second;
        cout << x << " " << y << endl;
    }
    // now de-queue
    //  its called double ended queue;
    //  its a dynamic array ,it give the posibolity for random access
    deque<ll> d1;                       // Creates an empty deque.
    deque<ll> d2(n, 10);                // Creates a deque with n elements, each initialized to value.
    deque<ll> d3(d2.begin(), d2.end()); // Creates a deque initialized with elements from the range [begin, end).
    deque<ll> d4(d2);                   // Creates a copy of another deque d2.
    // element acces;
    d1.at(2);
    d1.front();
    d1.back();
    // modification (insert+delete)
    d2.push_back(1);
    d2.push_front(2);
    d2.pop_back();
    d2.pop_front();
    d1.insert(d1.begin() + 1, 4); // 2 is the position , 4 is the vlaue;
    d2.erase(d1.begin());         // erase any element in a particular position;
    d3.clear();                   // delete all the de-que;
    // capacity
    int sz = d2.size();
    d2.empty();                 // it returens true or false
                                // range
    sort(d3.begin(), d3.end()); // sorting the que
}