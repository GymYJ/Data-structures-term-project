#pragma once
#ifndef _GenreType_H
#define _GenreType_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#include "BinarySearchTree.h"
#include "SimpleMusicType.h"

/**
*	@brief	SimpleMusic을 멤버변수로 갖는 장르타입 클래스
*/
class GenreType
{
public:
	GenreType();
	~GenreType();

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
	*	@brief	화면에 장르 출력
	*	@pre	장르가 설정되있어야 함
	*	@post	none
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre  : " << genre << endl;
	};

	/**
	*	@brief	화면에 장르리스트 출력
	*	@pre	장르리스트가 설정되있어야 함
	*	@post	none
	*/
	void DisplayListOnScreen();

	/**
	*	@brief	현재 리스트의 아이템 갯수 가져오기
	*	@pre	none.
	*	@post	none.
	*	@return	현재 리스트의 아이템 갯수
	*/
	int GetLength();

	/**
	*	@brief	장르리스트에 새로운 Music 추가
	*	@pre	장르리스트가 초기화 되어있어야 됨
	*	@post	장르리스트에 새로운 Music 추가됨
	*	@param	inData	추가할 새로운 Music
	*/
	void Add(SimpleMusicType inData);

	/**
	*	@brief	장르리스트에서 Music 삭제
	*	@pre	장르리스트가 초기화 되어있어야 됨
	*	@post	장르리스트에 일치하는 Music이 있으면 삭제
	*	@param	inData	삭제하고자 하는 Music클래스
	*	@return	삭제에 성공했으면 1, 실패했으면 0 리턴
	*/
	void Delete(SimpleMusicType inData);

	// 연산자 오버로딩

	/**
	*	@brief	장르클래스 간에 == 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator== (GenreType &obj)
	{
		if (genre == obj.GetGenre())
			return true;
		else
			return false;
	}
	/**
	*	@brief	장르클래스 간에 > 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator> (GenreType &obj)
	{
		if (genre > obj.GetGenre())
			return true;
		else
			return false;
	}
	/**
	*	@brief	장르클래스 간에 < 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	bool operator< (GenreType &obj)
	{
		if (genre < obj.GetGenre())
			return true;
		else
			return false;
	}
	/**
	*	@brief	장르클래스 간에 딥카피를 위한 = 연산자 오버로딩
	*	@param	obj	해당 클래스와 연산될 피연산자 클래스
	*/
	GenreType& operator=(GenreType& obj)
	{
		genre = obj.GetGenre();
		m_List = obj.m_List;
		return *this;
	}

private:
	string genre;
	int m_Length;
	BinarySearchTree<SimpleMusicType> m_List;
};

#endif	// _GenreType_H