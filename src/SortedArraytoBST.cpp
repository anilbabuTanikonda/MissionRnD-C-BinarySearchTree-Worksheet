/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
}*root1;
int flag = 0;
struct node *create1(int val)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
struct node *create_bst(int *a, int start, int end)
{
	int mid;
	if (start > end)
		return NULL;
	mid = (start + end) / 2;
	struct node *head= create1(a[mid]);
	head->left = create_bst(a, start, mid - 1);
	head->right = create_bst(a, mid + 1, end);
	return head;
}
struct node * convert_array_to_bst(int *arr, int len){
	int start = 0, end = len;
	int lheight, rheight;
if (arr==NULL || len==0 || len<0)
	return NULL;
	root1=create_bst(arr,start,end-1);
	
	 
return root1;
	

	

}

