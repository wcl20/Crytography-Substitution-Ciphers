#ifndef __CAESAR_HPP__
#define __CAESAR_HPP__

#include <iostream>
#include <fstream>

namespace caesar
{
// Encoding
void encode(std::string text, int k, std::string filename);

// Decoding
void decode(std::string cipher, int k, std::string filename);
void decode(std::string cipher, std::string filename);
}

#endif
