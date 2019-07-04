#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/longest-univalue-path/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:


    int longestPath(TreeNode *r, int &longest) {
        if (!r) return 0;
        int pathLeft = longestPath(r->left, longest);
        int pathRight = longestPath(r->right, longest);
        int lp = 0, rp = 0;
        if (r->left && r->left->val == r->val)
            lp = pathLeft + 1;
        if (r->right && r->right->val == r->val)
            rp = pathRight + 1;
        longest = max(longest, lp + rp);
        return max(lp, rp);

    }

    int longestUnivaluePath(TreeNode *root) {
        if (!root) return 0;
        int longest = 0;
        longestPath(root, longest);
        return longest;
    }
};


void test1() {
    vector<int> v1{5, 4, 5, 1, 1, -1, 5};
    auto t1 = new TreeNode(v1, -1);
    cout << t1 << endl;
    cout << "2 ? " << Solution().longestUnivaluePath(t1) << endl;

    vector<int> v2{1, 4, 5, 4, 4, -1, 5};
    auto t2 = new TreeNode(v2, -1);
    cout << t2 << endl;
    cout << "2 ? " << Solution().longestUnivaluePath(t2) << endl;
//
    vector<int> v3{5, 4, 5, 1, 1, 5};
    auto t3 = new TreeNode(v3, -1);
    cout << t3 << endl;
    cout << "2 ? " << Solution().longestUnivaluePath(t3) << endl;
}


void test2() {

}

void test3() {

}