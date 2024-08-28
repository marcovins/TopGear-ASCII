#ifndef MUSICANAOENCONTRADA_HPP
#define MUSICANAOENCONTRADA_HPP

#include <stdexcept>  // Necessário para std::runtime_error
#include <string>     // Necessário para std::string
#include <iostream>   // Necessário para std::cerr

using namespace std; 

class MusicaNaoEncontrada : public runtime_error {
public:
    explicit MusicaNaoEncontrada(const string& filename)
        : runtime_error("Musica nao encontrada: " + filename), filename_(filename) {}

    const char* what() const noexcept override {
        return ("Musica nao encontrada: " + filename_).c_str();
    }

    string getFilename() const {
        return filename_;
    }

private:
    string filename_;
};



#endif