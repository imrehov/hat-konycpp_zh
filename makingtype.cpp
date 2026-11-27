#include "makingtype.h"
#include <stdexcept>

MakingType toMakingType(const std::string& s) {
	if (s == "HighPressure")
		return MakingType::HighPressure;
	if (s == "Turkish")
		return MakingType::Turkish;
	if (s == "Filter")
		return MakingType::Filter;
	if (s == "FrenchPress")
		return MakingType::FrenchPress;
	if (s == "AeroPress")
		return MakingType::AeroPress;
	if (s == "Capsule")
		return MakingType::Capsule;
	else
		throw std::invalid_argument("Invalid MakingType");
}