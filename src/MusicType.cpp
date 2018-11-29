#include "MusicType.h"

// Ű����� ��� ����
void MusicType::SetSongFromKB()
{
	cout << "\t���      : ";
	cin >> song;
}


// Ű����� ������ ����
void MusicType::SetSingerFromKB()
{
	cout << "\t������    : ";
	cin >> singer;
}


// Ű����� �ٹ� ����
void MusicType::SetAlbumFromKB()
{
	cout << "\t�ٹ���    : ";
	cin >> album;
}

// Ű����� �帣 ����
void MusicType::SetGenreFromKB()
{
	cout << "\t�帣      : ";
	cin >> genre;
}

// Ű����� ���� ����
void MusicType::SetLyricsFromKB()
{
	cout << "\t����      : ";
	getline(cin, lyrics, '\n');
	getline(cin, lyrics, '\n');
}

// Ű����� �뷡 ���� ����
void MusicType::SetRecordFromKB()
{
	SetSongFromKB();
	SetSingerFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}

void operator<<(ostream& out, MusicType& music)
{
	out << "\t���      : " << music.song << endl;
	out << "\t������    : " << music.singer << endl;
	out << "\t�ٹ���    : " << music.album << endl;
	out << "\t�帣      : " << music.genre << endl;
	out << "\t����      : " << music.lyrics << endl;
}

void operator<<(ofstream& out, MusicType& music)
{
	out << music.song << "\t" << music.singer << "\t" << music.album << "\t" << music.genre << endl;
	out << music.lyrics << endl;
}