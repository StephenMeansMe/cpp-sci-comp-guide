#ifndef EBOOKHEADERDEF
#define EBOOKHEADERDEF

#include <string>
#include <ch05/src/Book.hpp>

class Ebook: public Book {

public:
	Ebook();
	std::string hiddenUrl;
};

#endif //EBOOKHEADERDEF
