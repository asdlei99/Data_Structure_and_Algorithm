#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef struct _BinTreeNode BinTreeNode;
typedef struct _BinTreeNode
{
	int value;
	BinTreeNode *parentNode;
	BinTreeNode *leftSubTree;
	BinTreeNode *rightSubTree;
} BinTreeNode;

typedef struct _BinaryTree
{
	unsigned int nodeCnt;
	BinTreeNode *rootNode;
} BinaryTree;

void Init_BinaryTreeNode_with_value(BinTreeNode &node, int value);

void Init_BinaryTree(BinaryTree &tree);

void Init_BinaryTree_with_RootNode(BinaryTree &tree, BinTreeNode *rootNode);

BinTreeNode *Get_BinaryTree_RootNode(BinaryTree &tree);

BinTreeNode *Get_node_parent(BinTreeNode *node);

BinTreeNode *Get_node_left_children(BinTreeNode *node);

BinTreeNode *Get_node_right_children(BinTreeNode *node);

int Add_left_children_to_node_with_value(BinTreeNode *currentNode, int value);

int Add_right_children_to_node_with_value(BinTreeNode *currentNode, int value);

void Pre_order_tranverse(BinaryTree &tree);

void In_order_tranverse(BinaryTree &tree);

void Post_order_tranverse(BinaryTree &tree);

#endif