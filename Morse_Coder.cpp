#include "Morse_Coder.h" 
#include <iostream>
#include <fstream>
#include <string>

Morse_Coder::Morse_Coder() {
    letter_tree = build_morse_tree();
    code_key = {};
}

Binary_Tree<string> Morse_Coder::build_morse_tree() {
    ifstream fin("morse.txt");
    Binary_Tree<string> result;
    // for each line in the file
    // 1. read in the first character and save it as temp variable "letter"
    // 2. do:
    //      read in next character. 
    //          if it's a dot, 
    //              if there is no left child, create it
    //              go to the left child
    //          if it's a dash,
    //              if there is no right child, create it
    //              go to the right child
    //    keep doing this while there are still more characters in the line
    // 3. Make the data of the current node equal to "letter".


    return result;
}
