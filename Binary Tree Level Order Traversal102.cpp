/* 
题目描述：给出一颗二叉树，返回他的层序遍历，队列的解法
input 1，null， 2，3   output 1，2，3
思路：层序遍历是广度优先的BFS的应用
首先建立一个队列，根节点入队
队列不为空的情况下，根节点出队，左右子节点入队，此时队列里是下一层的节点
for循环遍历这一层的队列，同时再把他们的子节点入队，上一层的节点出队，依次类推就是层序遍历

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

vector<vector<int> > levelOrder(TreeNode *root)
{
   if(!root) return {};
   vector<vector<int> > res;//二维变量存储
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty())//队列不为空的时候
   {
        vector<int> oneLevel;    //一维存储每一层的节点
        for(int i = q.size(); i > 0; --i)
        {
            TreeNode* temp = q.front();
            q.pop();
            oneLevel.push_back(temp->data);//队首节点出队
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);//左右子节点分别入队
        }
        res.push_back(oneLevel);
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
    vector<vector<int> > res;
    res = levelOrder(T);
    return 0;
}
