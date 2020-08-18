#ifndef __VIGENERE_HPP__
#define __VIGENERE_HPP__

#include <iostream>
#include <fstream>

namespace vigenere
{

// Encoding
void encode(std::string text, std::string key, std::string filename);

// Decoding
void decode(std::string cipher, std::string key, std::string filename);
void decode(std::string cipher, int length, std::string filename);
void decode(std::string cipher, std::string filename);

}

#endif
