#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

/**
*	@brief	���� ���� Ŭ����
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
	*	@brief	�۰ ��������
	*	@pre	�۰�� �������־�� ��
	*	@post	none.
	*	@return	�۰
	*/
	string GetSongWriter()
	{
		return songwriter;
	}

	/**
	*	@brief	�ۻ簡 ��������
	*	@pre	�ۻ簡�� �������־�� ��
	*	@post	none.
	*	@return	�ۻ簡
	*/
	string GetLyricWriter()
	{
		return lyricwriter;
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
	*	@brief	�۰ ����
	*	@pre	none.
	*	@post	�۰ ����
	*	@param	inSongWriter	������ �۰
	*/
	void SetSongWriter(string inSongWriter)
	{
		songwriter = inSongWriter;
	}

	/**
	*	@brief	�ۻ簡 ����
	*	@pre	none.
	*	@post	�ۻ簡 ����
	*	@param	inLyricWriter	������ �ۻ簡
	*/
	void SetLyricWriter(string inLyricWriter)
	{
		lyricwriter = inLyricWriter;
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
	*	@param	inSongWriter	������ �۰
	*	@param	inLyricWriter	������ �ۻ簡
	*	@param	inAlbum	�ٹ�
	*	@param	inGenre	�帣
	*	@param	inLyrics	����
	*/
	void SetRecord(string inSong, string inSinger, string inSongWriter, string inLyricWriter, string inAlbum, string inGenre, string inLyrics)
	{
		SetSong(inSong);
		SetSinger(inSinger);
		SetSongWriter(inSongWriter);
		SetLyricWriter(inLyricWriter);
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
	*	@brief	ȭ�鿡 �۰ ���
	*	@pre	�۰�� �������־�� ��
	*	@post	none
	*/
	void DisplaySongWriterOnScreen()
	{
		cout << "\t�۰    : " << songwriter << endl;
	};

	/**
	*	@brief	ȭ�鿡 �ۻ簡 ���
	*	@pre	�ۻ簡�� �������־�� ��
	*	@post	none
	*/
	void DisplayLyricWriterOnScreen()
	{
		cout << "\t�ۻ簡    : " << lyricwriter << endl;
	};

	/**
	*	@brief	ȭ�鿡 �ٹ� ���
	*	@pre	�ٹ��� �������־�� ��
	*	@post	none
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t�ٹ���    : " << album << endl;
	};

	/**
	*	@brief	ȭ�鿡 �帣 ���
	*	@pre	�帣�� �������־�� ��
	*	@post	none
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t�帣      : " << genre << endl;
	};

	/**
	*	@brief	ȭ�鿡 ���� ���
	*	@pre	���簡 �������־�� ��
	*	@post	none
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\t����      : " << lyrics << endl;
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
		DisplaySongWriterOnScreen();
		DisplayLyricWriterOnScreen();
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
	*	@brief	Ű����� �۰ ����
	*	@pre	none.
	*	@post	�۰ ����
	*/
	void SetSongWriterFromKB();

	/**
	*	@brief	Ű����� �ۻ簡 ����
	*	@pre	none.
	*	@post	�ۻ簡 ����
	*/
	void SetLyricWriterFromKB();

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
private:
	string song;		///< �뷡����(primary key)
	string singer;		///< ����
	string songwriter;	///< �۰
	string lyricwriter;	///< �ۻ簡
	string album;		///< �ٹ�
	string genre;		///< �帣
	string lyrics;		///< ����
};

#endif	// _MusicType_H
