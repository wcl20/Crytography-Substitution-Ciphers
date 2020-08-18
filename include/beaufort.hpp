#ifndef __BEAUFORT_HPP__
#define __BEAUFORT_HPP__

#include <iostream>
#include <fstream>

namespace beaufort
{

// Encoding
void encode(std::string text, std::string key, std::string filename);

// Decoding
void decode(std::string cipher, std::string key, std::string filename);
void decode(std::string cipher, int length, std::string filename);
void decode(std::string cipher, std::string filename);

// Helper
std::string reverse(std::string string);
}

#endif
