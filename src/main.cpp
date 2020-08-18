#include <iostream>
#include <fstream>
#include <sstream>
#include "vigenere.hpp"
#include "caesar.hpp"
#include "beaufort.hpp"

std::string read_file(std::string filename)
{
  // Read text from file
  std::ifstream file(filename);

  std::stringstream buffer;
  buffer << file.rdbuf();

  std::string text(buffer.str());
  return text;
}

int main() {

  std::string text = read_file("../plain.txt");
  std::string encoded;

  /***************************************************************
    Veigenere Cipher
  ****************************************************************/

  std::string key = "RANDOMKEY";

  vigenere::encode(text, key, "../results/VigenereEncoded.txt");
  encoded = read_file("../results/VigenereEncoded.txt");

  vigenere::decode(encoded, key, "../results/VigenereWithKey.txt");
  vigenere::decode(encoded, key.length(), "../results/VigenereWithLength.txt");
  vigenere::decode(encoded, "../results/VigenereWithoutKey.txt");

  /***************************************************************
    Caesar Cipher
  ****************************************************************/

  int shift = 18;

  caesar::encode(text, shift, "../results/CaesarEncoded.txt");
  encoded = read_file("../results/CaesarEncoded.txt");

  caesar::decode(encoded, shift, "../results/CaesarWithShift.txt");
  caesar::decode(encoded, "../results/CaesarWithoutShift.txt");

  /***************************************************************
    Beaufort Cipher
  ****************************************************************/

  key = "SECRETKEY";

  beaufort::encode(text, key, "../results/BeaufortEncoded.txt");
  encoded = read_file("../results/BeaufortEncoded.txt");

  beaufort::decode(encoded, key, "../results/BeaufortWithKey.txt");
  beaufort::decode(encoded, key.length(), "../results/BeaufortWithLength.txt");
  beaufort::decode(encoded, "../results/BeaufortWithoutKey.txt");

  return 0;
}
