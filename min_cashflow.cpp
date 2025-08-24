#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimizeCashFlow(vector<vector<int>> &transactions) {
    int n = transactions.size();
    priority_queue<vector<int>> debtors, creditors;

    for (int person = 0; person < n; person++) {
        int netAmount = 0;
        for (int i = 0; i < n; i++)
            netAmount += transactions[i][person];
        for (int j = 0; j < n; j++)
            netAmount -= transactions[person][j];
        if (netAmount < 0)
            debtors.push({abs(netAmount), person});
        else if (netAmount > 0)
            creditors.push({netAmount, person});
    }

    vector<vector<int>> result(n, vector<int>(n, 0));

    while (!debtors.empty() && !creditors.empty()) {
        int debtAmount = debtors.top()[0];
        int creditAmount = creditors.top()[0];
        int debtorId = debtors.top()[1];
        int creditorId = creditors.top()[1];

        debtors.pop();
        creditors.pop();

        int transferAmount = min(debtAmount, creditAmount);
        result[debtorId][creditorId] = transferAmount;

        debtAmount -= transferAmount;
        creditAmount -= transferAmount;

        if (debtAmount > 0)
            debtors.push({debtAmount, debtorId});
        if (creditAmount > 0)
            creditors.push({creditAmount, creditorId});
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<vector<int>> transactions(n, vector<int>(n));
    cout << "\nEnter the transaction matrix:\n";
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Amount to be paid by Person " << i 
                 << " to Person " << j << ": ";
            cin >> transactions[i][j];
        }
    }

    vector<vector<int>> result = minimizeCashFlow(transactions);

    cout << "\nOptimized Transactions:\n";
    bool hasTransactions = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] > 0) {
                cout << "Person " << i << " should pay Person " << j
                     << " an amount of " << result[i][j] << "\n";
                hasTransactions = true;
            }
        }
    }

    if (!hasTransactions) {
        cout << "No transactions needed. All accounts are settled.\n";
    }

    return 0;
}

