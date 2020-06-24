class Solution {
public:
    std::unordered_map<int, std::string> levelTreeStr;
    void printBinaryTree(TreeNode* root) {
        traverse(root, 0, 4);
        for (int i = 0; levelTreeStr.find(i) != levelTreeStr.end(); i++) {
            std::cout<<levelTreeStr[i]<<std::endl;
        }
        return vector<int>();
    }
    void traverse(TreeNode *root, int level, int spaceOffset) {
        if (root == nullptr)
            return;
        if (levelTreeStr[level + 1].empty()) {
            if (root->left && root->right) {
                levelTreeStr[level + 1] = std::move(std::string(spaceOffset - 1, ' ') + "/ \\");
            }else if (root->left) {
                levelTreeStr[level + 1] = std::move(std::string(spaceOffset - 1, ' ') + "/");
            }else if (root->right) {
                levelTreeStr[level + 1] = std::move(string(spaceOffset - 1, ' ') + "  \\");
            }
        }
        if (levelTreeStr[level].empty()) {
            levelTreeStr[level] += std::move(std::string(spaceOffset, ' '));
            levelTreeStr[level] += std::move(to_string(root->val));
        } else {
            levelTreeStr[level] += std::move(string("  "));
            levelTreeStr[level] += to_string(root->val);
        }
        level += 2;
        traverse(root->left, level, spaceOffset - 2);
        traverse(root->right, level, spaceOffset + 2);
        level -= 2;
    }
};
