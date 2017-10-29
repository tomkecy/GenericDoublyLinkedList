#pragma once
#include "CList.h"
#define I_EXIT 0
#define I_ADD_HEAD 1
#define I_ADD_TAIL 2
#define I_ADD_AT_INDEX 3
#define I_GET_ELEMENT 4
#define I_GET_INDEX 5
#define I_REMOVE_HEAD 6
#define I_REMOVE_TAIL 7
#define I_REMOVE_AT 8
#define I_PRINT_SIZE 9
#define I_PRINT_LIST 10
#define I_PRINT_STRING_LIST 11


class CUserInterface
{
private:
	CList<int> c_int_list;
	bool b_menu_loop_condition;

	void v_show_menu();
	int i_get_user_input();
	void v_print_size();
	void v_add_head();
	void v_add_tail();
	void v_add_at_index();
	void v_print_list();
	void v_get_element();
	void v_get_index();
	void v_remove_head();
	void v_remove_tail();
	void v_remove_at_index();
	void v_print_string_list();
	void v_print_menu();

public:
	CUserInterface();
	~CUserInterface();

	void vRun();
};//class CUserInterface

