/*
 * linked_list.h
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>


#define Dprintf(...)  {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}

typedef struct{
	int ID;
	char name[40];
	float height;
}Sdata_t;

typedef struct Snode{
	Sdata_t sdata;
	struct Snode* p_nextnode;
}Snode;


void fill_the_record(Snode*new_node);
void print_Data(Snode* node,int count);

Snode* Add_node(Snode* gp_firstnode);
Snode* delete_node(Snode* gp_firstnode);
Snode* delete_all(Snode* gp_firstnode);
int view_nodes(Snode* gp_firstnode);

int GetNth(Snode* gp_firstnode,int n);
int len_list(Snode* gp_firstnode);
int GetNth_from_end(Snode* gp_firstnode,int n);
int middle_list(Snode* gp_firstnode);
int Detect_loop(Snode* gp_firstnode);
Snode* Reverse_list(Snode* gp_firstnode);
Snode* Reverse_each_k(Snode* gp_firstnode,int n);
#endif /* LINKED_LIST_H_ */
