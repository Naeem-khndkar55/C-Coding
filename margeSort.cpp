#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(vector<ll> &v, int s, int m, int e) {
    vector<ll> temp;
    int i = s;
    int j = m + 1;

    // Merging two sorted halves
    while (i <= m && j <= e) {
        if (v[i] <= v[j]) {
            temp.push_back(v[i]);
            i++;
        } else {
            temp.push_back(v[j]);
            j++;
        }
    }

    // Copy remaining elements from the left half
    while (i <= m) {
        temp.push_back(v[i]);
        i++;
    }

    // Copy remaining elements from the right half
    while (j <= e) {
        temp.push_back(v[j]);
        j++;
    }

    // Copy the merged elements back into the original array
    for (int k = 0; k < temp.size(); k++) {
        v[k + s] = temp[k];
    }
}

void mergeSort(vector<ll> &v, int s, int e) {
    if (s < e) {
        int m = s + (e - s) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

int main() {
    ll p;
    cin >> p;
    vector<ll> v(p);
    for (ll i = 0; i < p; i++) {
        cin >> v[i];
    }

    mergeSort(v, 0, p - 1);

    for (ll i = 0; i < p; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
