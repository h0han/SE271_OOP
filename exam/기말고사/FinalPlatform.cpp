#include "FinalPlatform.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Encryption library - https://github.com/philipperemy/easy-encryption
static std::string base64_encode(const std::string& in) {

    std::string out;

    int val = 0, valb = -6;
    for (size_t jj = 0; jj < in.size(); jj++) {
        char c = in[jj];
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}

static std::string base64_decode(const std::string& in) {

    std::string out;

    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val = 0, valb = -8;
    for (size_t jj = 0; jj < in.size(); jj++) {
        char c = in[jj];
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

std::string AVAILABLE_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

int index(char c) {
	for(size_t ii = 0; ii < AVAILABLE_CHARS.size(); ii++) {
		if(AVAILABLE_CHARS[ii] == c) {
			// std::cout << ii << " " << c << std::endl;
			return ii;
		}
	}
	return -1;
}


std::string extend_key(std::string& msg, std::string& key) {
	//generating new key
	int msgLen = msg.size();
	std::string newKey(msgLen, 'x');
	int keyLen = key.size(), i, j;
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
	return newKey;
}


std::string encrypt_vigenere(std::string& msg, std::string& key) {
	size_t msgLen = msg.size(), keyLen = key.size(), i;
 	std::string encryptedMsg(msgLen, 'x');
    // char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
	std::string newKey = extend_key(msg, key);
 
    //encryption
    for(i = 0; i < msgLen; ++i) {
    	// std::cout << msg[i] << " " << isalnum(msg[i]) << std::endl;
    	if(isalnum(msg[i]) or msg[i] == ' ') {
    		encryptedMsg[i] = AVAILABLE_CHARS[((index(msg[i]) + index(newKey[i])) % AVAILABLE_CHARS.size())];
    	} else {
    		encryptedMsg[i] = msg[i];
    	}
    }
	
    encryptedMsg[i] = '\0';
    return encryptedMsg; 
}

std::string decrypt_vigenere(std::string& encryptedMsg, std::string& newKey) {
	// decryption
	int msgLen = encryptedMsg.size();
	std::string decryptedMsg(msgLen, 'x');
	int i;
    for(i = 0; i < msgLen; ++i) {
    	if(isalnum(encryptedMsg[i]) or encryptedMsg[i] == ' ') {
    		decryptedMsg[i] = AVAILABLE_CHARS[(((index(encryptedMsg[i]) - index(newKey[i])) + AVAILABLE_CHARS.size()) % AVAILABLE_CHARS.size())];
    	} else {
    		decryptedMsg[i] = encryptedMsg[i];
    	}
    }
    decryptedMsg[i] = '\0';
	return decryptedMsg;
}

#include <cassert>

std::string encrypt(std::string& msg, std::string& key) {
	std::string b64_str = base64_encode(msg);
	std::string vigenere_msg = encrypt_vigenere(b64_str, key);
	// std::cout << vigenere_msg << std::endl;

    assert(std::find(vigenere_msg.begin(), vigenere_msg.end(), '\n') == vigenere_msg.end());

	return vigenere_msg;
}


std::string decrypt(std::string& encrypted_msg, std::string& key) {
	std::string newKey = extend_key(encrypted_msg, key);
	std::string b64_encoded_str = decrypt_vigenere(encrypted_msg, newKey);
	std::string b64_decode_str = base64_decode(b64_encoded_str);
	return b64_decode_str;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <string>
static int getLines(std::string filename) {
    int i = 0;
    ifstream f(filename);
    std::string line;
    while (std::getline(f, line)) {
        ++i;
    }
    return i;
}

static inline bool exists(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

#define HEADER "Happy Holiday!"
void encodefiles(std::vector<std::string> filenames, std::string key, std::string outfile) {
    ofstream ofile(outfile);
    auto h = std::string(HEADER);
    std::string header = encrypt(h, key) + "\n";
    ofile.write(header.c_str(), header.size());

	auto t = std::to_string(filenames.size());
	auto tt = encrypt(t, key) + "\n";
	ofile.write(tt.c_str(), tt.size());

    for (auto filename : filenames) {
		std::string fn_enc = encrypt(filename, key) + "\n";
		ofile.write(fn_enc.c_str(), fn_enc.size());
        auto l = std::to_string(getLines(filename));
        auto line = encrypt(l, key) + "\n";
		ofile.write(line.c_str(), line.size());
    }

    for (auto filename : filenames) {
		ifstream f(filename);
		std::string line;
		while (std::getline(f, line)) {
			auto line_enc = encrypt(line, key) + "\n";
			ofile.write(line_enc.c_str(), line_enc.size());
		}
    }

    ofile.close();
}

#include <random>
void problemB2Scrambler() {
    ifstream f("ProblemB2.cpp");
    if (!f.good())
        return;

    std::vector<std::vector<std::string>> blocks;
    std::vector<std::string> newblock;
	std::string line;
	while (std::getline(f, line)) {
        newblock.push_back(line);

		size_t n = std::count(line.begin(), line.end(), '#');
        if (n > 50) {
            blocks.push_back(newblock);
            newblock.clear();
        }
    }
	blocks.push_back(newblock);
    if (blocks.size() != 7)
        return;

	std::random_device rd;
    std::mt19937 random_gen;
	random_gen.seed(rd());
	std::uniform_real_distribution<float> coin(0, 1);
    auto p = coin(random_gen);
    auto& b = blocks;

    for (int i = 0; i < 100; ++i) {
		auto p = coin(random_gen);
        if (p <= 0.3) {
            std::swap(b[1], b[3]);
        }
        else if (p >= 0.6) {
            std::swap(b[3], b[5]);
        }
        else {
            std::swap(b[5], b[1]);
        }
    }


	ofstream of("ProblemB2.cpp");
    if (!of.good())
        return;

    for (auto tb : blocks) {
        for (auto s : tb) {
            of.write(s.c_str(), s.size());
			of.write("\n", 1);
        }
    }
}


static bool decodeFiles(std::string key, std::string infile) {
    if (!exists(infile))
        return false;

	std::string line;
	ifstream f(infile);
    std::getline(f, line);
    if (decrypt(line, key) != HEADER)
        return false;

    std::getline(f, line);
    int filecount = atoi(decrypt(line, key).c_str());

    std::vector<std::string> filenames;
    std::vector<int> filelines;
    bool doscramble = false;
    for (int i = 0; i < filecount; ++i) {
        std::string filename;
		std::getline(f, filename);
        filename = decrypt(filename, key);
        filenames.push_back(filename);

        if (filename == "ProblemB2.cpp")
            doscramble = true;

        std::string filelength;
		std::getline(f, filelength);
        filelength = decrypt(filelength, key);
        int linecount = atoi(filelength.c_str());
        filelines.push_back(linecount);
    }

    for (size_t i = 0; i < filenames.size(); ++i) {
        auto filename = filenames[i];
        auto linecount = filelines[i];

        // If you meet some problem to overwrite the file, 
        // Use this instead
        // ofstream eachf(filename + ".tmp"); 
        ofstream eachf(filename);
        assert(eachf.good());

        for (int j = 0; j < linecount; ++j) {
            std::getline(f, line);
            line = decrypt(line, key);
            eachf.write(line.c_str(), line.size());
            eachf.write("\n", 1);
        }
    }


    ofstream descf("desc.txt");
    std::string ttt = "You're now solving : ";
    descf.write(ttt.c_str(), ttt.size());
    for (auto fn : filenames) {
        descf.write(fn.c_str(), fn.size());
        descf.write(", ", 2);
    }

    if (doscramble)
        problemB2Scrambler();

    return true;
}

static bool load_description() {
    if (!exists("desc.txt")) {
        std::cout << "Can't find ready problems. Waiting for a new code." << std::endl;
        return false;
    }

    ifstream f("desc.txt");
    std::string line;
	while (std::getline(f, line)) {
        std::cout << line << std::endl;
    }
    
    return true;
}


#include <chrono>
#include <ctime>    
#include <iomanip>


void save_sourcecode() {
    auto filelist = {
        "ProblemA.h", "ProblemA.cpp",
        "ProblemB1.hpp", "ProblemB2.h", "ProblemB2.cpp",
        "ProblemC.h", "ProblemC.cpp",
        "ProblemD.h", "ProblemD.cpp", "ProblemD_Provided.cpp",
    };

	std::ofstream outfile;
	outfile.open("history.txt", std::ios_base::app);

	auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    outfile << ">>>>>>>>" << now_time << '\n';

    for (auto filename : filelist) {
		outfile << "[[[[[" << filename << "]]]]]" << std::endl;
        ifstream f(filename);
        std::string line;
        while (std::getline(f, line)) {
			outfile << line << std::endl;
        }

    }
}

FinalPlatform::FinalPlatform() {
    
}

bool FinalPlatform::check() {
    save_sourcecode();

    load_description();

    std::string answer;
    std::cout << ">> Do you have a new passcode? " << std::endl;
    std::cout << "(Y or y if you have, type any other words if you want to run your source code)" << std::endl;
    std::cin >> answer;
    if (answer == "y" || answer == "Y") {
        std::string key;
		std::cout << "Enter the passcode: " << std::endl;
		std::cout << "Important: Don't enter the passcode already used. It may overwrite !" << std::endl;
		std::cin >> key;
        auto filelist = {
            "Test.se271",
            "Exam.11.se271", "Exam.21.se271", "Exam.31.se271",
            "Exam.12.se271", "Exam.22.se271", "Exam.32.se271",
            "Exam.13.se271", "Exam.23.se271", "Exam.33.se271",
            "Exam.4.se271",
        };

        bool isDecode = false;
        for (auto f : filelist) {
            if (decodeFiles(key, f)) {
                std::cout << "Sucessfully create a new problem." << std::endl;
				load_description();
                isDecode = true;
                break;
            }
        }

        if (!isDecode) {
			std::cout << "Can't create a new problem. Check your passcode again." << std::endl;
        }

		return false;
    }

    return true;
}
