#include <iostream>
#include <algorithm>
#include "cipher.h"

using namespace std;

int main(int argc, char **argv) {
    argCount(argc);
    /** Set arguments for program **/
    string cipherType = argv[1];
    string plainTextFile = R"(C:\Users\Misa Sandoval\Coding Projects\CS356\HW1-356\inputFile.txt)";
    //string plainTextFile = argv[2];
    string keyFile = argv[4];
    //string cipherTextFile = argv[3];
    string cipherTextFile = R"(C:\Users\Misa Sandoval\Coding Projects\CS356\HW1-356\outputFile.txt)";
    string cryptType = argv[5];

    if(setDirection(cryptType) == "Encryption"){
        cout<<"Encrypting plaintext...\n";
        set_key(); //successfully takes key.
        if(setCipherType(cipherType) == "block"){
            read(plainTextFile);
            vectorSplit(fullText);
            writeToCipherText(cipherText);
            cout<<"Done";
        }
        else if(setCipherType(cipherType) == "stream"){
            read(plainTextFile);
            streamEncrypt(fullText);
            writeToCipherText(cipherText);
        }
    }
    else if(setDirection(cryptType)== "Decryption"){
        cout<<"Decrypting ciphertext...\n";
        set_key();
        if(setCipherType(cipherType)== "block") {
            readDecrypt(cipherTextFile); //read decrypt is ok
            encryptSwap(cipherText);
            blockDecrypt(cipherText);
            for(auto x: fullTextNum){
                cout<<char(x);
            }
        }
        else if(setCipherType(cipherType)== "stream"){
            readDecrypt(cipherTextFile);
            cout<<'\n';
            streamDecrypt(cipherText);
            writeToPlainText(fullText);
        }
    }
    else if (setDirection(cryptType) =="Invalid"){
       cerr<<"Error: Invalid argument in argv[5]. Please input 'E' or 'D' ";
       exit(1);
    }



    /* TO DO: MAKE AN ENCRYPTION VERSION AND DECRYPTION VERSION.
     * STEP 1: IF ENCRYPT: READ IN, VECTOR SPLIT, blockEncrypt/padBlock->blockEncrypt ENCRYPT SWAP, WRITE TO OUTPUT done.
     * STEP 2: IF DECRYPT: READ IN FROM OUTPUT, SWAP, ENCRYPT, PAD BLOCK. ADD TO VECTOR, OUTPUT TO INPUT FILE.
     * STEP 3: TEST WITH MULTIPLE LINES
     * STEP 4: STREAM CIPHER: 1 VECTOR, XOR CONTINUOUSLY, SWAP CONTINUOUSLY WRITE TO CIPHER.
     * STEP 5: READ CIPHER, SWAP, XOR, WRITE TO PLAINTEXT.
     *TESTING
     */
    return 0;
}
