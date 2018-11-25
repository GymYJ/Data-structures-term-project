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
template <typename T>	//generic data을 위해 template 선언
class SortedLinkedList
{
public:
	SortedLinkedList();		// 디폴트 생성자
	~SortedLinkedList();		// 소멸자

	/**
	*	@brief	리스트 비우기	
	*	@pre	리스트가 설정되어있어야함
	*	@post	리스트 비워짐
	*/
	void MakeEmpty();			// 리스트 비우기
	/**
	*	@brief	리스트 길이 가져오기
	*	@pre	리스트 길이가 설정되어있어야함
	*	@return	리스트 길이	
	*/
	int GetLength() const;		// 리스트 길이 가져오기
	/**
	*	@brief	리스트에 객체 추가
	*	@post	리스트에 객체 추가됨
	*	@param	item	추가할 객채
	*	@return	추가에 성공했으면 1, 실패했으면 0 리턴
	*/
	int Add(T& item);			// 객체 추가
	/**
	*	@brief	리스트에서 객체 삭제
	*	@pre	리스트가 설정되어있어야함
	*	@post	리스트에서 객체 삭제됨
	*	@param	item	삭제할 객체
	*	@return	삭제에 성공했으면 1, 실패했으면 0 리턴
	*/
	int Delete(T item);			// 객체 삭제
	/**
	*	@brief	리스트에서 객체 갱신
	*	@pre	리스트가 설정되어있어야함
	*	@post	리스트에서 객체 갱신됨
	*	@param	item	갱신할 객체
	*	@return	갱신에 성공했으면 1, 실패했으면 0 리턴
	*/
	int Replace(T& item);		// 객체 갱신
	/**
	*	@brief	리스트에서 일치하는 객체 가져오기
	*	@pre	리스트가 설정되어있어야함
	*	@post	파라미터item에 해당 객체 주소 복사됨
	*	@param	item	찾고자 하는 객체의 정보
	*	@return	찾는데 성공했으면 1, 실패했으면 0 리턴
	*/
	int Get(T& item);			// 객체 가져오기
	/**
	*	@brief	리스트에서 객체 주소 받아오기
	*	@pre	리스트가 설정되어있어야함
	*	@post	리스트에서 객체 주소 받아옴
	*	@param	data	찾고 싶은 객체
	*	@return	찾는데 성공했으면 해당 객체의 주소, 실패했으면 NULL 리턴
	*/
	T* GetPoint(T data);			// 객체주소 가져오기
	/**
	*	@brief	커런트포인터 초기화
	*	@post	커런트포인터 초기화됨
	*/
	void ResetList();			// 커런트포인터 초기화
	/**
	*	@brief	리스트의 다음 객체 가져오기
	*	@pre	리스트가 설정되어있어야함
	*	@post	파라미터item에 다음 객체 주소 복사됨
	*	@param	item	다음 객체를 받아올 파라미터
	*/
	void GetNextItem(T& item);	// 리스트의 다음 객체 가져오기

private:
	NodeType<T>* m_pList;		/// 리스트의 첫번째 노드를 가리키는 포인터
	NodeType<T>* m_pCurPointer;	/// 현재 노드를 가리키는 포인터 
	int m_nLength;				/// 리스트의 길이
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
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 cur 포인터 갱신.
			GetNextItem(dummy);

			if (m_pCurPointer->data == node->data)
			{
				// 같은 자료 존재, 추가 실패
				return 0;
			}

			if (m_pCurPointer->data > node->data)
			{
				// 넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}
				//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	NodeType<T>* pre = NULL;	//변수 선언

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == m_pCurPointer->data)	//현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;	//찾았으므로 found 값 변경
			if (pre == NULL)
				m_pList = m_pCurPointer->next;	//항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_nLength--;	//리스트의 길이를 1 줄여준다.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if (found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.
	
}

template<typename T>
int SortedLinkedList<T>::Replace( T& item)
{
	// 리스트 초기화
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
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
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
	return NULL;	//찾지 못하면 0을 리턴한다.
}

template<typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}

template<typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}


#endif	// SORTEDLINKED_LIST
