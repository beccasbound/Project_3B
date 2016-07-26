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

	//conver text into the morse code by using map
	string Morse_Coder::encode_to_code(string text)
	{
		// convert text to lower letters
		for (int j = 0; text[j] != '\0'; j++)
		{
			text[j] = tolower(text[j]);
		}
		//decalaring a map
		map<const char, string> encode;
		//initializing map
		encode['a'] = ".-";
		encode['b'] = "-...";
		encode['c'] = "-.-.";
		encode['d'] = "-..";
		encode['e'] = ".";
		encode['f'] = "..-.";
		encode['g'] = "--.";
		encode['h'] = "....";
		encode['i'] = "..";
		encode['j'] = ".---";
		encode['k'] = "-.-";
		encode['l'] = ".-..";
		encode['m'] = "--";
		encode['n'] = "-.";
		encode['o'] = "---";
		encode['p'] = ".--.";
		encode['q'] = "--.-";
		encode['r'] = ".-.";
		encode['s'] = "...";
		encode['t'] = "-";
		encode['u'] = "..-";
		encode['v'] = "...-";
		encode['w'] = ".--";
		encode['x'] = "-..-";
		encode['y'] = "-.--";
		encode['z'] = "--..";

		// iterator to iterate through map in order to find the right code for letter
		map<char, string>::iterator iter;
		string result;
		for (int i = 0; text[i]; i++)
		{
			result += encode.find(text[i])->second + " ";
		}
		return result;
	}
	
	// convert Morse code into text
	string Morse_Coder::decode_to_text(string text)
	{
		// create a binary tree
		Binary_Tree<string> Btree = build_morse_tree();
		string the_result;
		// initialize current node with a root of binary tree
		BTNode<string>* current = Btree.getRoot();
		// if current node is null return an empty sting
		if (current == NULL)
		{
			return "";
		}
		//loop through text in order to fing coresponding letter to code
		for (int i = 0; i <= text.length(); i++)
		{
			// error checking if inccorect code been entered
			if (text[i] != '.' || text[i] != '-' || text[i] != ' ' || text[i] != '\0')
			{
				return  "Incorrect code entered. Morse code should consis of dots: \".\" and dashes: \" - \" only.";
				
			}
			// if code equals . go left
			if (text[i] == '.')
			{
				if (current->left != NULL)
				{
					current = current->left;
				}

			}
			// if code equals - go right
			if (text[i] == '-')
			{
				if (current->right != NULL)
				{
					current = current->right;
				}
     		}
			// if space or end of text is reached get the data
			if (text[i] == ' ' || text[i]=='\0')
			{
				the_result += current->data;
				if (text[i] == '\n')
				{
					return the_result;
				}
				else if(text[i]==' ')
				{
					// make a current node point to the root
					current = Btree.getRoot();
				}
			}
		}
		return the_result;
	}

