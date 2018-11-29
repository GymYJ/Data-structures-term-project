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
*	@brief	앨범타입 클래스
*/
class AlbumType
{
public:
	AlbumType();		// 디폴트 생성자
	~AlbumType();		// 소멸자

	/**
	*	@brief	앨범에 수록곡 추가
	*	@pre	앨범이 생성되어있어야함
	*	@post	앨범에 수록곡 추가됨
	*	@param	inData	추가할 곡의 정보
	*/
	void Add(SimpleMusicType inData);		// 수록곡 추가
	
	/**
	*	@brief	앨범에서 수록곡 삭제
	*	@pre	앨범이 생성되어있어야함
	*	@post	앨범에서 수록곡 삭제됨
	*	@param	inData	삭제할 곡의 정보
	*/
	void Delete(SimpleMusicType inData);	// 수록곡 삭제

	/**
	*	@brief	가수명 가져오기
	*	@pre	가수명이 설정되있어야함
	*	@return	가수명
	*/
	string GetArtistName();	// 가수명 가져오기
	/**
	*	@brief	앨범명 가져오기
	*	@pre	앨범명이 설정되있어야함
	*	@return	앨범명
	*/
	string GetAlbumName();	// 앨범명 가져오기
	
	/**
	*	@brief	수록곡 수 가져오기
	*	@pre	수록곡 수가 설정되있어야함
	*	@return	수록곡 수
	*/
	int GetNumberOfContainMusic();	// 수록곡 수 가져오기

	/**
	*	@brief	가수명 설정하기
	*	@post	가수명 설정
	*	@param	inArtistName	설정할 가수명
	*/
	void SetArtistName(string inArtistName);	// 가수명 설정
	/**
	*	@brief	앨범명 설정하기
	*	@post	앨범명 설정
	*	@param	inAlbumName	설정할 앨범명
	*/
	void SetAlbumName(string inAlbumName);// 앨범명 설정
	
	/**
	*	@brief	모든 레코드 설정하기
	*	@post	모든 레코드 설정
	*	@param	inArtistName	설정할 가수명
	*	@param	inAlbumName	설정할 앨범명
	*/
	void SetRecord(string inArtistName, string inAlbumName);	// 모든 레코드 설정

	/**
	*	@brief	화면에 가수명 출력
	*	@pre	가수명이 설정되어있어야함
	*/
	void DisplayArtistNameOnScreen();	// 화면에 가수명 출력
	/**
	*	@brief	화면에 앨범명 출력
	*	@pre	앨범명이 설정되어있어야함
	*/
	void DisplayAlbumNameOnScreen();	// 화면에 앨범명 출력
	
	/**
	*	@brief	화면에 수록곡 수 출력
	*	@pre	수록곡 수가 설정되어있어야함
	*/
	void DisplayNumberOfContainMusicOnScreen();	// 화면에 수록곡 수 출력
	/**
	*	@brief	화면에 수록곡 리스트 출력
	*	@pre	수록곡 리스트가 설정되어있어야함
	*/
	void DisplayContainMusicListOnScreen();// 화면에 수록곡리스트 출력
	/**
	*	@brief	화면에 모든 레코드 출력
	*	@pre	모든 레코드가 설정되어있어야함
	*/
	void DisplayRecordOnScreen();		// 화면에 모든 레코드 출력

	// 연산자 오버로딩

	/**
	*	@brief	앨범클래스 간에 == 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator== (AlbumType &obj)
	{
		if (AlbumName == obj.GetAlbumName())
			return true;
		else
			return false;
	}
	/**
	*	@brief	앨범클래스 간에 > 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator> (AlbumType &obj)
	{
		if (AlbumName > obj.GetAlbumName())
			return true;
		else
			return false;
	}
	/**
	*	@brief	앨범클래스 간에 < 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator< (AlbumType &obj)
	{
		if (AlbumName < obj.GetAlbumName())
			return true;
		else
			return false;
	}
	/**
	*	@brief	앨범클래스의 ostream시 << 연산자 오버로딩
	*	@param	out	ostream시 할 out 종류
	*	@param	album	out과 연산될 피연산자 앨범클래스
	*/
	friend void operator<<(ostream& out, AlbumType& album);
private:
	string AlbumName;	///< 앨범명(primary key)
	string ArtistName;	///< 가수명
	BinarySearchTree<SimpleMusicType> m_List; 	///< 수록곡리스트
	int m_Length;	///< 수록곡 수
};

#endif	// _AlbumType_H
