#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileManager
{
	struct Meta {
		size_t floorsNum;
		size_t largeCap;
		size_t smallCap;
		size_t commandsNum;

		Meta(size_t floors = 0, size_t large = 0, size_t small = 0 ,  size_t commands = 0)
			:floorsNum(floors), largeCap(large), smallCap(small), commandsNum(commands) {}

		friend std::ifstream& operator>>(std::ifstream& stream, Meta& meta) {
			if (stream.is_open()) {
				size_t floors, large, small, commands;
				stream >> floors >> large>> small >> commands;

				meta = Meta(floors, large, small, commands);
			}
		}
	};

	std::ifstream stream;
	Meta meta;
	
public:
	FileManager(std::string file = "");

	size_t floors()	  const;
	size_t large()	  const;
	size_t small()	  const;
	size_t commands() const;
};

