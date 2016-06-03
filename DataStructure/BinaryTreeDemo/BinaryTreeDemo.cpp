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

	BinTreeNode *thisNode = Get_node_left_children(&rootNode);
	Add_left_children_to_node_with_value(thisNode, 2);
	Add_right_children_to_node_with_value(thisNode, 3);

	thisNode = Get_node_right_children(&rootNode);
	Add_left_children_to_node_with_value(thisNode, 4);
	Add_right_children_to_node_with_value(thisNode, 5);

	thisNode = Get_node_left_children(thisNode);
	Add_right_children_to_node_with_value(thisNode, 6);

//	Pre_order_tranverse(tree);
//	In_order_tranverse(tree);
	Post_order_tranverse(tree);
	return 0;
}

