/* 
题目描述：给出一颗二叉树，返回他的中序遍历
input 1，null， 2，3   output 1，3，2
思路：两种解法：递归（比较简单）和迭代
中序遍历：左-根-右
方法一：首先把根节点push栈中,然后把所有的左子节点入栈，然后出栈栈顶元素，把指针移到他的右子节点上，

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

void inordertraveral1(TreeNode *root)
{
    // vector<int> res;
    if (root != NULL)
    {
        //res.push_back(root->data);
        //return res;     
        if (root->left != NULL)
        {
            inordertraveral1(root->left);
        }
         cout << root->data;
        if (root->right != NULL)
        {
            inordertraveral1(root->right);
        }
        
    }
}

vector<int> inordertraveral2(TreeNode *root)
{
    if(root != NULL)
    {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);//根节点入栈
                p = p->left;//所有的左子节点入栈
            }
            p = s.top();
            s.pop();
            res.push_back(p->data);
            p = p->right;//移到右子节点
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
    res = inordertraveral2(T);
    for(auto c : res)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
