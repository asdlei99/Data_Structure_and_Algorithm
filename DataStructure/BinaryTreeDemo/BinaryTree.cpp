#include "stdafx.h"
#include "BinaryTree.h"

void Init_BinaryTreeNode_with_value(BinTreeNode &node, int value)
{
	node.value = value;
	node.parentNode = node.leftSubTree = node.rightSubTree = NULL;
}

void Init_BinaryTree(BinaryTree &tree)
{
	tree.nodeCnt = 0;
	tree.rootNode = NULL;
}

void Init_BinaryTree_with_RootNode(BinaryTree &tree, BinTreeNode *rootNode)
{
	Init_BinaryTree(tree);
	tree.rootNode = rootNode;
}

BinTreeNode * Get_BinaryTree_RootNode(BinaryTree &tree)
{
	return tree.rootNode;
}

int Add_left_children_to_node_with_value(BinTreeNode *currentNode, int value)
{
	BinTreeNode *leftNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!leftNode)
	{
		return -1;
	}

	leftNode->value = value;
	leftNode->parentNode = currentNode;
	leftNode->leftSubTree = leftNode->rightSubTree = NULL;
	currentNode->leftSubTree = leftNode;

	return 0;
}

int Add_right_children_to_node_with_value(BinTreeNode *currentNode, int value)
{
	BinTreeNode *rightNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!rightNode)
	{
		return -1;
	}

	rightNode->value = value;
	rightNode->parentNode = currentNode;
	rightNode->leftSubTree = rightNode->rightSubTree = NULL;
	currentNode->rightSubTree = rightNode;

	return 0;
}

BinTreeNode * Get_node_parent(BinTreeNode *node)
{
	return node->parentNode;
}

BinTreeNode * Get_node_left_children(BinTreeNode *node)
{
	return node->leftSubTree;
}

BinTreeNode * Get_node_right_children(BinTreeNode *node)
{
	return node->rightSubTree;
}

static void pre_order_start_node(BinTreeNode *node)
{
	if (!node)
	{
		return;
	}
	printf("%d ", node->value);
	pre_order_start_node(node->leftSubTree);
	pre_order_start_node(node->rightSubTree);
}

void Pre_order_tranverse(BinaryTree &tree)
{
	pre_order_start_node(tree.rootNode);
	printf("\n");
}

static void in_order_start_node(BinTreeNode *node)
{
	if (!node)
	{
		return;
	}
	in_order_start_node(node->leftSubTree);
	printf("%d ", node->value);
	in_order_start_node(node->rightSubTree);
}

void In_order_tranverse(BinaryTree &tree)
{
	in_order_start_node(tree.rootNode);
	printf("\n");
}

static void post_order_start_node(BinTreeNode *node)
{
	if (!node)
	{
		return;
	}
	post_order_start_node(node->leftSubTree);
	post_order_start_node(node->rightSubTree);
	printf("%d ", node->value);
}

void Post_order_tranverse(BinaryTree &tree)
{
	post_order_start_node(tree.rootNode);
	printf("\n");
}
