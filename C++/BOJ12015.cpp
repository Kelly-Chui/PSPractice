//
//  main.cpp
//  CPPAlgorithm
//
//  Created by KellyChui on 2023/02/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int n, int t, vector<int> * dpTable) {
    int low = 0, high = n, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if ((*dpTable)[mid] < t) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(void) {
    int n, ai, bsidx;
    vector<int> a, order, dpTable;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        a.push_back(ai);
    }
    dpTable = vector<int>(n + 1, 1000001);
    dpTable[0] = 0;
    
    for (int i = 0; i <= n; i++) {
        bsidx = binarySearch(n, a[i], &dpTable);
        if (dpTable[bsidx] > a[i]) {
            dpTable[bsidx] = a[i];
        }
        order.push_back(bsidx);
    }

    cout << *max_element(order.begin(), order.end()) << endl;
    return 0;
}
