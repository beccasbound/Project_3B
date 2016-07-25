#ifndef MORSE_CODER_H
#define MORSE_CODER_H

#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <map>



using namespace std;

class Morse_Coder {

public:
    Morse_Coder();


private:
    map<char, string> code_key;
    string plaintext;
    string ciphertext;
    Binary_Tree<char> letters;

    Binary_Tree<char> build_morse_tree();
    





};




#endif
