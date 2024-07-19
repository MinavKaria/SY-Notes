#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

vector<vector<int>> board(N, vector<int>(N, 0));

void print_solution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int x : row) {
            cout << (x ? 'Q' : '.') << ' ';
        }
        cout << endl;
    }
}

bool is_safe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solve_nq_util(vector<vector<int>>& board, int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;

            if (solve_nq_util(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

bool solve_nq() {
    if (!solve_nq_util(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    print_solution(board);
    return true;
}

int main() {
    solve_nq();
    return 0;
}
