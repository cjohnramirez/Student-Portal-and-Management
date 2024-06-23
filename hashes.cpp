#ifndef HASHES_H
#define HASHES_H
#include <string>

class Hashes {
public:
    virtual std::string pretendre_md5(const std::string& plaintext) {
        std::string hashv = "";
        for (char letter : plaintext) {
            std::string x = std::to_string(static_cast<int>(letter) ^ static_cast<int>(plaintext.length()));
            hashv += x;
        }
        return hashv;
    }   
};

#endif
