/* 题目描述：反转二叉树，把二叉树变成左右对称的
方法一：递归遍历，交换当前左右节点，不断递归调用
方法二：类似于层序遍历,根节点入队，保存队首节点并出队
交换队首节点的左右子节点，如果左右子节点存在，依次push进队列
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
TreeNode *creatTree(vector<int> &v)
{
    TreeNode *root;
    if (v.size() == 0)
        return NULL;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[0] == -1)
        {
            root = NULL;
            v.erase(v.begin());
        }
        else
        {
            root = new TreeNode(v[0]);
            v.erase(v.begin());
            root->left = NULL;
            root->left = creatTree(v);
            root->right = NULL;
            root->right = creatTree(v);
        }
    }
    return root;
}

TreeNode* invertTree1(TreeNode *root)
{
    if(!root) return NULL;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = invertTree1(right);
    root->right = invertTree1(left);
    return root;
}
TreeNode* invertTree2(TreeNode *root)
{
    if(!root) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        TreeNode* temp = node->left;//交换当前节点的左右子节点
        node->left = node->right;
        node->right = temp;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }
    TreeNode *T = creatTree(v);
    TreeNode* TT = invertTree1(T);
    return 0;
}
