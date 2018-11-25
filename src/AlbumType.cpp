#include "AlbumType.h"



AlbumType::AlbumType()
{
	m_Length = 0;
}


AlbumType::~AlbumType()
{
}

void AlbumType::Add(SimpleMusicType inData)		// ���ϰ� �߰�
{
	m_List.Add(inData);
	m_Length++;
}

void AlbumType::Delete(SimpleMusicType inData)	// ���ϰ� ����
{
	m_List.DeleteItem(inData);
	m_Length--;
}

string AlbumType::GetArtistName()	// ������ ��������
{
	return ArtistName;
}

string AlbumType::GetAlbumName()	// �ٹ��� ��������
{
	return AlbumName;
}

int AlbumType::GetNumberOfContainMusic()	// ���ϰ� �� ��������
{
	return m_Length;
}

string AlbumType::GetPrimaryKey() // Primary key ��������
{
	return PrimaryKey;
}

void AlbumType::SetArtistName(string inArtistName)	// ������ ���� + primary key ����
{
	ArtistName = inArtistName;
	PrimaryKey = ArtistName + AlbumName;
}

void AlbumType::SetAlbumName(string inAlbumName)		// �ٹ��� ���� + primary key ����
{
	AlbumName = inAlbumName;
	PrimaryKey = ArtistName + AlbumName;
}

void AlbumType::SetRecord(string inArtistName, string inAlbumName)	// ��� ���ڵ� ����
{
	ArtistName = inArtistName;
	AlbumName = inAlbumName;
	PrimaryKey = ArtistName + AlbumName;
}

void AlbumType::DisplayArtistNameOnScreen()	// ȭ�鿡 ������ ���
{
	cout << "\tArtistName : " << ArtistName << endl;
}

void AlbumType::DisplayAlbumNameOnScreen()	// ȭ�鿡 �ٹ��� ���
{
	cout << "\tAlbumName : " << AlbumName << endl;
}

void AlbumType::DisplayNumberOfContainMusicOnScreen()	// ȭ�鿡 ���ϰ� �� ���
{
	cout << "\tNumberOfContainMusic : " << m_Length << endl;
}

void AlbumType::DisplayContainMusicListOnScreen()		// ȭ�鿡 ���ϰ��Ʈ ���
{
	DisplayArtistNameOnScreen();
	DisplayAlbumNameOnScreen();
	DisplayNumberOfContainMusicOnScreen();
	cout << "------------------------------------------" << endl;
	m_List.PrintTree(cout);
}

void AlbumType::DisplayRecordOnScreen()		// ȭ�鿡 ��� ���ڵ� ���
{
	DisplayArtistNameOnScreen();
	DisplayAlbumNameOnScreen();
	DisplayNumberOfContainMusicOnScreen();
}

void operator<<(ostream& out, AlbumType& album)
{
	out << "\tArtistName : " << album.ArtistName << endl;
	out << "\tAlbumName : " << album.AlbumName << endl;
	out << "\tNumberOfContainMusic : " << album.m_Length << endl;
}