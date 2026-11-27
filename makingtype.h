#pragma once
#include <string>
#include <cstdint>

enum class MakingType : uint8_t {
	HighPressure,
	Turkish,
	Filter,
	FrenchPress,
	AeroPress,
	Capsule,
};

MakingType toMakingType(const std::string& s);