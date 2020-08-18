# Cryptography Substitution Ciphers
Implementation of basic substitution ciphers:
* Caesar Cipher
* Vigenere Cipher
* Beaufort Cipher

These ciphers can be cracked using different analysis:
* Frequential analysis can determine the shift by analysing the frequency of each letter.
* Kasiski analysis can determine the key length by finding repeating patterns.

## Setup
Create build directory
```bash
mkdir build && cd $_
```
Create MAKEFILE
```bash
cmake ..
```
Create executable
```bash
make
```
Run executable
```bash
./main
```
The program reads plain text from plain.txt, then encrypts the text using different ciphers.

The program then tries to decrypt the encoded message with a known key, or unknown key.
