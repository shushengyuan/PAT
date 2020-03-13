#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int val;
    struct node *l, *r;
    int num;
    int index;
};
vector<node> v;
node *rotateLeft(node *root)
{
    node *t = root->r;
    root->r = t->l;
    t->l = root;
    return t;
}
node *rotateRight(node *root)
{
    node *t = root->l;
    root->l = t->r;
    t->r = root;
    return t;
}
node *rotateLeftRight(node *root)
{
    root->l = rotateLeft(root->l);
    return rotateRight(root);
}
node *rotateRightLeft(node *root)
{
    root->r = rotateRight(root->r);
    return rotateLeft(root);
}
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return max(getHeight(root->l), getHeight(root->r)) + 1;
}
node *Insert(node *root, int value)
{
    if (root == NULL)
    {
        root = new node();
        root->val = value;
        root->l = NULL;
        root->r = NULL;
        // root->num = 0;
    }
    else if (value < root->val)
    {
        root->l = Insert(root->l, value);
        if (getHeight(root->l) - getHeight(root->r) == 2)
        {
            root = value < root->l->val ? rotateRight(root) : rotateLeftRight(root);
        }
    }
    else
    {
        root->r = Insert(root->r, value);
        if (getHeight(root->l) - getHeight(root->r) == -2)
        {
            root = value > root->r->val ? rotateLeft(root) : rotateRightLeft(root);
        }
    }
    return root;
}
int tolnum = 0;

void levelOrder(node *root, int level, int index)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        root->num = level;
        root->index = index;
        v.push_back(*root);
    }
    levelOrder(root->l, level + 1, index * 2 + 1);
    // tolnum = 0
    levelOrder(root->r, level + 1, index * 2 + 2);
    return;
}
int temps(node a, node b)
{
    if(a.num < b.num){
        return 1;
    }else if(a.num == b.num){
        if(a.index<b.index){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    // v.resize(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        root = Insert(root, temp);
    }
    // printf("%d", root->val);
    levelOrder(root, 0, 0);
    sort(v.begin(), v.end(), temps);
    printf("%d", v[0].val);
    for (int i = 1; i < v.size(); i++)
    {
        printf(" %d", v[i].val);
    }
    // cout << endl;
    // cout << v[v.size() - 1].index ;
    for (int i = 0; i < n; i++)
    {
        if (v[i].index != i)
        {
            printf("\nNO");
            return 0;
        }
        
    }
    printf("\nYES");
    return 0;
}