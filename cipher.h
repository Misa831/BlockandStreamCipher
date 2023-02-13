//
// Created by Misa Sandoval on 2/8/2023.
//

#ifndef HW1_356_CIPHER_H
#define HW1_356_CIPHER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <vector>

/*-------------method declarations------------------*/
void vectorSplit(std::vector<char> &arg);
void blockEncrypt(std::vector<char> &arg);
void padBlock(std::vector<char> &arg);
void set_key();
void encryptSwap(std::vector<int> &vector1);
void writeToCipherText(const std::vector<int>& vector1);
void blockDecrypt(std::vector<int> &arg);
void streamEncrypt(std::vector<char> &arg);
void streamDecrypt(std::vector<int> &arg);
void writeToPlainText(const std::vector<char>& vector1);

/*--------------variables-----------------------------*/
const int blockSize = 16;
std::vector<char> fullText;
std::vector<char> block;
std::vector<char> keyVal;
std::vector<int> cipherText;
std::vector<int> fullTextNum;
/*--------------implementation-------------------------*/
void set_key(){
    std::ifstream path(R"(C:\Users\Misa Sandoval\Coding Projects\CS356\HW1-356\keyFile.txt)");
    if(!path.is_open()){
        std::cerr<<"Error: keyFile not open";
        exit(1);
    }
    char ch;
    while (path.get(ch)) {
        keyVal.push_back(ch);
    }
}

void argCount(int argc){
    if(argc <5){
        std::cerr<<"Error: Not enough arguments provided."<<'\n';
        exit(1);
    }
}

std::string setCipherType(std::string &arg1){
    if(arg1 == "B"){
        return "block";
    }
    else if(arg1 =="S"){
        return "stream";
    }
    else{
        std::cerr<<"Invalid Cipher Type in argv[1]: " + arg1;
        exit(1);
    }
}

std::string setDirection(std::string &arg5){
    if(arg5 == "E"){
        return "Encryption";
    }
    else if(arg5 =="D"){
        return "Decryption";
    }
    else{
        return "Invalid";
    }
}

void read(const std::string& filePath) {
    char ch;
    std::ifstream path(filePath);
    if(!path.is_open()){
        std::cerr<<"Error: unable to open file";
        exit(1);
    }
    while (path.get(ch)) {
        fullText.push_back(ch);
    }
    //std::c out<<fullText.size()<<'\n';
}
void readDecrypt(const std::string &filePath){
    std::ifstream path(filePath);
    if(!path.is_open()){
        std::cerr<<"Error: unable to open file";
        exit(1);
    }
    int x;
    while(path >> x){
        cipherText.push_back(x);
    }
}

void vectorSplit(std::vector<char> &arg) {
    int counter = 0;
    //std::c out<<"run";
    for(int i = 0; i < arg.size(); i++) {
         if (counter < 16) {  //while block
             block.push_back(arg[i]);
             counter++; //counts how many elements get pushed into block.
        }
         else{
             counter = 0; //reset counter back to 0 elems in block, push block to encrypt and clear the vector.
             blockEncrypt(block);
             block.clear();
             block.push_back(arg[i]); //in cleared vector, add the next element and count up again.
             counter++;
         }
     }
         if(block.size()<blockSize){ //push any blocks that aren't full to padBlock.
             padBlock(block);
         }
    blockEncrypt(block);
    }

void padBlock(std::vector<char> &arg) {
    char padChar = char(0x81);
while(arg.size()<16){
    arg.push_back(padChar);
}

}

void blockEncrypt(std::vector<char> &arg){
     int val;
     //std::c out<<"block encrypt run\n";
     for(int i = 0; i<blockSize; i++) {
         val = arg[i] ^ keyVal[i];
         cipherText.push_back(val);
     }


     encryptSwap(cipherText);
     //std::c out<<cipherText.size();
     cipherText.clear();
}

void blockDecrypt(std::vector<int> &arg){
    int val;
    int counter = 0;
    for(int i = 0; i<arg.size(); i++){
        if(counter <16) {
            val = arg[i] ^ keyVal[counter];
            fullTextNum.push_back(val);
            counter++;
        }
        else{
            counter =0;
            val = arg[i]^keyVal[counter];
            fullTextNum.push_back(val);
            counter++;
        }

    }
}

void encryptSwap(std::vector<int> &vector1) {
    size_t end = vector1.size()-1;
    for(size_t i = 0; i<vector1.size(); i++){
        if(vector1[i] %2 != 0){
            if(end>i){
                int temp = vector1[i];
                vector1[i] = vector1[end];
                vector1[end] = temp;
                end--;

            }
        }
    }
    //writeToCipherText(vector1);
}

void writeToCipherText(const std::vector<int>& vector1) {
std::ofstream output;
output.open(R"(C:\Users\Misa Sandoval\Coding Projects\CS356\HW1-356\outputFile.txt)", std::fstream::app);
for(auto x : vector1){
    output<<x<<' ';
}
output.close();
}

void writeToPlainText(const std::vector<char>& vector1) {
    std::ofstream output;
    output.open(R"(C:\Users\Misa Sandoval\Coding Projects\CS356\HW1-356\inputFile.txt)", std::fstream::app);
    for(auto x : vector1){
        output<<x;
    }
    output<<"\n"; //may remove based on format for longer streams.
    output.close();
}

void streamEncrypt(std::vector<char> &arg){
    int counter = 0;
    int cipherVal;
for(size_t i = 0; i<fullText.size(); i++){
    if(counter <16){
        cipherVal = arg[i] ^ keyVal[counter];
        cipherText.push_back(cipherVal);
        counter++;
    }
    else if(counter == 16){
        counter = 0;
        cipherVal = arg[i]^keyVal[counter];
        cipherText.push_back(cipherVal);
        counter++;
    }
}
}

void streamDecrypt(std::vector<int> &arg){
    int counter = 0;
    char val;
    for(size_t i = 0; i<arg.size();i++){
        if(counter <16){
            val = char(arg[i]^keyVal[counter]);
            fullText.push_back(val);
            counter++;
        }
        else if(counter == 16){
            counter = 0;
            val = char(arg[i]^keyVal[counter]);
            fullText.push_back(val);
            counter++;
        }
    }
}


#endif //HW1_356_CIPHER_H
