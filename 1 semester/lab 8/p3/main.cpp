#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

//Var 1
/* 	В текстовом файле input.txt записан английский текст. Найти в тексте слова,
содержащие не менее четырех из пяти наиболее часто встречающихся букв текста,
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным,
включая и знаки препинания.
*/


const int N_MAX{ 5120 };


//reading a file
bool read(int& cnt, std::string words[N_MAX]) {
    std::ifstream in("input.txt");
    if (!in.is_open()) {
        std::cerr << "File not found" << '\n';
        return false;
    }

    //writing words from a file to an array of strings
    cnt = { 0 };
    while (!in.eof()) {
        in >> words[cnt];
        cnt++;
    }
    return true;
}


//removing punctuation marks and other characters
void clearWords(int cnt, std::string words[N_MAX]) {
    //let's run through the word
    for (int i = 0; i < cnt; ++i) {
        //let's run through the symbols of the word
        for (int j = 0; j < words[i].length(); ++j) {
            //checking for the letter of the alphabet
            if (!isalpha(words[i][j])) {
                words[i].erase(j, 1);
                j--;
                continue;
            }
            words[i][j] = tolower(words[i][j]);
        }
    }
}

//The function counts the maximum number of individual letters in all words
void maxLetters(int cnt, std::string words[N_MAX], int countLetters[26], std::string alphabet) {
    for (int i = 0; i < cnt; ++i) {
        // lower case
        for (int j = 0; j < words[i].length(); ++j) {
            char c = tolower(words[i][j]);
            for (int k = 0; k < 26; ++k) {
                if (alphabet[k] == c) {
                    countLetters[k]++;
                }
            }
        }
    }
}


//top 5 repeating letters
void sortMaxLetters(int countLetters[26], std::string& maxLetters, std::string alphabet) {
    for (int i = 0; i < 26 - 1; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if (countLetters[i] < countLetters[j]) {
                std::swap(countLetters[i], countLetters[j]);
                std::swap(alphabet[i], alphabet[j]);
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        maxLetters += alphabet[i];
    }
}


//to count the top 5 duplicate letters in a single copy, delete all the duplicate letters in the word
void uniqueLetters(std::string& word) {
    for (int i = 0; i < word.length(); ++i) {
        for (int j = i + 1; j < word.length(); ++j) {
            if (word[i] == word[j]) {
                word.erase(j, 1);
                j--;
            }
        }
    }
}


//search for the top 5 letters in a word
void repeatMaxLetters(std::string word, std::string maxLetters, std::string& wordMaxLetters) {
    for (int i = 0; i < word.length(); ++i) {
        // lower case
        char c = tolower(word[i]);
        for (int j = 0; j < 5; ++j) {
            if (maxLetters[j] == c) {
                wordMaxLetters += maxLetters[j];
            }
        }

    }
}


//we make the letters of the word uppercase, without changing other characters
void bigWord(std::string& wordsNew) {
    for (int i = 0; i < wordsNew.length(); ++i) {
        if (wordsNew[i] >= 'a' && wordsNew[i] <= 'z') {
            wordsNew[i] = toupper(wordsNew[i]);
        }
    }   
}


//writing words that match the conditions to a file
void write(int cnt, std::string words[N_MAX], std::string maxLetters) {
    std::ifstream in("input.txt");
    std::string wordsNew{ "" };

    int n{ 0 };
    while (!in.eof()) {
        in >> wordsNew;
        
        uniqueLetters(words[n]);
        std::string wordMaxLetters{ "" };
        repeatMaxLetters(words[n], maxLetters, wordMaxLetters);

        if (wordMaxLetters.length() >= 4) {
            bigWord(wordsNew);
            std::cout << wordsNew << "(" << wordMaxLetters << ")" << " ";
        }
        else {
            std::cout << wordsNew << " ";
        }

        n++;
    }
}


int main() {
    int cnt{};
    std::string words[N_MAX];

    if (!read(cnt, words))
        return -1;
    clearWords(cnt, words);

    std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" };
    int countLetters[26]{ 0 };
    
    maxLetters(cnt, words, countLetters, alphabet);
    std::string maxLetters{ "" };
    sortMaxLetters(countLetters, maxLetters, alphabet);

    write(cnt, words, maxLetters);
    return 0;
}