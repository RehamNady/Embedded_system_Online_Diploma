/*
 * linked_list.c
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */
#include "linked_list.h"
#include <string.h>

void fill_the_record(Snode*new_node){
	char temp_text[40];
	Dprintf("Enter ID: ");
	gets(temp_text);
	new_node->sdata.ID=atoi(temp_text);
	Dprintf("Enter full name : ");
	gets(new_node->sdata.name);
	Dprintf("Enter height : ");
	gets(temp_text);
	new_node->sdata.height=atof(temp_text);

}
void print_Data(Snode* node,int count){
	Dprintf("record number %d \n",count);
	Dprintf("ID : %d\n",node->sdata.ID);
	Dprintf("Name : %s\n",node->sdata.name);
	Dprintf("ID : %f\n",node->sdata.height);
	Dprintf("\n====================================================\n");
}
Snode* Add_node(Snode* gp_firstnode){
	Snode *last_node=NULL;
	Snode *new_node=NULL;
	new_node = (Snode*)malloc(sizeof(Snode));

	if(!new_node){
		Dprintf("cannot add student,heap is full\n");
		return gp_firstnode;
	}

	if(gp_firstnode== NULL){
		gp_firstnode=new_node;
	}
	else{
		last_node=gp_firstnode;
		while(last_node->p_nextnode){
			last_node=last_node->p_nextnode;
		}

		last_node->p_nextnode=new_node;
	}
	fill_the_record(new_node);
	new_node->p_nextnode=NULL;
	Dprintf("Add student is Done\n");
	return gp_firstnode;
}
Snode* delete_node(Snode* gp_firstnode){
	int ID;
	Dprintf("Enter student id to be deleted\n");
	scanf("%d",&ID);
	if(gp_firstnode==NULL){
		Dprintf("list is Empty\n");
		return gp_firstnode;
	}
	Snode* previous_node=NULL;
	Snode *current_node=gp_firstnode;

	while(current_node){
		if(current_node->sdata.ID==ID)
		{
			if(!previous_node){
				gp_firstnode=current_node->p_nextnode;
			}
			else{
				previous_node->p_nextnode=current_node->p_nextnode;
			}
			free(current_node);
			Dprintf("Student is deleted\n");
			return gp_firstnode;
		}
		previous_node=current_node;
		current_node=current_node->p_nextnode;
	}
	Dprintf("cannot find student\n");
	return gp_firstnode;
}
Snode* delete_all(Snode* gp_firstnode){
	Snode* Current_node = gp_firstnode;
	if(gp_firstnode==NULL){
		Dprintf("list is Empty\n");
		return gp_firstnode;
	}

	while(Current_node){
		Snode* temp_node = Current_node;
		Current_node=Current_node->p_nextnode;
		free(temp_node);
	}
	gp_firstnode=NULL;
	Dprintf("Students are deleted\n");
	return gp_firstnode;
}
int view_nodes(Snode* gp_firstnode){
	if(!gp_firstnode){
		Dprintf("list is Empty\n");
		return 0;
	}
	Snode* Current_node = gp_firstnode;
	int count=1;
	while(Current_node){
		print_Data(Current_node,count);
		Current_node=Current_node->p_nextnode;
		count++;
	}
	return 1;
}

int GetNth(Snode* gp_firstnode,int n){
	int count =0;
	if(!gp_firstnode){
		Dprintf("Empty list\n");
		return 0;
	}
	Snode* current_node=gp_firstnode;
	while(current_node){
		if(count==n)
		{
			print_Data( current_node,count+1);
			break;
		}
		else
		{
			current_node=current_node->p_nextnode;
			count++;
		}
	}
	if(count<=n && !current_node &&gp_firstnode)
		Dprintf("this index doesn't exist\n");
	return 1;
}
int GetNth_from_end(Snode* gp_firstnode,int n){
	int count =0,len=0;
	if(!gp_firstnode){
		Dprintf("Empty list\n");
		return 0;
	}
	Snode *base_ptr,*ref_ptr;
	base_ptr=gp_firstnode;
	ref_ptr=gp_firstnode;
	while(count<n && ref_ptr){
		ref_ptr=ref_ptr->p_nextnode;
		count++;
		len++;
	}
	while(ref_ptr){
		len++;
		base_ptr=base_ptr->p_nextnode;
		ref_ptr=ref_ptr->p_nextnode;
	}
	if(!ref_ptr && count==n){
		print_Data(base_ptr, len-n+1);
	}
	if(!ref_ptr && count!=n && gp_firstnode){
		Dprintf("this index doesn't exist\n");
	}
	return 1;

}
int len_list(Snode* gp_firstnode){
	int len=0;
	if(!gp_firstnode)
		return 0;
	len++;
	return (len+len_list(gp_firstnode->p_nextnode));

}
int middle_list(Snode* gp_firstnode){
	int count=0;
	if(!gp_firstnode){
		Dprintf("Empty list\n");
		return 0;
	}
	Snode *slow_ptr,*fast_ptr;
	fast_ptr=gp_firstnode;
	slow_ptr=gp_firstnode;
	while(fast_ptr->p_nextnode){
		slow_ptr=slow_ptr->p_nextnode;
		count++;
		if(fast_ptr->p_nextnode){
			fast_ptr=fast_ptr->p_nextnode->p_nextnode;
		}
		if(!fast_ptr)
			break;

	}
	print_Data(slow_ptr, count+1);
	return 1;
}
int Detect_loop(Snode* gp_firstnode){
	if(!gp_firstnode){
		Dprintf("Empty list\n");
		return 0;
	}
	Snode *slow_ptr,*fast_ptr;
	slow_ptr=gp_firstnode;
	fast_ptr=gp_firstnode;
	while(fast_ptr){
		slow_ptr=slow_ptr->p_nextnode;
		fast_ptr=fast_ptr->p_nextnode->p_nextnode;
		if(fast_ptr==slow_ptr){
			Dprintf("there is a loop\n");
			return 1;
		}
	}
	Dprintf("there is no loop\n");
	return 0;

}
Snode* Reverse_list(Snode* gp_firstnode){

	if(!gp_firstnode){
		Dprintf("Empty list\n");
		return NULL;
	}
	Snode *last_ptr,*curr_ptr,*next_ptr;
	last_ptr=NULL;
	curr_ptr=gp_firstnode;
	while(curr_ptr){
		next_ptr=curr_ptr->p_nextnode;
		curr_ptr->p_nextnode=last_ptr;
		last_ptr=curr_ptr;
		curr_ptr=next_ptr;
	}
	gp_firstnode=last_ptr;
	return gp_firstnode;
}
Snode* Reverse_each_k(Snode* gp_firstnode,int n){
	int count =0;
	if(!gp_firstnode){
		Dprintf("Empty list\n");
		return NULL;
	}
	Snode *last_ptr,*curr_ptr,*next_ptr;
	last_ptr=NULL;
	curr_ptr=gp_firstnode;
	while(curr_ptr && count<n){
		next_ptr=curr_ptr->p_nextnode;
		curr_ptr->p_nextnode=last_ptr;
		last_ptr=curr_ptr;
		curr_ptr=next_ptr;
		count++;
	}
	if(curr_ptr){
		gp_firstnode->p_nextnode=Reverse_each_k(curr_ptr, n);
	}
	return last_ptr;

}
