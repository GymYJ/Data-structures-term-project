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

void MusicType::SetSongWriterFromKB()
{
	cout << "\t�۰    : ";
	cin >> songwriter;
}

void MusicType::SetLyricWriterFromKB()
{
	cout << "\t�ۻ簡    : ";
	cin >> lyricwriter;
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
	SetSongWriterFromKB();
	SetLyricWriterFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}

void operator<<(ostream& out, MusicType& music)
{
	out << "\t���      : " << music.song << endl;
	out << "\t������    : " << music.singer << endl;
	out << "\t�۰    : " << music.songwriter << endl;
	out << "\t�ۻ簡    : " << music.lyricwriter << endl;
	out << "\t�ٹ���    : " << music.album << endl;
	out << "\t�帣      : " << music.genre << endl;
	out << "\t����      : " << music.lyrics << endl;
}

void operator<<(ofstream& out, MusicType& music)
{
	out << music.song << "\t" << music.singer << "\t" << music.songwriter << "\t" << music.lyricwriter << "\t" << music.album << "\t" << music.genre << endl;
	out << music.lyrics << endl;
}