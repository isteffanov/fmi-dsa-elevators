#include "WaitingPeople.hpp"

WaitingPeople::WaitingPeople(size_t floors)
{
	people.reserve(floors);
	people = { 0, }; //fill with 0s
}
