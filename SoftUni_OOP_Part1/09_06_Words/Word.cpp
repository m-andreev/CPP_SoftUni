#include "Word.h"

std::map<std::string, size_t> Word::words;

Word::Word(const std::string & word_) : word(word_) {
	words[word]++;
}

size_t Word::getCount() const {
	size_t count = words[word];
	words.erase(word);

	return count;

}
