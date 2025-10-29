#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include <openssl/evp.h>
#include<fmt/core.h>

using namespace std;




// i copied it from the internet
std::string sha256(const std::string& str) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (context == nullptr) {
        throw std::runtime_error("EVP_MD_CTX_new failed");
    }

    if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(context);
        throw std::runtime_error("EVP_DigestInit_ex failed");
    }

    if (EVP_DigestUpdate(context, str.c_str(), str.length()) != 1) {
        EVP_MD_CTX_free(context);
        throw std::runtime_error("EVP_DigestUpdate failed");
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int lengthOfHash = 0;

    if (EVP_DigestFinal_ex(context, hash, &lengthOfHash) != 1) {
        EVP_MD_CTX_free(context);
        throw std::runtime_error("EVP_DigestFinal_ex failed");
    }

    EVP_MD_CTX_free(context);

    std::stringstream ss;
    for (unsigned int i = 0; i < lengthOfHash; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}

std::string sha256_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (context == nullptr) {
        throw std::runtime_error("EVP_MD_CTX_new failed");
    }

    if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(context);
        throw std::runtime_error("EVP_DigestInit_ex failed");
    }

    // Read file in chunks and update hash
    char buffer[4096];
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        if (EVP_DigestUpdate(context, buffer, file.gcount()) != 1) {
            EVP_MD_CTX_free(context);
            throw std::runtime_error("EVP_DigestUpdate failed");
        }
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int lengthOfHash = 0;

    if (EVP_DigestFinal_ex(context, hash, &lengthOfHash) != 1) {
        EVP_MD_CTX_free(context);
        throw std::runtime_error("EVP_DigestFinal_ex failed");
    }

    EVP_MD_CTX_free(context);
    file.close();

    std::stringstream ss;
    for (unsigned int i = 0; i < lengthOfHash; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}


// string read_file_contents(string path){
// 	ifstream file(path);
// 
// 
// 	if(!file.is_open()){
// 		cout << "Sorry! We can't open this file right now!";
// 		exit(0);
// 	}
// 
// 	
// 	string contents = "", row;
// 
// 	while(getline(file, row)){
// 		contents += row;
// 	}
// 
// 	return contents;
// }









int main(int argcount, char* argv[]){
	// read file path
	if(argcount <= 1){
		cout << "Please pass file path to get SHA256 hash" << endl;
		cout << "Usage: ./hash.bin ./file_path" << endl;
		
		exit(0);
	}


	string file_path = argv[1];
	string hash = sha256_file(file_path);
	
	cout << fmt::format("SHA256(hash={}, file={})\n", hash, file_path);


	return 0;
}
