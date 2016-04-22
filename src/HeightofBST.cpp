/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>
int lsum = 0, rsum = 0;
int height1 = 1;
struct node{
	struct node * left;
	int data;
	struct node *right;
};

int left_sum(struct node *head)
{
	if (head->left != NULL)
		lsum = lsum + head->left->data;
	if (head->right != NULL)
		lsum = lsum + head->right->data;
	if (head->left != NULL)
		left_sum(head->left);
	if (head->right != NULL)
		left_sum(head->right);
	return lsum;
}
int right_sum(struct node *head)
{
	if (head->left != NULL)
		rsum = rsum + head->left->data;
	if (head->right != NULL)
		rsum = rsum+ head->right->data;
	if (head->left != NULL)
		right_sum(head->left);
	if (head->right != NULL)
		right_sum(head->right);
	return rsum;
}
int get_height(struct node *root){
	if (root == NULL)
		return 0;

	
	int heightLeft = get_height(root->left);
	int heightRight = get_height(root->right);
    if (heightLeft > heightRight)
		return(heightLeft + 1);
	else
		return(heightRight + 1);
}
int get_left_subtree_sum(struct node *root){
	int sum=0;
	if (root == NULL)
		return 0;
	if (root->left != NULL)
	{

		sum = left_sum(root->left);
		sum = sum + root->left->data;
	}
	return sum;
}

int get_right_subtree_sum(struct node *root){
	int sum=0;
	if (root == NULL)
		return 0;
	if (root->right != NULL)
	{

		sum = right_sum(root->right);
		sum = sum + root->right->data;
	}
	
	return sum;
	
}

