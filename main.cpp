//
// Created by SunRenchen on 2015-04-23.
//

#include "btree.h"


int main(void)
{
    const char* cOutStr = "--------------";
    const char* cEndStr = "--------------------END-------------------\n";
    // BTree Tests
    typedef src::BTree<int> _Node;
    _Node* root
            = new _Node(1, new _Node
                    (2, new _Node
                             (3, new _Node
                                     (4, new _Node
                                              (5, NULL, new _Node (6, NULL, NULL))
                                             , new _Node(7, NULL, new _Node(11, NULL, NULL))), NULL)
                            , new _Node(8, new _Node(9, NULL, NULL), NULL)), NULL);
    std::cout << cOutStr << "In order Print" << cOutStr << std::endl;
    root->InOrderPrint(std::cout);
    std::cout << cEndStr;

    std::cout << cOutStr << "Height" << cOutStr << std::endl;
    std::cout << root->Height() << std::endl;
    std::cout << cEndStr;

    std::cout << cOutStr << "Print By Level" << cOutStr << std::endl;
    root->PrintByLevel(std::cout);
    std::cout << cEndStr;

    std::cout << cOutStr << "Lowest Common Ancestor" << cOutStr << std::endl;
    const _Node* lca = root->LowestCommonAncestor(root->Left()->Left()->Left(), root->Left()->Right()->Left());
    lca->PrintByLevel(std::cout);

    lca = root->LowestCommonAncestor(root->Left()->Left()->Left(), root->Left()->Left()->Left()->Right());
    lca->PrintByLevel(std::cout);
    return 0;
}