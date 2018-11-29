#pragma once
#ifndef _ArtistType_H
#define _ArtistType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

#include "AlbumType.h"
#include "BinarySearchTree.h"
/**
*	@brief	SimpleMusicType���� �� ����Ʈ�� ���� ��Ƽ��ƮŸ�� Ŭ����
*/
class ArtistType
{
public:
	ArtistType();	// ����Ʈ ������
	~ArtistType();	// �Ҹ���

	/**
	*	@brief	��Ƽ��Ʈ�� �뷡 �߰�	
	*	@pre	��Ƽ��Ʈ�� �����Ǿ��־����
	*	@post	��Ƽ��Ʈ�� �뷡 �߰���
	*	@param	inData	�߰��� �뷡�� ����
	*/
	void Add(SimpleMusicType inData);		// �뷡 �߰�
	/**
	*	@brief	��Ƽ��Ʈ���� �뷡 ����	
	*	@pre	��Ƽ��Ʈ�� �����Ǿ��־����
	*	@post	��Ƽ��Ʈ���� �뷡 ������
	*	@param	inData	������ �뷡�� ����
	*/
	void Delete(SimpleMusicType inData);	// �뷡 ����
	
	/**
	*	@brief	������ ��������
	*	@pre	�������� �������־����
	*	@return	������
	*/
	string GetArtistName();	// ������ ��������
	/**
	*	@brief	�ٹ� ���� ��������
	*	@pre	�ٹ� ������ �������־����
	*	@return	�ٹ� ����
	*/
	int GetLength();	// �ٹ� ���� ��������
	
	/**
	*	@brief	������ �����ϱ�
	*	@post	������ ����
	*	@param	inArtistName	������ ������
	*/
	void SetArtistName(string inArtistName);		// ������ ����

	/**
	*	@brief	������ �����ϱ�
	*	@post	������ ����
	*	@param	inArtistName	������ ������
	*/
	void SetRecord(string inArtistName);	// ������� ������� ����

	/**
	*	@brief	ȭ�鿡 ������ ���
	*	@pre	�������� �����Ǿ��־����
	*/
	void DisplayArtistNameOnScreen();		// ȭ�鿡 ������ ���

	/**
	*	@brief	ȭ�鿡 ���Ʈ ���
	*	@pre	���Ʈ�� �����Ǿ��־����
	*/
	void DisplaySongListOnScreen();		// ȭ�鿡 ���Ʈ ���


	// ������ �����ε�

	/**
	*	@brief	��Ƽ��ƮŬ���� ���� == ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator== (ArtistType &obj)
	{
		if (ArtistName.compare(obj.GetArtistName()) == 0)
			return true;
		else
			return false;
	}
	/**
	*	@brief	��Ƽ��ƮŬ���� ���� > ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator> (ArtistType &obj)
	{
		if (ArtistName.compare(obj.GetArtistName()) == 1)
			return true;
		else
			return false;
	}
	/**
	*	@brief	��Ƽ��ƮŬ���� ���� < ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator< (ArtistType &obj)
	{
		if (ArtistName.compare(obj.GetArtistName()) == -1)
			return true;
		else
			return false;
	}

private:
	string ArtistName;	///< ������(primary key)
	BinarySearchTree<SimpleMusicType> m_List;	///< �뷡���
	int m_Length;	///< �ٹ� ����
};

#endif	// _ArtistType_H
