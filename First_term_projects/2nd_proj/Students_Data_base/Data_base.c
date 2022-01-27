/*
 * Data_base.c
 *
 *  Created on: Jan 24, 2022
 *      Author: reham
 */

#include"Data_base.h"
void print_stud_data_without_Courses(element_type * data){
	Dprintf("The First name is %s \n",data->fname);
	Dprintf("The Last name is %s \n",data->lname);
	Dprintf("The Roll Number is %d\n",data->roll);
	Dprintf("The GPA is %f \n",data->GPA);
}

void print_stud_data(element_type * data){
	int i;
	print_stud_data_without_Courses(data);
	Dprintf("Courses recorded is :\n");
	for(i=0;i<Courses_number;i++){
		Dprintf("%d- The Course ID is %d\n",i+1,data->cid[i]);
	}
}


int check_unique(FIFO_BUF_t* fifo_buffer,int r){
	int i;
	element_type* p_temp = fifo_buffer->tail;
	for(i=0;i<fifo_buffer->count;i++){
		if(r==p_temp->roll){
			Dprintf("sorry this ID is exist\n");
			return 0;
		}
		p_temp++;
	}
	return 1;
}
void add_student_file(FIFO_BUF_t* fifo_buffer){
	FILE* ptr;
	Sdata_t data_temp;
	FIFO_Status status_temp;
	ptr = fopen("test.txt","r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
	while (fscanf(ptr, "%d %s %s %f %d %d %d %d %d",&data_temp.roll,data_temp.fname,data_temp.lname,&data_temp.GPA,&data_temp.cid[0],&data_temp.cid[1],&data_temp.cid[2],&data_temp.cid[3],&data_temp.cid[4])){
		Dprintf("\n");
		if(!check_unique(fifo_buffer, data_temp.roll)){
				continue ;
			}
		status_temp = FIFO_enqueue(fifo_buffer, data_temp);
		if(status_temp==FIFO_no_error){
			Dprintf("[INFO] Student Details is added successfully\n");
			Dprintf("\n----------------------\n");
			total_numb_students(fifo_buffer);
		}
		else if(status_temp == FIFO_full){
			Dprintf("data base is full \n");
		}
		else{
			Dprintf("data base not initialize\n");
		}

	}

}
void add_student(FIFO_BUF_t* fifo_buffer){
	char d[50];
	int i,j;
	FIFO_Status status_temp;
	Sdata_t data_temp;
	Dprintf("Enter the Roll Number");
	gets(d);
	if(!check_unique(fifo_buffer, atoi(d))){
		return ;
	}
	data_temp.roll=atoi(d);
	Dprintf("Enter the First Name");
	gets(data_temp.fname);
	Dprintf("Enter the Second Name");
	gets(data_temp.lname);
	Dprintf("Enter the GPA you obtained ");
	gets(d);
	data_temp.GPA=atof(d);
	Dprintf("Enter the course ID of each course \n");
	for(i=0;i<Courses_number;i++){
		Dprintf("Course %d id:",i+1);
		gets(d);
		for(j=0;j<i;j++){
			if (atoi(d)==data_temp.cid[j]){
				Dprintf("course id is recorded before\n ");
				i--;
				break;
			}
			else{
				data_temp.cid[i]=atoi(d);
			}
		}
		data_temp.cid[i]=atoi(d);
	}
	status_temp = FIFO_enqueue(fifo_buffer, data_temp);
	if(status_temp==FIFO_no_error){
		Dprintf("[INFO] Student Details is added successfully\n");
		Dprintf("\n----------------------\n");
		total_numb_students(fifo_buffer);
	}
	else if(status_temp == FIFO_full){
		Dprintf("data base is full \n");
	}
	else{
		Dprintf("data base not initialize\n");
	}


}
void find_details_rl(FIFO_BUF_t* fifo_buffer){
	int i,r;
	element_type* p_temp = fifo_buffer->tail;

	if(FIFO_is_exist(fifo_buffer)== FIFO_Null){
		return;
	}

	Dprintf("Enter the Roll Number of the student:\n");
	scanf("%d",&r);
	for(i=0;i<fifo_buffer->count;i++){
		if(r == p_temp->roll){
			Dprintf("The Students Details are\n ");
			print_stud_data(p_temp);
			return;
		}
		p_temp++;
	}
	Dprintf("[ERORR] Roll Number %d not found\n ",r);
}
void find_details_fname(FIFO_BUF_t* fifo_buffer){
	int i,f=0;
	char name [50];
	element_type* p_temp = fifo_buffer->tail;
	if(FIFO_is_exist(fifo_buffer)== FIFO_Null){
		return;
	}
	Dprintf("Enter the first name of the student:\n");
	gets(name);
	for(i=0;i<fifo_buffer->count;i++){
		if(! stricmp(name,p_temp->fname)){
			f++;
			Dprintf("%d The Student Details are\n ",f);
			print_stud_data(p_temp);
		}
		p_temp++;
	}
	if(f==0){
		Dprintf("[ERORR] this name %s not found\n",name);
	}


}
void find_details_courses(FIFO_BUF_t* fifo_buffer){
	int i,f=0,id,j;
	element_type* p_temp = fifo_buffer->tail;
	if(FIFO_is_exist(fifo_buffer)== FIFO_Null){
		return;
	}
	Dprintf("Enter the ID of the course:\n");
	scanf("%d",&id);
	for(i=0;i<fifo_buffer->count;i++){
		for(j=0;j<Courses_number;j++){
			if(id==p_temp->cid[j]){
				f++;
				Dprintf("\n%d The Student Details are\n ",f);
				print_stud_data_without_Courses(p_temp);
				break;
			}
		}
		p_temp++;
	}
	if(f==0){
		Dprintf("[ERORR] Course ID %d not found\n",id);
	}

}
void total_numb_students(FIFO_BUF_t* fifo_buffer){
	if(FIFO_is_exist(fifo_buffer)== FIFO_Null){
		return;
	}
	Dprintf("[INFO] the total number of students is %d\n",fifo_buffer->count);
	Dprintf("[INFO] you can add up to %d\n",fifo_buffer->length);
	Dprintf("[INFO] you can add %d more students\n",fifo_buffer->length - fifo_buffer->count);

};
void del_student(FIFO_BUF_t* fifo_buffer){
	element_type *p_curr,*p_next;
	int i,r,f=0;

	if(FIFO_is_exist(fifo_buffer)== FIFO_Null){
		return;
	}
	p_curr=fifo_buffer->tail;
	Dprintf("Enter the Roll Number of the student:\n");
	scanf("%d",&r);
	for(i=0;i<fifo_buffer->count;i++){
		if(r == p_curr->roll){
			f=1;
			break;
		}
		p_curr++;
	}
	if(!f){
		Dprintf("[ERORR] Roll Number %d not found\n ",r);
		return;
	}
	p_next = p_curr+1;

	for(i;i<fifo_buffer->count;i++){
		*p_curr = *p_next;
		p_curr = p_next;
		p_next = p_next+1;
	}
	fifo_buffer->Head--;
	fifo_buffer->count--;

}
void update_student(FIFO_BUF_t* fifo_buffer){
	int r,ch,i,c_ch;
	char temp[30];
	element_type* p_temp=fifo_buffer->tail;
	element_type* P_check=NULL;
	Dprintf("The Roll Number to update the entry :");
	scanf("%d",&r);
	for(i=0;i<fifo_buffer->count;i++){
		if(r == p_temp->roll){
			P_check=p_temp;
			break;
		}
		p_temp++;
	}
	if(P_check == NULL){
		Dprintf("[ERORR] Roll Number %d not found\n ",r);
		return;
	}
	Dprintf("Choose data want to update:\n");
	Dprintf("1. first name\n");
	Dprintf("2. second name\n");
	Dprintf("3. Roll Number\n");
	Dprintf("4. GPA\n");
	Dprintf("5. Courses\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:
		Dprintf("Enter the new first name: ");
		gets(temp);
		strcpy(P_check->fname,temp);
		break;
	case 2:
		Dprintf("Enter the new Last name: ");
		gets(temp);
		strcpy(P_check->lname,temp);
		break;
	case 3:
		Dprintf("Enter the new Roll number: ");
		gets(temp);
		P_check->roll=atoi(temp);
		break;
	case 4:
		Dprintf("Enter the new GPA: ");
		gets(temp);
		P_check->GPA=atof(temp);
		break;
	case 5:
		Dprintf("choose course id want to change \n");
		Dprintf("1- to update course id = %d\n",P_check->cid[0]);
		Dprintf("2- to update course id = %d\n",P_check->cid[1]);
		Dprintf("3- to update course id = %d\n",P_check->cid[2]);
		Dprintf("4- to update course id = %d\n",P_check->cid[3]);
		Dprintf("5- to update course id = %d\n",P_check->cid[4]);
		c_ch=atoi(gets(temp));
		Dprintf("enter the new course id : \n");
		gets(temp);
		switch(c_ch){
		case 1:
			P_check->cid[0]=atoi(temp);
			break;
		case 2:
			P_check->cid[1]=atoi(temp);
			break;
		case 3:
			P_check->cid[2]=atoi(temp);
			break;
		case 4:
			P_check->cid[3]=atoi(temp);
			break;
		case 5:
			P_check->cid[4]=atoi(temp);
			break;
		default:
			Dprintf("sorry this id course not recorded before\n");
			return ;
			break;
		}
		break;
		default:
			Dprintf("please choose from list\n");
			return ;
			break;

	}
	Dprintf("[INFO] UPDATED SUCESSFULLY\n");
}
void show_students(FIFO_BUF_t* fifo_buffer){
	int i=0;
	element_type* p_temp = fifo_buffer->tail;
	if(FIFO_is_exist(fifo_buffer)== FIFO_Null){
		return;
	}
	Dprintf("data of Students are recorded in this base :\n");
	for(i=0;i<fifo_buffer->count;i++){
		Dprintf("----------------\n");
		Dprintf("%d- ",i+1);
		print_stud_data(p_temp);
		p_temp++;

	}
}

