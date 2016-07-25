/******************************************************************************
This is the control file for the Morse_Coder class. It creates a Morse_Coder
object, then uses it to encode a plaintext message and decode a cipertext
message. A message must be a string consisting of a single word.
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Morse_Coder.h"

using namespace std;

int main() {
    string plaintext_in, plaintext_out, ciphertext_in, ciphertext_out;

    Morse_Coder session = Morse_Coder();
   // ciphertext_out = session.encode(plaintext_in);
  //  plaintext_out = session.decode(ciphertext_in);

    
    system("pause");
    return 0;
}