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
	*	@param	inSinger	������
	*/
	void SetSinger(string inSinger)
	{
		singer = inSinger;
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
		if (song == obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	��� ���� == ������ �����ε�
	*	@param	data	�ش� Ŭ������ ���� ����� ���
	*/
	bool operator== (string data)
	{
		if (song.find(data) != string::npos)
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
		if (song > obj.GetSong())
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
		if (song < obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	����Ŭ������ ostream�� << ������ �����ε�
	*	@param	out	ostream�� �� out ����
	*	@param	music	out�� ����� �ǿ����� ����Ŭ����
	*/
	friend void operator<<(ostream& out, MusicType& music);
	/**
	*	@brief	����Ŭ������ ofstream�� << ������ �����ε�
	*	@param	out	ofstream�� �� out ����
	*	@param	music	out�� ����� �ǿ����� ����Ŭ����
	*/
	friend void operator<<(ofstream& out, MusicType& music);
protected:
	string song;		///< �뷡����
	string singer;		///< ����
	string songwriter;		///< �۰
	string lyricwriter;		///< �ۻ簡
	string album;		///< �ٹ�
	string genre;		///< �帣
	string lyrics;		///< ����
};

#endif	// _MusicType_H
