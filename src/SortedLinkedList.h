#pragma once
#ifndef _SORTEDLINKED_LIST_H
#define _SORTEDLINKED_LIST_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

/**
*	@brief	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};

/**
*	@brief	Simple sorted list class for managing items.
*/
template <typename T>	//generic data�� ���� template ����
class SortedLinkedList
{
public:
	SortedLinkedList();		// ����Ʈ ������
	~SortedLinkedList();		// �Ҹ���

	/**
	*	@brief	����Ʈ ����	
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	����Ʈ �����
	*/
	void MakeEmpty();			// ����Ʈ ����
	/**
	*	@brief	����Ʈ ���� ��������
	*	@pre	����Ʈ ���̰� �����Ǿ��־����
	*	@return	����Ʈ ����	
	*/
	int GetLength() const;		// ����Ʈ ���� ��������
	/**
	*	@brief	����Ʈ�� ��ü �߰�
	*	@post	����Ʈ�� ��ü �߰���
	*	@param	item	�߰��� ��ä
	*	@return	�߰��� ���������� 1, ���������� 0 ����
	*/
	int Add(T& item);			// ��ü �߰�
	/**
	*	@brief	����Ʈ���� ��ü ����
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	����Ʈ���� ��ü ������
	*	@param	item	������ ��ü
	*	@return	������ ���������� 1, ���������� 0 ����
	*/
	int Delete(T item);			// ��ü ����
	/**
	*	@brief	����Ʈ���� ��ü ����
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	����Ʈ���� ��ü ���ŵ�
	*	@param	item	������ ��ü
	*	@return	���ſ� ���������� 1, ���������� 0 ����
	*/
	int Replace(T& item);		// ��ü ����
	/**
	*	@brief	����Ʈ���� ��ġ�ϴ� ��ü ��������
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	�Ķ����item�� �ش� ��ü �ּ� �����
	*	@param	item	ã���� �ϴ� ��ü�� ����
	*	@return	ã�µ� ���������� 1, ���������� 0 ����
	*/
	int Get(T& item);			// ��ü ��������
	/**
	*	@brief	����Ʈ���� ��ü �ּ� �޾ƿ���
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	����Ʈ���� ��ü �ּ� �޾ƿ�
	*	@param	data	ã�� ���� ��ü
	*	@return	ã�µ� ���������� �ش� ��ü�� �ּ�, ���������� NULL ����
	*/
	T* GetPoint(T data);			// ��ü�ּ� ��������
	/**
	*	@brief	Ŀ��Ʈ������ �ʱ�ȭ
	*	@post	Ŀ��Ʈ������ �ʱ�ȭ��
	*/
	void ResetList();			// Ŀ��Ʈ������ �ʱ�ȭ
	/**
	*	@brief	����Ʈ�� ���� ��ü ��������
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	�Ķ����item�� ���� ��ü �ּ� �����
	*	@param	item	���� ��ü�� �޾ƿ� �Ķ����
	*/
	void GetNextItem(T& item);	// ����Ʈ�� ���� ��ü ��������

private:
	NodeType<T>* m_pList;		/// ����Ʈ�� ù��° ��带 ����Ű�� ������
	NodeType<T>* m_pCurPointer;	/// ���� ��带 ����Ű�� ������ 
	int m_nLength;				/// ����Ʈ�� ����
};

template<typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	//MakeEmpty();
}

template<typename T>
void SortedLinkedList<T>::MakeEmpty()
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}

template<typename T>
int SortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

template<typename T>
int SortedLinkedList<T>::Add(T& item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� cur ������ ����.
			GetNextItem(dummy);

			if (m_pCurPointer->data == node->data)
			{
				// ���� �ڷ� ����, �߰� ����
				return 0;
			}

			if (m_pCurPointer->data > node->data)
			{
				// ���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}
				//���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;
	return 1;
}

template<typename T>
int SortedLinkedList<T>::Delete(T item)
{
	bool moreToSearch, found;
	NodeType<T>* pre = NULL;	//���� ����

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == m_pCurPointer->data)	//���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;	//ã�����Ƿ� found �� ����
			if (pre == NULL)
				m_pList = m_pCurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
	
}

template<typename T>
int SortedLinkedList<T>::Replace( T& item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	NodeType<T> *node = m_pList;
	NodeType<T> *pre = NULL;

	while (true)
	{
		if (node->data == item)
		{
			node->data = item;
			return 1;
		}

		node = node->next;

		if (node == NULL) break;
	}
	return 0;
}

template<typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

template <typename T>
T* SortedLinkedList<T>::GetPoint(T data)
{
	T dummy;
	m_pCurPointer = m_pList;
	for (int i = 0; i < m_nLength; i++)
	{
		if (m_pCurPointer->data == data)	
		{
			return &(m_pCurPointer->data);
		}
		GetNextItem(dummy);
	}
	return NULL;	//ã�� ���ϸ� 0�� �����Ѵ�.
}

template<typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}

template<typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}


#endif	// SORTEDLINKED_LIST
