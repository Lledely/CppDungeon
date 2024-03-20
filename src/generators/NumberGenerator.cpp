//
// Created by Амир Кашапов on 16.03.2024.
//
#include "generators/NumberGenerator.h"
#include <random>
std::mt19937 generators::NumberGenerator::getGenerator() {
    static std::random_device randomDevice;
    static std::mt19937 generatorDevice = std::mt19937(12);
    return generatorDevice;
}
int generators::NumberGenerator::generate() {
    return getGenerator()();
}

int generators::NumberGenerator::generate(int minNumber, int maxNumber) {
    std::uniform_int_distribution<> distribution(minNumber, maxNumber);
    static std::mt19937 generatorDevice = getGenerator();
    return distribution(generatorDevice);
}