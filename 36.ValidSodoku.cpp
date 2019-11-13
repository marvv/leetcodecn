class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i =0;i<9;i++)
        {
            set<char> st;
            for (int j=0;j<9;j++) {
                char tmp = board[i][j];
                if (tmp == '.') continue;
                if (st.find(tmp) != st.end()) return false;
                st.insert(tmp);
            }
        }

        for (int i =0;i<9;i++)
        {
            set<char> st;
            for (int j=0;j<9;j++) {
                char tmp = board[j][i];
                if (tmp == '.') continue;
                if (st.find(tmp) != st.end()) return false;
                st.insert(tmp);
            }
        }

        for (int i=0; i<9; i=i+3) 
          for (int j =0; j<9;j=j+3) {
              set<char> st;
              for (int m=i;m<i+3;m++) 
               for (int n=j;n<j+3;n++){
                   char tmp = board[m][n];
                   if (tmp == '.' ) continue;
                   if (st.find(tmp) != st.end()) return false;
                   st.insert(tmp);
               } 
          }
        
        return true;
    }
};