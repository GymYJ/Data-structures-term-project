#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;



/**
*	@brief	Music ���� Ŭ����
*/
class MusicType
{
public:
	/**
	*	����Ʈ ������
	*/
	MusicType()
	{
		song = "";
		singer = "";
		album = "";
		genre = "";
		PrimaryKey = "";
	}

	/**
	*	�Ҹ���
	*/
	~MusicType() {}

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
	*	@pre	������ �������־�� ��
	*	@post	none.
	*	@return	����
	*/
	string GetSinger()
	{
		return singer;
	}

	/**
	*	@brief	�ٹ� ��������
	*	@pre	�ٹ��� �������־�� ��
	*	@post	none.
	*	@return	�ٹ�
	*/
	string GetAlbum()
	{
		return album;
	}

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
	*	@brief	���� ��������
	*	@pre	���簡 �������־�� ��
	*	@post	none.
	*	@return	����
	*/
	string GetLyrics()
	{
		return lyrics;
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
	*	@param	inSinger	������
	*/
	void SetSinger(string inSinger)
	{
		singer = inSinger;
		PrimaryKey = song + singer;
	}

	/**
	*	@brief	�ٹ� ����
	*	@pre	none.
	*	@post	�ٹ� ����
	*	@param	inAlbum	�ٹ�
	*/
	void SetAlbum(string inAlbum)
	{
		album = inAlbum;
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
	*	@brief	���� ����
	*	@pre	none.
	*	@post	���� ����
	*	@param	inLyrics	����
	*/
	void SetLyrics(string inLyrics)
	{
		lyrics = inLyrics;
	}

	/**
	*	@brief	�뷡 ���� ����
	*	@pre	none.
	*	@post	�뷡 ���� ����
	*	@param	inSongNumber	���ȣ
	*	@param	inSong	���
	*	@param	inSinger	������
	*	@param	inAlbum	�ٹ�
	*	@param	inGenre	�帣
	*	@param	inLyrics	����
	*/
	void SetRecord(string inSong, string inSinger, string inAlbum, string inGenre, string inLyrics)
	{
		SetSong(inSong);
		SetSinger(inSinger);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
		SetLyrics(inLyrics);
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
		cout << "\tSinger : " << singer << endl;
	};

	/**
	*	@brief	ȭ�鿡 �ٹ� ���
	*	@pre	�ٹ��� �������־�� ��
	*	@post	none
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\tAlbum  : " << album << endl;
	};

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
	*	@brief	ȭ�鿡 ���� ���
	*	@pre	���簡 �������־�� ��
	*	@post	none
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << lyrics << endl;
	};

	/**
	*	@brief	ȭ�鿡 �뷡 ���� ���
	*	@pre	�뷡 ������ �������־�� ��
	*	@post	none
	*/
	void DisplayRecordOnScreen()
	{
		DisplaySongOnScreen();
		DisplaySingerOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayLyricsOnScreen();
	};

	/**
	*	@brief	Ű����� ��� ����
	*	@pre	none.
	*	@post	��� ����
	*/
	void SetSongFromKB();

	/**
	*	@brief	Ű����� ������ ����
	*	@pre	none.
	*	@post	������ ����
	*/
	void SetSingerFromKB();

	/**
	*	@brief	Ű����� �ٹ� ����
	*	@pre	none.
	*	@post	�ٹ� ����
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Ű����� �帣 ����
	*	@pre	none.
	*	@post	�帣 ����
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Ű����� ���� ����
	*	@pre	none.
	*	@post	���� ����
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	Ű����� �뷡 ���� ����
	*	@pre	none.
	*	@post	�뷡 ���� ����
	*/
	void SetRecordFromKB();

	// ������ �����ε�
	/**
	*	@brief	����Ŭ���� ���� == ������ �����ε�
	*	@param	obj	�ش� Ŭ������ ����� �ǿ����� Ŭ����
	*/
	bool operator== (MusicType &obj)
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
	bool operator> (MusicType &obj)
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
	bool operator< (MusicType &obj)
	{
		if (PrimaryKey < obj.GetPrimaryKey())
			return true;
		else
			return false;
	}

	friend void operator<<(ostream& out, MusicType& music);
protected:
	string song;		///< �뷡����
	string singer;		///< ����
	string album;		///< �ٹ�
	string genre;		///< �帣
	string lyrics;		///< ����
	string PrimaryKey;	///< primary key(�뷡����+����)
};

#endif	// _MusicType_H