#ifndef MORSE_CODER_H
#define MORSE_CODER_H

#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>



using namespace std;

class Morse_Coder {

public:
    Morse_Coder();
    string Morse_Coder::char_to_str(char the_char);
    Binary_Tree<string> build_morse_tree();

private:
    map<char, string> code_key;
    string plaintext;
    string ciphertext;
    Binary_Tree<string> letter_tree;

   
    





};




#endif
