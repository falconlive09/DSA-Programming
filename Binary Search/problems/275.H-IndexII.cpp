#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sortKBorder(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int k = 0; k <= (n - 1) / 2; k++) {
        vector<int> border;
        for (int j = k; j < n - k; j++) {
            border.push_back(matrix[k][j]);
        }
        for (int i = k + 1; i < n - k; i++) {
            border.push_back(matrix[i][n - k - 1]);
        }
        for (int j = n - k - 2; j >= k; j--) {
            border.push_back(matrix[n - k - 1][j]);
        }
        for (int i = n - k - 2; i > k; i--) {
            border.push_back(matrix[i][k]);
        }
        sort(border.begin(), border.end());
        int index = 0;
        for (int j = k; j < n - k; j++) {
            result[k][j] = border[index++];
        }
        for (int i = k + 1; i < n - k; i++) {
            result[i][n - k - 1] = border[index++];
        }
        for (int j = n - k - 2; j >= k; j--) {
            result[n - k - 1][j] = border[index++];
        }
        for (int i = n - k - 2; i > k; i--) {
            result[i][k] = border[index++];
        }
    }
    return result;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {9, 7, 4, 5},
        {1, 6, 2, -6},
        {12, 20, 2, 0},
        {-5, -6, 7, -2}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    vector<vector<int>> result = sortKBorder(matrix);

    cout << "\nSorted Matrix:" << endl;
    printMatrix(result);

    return 0;
}
