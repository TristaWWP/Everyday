/* 
题目描述：给出一颗二叉树，返回他的前序遍历
input 1，null， 2，3   output 1，2，3
思路：两种解法：递归（比较简单）和迭代
迭代法：递归问题本质是栈的调用，所以递归写法可以转换为栈写法
前序遍历：根-左-右
首先把根节点push栈中
当栈不为空的情况下，根节点（栈顶元素）出栈，再把右节点入栈，再把左节点入栈
为什么先入右再入左，因为栈是先进后出，这样就是先出左后出右
 */
#include <iostream>
#include <vector>
#include <stack>

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

/*
TreeNode* creatTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    return root;
}
*/
//vector<int> preordertraveral1(TreeNode *root)
void preordertraveral1(TreeNode *root)
{
    // vector<int> res;
    if (root != NULL)
    {
        //res.push_back(root->data);
        //return res;
        cout << root->data;
        if (root->left != NULL)
        {
            preordertraveral1(root->left);
        }
        if (root->right != NULL)
        {
            preordertraveral1(root->right);
        }
    }
}
vector<int> preordertraveral2(TreeNode *root)
{
    if (root != NULL)
    {
        vector<int> res;
        stack<TreeNode *> s; //定义一个栈
        s.push(root);        //先把根节点入栈
        while (!s.empty())   //当栈不为空
        {
            TreeNode *temp = s.top();
            s.pop();
            res.push_back(temp->data);
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        return res;
    }
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
   // preordertraveral1(T);
    vector<int> res;
    res = preordertraveral2(T);
    for(auto c : res)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
