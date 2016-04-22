/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<malloc.h>
#include "FunctionHeadersBST.h"
struct node{
	struct node * left;
	int data;
	struct node *right;
}*root2;

struct node *create(int value)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = value;
	tmp->left = tmp->right = NULL;
	return tmp;
}
struct node *insert(struct node *head, int key)
{
	if (head == NULL)
	{
		return create(key);
	}
	else if (
		key < head->data)
	{
		head->left = insert(head->left, key);
	}
	else if (key > head->data)
	{
		head->right = insert(head->right, key);
	}

	return head;

}
int main(){

	int  i, lsum = 0, rsum = 0, height_tree;
	int *arr;
	arr = (int *)malloc(10 * sizeof(int));
	root2 = insert(root2,50);
	int ar[10] = {25, 75, 30, 27, 60, 99, 53, 51, 57 };
	for (i = 0;	i<9; i++)
	{  
		insert(root2, ar[i]);
	}
	int distance = get_closest_leaf_distance(root2,root2->left);
	int *arr1 = BSTRighttoLeftRows(root2);
	inorder(root2, arr);
	preorder(root2, arr);
	postorder(root2, arr);
	fix_bst(root2);
	lsum = get_left_subtree_sum(root2);
	rsum = get_right_subtree_sum(root2);
	height_tree = get_height(root2);
	struct node *head = convert_array_to_bst(ar,10);
	
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr1[i]);
	}


	
	
	return 0;
}

