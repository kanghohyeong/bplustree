// Please implement most of your source codes here.

#include <iostream>
#include <fstream>
#include "BTree.h"

#define NUM_KEYS 10


BTreeNode::BTreeNode()
{
    num_node++;
    key_cnt = 0;
}



BTreeInternalNode::BTreeInternalNode()
{
    type = INTERNAL;
}

BTreeInternalNode::~BTreeInternalNode()
{

}

BTreeLeafNode::BTreeLeafNode()
{
    type = LEAF;
}

BTreeLeafNode::~BTreeLeafNode()
{

}

void BTreeLeafNode::printLeafNode()
{

}


BTree::BTree()
{
    root = new BTreeLeafNode();

}

BTree::~BTree()
{

}

void BTree::insert(long long value)
{

}

void BTree::remove(long long value)
{

}

void BTree::printLeafNode(long long value)
{

}

void BTree::pointQuery(long long value)
{

}

void BTree::rangeQuery(long long low, long long high)
{

}

void BTree::insert(BTreeNode* nodepointer, long long value, BTreeNode* newchildnode)
{
    newchildnode = NULL;
    if(nodepointer->getNodeType() != LEAF)  //non leaf
    {
        if(nodepointer->getNodeNum()==1)    //first root
        {

        }
    }
    else    //leaf
    {
        BTreeLeafNode& leaf_node = dynamic_cast<BTreeLeafNode&>(*nodepointer);

        if(leaf_node.getKeyCnt() < NUM_KEYS)
        {
            if(leaf_node.getKeyCnt() == 0)  //empty key
            {
                leaf_node.insert_key(0,value);
                leaf_node.IncreaseKeyCnt();
            }
            else    //not empty
            {
                for(int i=0;i<leaf_node.getKeyCnt();i++)
                {
                    if(leaf_node.getKeyValue(i)<value)
                    {
                        for(int j=leaf_node.getKeyCnt();j<=i;j--)
                        {

                        }
                    }
                }
            }
        }
    }

}
