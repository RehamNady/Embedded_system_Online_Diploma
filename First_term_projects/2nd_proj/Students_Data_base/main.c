/*
 * main.c
 *
 *  Created on: Jan 24, 2022
 *      Author: reham
 */
#include"Data_base.h"
element_type buffer[50];

int main(){
	unsigned int ch;
	FIFO_BUF_t base_buff;
	FIFO_init(&base_buff, sizeof(buffer)/sizeof(element_type), buffer);

	Dprintf("welcome to the student management system\n");

	while(1){
		Dprintf("\n choose the task that you want to perform\n");
		Dprintf("1. Add the student Details from text file\n");
		Dprintf("2. Add the student Details manually\n");
		Dprintf("3. Find the student Details by Roll Number\n");
		Dprintf("4. Find the student Details by First Name\n");
		Dprintf("5. Find the student Details by Course ID \n");
		Dprintf("6. Find the Total number of students \n");
		Dprintf("7. Delete the Students Details by Roll number\n");
		Dprintf("8. Update the Students Details by Roll number\n");
		Dprintf("9. Show all information \n");
		Dprintf("10. To Exit\n");
		Dprintf("----------------------\n");
		Dprintf("Enter your choice to perform the task :");
		scanf("%d",&ch);

		switch(ch){
		case 1:
			add_student_file(&base_buff);
			break;
		case 2:
			add_student(&base_buff);
			break;
		case 3:
			find_details_rl(&base_buff);
			break;
		case 4:
			find_details_fname(&base_buff);
			break;
		case 5:
			find_details_courses(&base_buff);
			break;
		case 6:
			total_numb_students(&base_buff);
			break;
		case 7:
			del_student(&base_buff);
			break;

		case 8:
			update_student(&base_buff);
			break;
		case 9:
			show_students(&base_buff);
			break;
		case 10:
			return 0;

		}


		Dprintf("===============================\n");
	}
	return 0;
}

