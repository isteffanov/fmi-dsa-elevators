#include "Building.hpp"

Building::Building(size_t largeCap, size_t smallCap, size_t floorCap)
	:large(largeCap, floorCap), small(smallCap, floorCap), people(floorCap) {}
