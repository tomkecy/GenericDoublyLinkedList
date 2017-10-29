#pragma once
#include <string>
#include <cstddef>

template <class T>
class CList
{
private:
	class CNode
	{
	private:
		CNode *pc_previous_node, *pc_next_node;
		T c_value;

		CNode(T cElement)
		{
			c_value = cElement;
			pc_next_node = NULL;
			pc_previous_node = NULL;
		}//CNode(T cElement)

		CNode(T cElement, CNode *pc_previous_node, CNode *pc_next_node)
		{
			c_value = cElement;
			this->pc_next_node = pc_next_node;
			this->pc_previous_node = pc_previous_node;
		}//CNode(T cElement, CNode *pc_previous_node, CNode *pc_next_node)

		~CNode()
		{
			if(pc_next_node!=NULL)
			{
				delete pc_next_node;
			}
		}//~CNode()

	public:
		friend class CList;
	};//class CNode

	CNode* pc_list_head;
	CNode* pc_list_tail;
	int i_size;
	void v_add(T cElement, int iIndex);
	T c_get_value(int iIndex);
	void v_remove(int iIndex);

public:
	CList();
	~CList();
	
	bool bAdd(T cElement, int iIndex);
	void vAddHead(T cElement);
	void vAddTail(T cElement);
	
	T cGetValue(int iIndex);

	int iGetIndex(T cElement);
	bool bRemove(int iIndex);
	bool bRemoveHead();
	bool bRemoveTail();
	

	int iGetSize();
	bool bIsEmpty();

	inline std::string sToString();

	inline CList<std::string> *pcToString();
	

};//class CList


template<class T>
CList<T>::CList()
{
	i_size = 0;
	pc_list_head = NULL;
	pc_list_tail = NULL;

}//CList<T>::CList()

template<class T>
CList<T>::~CList()
{
	if(pc_list_head!=NULL)
	{
		delete pc_list_head;
	}
}//CList<T>::~CList()



template<class T>
bool CList<T>::bAdd(T cElement, int iIndex)
{
	if(iIndex<0 || iIndex>i_size)
	{
		return false;
	}

	if(iIndex==0)
	{
		vAddHead(cElement);
	}
	else if (iIndex == i_size)
	{
		vAddTail(cElement);
	}
	else 
	{
		v_add(cElement, iIndex);
	}

	return true;
}//bool CList<T>::bAdd(T cElement)

template <class T>
void CList<T>::v_add(T cElement, int iIndex)
{
	CNode *pc_current_node;
	if (iIndex < (i_size - 1) / 2)
	{
		pc_current_node = pc_list_head;
		for (int ii = 0; ii<iIndex; ii++)
		{
			pc_current_node = pc_current_node->pc_next_node;
		}
	}
	else
	{
		pc_current_node = pc_list_tail;
		for (int ii = 0; ii< i_size - iIndex; ii++)
		{
			pc_current_node = pc_current_node->pc_previous_node;
		}
	}

	CNode *pc_new_node = new CNode(cElement, pc_current_node, pc_current_node->pc_next_node);
	pc_current_node->pc_next_node = pc_new_node;
	pc_new_node->pc_next_node->pc_previous_node = pc_new_node;
	i_size++;
}//void CList<T>::v_add(T cElement, int iIndex)

template <class T>
void CList<T>::vAddHead(T cElement)
{
	CNode *pc_new_head = new CNode(cElement, NULL, pc_list_head);
	if(pc_list_head == NULL)
	{
		pc_list_tail = pc_new_head;
	}
	else
	{
		pc_list_head->pc_previous_node = pc_new_head;
	}
	pc_list_head = pc_new_head;

	i_size++;
	
}//void CList<T>::vAddHead(T cElement)


template <class T>
void CList<T>::vAddTail(T cElement)
{
	CNode *pc_new_tail = new CNode(cElement, pc_list_tail, NULL);
	if (pc_list_tail == NULL)
	{
		pc_list_head = pc_new_tail;
	}
	else
	{
		pc_list_tail->pc_next_node = pc_new_tail;
	}
	pc_list_tail = pc_new_tail;

	i_size++;
}//void CList<T>::vAddTail(T cElement)




template<class T>
T CList<T>::cGetValue(int iIndex)
{
	if (iIndex <= -1 || iIndex >= i_size) 
	{
		return NULL;
	}
	else if (iIndex == 0) 
	{
		return pc_list_head->c_value;
	}//else if (iIndex == 0) 
	else if (iIndex == (i_size - 1)) 
	{
		return pc_list_tail->c_value;
	}
	else
	{
		return c_get_value(iIndex);
	}

}//T CList<T>::cGetValue(int iIndex)

template <class T>
T CList<T>::c_get_value(int iIndex)
{
	CNode *pc_current_node;
	if (iIndex < (i_size - 1) / 2)
	{
		pc_current_node = pc_list_head;
		for (int ii = 0; ii<iIndex; ii++)
		{
			pc_current_node = pc_current_node->pc_next_node;
		}
	}
	else
	{
		pc_current_node = pc_list_tail;
		for (int ii = 0; ii< (i_size - iIndex - 1); ii++)
		{
			pc_current_node = pc_current_node->pc_previous_node;
		}
	}
	return pc_current_node->c_value;
}//T CList<T>::c_get_value(int iIndex)

template<class T>
int CList<T>::iGetIndex(T cElement)
{
	CNode* pc_current_node = pc_list_head;
	for(int ii=0; ii<i_size; ii++)
	{
		if(pc_current_node->c_value == cElement)
		{
			return ii;
		}
		pc_current_node = pc_current_node->pc_next_node;
	}

	return -1;
}//int CList<T>::iGetIndex(T cElement)


template <class T>
void CList<T>::v_remove(int iIndex)
{
	CNode *pc_current_node;
	if (iIndex < (i_size - 1) / 2)
	{
		pc_current_node = pc_list_head;
		for (int ii = 0; ii<iIndex; ii++)
		{
			pc_current_node = pc_current_node->pc_next_node;
		}
	}
	else
	{
		pc_current_node = pc_list_tail;
		for (int ii = 0; ii< i_size - iIndex; ii++)
		{
			pc_current_node = pc_current_node->pc_previous_node;
		}
	}

	pc_current_node->pc_previous_node->pc_next_node = pc_current_node->pc_next_node;
	pc_current_node->pc_next_node->pc_previous_node = pc_current_node->pc_previous_node;
	pc_current_node->pc_previous_node = NULL;
	pc_current_node->pc_next_node = NULL;
	delete pc_current_node;
	i_size--;
}//void CList<T>::v_remove(int iIndex)

template<class T>
bool CList<T>::bRemove(int iIndex)
{
	if(iIndex<0 || iIndex>=i_size)
	{
		return false;
	}
	else if(iIndex==0)
	{
		bRemoveHead();
	}
	else if(iIndex==i_size-1)
	{
		bRemoveTail();
	}
	else
	{
		v_remove(iIndex);
	}
	return true;

}//bool CList<T>::bRemove(int iIndex)


template<class T>
bool CList<T>::bRemoveHead()
{
	if(pc_list_head != NULL && i_size>= 2)
	{
		CNode* pc_current_head = pc_list_head;
		pc_list_head = pc_list_head->pc_next_node;
		pc_current_head->pc_next_node = NULL;
		delete pc_current_head;
		i_size--;
		return true;
	}
	else if(pc_list_head!= NULL && i_size == 1)
	{
		delete pc_list_head;
		pc_list_head = NULL;
		pc_list_tail = NULL;
		i_size--;
		return true;
	}
	return false;

}//bool CList<T>::bRemoveHead()

template<class T>
bool CList<T>::bRemoveTail()
{
	if (pc_list_tail != NULL && i_size >= 2)
	{
		CNode* pc_current_tail = pc_list_tail;
		pc_list_tail = pc_list_tail->pc_previous_node;
		pc_current_tail->pc_previous_node = NULL;
		delete pc_current_tail;
		i_size--;
		return true;
	}
	else if (pc_list_tail != NULL && i_size == 1)
	{
		delete pc_list_head;
		pc_list_head = NULL;
		pc_list_tail = NULL;
		i_size--;
		return true;
	}
	return false;
}//bool CList<T>::bRemoveTail()

template <class T>
int CList<T>::iGetSize()
{
	return i_size;
}//int CList<T>::iGetSize()

template<class T>
bool CList<T>::bIsEmpty()
{
	return i_size == 0;
}//bool CList<T>::bIsEmpty()

template<class T>
std::string CList<T>::sToString()
{
	std::string s_result = "";
	for(int ii=0; ii<i_size; ii++)
	{
		T c_current_value = cGetValue(ii);
		s_result += std::to_string(c_current_value) + ", ";
	}
	return s_result;
}//std::string CList<T>::sToString()

template<>
std::string CList<std::string>::sToString()
{
	std::string s_result = "";
	for (int ii = 0; ii<i_size; ii++)
	{
		s_result += cGetValue(ii) + ", ";
	}
	return s_result;
}//std::string CList<T>::sToString()

template<class T>
CList<std::string> *CList<T>::pcToString()
{
	return NULL;
}//CList<std::string> CList<T>::pcToString()



template<>
CList<std::string> *CList<int>::pcToString()
{
	CList<std::string> *pc_string_list = new CList<std::string>;
	for (int ii = 0; ii<i_size; ii++)
	{
		pc_string_list->bAdd(std::to_string(this->cGetValue(ii)), ii);
	}
	return pc_string_list;
}//CList<std::string> CList<int>::pcToString()


