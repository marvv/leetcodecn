class Solution {
public:
    void updateSet(set<string>& st, int i, int j) {
        stringstream ss;
        ss << i << "_" << j;
        st.insert(ss.str());
    }

    bool valid(set<string>& st, int i, int j) {
        stringstream ss;
        ss << i << "_" << j;
        return st.find(ss.str()) == st.end();
    }

    bool f(vector<vector<char>>& board,string& word, set<string>&st, int i, int j, int index)
    {
        if (index >= word.size()) return true;
        char tmp = word[index];
        int row = board.size();
        int col = board[0].size();
        if (i>0 && board[i-1][j] == tmp && valid(st, i-1, j)) {
            set<string> tmpst = st;
            updateSet(tmpst, i-1, j);
            if (f(board, word, tmpst, i-1, j, index+1)) return true;
        }

        if (i<row-1 && board[i+1][j] == tmp && valid(st, i+1, j)) {
            set<string> tmpst = st;
            updateSet(tmpst, i+1, j);
            if (f(board, word, tmpst, i+1, j, index+1)) return true;
        }

        if (j>0 && board[i][j-1] == tmp && valid(st, i, j-1)) {
            set<string> tmpst = st;
            updateSet(tmpst, i, j-1);
            if (f(board, word, tmpst, i, j-1, index+1)) return true;          
        }
 
        if (j<col-1 && board[i][j+1] == tmp && valid(st, i, j+1)) {
            set<string> tmpst = st;
            updateSet(tmpst, i, j+1);
            if (f(board, word, tmpst, i, j+1, index+1)) return true;          
        }       

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        if (word.empty()) return true;
        int row = board.size();
        int col = board[0].size();
        if (word.size() > row*col) return false;
        for (int i=0; i< row; i++) 
            for (int j = 0;j<col;j++) {
                if (board[i][j] != word[0]) continue;
                set<string> st;
                updateSet(st, i, j);
                if (f(board, word, st, i, j, 1)) return true;
            }
        return false;
    }
};