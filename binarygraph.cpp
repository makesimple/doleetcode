class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<char> cvec;
        std::vector<char> stack;
        cvec.assign(graph.size(),0);
        for (int n = 0; n < graph.size(); n++) {
            if (cvec[n] == 0) {
                stack.push_back(n);
                cvec[n] = 1;
                while(!stack.empty()) {
                    auto s = stack.back();
                    stack.pop_back();
                    for (auto &i : graph[s]) {
                        if (cvec[i] == cvec[s]) {
                            return false;
                        } else if (cvec[i] == 0 ){
                            if (cvec[s] == 1) {
                                cvec[i] = 2;
                            } else {
                                cvec[i] = 1;
                            }
                            stack.push_back(i);
                        }
                    }
                }
            }
        }
        return true;
    }
};
