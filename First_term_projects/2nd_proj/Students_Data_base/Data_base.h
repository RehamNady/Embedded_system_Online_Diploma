/*
 * Data_base.h
 *
 *  Created on: Jan 24, 2022
 *      Author: reham
 */

#ifndef DATA_BASE_H_
#define DATA_BASE_H_
#include"fifo.h"

#define Courses_number 5

void add_student_file(FIFO_BUF_t* fifo_buffer);
void add_student(FIFO_BUF_t* fifo_buffer);
void find_details_rl(FIFO_BUF_t* fifo_buffer);
void find_details_fname(FIFO_BUF_t* fifo_buffer);
void find_details_courses(FIFO_BUF_t* fifo_buffer);
void total_numb_students(FIFO_BUF_t* fifo_buffer);
void del_student(FIFO_BUF_t* fifo_buffer);
void update_student(FIFO_BUF_t* fifo_buffer);
void show_students(FIFO_BUF_t* fifo_buffer);

#endif /* DATA_BASE_H_ */
