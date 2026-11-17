#include <iostream>
#include <vector>

using namespace std;

int target;
vector<int> arr;
vector<int> subset;
int arrSize;
int ans = 0;

void dfs(int i, int sum) {
    if (sum == target) {
        ans++;
        cout << "Subset " << ans << " -> ";
        for (int value : subset) {
            cout << value << " ";
        }
        cout << endl;
        return;
    }

    if (sum > target || i == arrSize) {
        return;
    }

    subset.push_back(arr[i]);
    dfs(i + 1, sum + arr[i]);
    subset.pop_back();

    dfs(i + 1, sum);
}

int main() {
    cout << "Enter the size of the array: ";
    cin >> arrSize;

    arr.resize(arrSize);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arrSize; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    dfs(0, 0);
    cout << "Number of Subset = " << ans << endl;

    return 0;
}