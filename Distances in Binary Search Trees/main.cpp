#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int value) {
  if (root == nullptr) {
    return new TreeNode(value);
  }
  if (value < root->value) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }
  return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, int node1, int node2) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->value == node1 || root->value == node2) {
    return root;
  }
  TreeNode *leftLCA = lowestCommonAncestor(root->left, node1, node2);
  TreeNode *rightLCA = lowestCommonAncestor(root->right, node1, node2);
  if (leftLCA && rightLCA) {
    return root;
  }
  return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int findDistance(TreeNode *root, int node1, int node2) {
  TreeNode *lca = lowestCommonAncestor(root, node1, node2);
  int distance1 = 0, distance2 = 0;
  TreeNode *temporary = lca;
  while (temporary->value != node1) {
    if (node1 < temporary->value) {
      temporary = temporary->left;
    } else {
      temporary = temporary->right;
    }
    distance1++;
  }
  temporary = lca;
  while (temporary->value != node2) {
    if (node2 < temporary->value) {
      temporary = temporary->left;
    } else {
      temporary = temporary->right;
    }
    distance2++;
  }

  return distance1 + distance2;
}

int main() {
  vector<int> values;
  stringstream ss;
  string in;
  int a;
  getline(cin, in);
  ss << in;
  while (ss >> a) { values.push_back(a); }
  ss.clear(), in.clear();
  getline(cin, in);
  ss << in;
  int node1, node2;
  ss >> node1 >> node2;
  ss.clear(), in.clear();
  TreeNode *root = nullptr;
  for (int i = 0; i < values.size(); i++) { root = insert(root, values[i]); }
  int distance = findDistance(root, node1, node2);
  cout << distance << endl;
  return 0;
}
