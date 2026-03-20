#define _CRT_SECURE_NO_WARNINGS
#include "Song.h"

const char* Song::convertToString(const Genre& genre)
{
	switch (genre)
	{
	case Genre::CLASSICAL:return "Classical";
	case Genre::POP:return "Pop";
	case Genre::POPFOLK: return "Pop folk";
	case Genre::ROCK: return "Rock";
	default:return "Other";
	}
}

Genre Song::convertToGenre(const char* genre)
{
	if (strcmp(genre, "Classical") == 0)
	{
		return Genre::CLASSICAL;
	}
	else if (strcmp(genre, "Pop") == 0)
	{
		return Genre::POP;
	}
	else if (strcmp(genre, "Pop folk") == 0)
	{
		return Genre::POPFOLK;
	}
	else if (strcmp(genre, "Rock") == 0)
	{
		return Genre::ROCK;
	}
	else
	{
		return Genre::OTHER;
	}
}

Song::Song()
{
	name = new char[DEFAULT_SIZE+1];
	name[DEFAULT_SIZE] = '\0';
	duration.min = 0;
	duration.sec = 0;
	genre = Genre::OTHER;
}

Song::Song(const char* name, Duration d, Genre g):duration(d),genre(g)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

Song::Song(const char* name, Duration d, const char* genre):duration(d)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->genre = convertToGenre(genre);
}

Song::~Song()
{
	delete[]name;
	name = nullptr;
}

bool Song::operator==(const Song& other)const
{
	if (strcmp(name, other.name) == 0 && duration.min == other.duration.min &&
		duration.sec==other.duration.sec && genre == other.genre)
	{
		return true;
	}

	return false;
}

void Song::copyFrom(const Song& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	duration = other.duration;
	genre = other.genre;
}

void Song::free()
{
	delete[]name;
	name = nullptr;
}

Song::Song(const Song& other)
{
	copyFrom(other);
}

Song& Song::operator=(const Song& other)
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);

	return *this;
}

const char* Song::getName()const
{
	return name;
}

Duration Song::getDuration()const
{
	return duration;
}

Genre Song::getGenre()const
{
	return genre;
}

void Song::setName(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Song::setDuration(const Duration& d)
{
	if (d.min < 0 || d.min >= 60 || d.sec < 0 || d.sec >= 60)
	{
		return;
	}

	duration = d;
}

void Song::setGenre(const Genre& g)
{
	genre = g;
}

void Song::printSong()const
{
	std::println("Name:{},Duration:{:02}:{:02},Genre:{}", name, duration.min, 
		duration.sec,convertToString(genre));
	std::println();
}