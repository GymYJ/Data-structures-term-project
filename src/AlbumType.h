#pragma once
#ifndef _AlbumType_H
#define _AlbumType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#include "BinarySearchTree.h"
#include "SimpleMusicType.h"
/**
*	@brief	�ٹ�Ÿ�� Ŭ����
*/
class AlbumType
{
public:
	AlbumType();		// ����Ʈ ������
	~AlbumType();		// �Ҹ���

	/**
	*	@brief	�ٹ��� ���ϰ� �߰�
	*	@pre	�ٹ��� �����Ǿ��־����
	*	@post	�ٹ��� ���ϰ� �߰���
	*	@param	inData	�߰��� ���� ����
	*/
	void Add(SimpleMusicType inData);		// ���ϰ� �߰�
	
	/**
	*	@brief	�ٹ����� ���ϰ� ����
	*	@pre	�ٹ��� �����Ǿ��־����
	*	@post	�ٹ����� ���ϰ� ������
	*	@param	inData	������ ���� ����
	*/
	void Delete(SimpleMusicType inData);	// ���ϰ� ����

	/**
	*	@brief	������ ��������
	*	@pre	�������� �������־����
	*	@return	������
	*/
	string GetArtistName();	// ������ ��������
	/**
	*	@brief	�ٹ��� ��������
	*	@pre	�ٹ����� �������־����
	*	@return	�ٹ���
	*/
	string GetAlbumName();	// �ٹ��� ��������
	
	/**
	*	@brief	���ϰ� �� ��������
	*	@pre	���ϰ� ���� �������־����
	*	@return	���ϰ� ��
	*/
	int GetNumberOfContainMusic();	// ���ϰ� �� ��������

	/**
	*	@brief	������ �����ϱ�
	*	@post	������ ����
	*	@param	inArtistName	������ ������
	*/
	void SetArtistName(string inArtistName);	// ������ ����
	/**
	*	@brief	�ٹ��� �����ϱ�
	*	@post	�ٹ��� ����
	*	@param	inAlbumName	������ �ٹ���
	*/
	void SetAlbumName(string inAlbumName);// �ٹ��� ����
	
	/**
	*	@brief	��� ���ڵ� �����ϱ�
	*	@post	��� ���ڵ� ����
	*	@param	inArtistName	������ ������
	*	@param	inAlbumName	������ �ٹ���
	*/
	void SetRecord(string inArtistName, string inAlbumName);	// ��� ���ڵ� ����

	/**
	*	@brief	ȭ�鿡 ������ ���
	*	@pre	�������� �����Ǿ��־����
	*/
	void DisplayArtistNameOnScreen();	// ȭ�鿡 ������ ���
	/**
	*	@brief	ȭ�鿡 �ٹ��� ���
	*	@pre	�ٹ����� �����Ǿ��־����
	*/
	void DisplayAlbumNameOnScreen();	// ȭ�鿡 �ٹ��� ���
	
	/**
	*	@brief	ȭ�鿡 ���ϰ� �� ���
	*	@pre	���ϰ� ���� �����Ǿ��־����
	*/
	void DisplayNumberOfContainMusicOnScreen();	// ȭ�鿡 ���ϰ� �� ���
	/**
	*	@brief	ȭ�鿡 ���ϰ� ����Ʈ ���
	*	@pre	���ϰ� ����Ʈ�� �����Ǿ��־����
	*/
	void DisplayContainMusicListOnScreen();// ȭ�鿡 ���ϰ��Ʈ ���
	/**
	*	@brief	ȭ�鿡 ��� ���ڵ� ���
	*	@pre	��� ���ڵ尡 �����Ǿ��־����
	*/
	void DisplayRecordOnScreen();		// ȭ�鿡 ��� ���ڵ� ���

	// ������ �����ε�

	/**
	*	@brief	�ٹ�Ŭ���� ���� == ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator== (AlbumType &obj)
	{
		if (AlbumName == obj.GetAlbumName())
			return true;
		else
			return false;
	}
	/**
	*	@brief	�ٹ�Ŭ���� ���� > ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator> (AlbumType &obj)
	{
		if (AlbumName > obj.GetAlbumName())
			return true;
		else
			return false;
	}
	/**
	*	@brief	�ٹ�Ŭ���� ���� < ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator< (AlbumType &obj)
	{
		if (AlbumName < obj.GetAlbumName())
			return true;
		else
			return false;
	}
	/**
	*	@brief	�ٹ�Ŭ������ ostream�� << ������ �����ε�
	*	@param	out	ostream�� �� out ����
	*	@param	album	out�� ����� �ǿ����� �ٹ�Ŭ����
	*/
	friend void operator<<(ostream& out, AlbumType& album);
private:
	string AlbumName;	///< �ٹ���(primary key)
	string ArtistName;	///< ������
	BinarySearchTree<SimpleMusicType> m_List; 	///< ���ϰ��Ʈ
	int m_Length;	///< ���ϰ� ��
};

#endif	// _AlbumType_H
