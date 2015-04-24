//
// Created by SunRenchen on 2015-04-21.
//
#include <iostream>

template <typename T>
struct bNode
{
    bNode(T data, bNode* left, bNode* right)
            : data(data)
            , left(left)
            , right(right){}
    ~bNode(){delete left; delete right;}
    T data;
    bNode* left;
    bNode* right;
};

template<typename T>
void InOrderPrintBTree(bNode<T>* root)
{
    using namespace std;
    if (!root){return;}
    InOrderPrintBTree(root->left);
    cout << root->data << " " << endl;
    InOrderPrintBTree(root->right);
}

template <typename T>
void PrintBTreeAtLevel(uint level, const bNode<T>* root)
{
    if (!root) {return;}
    if (level == 0)
    {
        std::cout << root->data;
    }

    PrintBTreeAtLevel(level - 1, root->left);
    PrintBTreeAtLevel(level - 1, root->right);
}

int max(int val1, int val2)
{
    return val1 > val2 ? val1 : val2;
}

template <typename T>
uint BTreeHeightHelper(const bNode<T>* root, uint height)
{
    if (!root){return height;}
    uint leftHeight = BTreeHeightHelper(root->left, height + 1);
    uint rightHeight = BTreeHeightHelper(root->right, height + 1);
    return max(leftHeight, rightHeight);
}

template <typename T>
uint BTreeHeight(const bNode<T>* root)
{
    return BTreeHeightHelper(root, 0);
}

template <typename T>
void PrintBTreeByLevel(const bNode<T>* root)
{
    using namespace std;
    cout << "----------------Print BTree By Level----------------" << endl;
    uint height = BTreeHeight(root);
    for (uint i = 0; i < height; i++)
    {
       PrintBTreeAtLevel<T>(i, root);
        cout << endl;
    }
    cout << "----------------------END--------------------------" << endl;
}

int main(void)
{
    typedef bNode<int> _Node;
    _Node* root
            = new _Node(1, new _Node
                            (2, new _Node
                                    (3, new _Node
                                            (4, new _Node
                                                    (5, NULL, new _Node (6, NULL, NULL))
                                                    , new _Node(7, NULL, new _Node(11, NULL, NULL))), NULL)
                                    , new _Node(8, new _Node(9, NULL, NULL), NULL)), NULL);
    InOrderPrintBTree(root);
    PrintBTreeByLevel(root);
    return 0;
}

