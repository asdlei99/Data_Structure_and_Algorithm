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
