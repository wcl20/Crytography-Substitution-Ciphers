#include "beaufort.hpp"
#include "analysis.hpp"

namespace beaufort
{

// Encodes text given given key
void encode(std::string text, std::string key, std::string filename)
{
    std::string cipher;
    int j = 0;
    for (int i = 0; i < text.size(); i++)
    {
        char c = text[i];
        if (isalpha(c)) {
            char a = isupper(c) ? 'A' : 'a';
            char k = key[j++ % key.size()] - 'A';
            c = (k - (c - a) + 26) % 26 + a;
        }
        cipher.push_back(c);
    }

    // Output to File
    std::ofstream file(filename);
    file << cipher;
    file.close();
}

// Decodes cipher with given key
void decode(std::string cipher, std::string key, std::string filename)
{
    std::string text;
    int j = 0;
    for (int i = 0; i < cipher.size(); i++)
    {
        char c = cipher[i];
        if (isalpha(c)) {
            char a = isupper(c) ? 'A' : 'a';
            char k = key[j++ % key.size()] - 'A';
            c = (k - (c - a) + 26) % 26 + a;
        }
        text.push_back(c);
    }

    // Output to File
    std::ofstream file(filename, std::ios_base::app);
    file << text << std::endl;
    file.close();
}

// Decodes cipher with unknown key (only key length)
void decode(std::string cipher, int length, std::string filename)
{

    // Gather all letters that uses the same key letter
    std::string substrings[length];
    int i = 0;
    for (char const &c : cipher)
    {
        if (isalpha(c)) substrings[i++ % length].push_back(c);
    }

    // Determine each key letter using statistical analysis
    std::string key;
    for (std::string const &string: substrings)
    {
        // Transform text to vigenere encoding
        std::string reversed = reverse(string);
        key.push_back(analysis::frequencial(reversed) + 'A');
    }
    key = reverse(key);

    std::ofstream file(filename, std::ios_base::app);
    file << "Key: " << key << std::endl;
    file.close();

    return decode(cipher, key, filename);
}

// Decodes cipher without keys
void decode(std::string cipher, std::string filename)
{
    std::vector<std::string> texts;

    // Find possible key lengths using kasiski analysis
    std::vector<int> lengths = analysis::kasiski(cipher);

    // Decode text using each possible key length
    for (auto it = lengths.begin(); it != lengths.end(); it++)
    {
        decode(cipher, *it, filename);
    }
}

// Flip each character in the string. i.e. 'a' becomes 'z', 'b' becomes 'y' ...
std::string reverse(std::string string)
{
    for (char &c : string)
    {
        if (!isalpha(c)) continue;
        char a = isupper(c) ? 'A' : 'a';
        char z = 'Z' - 'A';
        c = z - (c - a) + a;
    }
    return string;
}
}
