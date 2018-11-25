#pragma once
#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/**
*	@brief	Tree�� �����ϴ� Node (node data, left ������, right ������)
*/
template<typename T>
struct Node
{
	T data; ///< �� ����� ������.
	Node* left; ///< �� ��庸�� ���� ���� ���� ���
	Node* right; ///< �� ��庸�� ū ���� ���� ���
};

/**
*	@brief	Binary Search Tree 
*/
template<typename T>
class BinarySearchTree
{
public:
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree() { }

	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	T�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*	@param	item	�߰��� ��ü
	*/
	void Add(T item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	T�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*	@param	item	������ ��ü
	*/
	void DeleteItem(T item);

	/**
	*	@brief	����Ʈ���� ��ü ����
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	����Ʈ���� ��ü ���ŵ�
	*	@param	item	������ ��ü
	*/
	void ReplaceItem(T& item);		// ��ü ����

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*	@param	item	ã���� �ϴ� ��ü
	*	@param	found	ã������ true, ��ã������ false �Է�
	*/
	void RetrieveItem(T& item, bool &found)const;

	/**
	*	@brief	�Է��� ���� ��ġ�ϴ� ���� �ִ� ��带 Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	��ġ�ϴ� ��� ��尪�� ���
	*	@param	data	ã���� �ϴ� �ܾ�
	*/
	void RetrieveByString(string data);

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*	@param	out	��� ���
	*/
	void PrintTree(ostream &out)const;

	/**
	*	@brief	Tree�� node�� ���Ͽ� �Է��Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*	@param	out	��� ���
	*/
	void WriteTree(ofstream &out)const;
	/**
	*	@brief	���̳ʸ���ġƮ�� ���� ��ī�Ǹ� ���� = ������ �����ε�
	*	@param	tree	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& tree)
	{
		MakeEmpty();
		CopyNode(root, tree.root);
		return *this;
	}

private:
	Node<T>* root;		// Node Ÿ���� root
};

// ������
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

// Tree�� ����ִ��� Ȯ��
template<typename T>
bool BinarySearchTree<T>::IsEmpty()const
{
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

// Tree�� Full���� Ȯ��
template<typename T>
bool BinarySearchTree<T>::IsFull()const
{
	Node<T> *room;					// �ӽ��� node�� �����
	try
	{
		room = new Node<T>;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete room;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
	}
}

// Tree�� ���
template<typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree �ʱ�ȭ �Լ� ȣ��
}

// Tree�� node������ �˷���
template<typename T>
int BinarySearchTree<T>::GetLength()const
{
	return CountNodes(root);			// node ������ ���� �Լ� ȣ��
}

// Tree�� ���ο� node �߰�
template<typename T>
void BinarySearchTree<T>::Add(T item)
{
	Insert(root, item);					// �� node �߰��ϴ� �Լ� ȣ��
}

// Tree�� node�� ����
template<typename T>
void BinarySearchTree<T>::DeleteItem(T item)
{
	Delete(root, item);					// �����ϴ� node �����ϴ� �Լ��� ȣ��
}

template<typename T>
void BinarySearchTree<T>::ReplaceItem(T& item)
{
	Replace(root, item);
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<typename T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool &found)const
{
	Retrieve(root, item, found);		// Tree �˻� �Լ� ȣ��
}

template<typename T>
void BinarySearchTree<T>::RetrieveByString(string data)
{
	RetrieveString(root, data);
}

// Tree�� node�� ������ ������ �����
template<typename T>
void BinarySearchTree<T>::PrintTree(ostream &out)const
{
	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root, out);			// InOrder ������� ���
	//cout << endl << "[PreOrder]" << endl;
	//PrintPreOrderTraversal(root, out);			// PreOrder ������� ���
	//cout << endl << "[PostOrder]" << endl;
	//PrintPostOrderTraversal(root, out);			// PostOrder ������� ���
}

// Tree�� node�� ���Ͽ� �Է���
template<typename T>
void BinarySearchTree<T>::WriteTree(ofstream &out)const
{
	PrintPreOrderTraversal(root, out);
}

/////////////////////////////Global functions//////////////////////////
// Tree�� �ʱ�ȭ�ϴ� �Լ�
template<typename T>
void MakeEmptyTree(Node<T>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}

// Tree�� node ������ ���� �Լ�
template<typename T>
int CountNodes(Node<T>* root)
{
	if (root == NULL)		// root ��尡 null�ϰ�� 0�� ����
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// ����� ����, �����ʿ� ���� ����� ȣ��� root�� �ش��ϴ� 1�� ���ؼ� ���� ����
}

// BinarySearchTree�� ���ο� ��� �߰�
template<typename T>
void Insert(Node<T>*& root, T item)
{
	if (root == NULL)				// root�� null�� ��� 
	{
		root = new Node<T>;	// root ��� ����
		root->left = NULL;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = NULL;
		root->data = item;			// root ����� ��
	}
	else if (root->data == item)
		return;
	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
		Insert(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
		Insert(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
}

// ���� ū ���� ã�� �Լ� 
template<typename T>
void GetPredecessor(Node<T> *root, T& item)
{
	while (root->right != NULL)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ������� ��带 ã���� ������ Ʈ������ �� ��带 ����� �Լ�
template<typename T>
void DeleteNode(Node<T> *&root)
{
	T item;
	Node<T>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == NULL)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == NULL)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		Delete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<typename T>
void Delete(Node<T> *&root, T item)
{
	
	if (item < root->data)				// root��尪���� item��尡 ���� ��
		Delete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		Delete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
}

// Tree���� node�� �˻��ϴ� �Լ�
template<typename T>
void Retrieve(Node<T> *root, T& item, bool &found)
{
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		Retrieve(root->left, item, found);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		Retrieve(root->right, item, found);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		found = true;						// found���� true�� �ؼ� ã�� ������ ����
	}
}

template<typename T>
void Replace(Node<T> *&root, T& item)
{
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		return;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		Replace(root->left, item);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		Replace(root->right, item);	// ������ ���� ���� retrieve �Լ� ȣ��
	else								// ã���� �ϴ� ���� ��ġ�� ��	
		root->data = item;					// item�� ��� ������ ����
}

template<typename T>
void RetrieveString(Node<T> *root, string data)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		RetrieveString(root->left, data);
		if (root->data == data)
		{
			cout << root->data;
			cout << "------------------------------------------" << endl;
		}
		RetrieveString(root->right, data);
	}
}

// InOrder ������� ����ϴ� �Լ� 
template<typename T>
void PrintInOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintInOrderTraversal(root->left, out);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		out << root->data;							// root ���
		cout << endl;
		PrintInOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}

// PreOrder ������� ����ϴ� �Լ�
template<typename T>
void PrintPreOrderTraversal(Node<T>* root, ofstream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		out << root->data;							// root�� ���� ���
		PrintPreOrderTraversal(root->left, out);	// root�� �������� ���� PreOrder �Լ� �ٽ� ȣ��
		PrintPreOrderTraversal(root->right, out);	// root�� ���������� ���� PreOrder �Լ� �ٽ� ȣ��
	}
}

// PostOrder ������� ����ϴ� �Լ�
template<typename T>
void PrintPostOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintPostOrderTraversal(root->left, out);	// root�� �������� ���� �ٽ� PostOrder �Լ� ȣ��
		PrintPostOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� PostOrder �Լ� ȣ��
		out << root->data;							// root�� �� ���
	}
};

template<typename T>
void CopyNode(Node<T> *&node, Node<T> *copy)
{
	if (copy == NULL)
		return;
	node = new Node<T>;
	node->data = copy->data;
	node->left = NULL;
	node->right = NULL;
	CopyNode(node->left, copy->left);
	CopyNode(node->right, copy->right);
}

#endif //_BinarySearchTree_H
