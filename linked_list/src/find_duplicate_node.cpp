/***
Finding Duplicate from an unsorted linked list

*/

#include <stdio.h>
#include <iostream>
#include <map>
#include "../inc/singly_list.h"

using namespace std;

void delete_dups(SinglyNode * node)
{
	std::map<int, bool> values;
	SinglyNode * previous = NULL;

	while(node)
	{
		#if 1
		if (values.find(node->data) != values.end())
		{
			std::cout << "duplicate node found " << node->data << "\n";
			SinglyNode * duplicate = node;
			previous->next = node->next;
			delete duplicate;
		}
		else
		#endif
		{
			values[node->data] = true;
			previous = node;
		}

		node = node->next;
	}
}


int main(int argc, char ** argV)
{
	SinglyNode * head = NULL;

	head = append_node(head, 1);

	for (int i = 2; i < 100; i++)
	{
		if (i %5 == 0)
		{
			append_node(head, i);
		}
		append_node(head, i);
	}
	cout << "Before removing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	print_singlyList(head);

	delete_dups(head);

	cout << "After removing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	print_singlyList(head);
	
	return 0;
}