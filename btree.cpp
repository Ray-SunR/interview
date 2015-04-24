//
// Created by SunRenchen on 2015-04-21.
//
#include <iostream>
#include "btree.h"

namespace src
{
    template <typename T>
    BTree<T>::BTree(T data, BTree<T> *left, BTree<T> *right)
    : m_data(data)
    , m_left(left)
    , m_right(right){}

    template <typename T>
    BTree<T>::~BTree()
    {
        delete m_left;
        delete m_right;
    }

    template <typename T>
    void BTree<T>::InOrderPrint(std::ostream &out) const
    {
        using namespace std;

        if (m_left) {m_left->InOrderPrint(out);}

        out << m_data << " " << endl;

        if (m_right) {m_right->InOrderPrint(out);}
    }

    template <typename T>
    void BTree<T>::PrintAtLevel(std::ostream &out, UInt32 level) const
    {
        if (level == 0)
        {
            out << m_data;
        }

        if (m_left)
        {
            m_left->PrintAtLevel(out, level - 1);
        }

        if (m_right)
        {
            m_right->PrintAtLevel(out, level - 1);
        }
    }

    template <typename T>
    void BTree<T>::PrintByLevel(std::ostream &out) const
    {
        UInt32 height = Height();
        for (UInt32 i = 0; i < height; i++)
        {
            PrintAtLevel(out, i);
            out << std::endl;
        }
    }

    template <typename T>
    UInt32 BTree<T>::Height() const
    {
        return 1 + std::max(m_left ? m_left->Height() : 0, m_right ? m_right->Height() : 0);
    }

    template <typename T>
    const BTree<T>* BTree<T>::Left() const
    {
        return m_left;
    }

    template <typename T>
    const BTree<T>* BTree<T>::Right() const
    {
        return m_right;
    }

    template <typename T>
    bool BTree<T>::HasChild(src::BTree<T> const *node) const
    {
        if (!node){return false;}
        if (m_left == node || m_right == node)
        {
            return true;
        }

        bool leftsubtree = m_left ? m_left->HasChild(node) : false;
        bool rightsubtree = m_right ? m_right->HasChild(node) : false;
        return leftsubtree || rightsubtree;
    }

    template <typename T>
   const BTree<T>* BTree<T>::LowestCommonAncestor(const BTree<T>* one, const BTree<T>* two) const
    {
        if (!one || !two) {return NULL;}
        if (one->HasChild(two)){ return one; }
        if (two->HasChild(one)){ return two; }

        bool HasOne = HasChild(one);
        bool HasTwo = HasChild(two);
        if (!HasChild(one) || !HasChild(two)) { return NULL; }
        if (m_left && m_left->HasChild(one) && m_left->HasChild(two))
        {
            return m_left->LowestCommonAncestor(one, two);
        }
        else if (m_right && m_right->HasChild(one) && m_right->HasChild(two))
        {
            return m_right->LowestCommonAncestor(one, two);
        }

        return this;
    }
    template class BTree<int>;
}

