#include <iostream>
#include <string>
#include <sstream>
#include <set>

#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) : copyrighted(copyrighted) {}

bool Article13Filter::blockIfCopyrighted(std::string s) {
	bool isBlocked = isCopyrighted(s);

	if (isBlocked)
		blocked.push_back(s);

	return isBlocked;
}
bool Article13Filter::isCopyrighted(std::string s) {
	return copyrighted.find(s) != copyrighted.end();
}

std::vector<std::string> Article13Filter::getBlocked() {
	return blocked;
}