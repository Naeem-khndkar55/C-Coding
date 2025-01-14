#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    // with list we can push and pop from both front side and back side;
    list<ll> li;
    li.push_front(1); // insert value from the front
    li.push_front(2);
    li.push_back(3);
    li.push_back(4); // insert value from the back

    for (auto i : li)
    {
        cout << i << " ";
    }
    cout << endl;
    li.pop_front(); // delete value from the front;
    li.pop_back();  // delete value from the back;
    for (auto i : li)
    {
        cout << i << " ";
    }
    li.back();        // to check the last value;
    li.front();       // to check the 1st value;
    ll p = li.size(); // to check the size;
    // its work like vector but its benifit is it can push and pop from the front and back both side;
    li.empty(); // remove all the element from list;
}
