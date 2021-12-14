#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {   
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
void reverseRow(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (vector<int> &v : matrix)
    {
        int st = 0;
        int end = n - 1;
        while (st < end)
        {
            int temp = v[st];
            v[st] = v[end];
            v[end] = temp;
            st++;
            end--;
        }
    }
}
void rotate(vector<vector<int>> &matrix)
{
    // Transpose
    transpose(matrix);
    // reversing rows
    reverseRow(matrix);
}

int main()
{
    // vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    for (auto row : v)
    {
        for (auto x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
    rotate(v);
    for (auto row : v)
    {
        for (auto x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}