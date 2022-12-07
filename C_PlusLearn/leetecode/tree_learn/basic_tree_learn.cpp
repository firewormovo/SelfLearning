#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    string val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(""), left(nullptr), right(nullptr) {}
    TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(string x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void preOrder(TreeNode *root, vector<string> &res)
{
    if (root == nullptr)
    {
        return;
    }
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

vector<string> preorderTravelsal(TreeNode *root)
{
    vector<string> res;
    preOrder(root, res);
    return res;
}

vector<string> preorderTravelsal1(TreeNode *root)
{
    vector<string> res;
    
    
}

int main(int argc, const char **argv)
{
    // 定义一个二叉树
    TreeNode *tree_node = new TreeNode;
    tree_node->val = "A";
    TreeNode *nodeb = new TreeNode;
    nodeb->val = "B";
    TreeNode *noded = new TreeNode;
    noded->val = "D";
    TreeNode *nodee = new TreeNode;
    nodee->val = "E";
    TreeNode *nodef = new TreeNode;
    nodef->val = "F";
    TreeNode *nodec = new TreeNode;
    nodec->val = "C";

    tree_node->left = nodeb;
    tree_node->right = nodec;
    nodeb->left = noded;
    nodeb->right = nodee;
    nodec->left = nodef;

    //
    vector<string> res = preorderTravelsal(tree_node);
    for (auto val : res)
    {
        std::cout << val << std::endl;
    }

    return 0;
}