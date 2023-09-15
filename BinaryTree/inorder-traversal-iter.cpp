#include<bits/stdc++.h> 
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode *> st;
      vector<int> res;
      TreeNode *curr = root;
      while(curr != NULL || !st.empty()) {
        while(curr != NULL) {
          st.push(curr);
          curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
      }

      return res;
    }
};

TreeNode* insertLevelOrder(vector<int> &arr, int i, int n) {
      TreeNode *root = nullptr;
    // Base case for recursion
    if (i < n)
    {
        root = new TreeNode(arr[i]);
        // insert left child
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        // insert right child
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  int temp;
  for(int i=0; i<n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  TreeNode *root = insertLevelOrder(arr, 0, arr.size());
  Solution ob;
  vector<int> res = ob.inorderTraversal(root);
  for(int i=0; i<res.size(); i++) {
    cout << res[i] << " ";
  }
}