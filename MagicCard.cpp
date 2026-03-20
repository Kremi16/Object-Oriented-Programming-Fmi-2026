#define _CRT_SECURE_NO_WARNINGS
#include "MagicCard.h"

const char* MagicCard::converToString(Type type)const
{
	switch (type)
	{
	case Type::SPELL:return "spell";
	case Type::EQUIP: return "equip";
	case Type::TRAP:return "trap";
	default:return "none";
	}
}

const Type MagicCard::convertToType(const char* type)const
{
	if (strcmp(type, "spell") == 0)
	{
		return Type::SPELL;
	}
	else if (strcmp(type, "equip") == 0)
	{
		return Type::EQUIP;
	}
	else if (strcmp(type, "trap") == 0)
	{
		return Type::TRAP;
	}
	else
	{
		return Type::NONE;
	}
}

MagicCard::MagicCard():type(Type::SPELL)
{
	strcpy(name, " ");
	strcpy(effect, " ");
}

MagicCard::MagicCard(const char* name, const char* effect, const char* type)
{
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = convertToType(type);
}

void MagicCard::describeType()
{
	std::println("Magic cards have a name, effect and a type - spell, equip or trap.");
}

void MagicCard::printInfo()const
{
	std::println("{} is a {} with the following effect - {}.",name,MagicCard::converToString(type),effect);
}