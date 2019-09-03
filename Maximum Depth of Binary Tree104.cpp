/* 题目描述：求二叉树的最大深度，深度优先DFS，递归的完美运用
input ：3 9 -1 -1 15 7
方法一：递归遍历
方法二：层序遍历增加一个求层数count
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


int maxDepth1(TreeNode *root)
{
    if(!root) return 0;
    return 1+max(maxDepth1(root->left), maxDepth1(root->right));
    
}
int maxDepth2(TreeNode *root)
{
    if(!root) return 0;
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        ++res;
        for(int i = q.size(); i > 0; --i)
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return res;
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
  int a = maxDepth1(T);
  cout << a << endl;
  int b = maxDepth2(T);
  cout<< b << endl;

    return 0;
}
