#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    if (a.weight == 0) return true;
    if (b.weight == 0) return false;
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto &item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return totalValue;
}

int zeroOneKnapsack(int W, vector<Item>& items, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(
                    items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> items[i].value;

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> items[i].weight;

    cout << "Enter capacity: ";
    cin >> W;

    vector<Item> itemsCopy = items;

    double greedyResult = fractionalKnapsack(W, itemsCopy);
    int dpResult = zeroOneKnapsack(W, items, n);

    cout << fixed << setprecision(2);

    cout << "\n--- Results ---\n";
    cout << "Fractional Knapsack (Greedy): " << greedyResult << endl;
    cout << "0/1 Knapsack (DP): " << dpResult << endl;

    return 0;
}
