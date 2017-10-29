#include "CUserInterface.h"
#include <iostream>


CUserInterface::CUserInterface()
{
	b_menu_loop_condition = false;
}//CUserInterface::CUserInterface()

CUserInterface::~CUserInterface()
{
}//CUserInterface::~CUserInterface()

void CUserInterface::vRun()
{
	b_menu_loop_condition = true;
	while (b_menu_loop_condition)
	{
		v_show_menu();
	}
}//void CUserInterface::vRun()

void CUserInterface::v_print_menu()
{
	std::cout << std::endl << "MENU" << std::endl;
	std::cout << "1. Add head" << std::endl;
	std::cout << "2. Add tail" << std::endl;
	std::cout << "3. Add at index" << std::endl;
	std::cout << "4. Get element" << std::endl;
	std::cout << "5. Get index of element" << std::endl;
	std::cout << "6. Remove head" << std::endl;
	std::cout << "7. Remove tail" << std::endl;
	std::cout << "8. Remove at index" << std::endl;
	std::cout << "9. Print size" << std::endl;
	std::cout << "10. Print list" << std::endl;
	std::cout << "11. To string list" << std::endl;
	std::cout << "0. Exit" << std::endl;
}//void CUserInterface::v_print_menu()

void CUserInterface::v_show_menu()
{
	v_print_menu();
	int i_user_input = i_get_user_input();

	switch (i_user_input)
	{
	case I_ADD_HEAD:
		v_add_head();
		break;
	case I_ADD_TAIL:
		v_add_tail();
		break;
	case I_ADD_AT_INDEX:
		v_add_at_index();
		break;
	case I_GET_ELEMENT:
		v_get_element();
		break;
	case I_GET_INDEX:
		v_get_index();
		break;
	case I_REMOVE_HEAD:
		v_remove_head();
		break;
	case I_REMOVE_TAIL:
		v_remove_tail();
		break;
	case I_REMOVE_AT:
		v_remove_at_index();
		break;
	case I_PRINT_SIZE:
		v_print_size();
		break;
	case I_PRINT_LIST:
		v_print_list();
		break;
	case I_PRINT_STRING_LIST:
		v_print_string_list();
		break;
	case I_EXIT:
		b_menu_loop_condition = false;
		break;
	default:
		std::cout << "Wrong input!" << std::endl;
	}

}//void CUserInterface::v_show_menu()


int CUserInterface::i_get_user_input()
{
	int i_user_input;
	std::cin >> i_user_input;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "You have entered wrong input" << std::endl << "Try again: ";
		std::cin >> i_user_input;
	}

	return i_user_input;
}//int CUI::i_get_user_input()

void CUserInterface::v_add_head()
{
	std::cout << "Enter value: ";
	c_int_list.vAddHead(i_get_user_input());
}//void CUserInterface::v_add_head()

void CUserInterface::v_add_tail()
{
	std::cout << "Enter value: ";
	c_int_list.vAddTail(i_get_user_input());
}//void CUserInterface::v_add_tail()

void CUserInterface::v_add_at_index()
{
	int i_index;
	int i_value;
	
	std::cout << "Enter value: ";
	i_value = i_get_user_input();
	std::cout << "Enter index: ";
	i_index = i_get_user_input();

	if(c_int_list.bAdd(i_value, i_index))
	{
		std::cout << "Successfully added element" << std::endl;
	}
	else
	{
		std::cout << "Incorrect index" << std::endl;
	}
}//void CUserInterface::v_add_at_index()


void CUserInterface::v_get_element()
{
	std::cout << "Enter index: ";
	int i_value = c_int_list.cGetValue(i_get_user_input());
	
	if(i_value == NULL)
	{
		std::cout << "Incorrect index!" << std::endl;
	}
	else
	{
		std::cout << "Value: " << i_value << std::endl;
	}
}//void CUserInterface::v_get_element()

void CUserInterface::v_get_index()
{
	int i_index;

	std::cout << "Enter value: ";
	i_index = c_int_list.iGetIndex(i_get_user_input());

	if(i_index == -1)
	{
		std::cout << "List doesn't contain entered value" << std::endl;
	}
	else
	{
		std::cout << "Value index: " << i_index << std::endl;
	}	
}//void CUserInterface::v_get_index()

void CUserInterface::v_remove_head()
{
	if(c_int_list.bRemoveHead())
	{
		std::cout << "Successfully deleted list head";
	}
	else
	{
		std::cout << "Error: List is empty!";
	}

}//void CUserInterface::v_remove_head()

void CUserInterface::v_remove_tail()
{
	if (c_int_list.bRemoveTail())
	{
		std::cout << "Successfully deleted list tail";
	}
	else
	{
		std::cout << "Error: List is empty!";
	}
}//void CUserInterface::v_remove_tail()


void CUserInterface::v_remove_at_index()
{
	int i_index;
	std::cout << "Enter index: ";
	i_index = i_get_user_input();

	if (c_int_list.bRemove(i_index))
	{
		std::cout << "Successfully deleted list tail" << std::endl;
	}
	else
	{
		if(c_int_list.bIsEmpty())
		{
			std::cout << "Error: List is empty!"<<std::endl;
		}
		else
		{
			std::cout << "Incorrect index!" << std::endl;
		}
	}
}//void CUserInterface::v_remove_at_index()


void CUserInterface::v_print_size()
{
	std::cout << "List size: " << c_int_list.iGetSize() << std::endl;
}//void CUserInterface::v_print_size()

void CUserInterface::v_print_list()
{
	std::cout << "List: " << c_int_list.sToString() << std::endl;
}//void CUserInterface::v_print_list()

void CUserInterface::v_print_string_list()
{
	CList<std::string> *pc_string_list = c_int_list.pcToString();
	std::cout << "String list: " << pc_string_list->sToString() << std::endl;
	delete pc_string_list;
}//void CUserInterface::v_print_string_list()