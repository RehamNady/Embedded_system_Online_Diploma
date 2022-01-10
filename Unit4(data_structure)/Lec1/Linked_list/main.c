/*
 * main.c
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */
#include "linked_list.h"
Snode* gp_firstnode=NULL;
int main(){

	while(1){
		int select=0,n,len;
		Snode* gp_reverse,*gp_reverse_k;
		Dprintf("Choose on the following options\n");
		Dprintf("1: Add student \n");
		Dprintf("2: Delete student \n");
		Dprintf("3: view students \n");
		Dprintf("4: Delete all \n");
		Dprintf("5: Get Nth index \n");
		Dprintf("6: Get length of linked list \n");
		Dprintf("7: Get Nth index from end \n");
		Dprintf("8: Get middle list \n");
		Dprintf("9: Detect loop \n");
		Dprintf("10: reverse list\n");
		Dprintf("11: reverse each k number\n");
		Dprintf("12: close this \n");
		Dprintf("====================\n");
		Dprintf("Enter option number : ");
		scanf("%d",&select);

		switch(select){
		case 1:
			gp_firstnode=Add_node(gp_firstnode);
			break;

		case 2:
			gp_firstnode = delete_node(gp_firstnode);

			break;
		case 3:
			view_nodes(gp_firstnode);
			break;
		case 4:
			gp_firstnode=delete_all(gp_firstnode);
			break;
		case 5:
			Dprintf("Enter index");
			scanf("%d",&n);
			GetNth(gp_firstnode,n);
			break;
		case 6:
			len=len_list(gp_firstnode);
			Dprintf("length of a linked list = %d\n",len);
			break;
		case 7:
			Dprintf("Enter index");
			scanf("%d",&n);
			GetNth_from_end(gp_firstnode, n);
			break;
		case 8:
			middle_list(gp_firstnode);
			break;
		case 9:
			Detect_loop(gp_firstnode);
			break;
		case 10:
			gp_reverse=Reverse_list(gp_firstnode);
			view_nodes(gp_reverse);
			break;
		case 11:
			Dprintf("Enter index");
			scanf("%d",&n);
			gp_reverse_k=Reverse_each_k(gp_firstnode, n);
			view_nodes(gp_reverse_k);
			break;
		case 12:
			return 0;
			break;
		default:
			Dprintf("wrong option\n");
			break;
		}
		Dprintf("===========================================\n");
	}

	return 0;
}
