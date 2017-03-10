#include"line_item.h"

LineItem::LineItem()
{
	std::chrono::time_point<std::chrono::system_clock> now;
	now = std::chrono::system_clock::now();

	std::time_t end_time = std::chrono::system_clock::to_time_t(now);

	strTimestamp = std::ctime(&end_time);
}

long LineItem::getSize()
{
	return sizeof(*this)+sizeof(strContent);
}

LineItem::~LineItem(){}