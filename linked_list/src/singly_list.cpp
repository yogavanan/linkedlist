
#include <stdio.h>
#include <iostream>
#include "../inc/singly_list.h"

SinglyNode * get_newNode(int data)
{
	SinglyNode * new_node = new SinglyNode;

	if (new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
	}

	return new_node;
}


SinglyNode * append_node(SinglyNode * head, int data)
{
	if (head == NULL)
	{
		head = get_newNode(data);
	}
	else
	{
		SinglyNode * temp = head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = get_newNode(data);
	}
}

void print_singlyList(SinglyNode * node)
{
	while (node)
	{
		printf("%d", node->data);
		if (node->next)
		{
			printf(" -> ");
		}
		else
		{
			printf("\n");
		}
		node = node->next;
	}
}