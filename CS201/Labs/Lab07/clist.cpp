#include "clist.h"

static int countRecur(node* head, node* curr, int total)
{
	total++;
	if(curr->next == head)
		return total;

	return(countRecur(head, curr->next, total));
}

static int sumRecur(node* head, node* curr, int sumTotal)
{
	if(curr->next == head){
		sumTotal += curr->data;
		return sumTotal;
	}
	sumTotal += curr->data;
	return(sumRecur(head, curr->next, sumTotal));
}	

int count(node* head)
{
	node * curr = head;
	int i;
	for(i = 0; curr->next != head; i++)
	{
		curr = curr->next;
	}

	i++;
	return i;
}

int countR(node* head)
{
	node* curr = head;
	int total = 0;
	return countRecur(head, curr, total);
}

int sum(node* head)
{
	node* currN = head;
	int total = currN->data;
	currN = currN->next;
	while(currN != head)
	{
		total += currN->data;
		currN = currN->next;
	}
	return total;
}

int sumR(node* head)
{
	node * curr = head;
	int sumTotal = 0;
	return sumRecur(head, curr, sumTotal);
}


