#pragma once
#include <string>

enum class MakingType {
	HighPressure,
	Turkish,
	Filter,
	FrenchPress,
};

MakingType toMakingType(const std::string& s);