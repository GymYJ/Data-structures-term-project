#pragma once
#ifndef _SimpleMusicType_H
#define _SimpleMusicType_H


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

/**
*	@brief	SimpleMusic ���� Ŭ����
*/
class SimpleMusicType
{
public:
	SimpleMusicType();
	~SimpleMusicType();

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
	*	@brief	primary key ��������
	*	@pre	primary key�� �������־�� ��
	*	@post	none.
	*	@return	primary key
	*/
	string GetPrimaryKey()
	{
		return PrimaryKey;
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
		PrimaryKey = song + singer;
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
		PrimaryKey = song + singer;
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
		PrimaryKey = song + singer;
	}

	/**
	*	@brief	ȭ�鿡 ��� ���
	*	@pre	����� �������־�� ��
	*	@post	none
	*/
	void DisplaySongOnScreen()
	{
		cout << "\tSong   : " << song << endl;
	};

	/**
	*	@brief	ȭ�鿡 ������ ���
	*	@pre	�������� �������־�� ��
	*	@post	none
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\tSinger   : " << singer << endl;
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
		if (PrimaryKey == obj.GetPrimaryKey())
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
		if (PrimaryKey > obj.GetPrimaryKey())
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
		if (PrimaryKey < obj.GetPrimaryKey())
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
	string song;
	string singer;
	string PrimaryKey;	///< primary key(�뷡����+����)
};

#endif	// _SimpleMusicType_H