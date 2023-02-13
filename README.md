# BlockandStreamCipher

## Project Description
C++ implementation of a Block and Stream Cipher

## How to run this application
This program is run in a terminal, requiring 5 additional arguments. 
Argv[1] must be either a 'B' or an 'S' to desginate block or stream cipher. Not using B or S will result in an error messsage and exit status 1. 
Argv[2] is the name of the file to be read. 
Argv[3] is the name of the file for the output digest. 
argv[4] is the name of the file containing the key. 
argv[5] must be either an 'E' or a 'D'. This will determine if the program is encrypting or decrypting. 

Example command: 
' ./a.out B plaintext.txt cipherText.txt keyValue.txt E ' 
- This would encypt the plaintext to ciphertext and output the digest in cipherText.txt. 
Example Command 2: ""./a.out B plaintext.txt cipherText.txt keyValue.txt D" 
- This decrypts digest found in cipherText.txt, and outputs the contents in the terminal. 
Example Command 3: "./a.out S plaintext.txt cipherText.txt keyValue.txt E"
- Encrypts plaintext and inserts text into cipherText.txt. 
Example Command 4: "./a.out B plaintext.txt cipherText.txt keyValue.txt D" 
 - decrypts contents of the cipherText.txt. 
