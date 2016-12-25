#ifndef __SINGLY_LIST_H__
#define __SINGLY_LIST_H__

typedef struct _SinglyNode
{
	int data;
	struct _SinglyNode * next;
} SinglyNode;

extern SinglyNode * get_newNode(int data);
extern SinglyNode * append_node(SinglyNode * head, int data);
extern void print_singlyList(SinglyNode * node);

#endif /**__SINGLY_LIST_H__ */