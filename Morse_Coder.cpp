#include "Morse_Coder.h" 
#include <iostream>
#include <fstream>

Morse_Coder::Morse_Coder() {
    ifstream fin("morse.txt");
    letters = build_morse_tree();
    code_key = {};
}

Binary_Tree<char> Morse_Coder::build_morse_tree() {

    return letters;
}
