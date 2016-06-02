// BinaryTreeDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BinTreeNode rootNode;
	BinaryTree tree;

	Init_BinaryTreeNode_with_value(rootNode, 128);

	Init_BinaryTree_with_RootNode(tree, &rootNode);

	Add_left_children_to_node_with_value(Get_BinaryTree_RootNode(tree), 0);
	
	Add_right_children_to_node_with_value(Get_BinaryTree_RootNode(tree), 1);

	return 0;
}

