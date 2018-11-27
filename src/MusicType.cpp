#include "MusicType.h"

// Ű����� ��� ����
void MusicType::SetSongFromKB()
{
	cout << "\tSong   : ";
	cin >> song;
}


// Ű����� ������ ����
void MusicType::SetSingerFromKB()
{
	cout << "\tSinger : ";
	cin >> singer;
}


// Ű����� �ٹ� ����
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum  : ";
	cin >> album;
}

// Ű����� �帣 ����
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre  : ";
	cin >> genre;
}

// Ű����� ���� ����
void MusicType::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
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
	out << "\tSong   : " << music.song << endl;
	out << "\tSinger : " << music.singer << endl;
	out << "\tAlbum  : " << music.album << endl;
	out << "\tGenre  : " << music.genre << endl;
	out << "\tLyrics : " << music.lyrics << endl;
}

void operator<<(ofstream& out, MusicType& music)
{
	out << music.song << "\t" << music.singer << "\t" << music.album << "\t" << music.genre << endl;
	out << music.lyrics << endl;
}