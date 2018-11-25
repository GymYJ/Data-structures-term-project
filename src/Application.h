#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#include "MusicType.h"
#include "GenreType.h"
#include "ArtistType.h"
#include "SimpleMusicType.h"
#include "BinarySearchTree.h"
#define FILENAMESIZE 1024

/**
*	@brief	Music 관리를 쉽게 하기 위한 application 클래스
*/
class Application
{
public:
	/**
	*	디폴트 생성자
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	소멸자
	*/
	~Application() {}

	/**
	*	@brief	프로그램 드라이버
	*	@pre	프로그램이 실행되어 있어야 됨.
	*	@post	프로그램이 종료됨.
	*/
	void Run();

	/**
	*	@brief	명령어를 화면에 출력하고 키보드로 입력 받음
	*	@pre	none.
	*	@post	none.
	*	@return	사용자가 입력한 명령어
	*/
	int GetCommand();

	/**
	*	@brief	리스트에 새로운 Music 추가
	*	@pre	리스트가 초기화 되어있어야 됨
	*	@post	리스트에 새로운 Music 추가
	*	@return	작동이 잘 되었으면 1, 안되었으면 0 리턴
	*/
	int AddMusic();

	/**
	*	@brief	리스트에서 Music 하나 삭제
	*	@pre	리스트가 초기화 되어있어야 됨
	*	@post	리스트에 일치하는 Music이 있으면 삭제
	*	@return	삭제 했으면 1, 없어서 못했으면 0 리턴
	*/
	int DeleteMusic();

	/**
	*	@brief	리스트에서 Music 하나의 데이터 갱신
	*	@pre	리스트가 초기화 되어있어야 됨
	*	@post	리스트에 일치하는 Music이 있으면 데이터 갱신
	*	@return	갱신 했으면 1, 없어서 못했으면 0 리턴
	*/
	int ReplaceMusic();

	/**
	*	@brief	리스트에서 곡명이 일치하는 모든 Music 정보 출력
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByName();

	/**
	*	@brief	리스트에서 가수명이 일치하는 모든 Music 정보 출력
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByArtist();

	/**
	*	@brief	리스트에서 앨범이 일치하는 모든 앨범 정보 출력
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByAlbum();

	/**
	*	@brief	리스트에서 장르가 일치하는 모든 Music 정보 출력
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByGenre();

	/**
	*	@brief	모든 Music 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	리스트 내에 모든 Music 삭제
	*	@pre	리스트가 초기화 되어있어야 됨
	*	@post	리스트 내에 모든 Music 삭제
	*	@return	작동 되었으면 1, 작동 안되었으면 0 리턴
	*/
	int MakeEmpty();

	/**
	*	@brief	파일 설명자별 파일을 입력 파일로 열기
	*	@pre	읽기 위한 파일이 존재해야 함
	*	@post	읽기 위한 파일 open
	*	@param	fileName	읽기 위한 파일의 이름
	*	@return	작동 되었으면 1, 작동 안되었으면 0 리턴
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	파일 설명자별 파일을 출력 파일로 열기
	*	@pre	리스트가 초기화 되어 있어야 함
	*	@post	쓰기 위한 파일 open
	*	@param	fileName	쓰기 위한 파일의 이름
	*	@return	작동 되었으면 1, 작동 안되었으면 0 리턴
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	읽기 모드로 파일 Open, 파일에서 모든 데이터 읽기, 데이터로부터 리스트 설정
	*	@pre	파일이 열려있지 않아야 함
	*	@post	리스트가 파일로 부터 모든 레코드를 갖고 있어야 함
	*	@return	작동 되었으면 1, 작동 안되었으면 0 리턴
	*/
	int ReadDataFromFile();

	/**
	*	@brief	쓰기 모드로 파일 Open, 모든 데이터를 파일에 쓰기
	*	@pre	파일이 열려있지 않아야 함
	*	@post	파일에 리스트 데이터 저장
	*	@return	작동 되었으면 1, 작동 안되었으면 0 리턴
	*/
	int WriteDataToFile();


private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	BinarySearchTree<MusicType> m_List;	///< Master list
	BinarySearchTree<SimpleMusicType> m_SongList; ///< Song list.
	BinarySearchTree<GenreType> m_GenreList; ///< Genre list.
	BinarySearchTree<ArtistType> m_ArtistList; ///< Artist list.
	BinarySearchTree<AlbumType> m_AlbumList; ///< Album list.
	int m_Command;			///< current command number.
};



#endif	// _APPLICATION_H