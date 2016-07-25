#include "Morse_Coder.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Morse_Coder::Morse_Coder() {
    letter_tree = build_morse_tree();
    code_key = {};
}

Binary_Tree<string> Morse_Coder::build_morse_tree() {
    // open file for reading & create ifstream object to work with
    ifstream fin("morse.txt");

    // create an empty tree to begin with
    Binary_Tree<string> result("");


    // declare variables to store parts of each line of the file in.
    string current_line;
    char temp_char;
    string letter;

    // for each line in the file

    do { // for each line of file 
        // make the variable local_root a pointer to the tree's root
        BTNode<string>* local_root = result.getRoot();
        getline(fin, current_line); // get first line of file as string
        stringstream line_of_file; // create a stringstream object
        line_of_file.str(current_line); // place the current line in the stringstream
        line_of_file >> temp_char; // read the first character (the letter) and strore it in temp_char
        letter = char_to_str(temp_char); // convert the letter to a string

        // read remaining character in line, creating/traversing left children
       // for '.' characters, and right children for '_' characters.
        while (line_of_file >> temp_char) {

            if (temp_char == '.') {
                if (local_root->left == NULL) {
                    local_root->left = new BTNode<string>("");
                }
                local_root = local_root->left;
            }
            if (temp_char == '_') {
                if (local_root->right == NULL) {
                    local_root->right = new BTNode<string>("");
                }
                local_root = local_root->right;
            }
        }

        local_root->data = letter;

    } while (!fin.eof()); // there are still lines in the file (Could hard-code this to exactly 26 iterations)

    cout << result.in_order() << endl;

    return result;
}


    string Morse_Coder::char_to_str(char the_char)
    {
        stringstream ss;
        string s;
        ss << the_char;
        ss >> s;
        return s;
    }

