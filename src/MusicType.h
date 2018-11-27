#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;



/**
*	@brief	Music 정보 클래스
*/
class MusicType
{
public:
	/**
	*	디폴트 생성자
	*/
	MusicType()
	{
		song = "";
		singer = "";
		album = "";
		genre = "";
	}

	/**
	*	소멸자
	*/
	~MusicType() {}

	/**
	*	@brief	곡명 가져오기
	*	@pre	곡명이 설정되있어야 함
	*	@post	none.
	*	@return	곡명
	*/
	string GetSong()
	{
		return song;
	}

	/**
	*	@brief	가수명 가져오기
	*	@pre	가수가 설정되있어야 함
	*	@post	none.
	*	@return	가수
	*/
	string GetSinger()
	{
		return singer;
	}

	/**
	*	@brief	앨범 가져오기
	*	@pre	앨범이 설정되있어야 함
	*	@post	none.
	*	@return	앨범
	*/
	string GetAlbum()
	{
		return album;
	}

	/**
	*	@brief	장르 가져오기
	*	@pre	장르가 설정되있어야 함
	*	@post	none.
	*	@return	장르
	*/
	string GetGenre()
	{
		return genre;
	}

	/**
	*	@brief	가사 가져오기
	*	@pre	가사가 설정되있어야 함
	*	@post	none.
	*	@return	가사
	*/
	string GetLyrics()
	{
		return lyrics;
	}

	/**
	*	@brief	곡명 설정
	*	@pre	none.
	*	@post	곡명 설정
	*	@param	inSong	설정할 곡명.
	*/
	void SetSong(string inSong)
	{
		song = inSong;
	}

	/**
	*	@brief	가수명 설정
	*	@pre	none.
	*	@post	가수명 설정
	*	@param	inSinger	가수명
	*/
	void SetSinger(string inSinger)
	{
		singer = inSinger;
	}

	/**
	*	@brief	앨범 설정
	*	@pre	none.
	*	@post	앨범 설정
	*	@param	inAlbum	앨범
	*/
	void SetAlbum(string inAlbum)
	{
		album = inAlbum;
	}

	/**
	*	@brief	장르 설정
	*	@pre	none.
	*	@post	장르 설정
	*	@param	inGenre	장르
	*/
	void SetGenre(string inGenre)
	{
		genre = inGenre;
	}

	/**
	*	@brief	가사 설정
	*	@pre	none.
	*	@post	가사 설정
	*	@param	inLyrics	가사
	*/
	void SetLyrics(string inLyrics)
	{
		lyrics = inLyrics;
	}

	/**
	*	@brief	노래 정보 설정
	*	@pre	none.
	*	@post	노래 정보 설정
	*	@param	inSong	곡명
	*	@param	inSinger	가수명
	*	@param	inAlbum	앨범
	*	@param	inGenre	장르
	*	@param	inLyrics	가사
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
	*	@brief	화면에 곡명 출력
	*	@pre	곡명이 설정되있어야 함
	*	@post	none
	*/
	void DisplaySongOnScreen()
	{
		cout << "\tSong   : " << song << endl;
	};

	/**
	*	@brief	화면에 가수명 출력
	*	@pre	가수명이 설정되있어야 함
	*	@post	none
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\tSinger : " << singer << endl;
	};

	/**
	*	@brief	화면에 앨범 출력
	*	@pre	앨범이 설정되있어야 함
	*	@post	none
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\tAlbum  : " << album << endl;
	};

	/**
	*	@brief	화면에 장르 출력
	*	@pre	장르가 설정되있어야 함
	*	@post	none
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre  : " << genre << endl;
	};

	/**
	*	@brief	화면에 가사 출력
	*	@pre	가사가 설정되있어야 함
	*	@post	none
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << lyrics << endl;
	};

	/**
	*	@brief	화면에 노래 정보 출력
	*	@pre	노래 정보가 설정되있어야 함
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
	*	@brief	키보드로 곡명 설정
	*	@pre	none.
	*	@post	곡명 설정
	*/
	void SetSongFromKB();

	/**
	*	@brief	키보드로 가수명 설정
	*	@pre	none.
	*	@post	가수명 설정
	*/
	void SetSingerFromKB();

	/**
	*	@brief	키보드로 앨범 설정
	*	@pre	none.
	*	@post	앨범 설정
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	키보드로 장르 설정
	*	@pre	none.
	*	@post	장르 설정
	*/
	void SetGenreFromKB();

	/**
	*	@brief	키보드로 가사 설정
	*	@pre	none.
	*	@post	가사 설정
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	키보드로 노래 정보 설정
	*	@pre	none.
	*	@post	노래 정보 설정
	*/
	void SetRecordFromKB();

	// 연산자 오버로딩
	/**
	*	@brief	뮤직클래스 간에 == 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator== (MusicType &obj)
	{
		if (song == obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	곡명 간에 == 연산자 오버로딩
	*	@param	data	해당 클래스의 곡명과 연산될 곡명
	*/
	bool operator== (string data)
	{
		if (song.find(data) != string::npos)
			return true;
		else
			return false;
	}
	/**
	*	@brief	뮤직클래스 간에 > 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator> (MusicType &obj)
	{
		if (song > obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	뮤직클래스 간에 < 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator< (MusicType &obj)
	{
		if (song < obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	뮤직클래스의 ostream시 << 연산자 오버로딩
	*	@param	out	ostream시 할 out 종류
	*	@param	music	out과 연산될 피연산자 뮤직클래스
	*/
	friend void operator<<(ostream& out, MusicType& music);
	/**
	*	@brief	뮤직클래스의 ofstream시 << 연산자 오버로딩
	*	@param	out	ofstream시 할 out 종류
	*	@param	music	out과 연산될 피연산자 뮤직클래스
	*/
	friend void operator<<(ofstream& out, MusicType& music);
protected:
	string song;		///< 노래제목
	string singer;		///< 가수
	string songwriter;		///< 작곡가
	string lyricwriter;		///< 작사가
	string album;		///< 앨범
	string genre;		///< 장르
	string lyrics;		///< 가사
};

#endif	// _MusicType_H
