/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include<stdlib.h>
int i = 0, j = 0, k = 0;
struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder(struct node *root, int *arr){
	if (root == NULL)
	{

	}
	else{
		inorder(root->left, arr);
		arr[i] = root->data;
		i++;
		inorder(root->right, arr);
	}
	
		

	
}
void preorder(struct node *root, int *arr){
	if (root == NULL)
	{

	}
	else
	{
		arr[j] = root->data;
		j++;
		preorder(root->left, arr);
		preorder(root->right, arr);
	}

	
}
void postorder(struct node *root, int *arr){
	
	if (root == NULL)
	{

	}
	else
	{
		postorder(root->left, arr);
		postorder(root->right, arr);
		arr[k] = root->data;
		k++;
		
	}
}

