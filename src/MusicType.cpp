#include "MusicType.h"

// 키보드로 곡명 설정
void MusicType::SetSongFromKB()
{
	cout << "\t곡명      : ";
	cin >> song;
}


// 키보드로 가수명 설정
void MusicType::SetSingerFromKB()
{
	cout << "\t가수명    : ";
	cin >> singer;
}


// 키보드로 앨범 설정
void MusicType::SetAlbumFromKB()
{
	cout << "\t앨범명    : ";
	cin >> album;
}

// 키보드로 장르 설정
void MusicType::SetGenreFromKB()
{
	cout << "\t장르      : ";
	cin >> genre;
}

// 키보드로 가사 설정
void MusicType::SetLyricsFromKB()
{
	cout << "\t가사      : ";
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
	out << "\t곡명      : " << music.song << endl;
	out << "\t가수명    : " << music.singer << endl;
	out << "\t앨범명    : " << music.album << endl;
	out << "\t장르      : " << music.genre << endl;
	out << "\t가사      : " << music.lyrics << endl;
}

void operator<<(ofstream& out, MusicType& music)
{
	out << music.song << "\t" << music.singer << "\t" << music.album << "\t" << music.genre << endl;
	out << music.lyrics << endl;
}