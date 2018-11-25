#include "AlbumType.h"



AlbumType::AlbumType()
{
	m_Length = 0;
}


AlbumType::~AlbumType()
{
}

void AlbumType::Add(SimpleMusicType inData)		// 수록곡 추가
{
	m_List.Add(inData);
	m_Length++;
}

void AlbumType::Delete(SimpleMusicType inData)	// 수록곡 삭제
{
	m_List.DeleteItem(inData);
	m_Length--;
}

string AlbumType::GetArtistName()	// 가수명 가져오기
{
	return ArtistName;
}

string AlbumType::GetAlbumName()	// 앨범명 가져오기
{
	return AlbumName;
}

int AlbumType::GetNumberOfContainMusic()	// 수록곡 수 가져오기
{
	return m_Length;
}

string AlbumType::GetPrimaryKey() // Primary key 가져오기
{
	return PrimaryKey;
}

void AlbumType::SetArtistName(string inArtistName)	// 가수명 설정 + primary key 설정
{
	ArtistName = inArtistName;
	PrimaryKey = ArtistName + AlbumName;
}

void AlbumType::SetAlbumName(string inAlbumName)		// 앨범명 설정 + primary key 설정
{
	AlbumName = inAlbumName;
	PrimaryKey = ArtistName + AlbumName;
}

void AlbumType::SetRecord(string inArtistName, string inAlbumName)	// 모든 레코드 설정
{
	ArtistName = inArtistName;
	AlbumName = inAlbumName;
	PrimaryKey = ArtistName + AlbumName;
}

void AlbumType::DisplayArtistNameOnScreen()	// 화면에 가수명 출력
{
	cout << "\tArtistName : " << ArtistName << endl;
}

void AlbumType::DisplayAlbumNameOnScreen()	// 화면에 앨범명 출력
{
	cout << "\tAlbumName : " << AlbumName << endl;
}

void AlbumType::DisplayNumberOfContainMusicOnScreen()	// 화면에 수록곡 수 출력
{
	cout << "\tNumberOfContainMusic : " << m_Length << endl;
}

void AlbumType::DisplayContainMusicListOnScreen()		// 화면에 수록곡리스트 출력
{
	DisplayArtistNameOnScreen();
	DisplayAlbumNameOnScreen();
	DisplayNumberOfContainMusicOnScreen();
	cout << "------------------------------------------" << endl;
	m_List.PrintTree(cout);
}

void AlbumType::DisplayRecordOnScreen()		// 화면에 모든 레코드 출력
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