#pragma once
#ifndef _SimpleMusicType_H
#define _SimpleMusicType_H


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

/**
*	@brief	SimpleMusic 정보 클래스
*/
class SimpleMusicType
{
public:
	SimpleMusicType();
	~SimpleMusicType();

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
	*	@pre	가수명이 설정되있어야 함
	*	@post	none.
	*	@return	가수명
	*/
	string GetSinger()
	{
		return singer;
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
	*	@param	inSinger	설정할 가수명.
	*/
	void SetSinger(string inSinger)
	{
		singer = inSinger;
	}

	/**
	*	@brief	노래 정보 설정
	*	@pre	none.
	*	@post	노래 정보 설정
	*	@param	inSong	설정할 곡명
	*	@param	inSinger	설정할 가수명
	*/
	void SetRecord(string inSong, string inSinger)
	{
		SetSong(inSong);
		SetSinger(inSinger);
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
		cout << "\tSinger   : " << singer << endl;
	};

	/**
	*	@brief	화면에 간단한 노래 정보 출력
	*	@pre	노래 정보가 설정되있어야 함
	*	@post	none
	*/
	void DisplayRecordOnScreen()
	{
		DisplaySongOnScreen();
		DisplaySingerOnScreen();
	};

	// 연산자 오버로딩

	/**
	*	@brief	뮤직클래스 간에 == 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator== (SimpleMusicType &obj)
	{
		if (song == obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	뮤직클래스 간에 > 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator> (SimpleMusicType &obj)
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
	bool operator< (SimpleMusicType &obj)
	{
		if (song < obj.GetSong())
			return true;
		else
			return false;
	}
	/**
	*	@brief	심플뮤직클래스의 ostream시 << 연산자 오버로딩
	*	@param	out	ostream시 할 out 종류
	*	@param	simplemusic	out과 연산될 피연산자 심플뮤직클래스
	*/
	friend void operator<<(ostream& out, SimpleMusicType& simplemusic);
private:
	string song;
	string singer;
};

#endif	// _SimpleMusicType_H