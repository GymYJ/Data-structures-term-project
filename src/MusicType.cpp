#include "MusicType.h"

// 키보드로 곡명 설정
void MusicType::SetSongFromKB()
{
	cout << "\tSong   : ";
	cin >> song;
}


// 키보드로 가수명 설정
void MusicType::SetSingerFromKB()
{
	cout << "\tSinger : ";
	cin >> singer;
}


// 키보드로 앨범 설정
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum  : ";
	cin >> album;
}

// 키보드로 장르 설정
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre  : ";
	cin >> genre;
}

// 키보드로 가사 설정
void MusicType::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
	getline(cin, lyrics, '\n');
	getline(cin, lyrics, '\n');
}

// 키보드로 노래 정보 설정
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