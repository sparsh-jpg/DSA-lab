#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    vector<int> pos;
    vector<int> neg;

    for (int value : arr) {
        if (value >= 0) {
            pos.push_back(value);
        } else {
            neg.push_back(value);
        }
    }

    int diff = abs(static_cast<int>(pos.size()) - static_cast<int>(neg.size()));
    if (diff > 1) {
        cout << "Not Possible" << endl;
        return 0;
    }

    vector<int> ans(size);
    int j = 0;

    if (pos.size() > neg.size()) {
        ans[j++] = pos[0];
        for (int i = 0; i < neg.size(); ++i) {
            ans[j++] = neg[i];
            ans[j++] = pos[i + 1];
        }
    } else if (neg.size() > pos.size()) {
        ans[j++] = neg[0];
        for (int i = 0; i < pos.size(); ++i) {
            ans[j++] = pos[i];
            if (i + 1 < neg.size()) {
                ans[j++] = neg[i + 1];
            }
        }
    } else {
        for (int i = 0; i < pos.size(); ++i) {
            ans[j++] = neg[i];
            ans[j++] = pos[i];
        }
    }

    for (int value : ans) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}