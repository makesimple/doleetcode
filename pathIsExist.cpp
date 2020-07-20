#if 0
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif
//dfs
#if 1
class Solution {
public:
    int row, col, wordSize;
    unordered_map<int, bool> flags;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        wordSize = word.size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (word[0] == board[i][j]) {
                    if (dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string &word, int index) {
        if (index == wordSize) {
            return true;
        }
        if (i < 0 || j < 0 || i > row - 1 || j > col - 1) {
            return false;
        }
        int key = (i << 16) + j;
        if (board[i][j] == word[index] && flags[key] == false) {
            auto res = false;
            vector<array<int,2>> neighbors = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
            for (array<int, 2> &a : neighbors) {
                flags[key] = true;
                // 此处不可以这样 loop(direction)res |= dfs(direction); return res;
                // 要理解深度的含义：dfs返回true说明深度到底了，返false没到底走不通了。
                // 之前有一种错误的理解：比如有左右两个方向都可行，但是第左方向到后面又不行，
                // 而右方向到后面可行，如果按下面这种办法，就错过了右方向。这是对深度优先的错误理解。
                // 深度，一句话，返回true说明，到底了并且走通了。
                res = dfs(board, a[0], a[1], word, index + 1);
                flags[key] = false;
                if (res)
                    return res;
            }
            return false;
        } else {
            return false;
        }
    }
};
#else
// TODO: bfs
#endif
