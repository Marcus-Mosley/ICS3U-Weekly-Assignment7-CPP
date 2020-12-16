// Copyright (c) 2020 Marcus A. Mosley All rights reserved.
//
// Created by Marcus A. Mosley
// Created on December 2020
// This program translates text into Pig Latin

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>

std::string translator(std::vector<std::string> word_list) {
    // This function translates text into Pig Latin

    std::vector<std::string> latin_list;
    std::string temp_string;
    std::string pig_latin;
    int counter = 0;
    auto length = word_list.size();
    while (counter < length) {
        temp_string = word_list[counter];
        if (temp_string[0] == 'a' || temp_string[0] == 'e' ||
                temp_string[0] == 'i' || temp_string[0] == 'o' ||
                temp_string[0] == 'u') {
            temp_string = temp_string + "yay";
        } else {
            temp_string = temp_string + temp_string[0] + "ay";
            temp_string = temp_string.erase(0, 1);
        }
        if (counter == 0) {
            pig_latin += temp_string;
        } else {
            pig_latin += " " + temp_string;
        }
        counter += 1;
    }
    pig_latin[0] = toupper(pig_latin[0]);
    return pig_latin;
}


int main() {
    // This function receives input

    std::vector<std::string> word_list;
    std::string string;

    // Input
    std::cout << "Enter the text that is to be translated: ";
    std::getline(std::cin, string);
    transform(string.begin(), string.end(), string.begin(), ::tolower);
    std::istringstream split(string);
    std::string token;
    while (std::getline(split, token, ' ')) {
        word_list.push_back(token);
    }
    std::cout << "" << std::endl;
    // Call Functions
    std::string pig_latin = translator(word_list);

    std::cout << pig_latin << std::endl;
}
