//============================================================================
// Name        : Caesar Cipher.cpp
// Author      : Jesus (Zeus) Banda
// Version     : 03/06/2020
// Copyright   : (c) Zeus Banda
// Description : Decrypting the Ceasar Cipher from an Encrypted File
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	//Variables used
	ifstream ciphertextfile ("cipher.txt"); 		//used to read cipher.txt file
	ofstream plaintextfile ("plain.txt");			//Used to write to plain.txt file
	string line;									//Used to parse the cipher.txt file
	string cipher;									//used to hold a copy of the cipher.txt file as a string for manipulation
													//
	if (ciphertextfile.is_open()){					//check to see if ciphertextfile is a valid file if not output error
	    while (std::getline(ciphertextfile,line)){	//read lines from ciphertext file until the end.
	    	cipher += line;							//turns an entire file into one string named cipher
	    }
	    ciphertextfile.close();						//close the ciphertext file after parsing the file is done
	}

	else cout << "Unable to open ciphertextfile"; //report the error in opening file

	cout << "The Ciphertext is : " << cipher << endl;				//Output to the console the ciphertext
	plaintextfile << "The Ciphertext is : " << cipher << endl;		//output to the plaintextfile what the ciphertext is

	for(int offset = 1; offset <= 25; offset++){									// We are only focusing the shift on alphabetic characters so the key space is only 26, if we were working with different character set the offset/key space would be different
		for(int currentChar = 0; currentChar <= cipher.length(); currentChar++){   	// because we are only working with one string we have to traverse the entire string
			if(islower(cipher[currentChar])){										// the upper and lower character are treated differently because they have different decimal value representations
				cipher[currentChar] = (cipher[currentChar] + 1);					// for every character, shift the character by each offset in the key space
				if(cipher[currentChar] > 'z'){										// if the characters goes beyond the alphabet
					cipher[currentChar] = ((cipher[currentChar] %('z' + 1)) + 'a');	// circle back around to a after z
				}
			}else
			if(isupper(cipher[currentChar])){										// if the character is upper-case
				cipher[currentChar] = (cipher[currentChar] + 1);					// for every character, shift the character by each offset in the key space
				if(cipher[currentChar] > 'Z'){										// if the character goes beyond the upper-case alphabet
					cipher[currentChar] = ((cipher[currentChar] %('Z' + 1)) + 'A');	//circle back around to A if the alphabet is beyond Z
				}
			}
		}
		cout << "The Plaintext Generated by Key " << offset << " is: " << cipher << endl;			// output to the console
		plaintextfile << "The Plaintext Generated by Key " << offset << " is: " << cipher << endl;	// output to the plaintextfile
	}
	plaintextfile.close();																			// close the plaintextfile because we are done writing to it normally we would check to see if we can write to the file but its not necessary here.
}
