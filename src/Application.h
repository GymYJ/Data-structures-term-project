#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <io.h>

#pragma comment(lib, "winmm.lib")
#define dir "..\\doc\\MusicSample\\"
using namespace std;

#include "MusicType.h"
#include "GenreType.h"
#include "ArtistType.h"
#include "SimpleMusicType.h"
#include "BinarySearchTree.h"
#define FILENAMESIZE 1024

/**
*	@brief	음악 관리를 쉽게 하기 위한 어플리케이션 클래스
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
	*	@brief	관리자계정 인터페이스
	*	@pre	Run함수가 실행되어 있어야 됨.
	*	@post	계정선택 창으로 돌아감
	*/
	void MasterMode();

	/**
	*	@brief	유저계정 드라이버
	*	@pre	Run함수가 실행되어 있어야 됨.
	*	@post	계정선택 창으로 돌아감
	*/
	void UserMode();

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
	*	@brief	재생목록에서 Music 하나 재생
	*	@pre	재생목록이 초기화 되어있어야 됨
	*	@post	음악이 재생되고 곡마다 재생된 횟수만큼 재생횟수가 증가
	*	@param	inNumber	재생할 곡의 리스트 내 순서
	*/
	void playMusic(int inNumber);

	/**
	*	@brief	재생목록에 Music 하나 추가
	*	@param	inSong	재생목록에 추가할 곡의 곡명
	*	@return	추가 했으면 1, 못했으면 0 리턴
	*/
	int AddMusicToPlayList(string inSong);

	/**
	*	@brief	재생목록에서 Music 하나 삭제
	*	@return	삭제 했으면 1, 없어서 못했으면 0 리턴
	*/
	int deleteMusicFromPlayList();

	/**
	*	@brief	재생목록에서 Music 찾기
	*	@pre	재생목록이 초기화 되어있어야 됨
	*	@param	inData	재생목록에서 찾는 곡의 곡명
	*	@return	찾으면 해당 곡의 순서, 없어서 못찾았으면 -1 리턴
	*/
	int GetSeqNumOfPlayList(SimpleMusicType inData);

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
	*	@brief	재생목록 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPlayList();

	/**
	*	@brief	모든 Music 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	가장 많이 재생된 30곡 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayMostPlayList();

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
	int m_Command;			///< current command number.
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	BinarySearchTree<MusicType> m_SongList;	///< Master list
	BinarySearchTree<SimpleMusicType> m_SimpleList; ///< Song list.
	BinarySearchTree<GenreType> m_GenreList; ///< Genre list.
	BinarySearchTree<ArtistType> m_ArtistList; ///< Artist list.
	BinarySearchTree<AlbumType> m_AlbumList; ///< Album list.
	SimpleMusicType* m_MostPlayList = new SimpleMusicType[30];	///< 가장 많이 재생한 곡 30개
	SimpleMusicType* m_PlayList = new SimpleMusicType[100];		///< 재생 목록
	int m_MostPlayListLength;		///< 가장 많이 재생한 곡 목록 길이
	int m_PlayListLength;			///< 재생목록 길이
};



#endif	// _APPLICATION_H