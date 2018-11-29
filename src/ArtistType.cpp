#include "ArtistType.h"



ArtistType::ArtistType()
{
	m_Length = 0;
}


ArtistType::~ArtistType()
{
}

void ArtistType::Add(SimpleMusicType inData)		// 앨범에 노래 추가
{
	m_List.Add(inData);
	m_Length++;
}

void ArtistType::Delete(SimpleMusicType inData)	// 앨범에 노래 삭제
{
	m_List.DeleteItem(inData);
	m_Length--;
}

string ArtistType::GetArtistName()	// 가수명 가져오기
{
	return ArtistName;
}

int ArtistType::GetLength()	// 앨범 개수 가져오기
{
	return m_Length;
}

void ArtistType::SetArtistName(string inArtistName)		// 가수명 설정
{
	ArtistName = inArtistName;
}

void ArtistType::SetRecord(string inArtistName)	// 가수명 설정
{
	ArtistName = inArtistName;
}

void ArtistType::DisplayArtistNameOnScreen()		// 화면에 가수명 출력
{
	cout << "\t가수명    : " << ArtistName << endl;
}

void ArtistType::DisplaySongListOnScreen()		// 화면에 앨범리스트 출력
{
	DisplayArtistNameOnScreen();
	cout << "──────────────────────────────────────────" << endl;
	m_List.PrintTree(cout);
}
