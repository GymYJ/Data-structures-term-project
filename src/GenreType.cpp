#include "GenreType.h"


// 기본 생성자, 크기는 10, 길이는 0 으로 초기화
GenreType::GenreType()
{
	m_Length = 0;
}

// 소멸자
GenreType::~GenreType()
{
}

// 리스트 길이 가져오기
int GenreType::GetLength()
{
	return m_Length;
}

// 장르별로 SimpleMusic 출력
void GenreType::DisplayListOnScreen()
{
	cout << "\t장르      : " << genre << endl;
	cout << "──────────────────────────────────────────" << endl;
	m_List.PrintTree(cout);
}

// 리스트에 music 추가
void GenreType::Add(SimpleMusicType inData)
{
	m_List.Add(inData);
	m_Length++;
}

// 리스트에서 music 삭제
void GenreType::Delete(SimpleMusicType inData)
{
	m_List.DeleteItem(inData);
	m_Length--;
}

