#pragma once
#include <string>
#include <cstdint>

enum class MugSize : uint8_t {
	Small,
	Medium,
	Large,
};

MugSize toMugSize(const std::string& s);