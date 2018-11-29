#include "ArtistType.h"



ArtistType::ArtistType()
{
	m_Length = 0;
}


ArtistType::~ArtistType()
{
}

void ArtistType::Add(SimpleMusicType inData)		// �ٹ��� �뷡 �߰�
{
	m_List.Add(inData);
	m_Length++;
}

void ArtistType::Delete(SimpleMusicType inData)	// �ٹ��� �뷡 ����
{
	m_List.DeleteItem(inData);
	m_Length--;
}

string ArtistType::GetArtistName()	// ������ ��������
{
	return ArtistName;
}

int ArtistType::GetLength()	// �ٹ� ���� ��������
{
	return m_Length;
}

void ArtistType::SetArtistName(string inArtistName)		// ������ ����
{
	ArtistName = inArtistName;
}

void ArtistType::SetRecord(string inArtistName)	// ������ ����
{
	ArtistName = inArtistName;
}

void ArtistType::DisplayArtistNameOnScreen()		// ȭ�鿡 ������ ���
{
	cout << "\t������    : " << ArtistName << endl;
}

void ArtistType::DisplaySongListOnScreen()		// ȭ�鿡 �ٹ�����Ʈ ���
{
	DisplayArtistNameOnScreen();
	cout << "������������������������������������������������������������������������������������" << endl;
	m_List.PrintTree(cout);
}
