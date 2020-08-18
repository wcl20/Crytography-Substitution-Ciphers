#include "analysis.hpp"

namespace analysis
{

// Determine shift by analysing character frequencies
int frequencial(std::string cipher)
{
    // Percentage of alphabet appearing in English
    double percentage[26] = {
        8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 2.0,
        0.8, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1,
        2.8, 1.0, 2.4, 0.2, 2.0, 0.1
    };

    // Create frequency table of the alphabets
    int frequency[26] = { 0 };
    for (char const &c : cipher)
    {
        if (isalpha(c)) {
            frequency[toupper(c) - 'A']++;
        }
    }

    // Use statistical analysis to determine shift.
    // Shift frequency table until it matches with the percentage
    int shift = 0;
    double max_product = 0.0;
    for (int k = 0; k < 26; k++)
    {
        double product = 0;
        for (int i = 0; i < 26; i++) {
            product += percentage[i] * frequency[(i + k) % 26];
        }
        if (product > max_product) {
            max_product = product;
            shift = k;
        }
    }

    return shift;
}

// Determine key length using kasiski analysis
std::vector<int> kasiski(std::string cipher)
{
    // Remove non characters
    cipher.erase(std::remove_if(cipher.begin(), cipher.end(),
      [](char c) { return !isalpha(c); }), cipher.end());

    // Transform all text to uppercase
    transform(cipher.begin(), cipher.end(), cipher.begin(), toupper);

    // Threshold length for pattern
    const int threshold = 3;

    // Max length of key
    const int max_length = 15;

    // Create a frequency table for factors
    int frequency[max_length] = { 0 };

    // Find repeating patterns
    for (int i = 0; i < cipher.size(); i++)
    {
        for (int j = i + 1; j < cipher.size(); j++)
        {
            int k = 0;
            while (cipher[i+k] == cipher[j+k]) k++;

            // Fepeating pattern excceeds threshold
            if (k < threshold) continue;

            // Calculate distance of until reoccuring pattern
            int distance = j - i;

            // Find all factors of distance
            for (int i = threshold; i < max_length; i++)
            {
                if (distance % i == 0) frequency[i]++;
            }
        }
    }

    // Return common factors with the highest frequency (Top 3)
    std::vector<int> lengths;
    for (int i = 0; i < 3; i++)
    {
        int max = *std::max_element(frequency, frequency + max_length);
        if (max == 0) break;

        for (int j = 0; j < max_length; j++)
        {
            if (frequency[j] == max) {
                lengths.push_back(j);
                frequency[j] = 0;
            }
        }
    }

    return lengths;
}

}
