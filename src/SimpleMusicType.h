#pragma once
#ifndef _SimpleMusicType_H
#define _SimpleMusicType_H


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

/**
*	@brief	������ ���� ���� Ŭ����
*/
class SimpleMusicType
{
public:
	SimpleMusicType();
	~SimpleMusicType();

	/**
	*	@brief	���Ƚ�� ����
	*	@post	���Ƚ���� 1 ������
	*/
	void AddNumberOfPlay();	// ���Ƚ�� �߰�

	/**
	*	@brief	��� ��������
	*	@pre	����� �������־�� ��
	*	@post	none.
	*	@return	���
	*/
	string GetSong()
	{
		return song;
	}

	/**
	*	@brief	������ ��������
	*	@pre	�������� �������־�� ��
	*	@post	none.
	*	@return	������
	*/
	string GetSinger()
	{
		return singer;
	}

	/**
	*	@brief	���Ƚ�� ��������
	*	@pre	���Ƚ���� �������־����
	*	@return	���Ƚ��
	*/
	int GetNumberOfPlay()	// ���Ƚ�� ��������
	{
		return numberofplay;
	}

	/**
	*	@brief	��� ����
	*	@pre	none.
	*	@post	��� ����
	*	@param	inSong	������ ���.
	*/
	void SetSong(string inSong)
	{
		song = inSong;
	}

	/**
	*	@brief	������ ����
	*	@pre	none.
	*	@post	������ ����
	*	@param	inSinger	������ ������.
	*/
	void SetSinger(string inSinger)
	{
		singer = inSinger;
	}

	/**
	*	@brief	�뷡 ���� ����
	*	@pre	none.
	*	@post	�뷡 ���� ����
	*	@param	inSong	������ ���
	*	@param	inSinger	������ ������
	*/
	void SetRecord(string inSong, string inSinger)
	{
		SetSong(inSong);
		SetSinger(inSinger);
	}

	/**
	*	@brief	ȭ�鿡 ��� ���
	*	@pre	����� �������־�� ��
	*	@post	none
	*/
	void DisplaySongOnScreen()
	{
		cout << "\t���      : " << song << endl;
	};

	/**
	*	@brief	ȭ�鿡 ������ ���
	*	@pre	�������� �������־�� ��
	*	@post	none
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\t������    : " << singer << endl;
	};

	/**
	*	@brief	ȭ�鿡 ���Ƚ�� ���
	*	@pre	���Ƚ���� �������־�� ��
	*	@post	none
	*/
	void DisplayNumberOfPlayOnScreen()
	{
		cout << "\t���Ƚ��  : " << numberofplay << endl;
	};

	/**
	*	@brief	ȭ�鿡 ������ �뷡 ���� ���
	*	@pre	�뷡 ������ �������־�� ��
	*	@post	none
	*/
	void DisplayRecordOnScreen()
	{
		DisplaySongOnScreen();
		DisplaySingerOnScreen();
	};

	// ������ �����ε�

	/**
	*	@brief	����Ŭ���� ���� == ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator== (SimpleMusicType &obj)
	{
		if (song == obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	����Ŭ���� ���� > ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator> (SimpleMusicType &obj)
	{
		if (song > obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	����Ŭ���� ���� < ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator< (SimpleMusicType &obj)
	{
		if (song < obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	���ù���Ŭ������ ostream�� << ������ �����ε�
	*	@param	out	ostream�� �� out ����
	*	@param	simplemusic	out�� ����� �ǿ����� ���ù���Ŭ����
	*/
	friend void operator<<(ostream& out, SimpleMusicType& simplemusic);
private:
	string song;	///< ���(primary key)
	string singer;	///< ����
	int numberofplay;	///< ���Ƚ��
};

#endif	// _SimpleMusicType_H