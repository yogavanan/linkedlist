/***
Finding Duplicate from an unsorted linked list

*/

#include <stdio.h>
#include <iostream>
#include "../inc/singly_list.h"


int main(int argc, char ** argV)
{
	SinglyNode * head = NULL;

	head = append_node(head, 1);

	for (int i = 2; i < 100; i++)
	{
		if (i %30)
		{
			append_node(head, i);
		}
		append_node(head, i);
	}

	print_singlyList(head);
	
	return 0;
}