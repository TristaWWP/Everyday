/* 
题目描述：给出一颗二叉树，返回他的后序遍历
input 1，null， 2，3   output 3，2，1
思路：两种解法：递归（比较简单）和迭代
迭代法：递归问题本质是栈的调用，所以递归写法可以转换为栈写法
后序遍历：左-右-根
方法一：比较复杂，要判断左节点右节点是否访问过
首先把根节点push栈中，temp为栈顶，如果temp没有子节点或者其中某个子节点被访问过
temp就出栈，且head= temp，head为出栈的那个元素，就是访问过的
否则，右节点入栈，左节点入栈
方法二：前序遍历的变体，前序遍历是根左右，改变访问顺序就是根右左
然后逆序这个变化后的前序，就是左右根
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

void postordertraveral1(TreeNode *root)
{
    // vector<int> res;
    if (root != NULL)
    {
        //res.push_back(root->data);
        //return res;     
        if (root->left != NULL)
        {
            postordertraveral1(root->left);
        }
        if (root->right != NULL)
        {
            postordertraveral1(root->right);
        }
         cout << root->data;
    }
}
vector<int> postordertraveral2(TreeNode *root)
{
    if (root != NULL)
    {
        vector<int> res;
        stack<TreeNode *> s; //定义一个栈
        s.push(root);        //先把根节点入栈
        TreeNode* head = root;//定义一个辅助节点head
        while (!s.empty())   //当栈不为空
        {
            TreeNode *temp = s.top();
            if((!temp->left && !temp->right) //左右节点都不存在，该根节点是叶子结点
            || temp->left == head || temp->right == head)//或者左右节点有一个或两个是上一次遍历过的
            {
                res.push_back(temp->data);
                s.pop();
                head = temp;//head指向上一个被遍历完成的节点
            }
            else{
                if (temp->right)
                    s.push(temp->right);
                if (temp->left)
                    s.push(temp->left);
            }
        }
        return res;
    }
}
vector<int> postordertraveral3(TreeNode *root)//前序遍历根左右->根右左->逆序->左右根
{
    if(root != NULL)
    {
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            res.insert(res.begin(), temp->data);
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);

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
    res = postordertraveral2(T);
    for(auto c : res)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
