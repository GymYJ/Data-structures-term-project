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
*	@brief	SimpleMusicType으로 된 리스트를 가진 아티스트타입 클래스
*/
class ArtistType
{
public:
	ArtistType();	// 디폴트 생성자
	~ArtistType();	// 소멸자

	/**
	*	@brief	아티스트에 노래 추가	
	*	@pre	아티스트가 생성되어있어야함
	*	@post	아티스트에 노래 추가됨
	*	@param	inData	추가할 노래의 정보
	*/
	void Add(SimpleMusicType inData);		// 노래 추가
	/**
	*	@brief	아티스트에서 노래 삭제	
	*	@pre	아티스트가 생성되어있어야함
	*	@post	아티스트에서 노래 삭제됨
	*	@param	inData	삭제할 노래의 정보
	*/
	void Delete(SimpleMusicType inData);	// 노래 삭제
	
	/**
	*	@brief	가수명 가져오기
	*	@pre	가수명이 설정되있어야함
	*	@return	가수명
	*/
	string GetArtistName();	// 가수명 가져오기
	/**
	*	@brief	앨범 개수 가져오기
	*	@pre	앨범 개수가 설정되있어야함
	*	@return	앨범 개수
	*/
	int GetLength();	// 앨범 개수 가져오기
	
	/**
	*	@brief	가수명 설정하기
	*	@post	가수명 설정
	*	@param	inArtistName	설정할 가수명
	*/
	void SetArtistName(string inArtistName);		// 가수명 설정

	/**
	*	@brief	가수명 설정하기
	*	@post	가수명 설정
	*	@param	inArtistName	설정할 가수명
	*/
	void SetRecord(string inArtistName);	// 가수명과 생년월일 설정

	/**
	*	@brief	화면에 가수명 출력
	*	@pre	가수명이 설정되어있어야함
	*/
	void DisplayArtistNameOnScreen();		// 화면에 가수명 출력

	/**
	*	@brief	화면에 곡리스트 출력
	*	@pre	곡리스트가 설정되어있어야함
	*/
	void DisplaySongListOnScreen();		// 화면에 곡리스트 출력


	// 연산자 오버로딩

	/**
	*	@brief	아티스트클래스 간에 == 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator== (ArtistType &obj)
	{
		if (ArtistName.compare(obj.GetArtistName()) == 0)
			return true;
		else
			return false;
	}
	/**
	*	@brief	아티스트클래스 간에 > 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator> (ArtistType &obj)
	{
		if (ArtistName.compare(obj.GetArtistName()) == 1)
			return true;
		else
			return false;
	}
	/**
	*	@brief	아티스트클래스 간에 < 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator< (ArtistType &obj)
	{
		if (ArtistName.compare(obj.GetArtistName()) == -1)
			return true;
		else
			return false;
	}

private:
	string ArtistName;	///< 가수명(primary key)
	BinarySearchTree<SimpleMusicType> m_List;	///< 노래목록
	int m_Length;	///< 앨범 개수
};

#endif	// _ArtistType_H
