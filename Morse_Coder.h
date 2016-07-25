#ifndef MORSE_CODER_H
#define MORSE_CODER_H

#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Morse_Coder {

public:
    Morse_Coder() { letters = build_morse_tree(); code_key = {}; }


private:
    map<char, string> code_key;
    string plaintext;
    string ciphertext;
    Binary_Tree letters;





}




#endif
