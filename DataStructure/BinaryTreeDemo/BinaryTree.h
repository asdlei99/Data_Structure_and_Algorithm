#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef struct _BinTreeNode BinTreeNode;
typedef struct _BinTreeNode
{
	int value;
	BinTreeNode *leftSubTree;
	BinTreeNode *rightSubTree;
} BinTreeNode;

typedef struct _BinaryTree
{
	unsigned int treeDepth;
	BinTreeNode *rootNode;
} BinaryTree;

#endif