#ifndef WORD_H
#define WORD_H

#include <map>
#include <string>

class Word {
	std::string word;
	static std::map<std::string, size_t> words;
	///size_t count;
public:

	Word(const std::string& word_);

	std::string getWord() const
	{
		return word;
	}
	
	size_t getCount() const;
	/*
	{
		return count;
	}
	*/

	
	bool operator < (const Word& other) const
	{
		return word < other.getWord();
	}
};

#endif //!WORD_H