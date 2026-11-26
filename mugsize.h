#pragma once
#include <string>

enum class MugSize {
	Small,
	Medium,
	Large,
};

MugSize toMugSize(const std::string& s);