#pragma once
#include<print>

enum class Type
{
	SPELL,
	EQUIP,
	TRAP,
	NONE
};

class MagicCard
{
private:
	char name[25];
	char effect[100];
	Type type;

	const char* converToString(Type type)const;
	const Type convertToType(const char* type)const;

public:
	MagicCard();

	MagicCard(const char* name, const char* effect, const char* type);

	static void describeType();

	void printInfo()const;
};

