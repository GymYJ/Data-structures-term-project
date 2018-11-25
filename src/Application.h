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
*	@brief	Music ������ ���� �ϱ� ���� application Ŭ����
*/
class Application
{
public:
	/**
	*	����Ʈ ������
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	�Ҹ���
	*/
	~Application() {}

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ����Ǿ� �־�� ��.
	*	@post	���α׷��� �����.
	*/
	void Run();

	/**
	*	@brief	���ɾ ȭ�鿡 ����ϰ� Ű����� �Է� ����
	*	@pre	none.
	*	@post	none.
	*	@return	����ڰ� �Է��� ���ɾ�
	*/
	int GetCommand();

	/**
	*	@brief	����Ʈ�� ���ο� Music �߰�
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	����Ʈ�� ���ο� Music �߰�
	*	@return	�۵��� �� �Ǿ����� 1, �ȵǾ����� 0 ����
	*/
	int AddMusic();

	/**
	*	@brief	����Ʈ���� Music �ϳ� ����
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	����Ʈ�� ��ġ�ϴ� Music�� ������ ����
	*	@return	���� ������ 1, ��� �������� 0 ����
	*/
	int DeleteMusic();

	/**
	*	@brief	����Ʈ���� Music �ϳ��� ������ ����
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	����Ʈ�� ��ġ�ϴ� Music�� ������ ������ ����
	*	@return	���� ������ 1, ��� �������� 0 ����
	*/
	int ReplaceMusic();

	/**
	*	@brief	����Ʈ���� ����� ��ġ�ϴ� ��� Music ���� ���
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByName();

	/**
	*	@brief	����Ʈ���� �������� ��ġ�ϴ� ��� Music ���� ���
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByArtist();

	/**
	*	@brief	����Ʈ���� �ٹ��� ��ġ�ϴ� ��� �ٹ� ���� ���
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByAlbum();

	/**
	*	@brief	����Ʈ���� �帣�� ��ġ�ϴ� ��� Music ���� ���
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByGenre();

	/**
	*	@brief	��� Music ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	����Ʈ ���� ��� Music ����
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	����Ʈ ���� ��� Music ����
	*	@return	�۵� �Ǿ����� 1, �۵� �ȵǾ����� 0 ����
	*/
	int MakeEmpty();

	/**
	*	@brief	���� �����ں� ������ �Է� ���Ϸ� ����
	*	@pre	�б� ���� ������ �����ؾ� ��
	*	@post	�б� ���� ���� open
	*	@param	fileName	�б� ���� ������ �̸�
	*	@return	�۵� �Ǿ����� 1, �۵� �ȵǾ����� 0 ����
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	���� �����ں� ������ ��� ���Ϸ� ����
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	���� ���� ���� open
	*	@param	fileName	���� ���� ������ �̸�
	*	@return	�۵� �Ǿ����� 1, �۵� �ȵǾ����� 0 ����
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	�б� ���� ���� Open, ���Ͽ��� ��� ������ �б�, �����ͷκ��� ����Ʈ ����
	*	@pre	������ �������� �ʾƾ� ��
	*	@post	����Ʈ�� ���Ϸ� ���� ��� ���ڵ带 ���� �־�� ��
	*	@return	�۵� �Ǿ����� 1, �۵� �ȵǾ����� 0 ����
	*/
	int ReadDataFromFile();

	/**
	*	@brief	���� ���� ���� Open, ��� �����͸� ���Ͽ� ����
	*	@pre	������ �������� �ʾƾ� ��
	*	@post	���Ͽ� ����Ʈ ������ ����
	*	@return	�۵� �Ǿ����� 1, �۵� �ȵǾ����� 0 ����
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