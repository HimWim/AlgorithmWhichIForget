#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &board, int n)
{
    vector<string> ret(n, string(n, '*'));

    for (int j = 0; j < n; j++)
    {
        ret[j][board[j]] = 'Q';
    }

    for (auto it : ret)
    {
        for (auto c : it)
        {
            cout << c << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isValid(vector<int> &board, int n, int index)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (board[i] == board[index] || abs(index - i) == abs(board[i] - board[index]))
        {
            return false;
        }
    }
    return true;
}

void solve(vector<int> &board, int n, int index)
{
    if (index == n)
    {

        display(board, n);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        board[index] = j;
        if (isValid(board, n, index))
        {
            solve(board, n, index + 1);
        }
        board[index] = -1;
    }
}

void nQueen(int n)
{
    vector<int> board(n, -1);

    solve(board, n, 0);
}

int main()
{
    int n;
    cin >> n;

    nQueen(n);
}