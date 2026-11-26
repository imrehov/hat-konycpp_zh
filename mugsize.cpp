#include "mugsize.h"
#include <stdexcept>

MugSize toMugSize(const std::string& s) {
	if (s == "Small")
		return MugSize::Small;
	if (s == "Medium")
		return MugSize::Medium;
	if (s == "Large")
		return MugSize::Large;
	else
		throw std::invalid_argument("Invalid MugSize");
}