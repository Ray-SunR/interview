//
// Created by SunRenchen on 2015-04-21.
//

#ifndef FACEBOOK_BTREE_H
#define FACEBOOK_BTREE_H
#include <iostream>
#include <MacTypes.h>

namespace src
{
    template <typename T>
    class BTree
    {
    public:
        BTree(T data, BTree<T>* left, BTree<T>* right);
        ~BTree();
        void InOrderPrint(std::ostream& out) const;
        void PrintAtLevel(std::ostream &out, UInt32 level) const;
        void PrintByLevel(std::ostream& out) const;
        const BTree<T>* LowestCommonAncestor(const BTree<T>* one, const BTree<T>* two) const;
        UInt32 Height() const;
        bool HasChild(const BTree<T> *node) const;
        const BTree<T>* Left() const;
        const BTree<T>* Right() const;
    private:
        T m_data;
        BTree<T>* m_left;
        BTree<T>* m_right;
    };


}
#endif //FACEBOOK_BTREE_H
