// Arquivo: RandomNumberGenerator.hpp
#ifndef RANDOM_NUMBER_GENERATOR_HPP
#define RANDOM_NUMBER_GENERATOR_HPP

#include <random>

class RandomNumberGenerator {
private:
    // Variáveis de randomização
    std::random_device rd;  
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;

    // Construtor privado para impedir instância externa
    RandomNumberGenerator() 
        : generator(rd()), distribution(1, 10) {}  // Inicializa gerador e distribuição

    // Deleta o operador de cópia e atribuição para evitar múltiplas instâncias
    RandomNumberGenerator(const RandomNumberGenerator&) = delete;
    RandomNumberGenerator& operator=(const RandomNumberGenerator&) = delete;

public:
    // Método para obter a única instância da classe
    static RandomNumberGenerator& getInstance() {
        static RandomNumberGenerator instance;  // Instância única
        return instance;
    }

    // Método para obter um número aleatório entre 0 e 100
    int getRandomNumber() {
        return distribution(generator);
    }
};

#endif // RANDOM_NUMBER_GENERATOR_HPP
