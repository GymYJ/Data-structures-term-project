#pragma once
#ifndef _GenreType_H
#define _GenreType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#include "BinarySearchTree.h"
#include "SimpleMusicType.h"

/**
*	@brief	SimpleMusic�� ��������� ���� �帣Ÿ�� Ŭ����
*/
class GenreType
{
public:
	GenreType();
	~GenreType();

	/**
	*	@brief	�帣 ��������
	*	@pre	�帣�� �������־�� ��
	*	@post	none.
	*	@return	�帣
	*/
	string GetGenre()
	{
		return genre;
	}

	/**
	*	@brief	�帣 ����
	*	@pre	none.
	*	@post	�帣 ����
	*	@param	inGenre	�帣
	*/
	void SetGenre(string inGenre)
	{
		genre = inGenre;
	}

	/**
	*	@brief	ȭ�鿡 �帣 ���
	*	@pre	�帣�� �������־�� ��
	*	@post	none
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre  : " << genre << endl;
	};

	/**
	*	@brief	ȭ�鿡 �帣����Ʈ ���
	*	@pre	�帣����Ʈ�� �������־�� ��
	*	@post	none
	*/
	void DisplayListOnScreen();

	/**
	*	@brief	���� ����Ʈ�� ������ ���� ��������
	*	@pre	none.
	*	@post	none.
	*	@return	���� ����Ʈ�� ������ ����
	*/
	int GetLength();

	/**
	*	@brief	�帣����Ʈ�� ���ο� Music �߰�
	*	@pre	�帣����Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	�帣����Ʈ�� ���ο� Music �߰���
	*	@param	inData	�߰��� ���ο� Music
	*/
	void Add(SimpleMusicType inData);

	/**
	*	@brief	�帣����Ʈ���� Music ����
	*	@pre	�帣����Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	�帣����Ʈ�� ��ġ�ϴ� Music�� ������ ����
	*	@param	inData	�����ϰ��� �ϴ� MusicŬ����
	*	@return	������ ���������� 1, ���������� 0 ����
	*/
	void Delete(SimpleMusicType inData);

	// ������ �����ε�

	/**
	*	@brief	�帣Ŭ���� ���� == ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator== (GenreType &obj)
	{
		if (genre == obj.GetGenre())
			return true;
		else
			return false;
	}
	/**
	*	@brief	�帣Ŭ���� ���� > ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator> (GenreType &obj)
	{
		if (genre > obj.GetGenre())
			return true;
		else
			return false;
	}
	/**
	*	@brief	�帣Ŭ���� ���� < ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator< (GenreType &obj)
	{
		if (genre < obj.GetGenre())
			return true;
		else
			return false;
	}
	/**
	*	@brief	�帣Ŭ���� ���� ��ī�Ǹ� ���� = ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	GenreType& operator=(GenreType& obj)
	{
		genre = obj.GetGenre();
		m_List = obj.m_List;
		return *this;
	}

private:
	string genre;
	int m_Length;
	BinarySearchTree<SimpleMusicType> m_List;
};

#endif	// _GenreType_H