/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
int *q1,t=0;

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void printGivenLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		q1[t] = root->data;
		t++;
	}
	else if (level > 1)
	{
		printGivenLevel(root->right, level - 1);
		printGivenLevel(root->left, level - 1);
	}
}

int get_height1(struct node *root){
	if (root == NULL)
		return 0;


	int heightLeft = get_height1(root->left);
	int heightRight = get_height1(root->right);
	if (heightLeft > heightRight)
		return(heightLeft + 1);
	else
		return(heightRight + 1);
}
int* BSTRighttoLeftRows(struct node* root)
{

	q1 = (int *)malloc(20 * sizeof(int));
	if (root == NULL)
		return q1;
	
	int h = get_height1(root);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(root, i);
	return q1;
}
