#include "caesar.hpp"
#include "analysis.hpp"

namespace caesar
{

// Encodes text given shift
void encode(std::string text, int k, std::string filename)
{
    std::string cipher;
    for (int i = 0; i < text.size(); i++)
    {
        char c = text[i];
        if (isalpha(c)) {
            char a = isupper(c) ? 'A' : 'a';
            c = (c - a + k) % 26 + a;
        }
        cipher.push_back(c);
    }

    // Output to File
    std::ofstream file(filename);
    file << cipher;
    file.close();
}

// Decodes cipher given shift
void decode(std::string cipher, int k, std::string filename)
{
    std::string text;
    for (int i = 0; i < cipher.size(); i++)
    {
        char c = cipher[i];
        if (isalpha(c)) {
            char a = isupper(c) ? 'A' : 'a';
            c = (c - a - k + 26) % 26 + a;
        }
        text.push_back(c);
    }

    // Output to File
    std::ofstream file(filename, std::ios_base::app);
    file << text << std::endl;
    file.close();
}

// Decodes cipher without shift
void decode(std::string cipher, std::string filename)
{
    // Determine shift using statistical analysis
    int k = analysis::frequencial(cipher);

    std::ofstream file(filename, std::ios_base::app);
    file << "Shift: " << k << std::endl;
    file.close();

    // Decode cipher
    return decode(cipher, k, filename);
}

}
