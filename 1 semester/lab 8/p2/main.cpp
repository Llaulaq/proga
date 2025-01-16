#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

//Var 1
/*  Дана строка, содержащая английский текст. Если в тексте нет слов-палиндромов длиной 
более 1-й буквы, то вывести слова текста в соответствии с убыванием количества согласных, 
в противном случае пpодублиpовать в словах текста гласные буквы и вывести полученные слова в поpядке, 
обpатном к алфавитному.
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
    cnt = 0;
    while (!in.eof()) {
        in >> words[cnt];
        cnt++;
    }
    return true;
}


//writing words that match the conditions to a file
void write(int cnt, std::string words[N_MAX]) {
    for (int i = 0; i < cnt; ++i) {
        std::cout << "<" << words[i] << "> " <<'\n';
    }

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


bool isVowels(char c) {
    // lower case
    c = tolower(c);
    std::string vowels = "aeiou";
    return vowels.find(c) != std::string::npos;
}


//the function counts the number of consonants in a word
void numberConsonants(int cnt, std::string words[N_MAX], int countConsonants[N_MAX]) {
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < words[i].length(); ++j) {
            // lower case
            if (!isVowels(words[i][j])) {
                countConsonants[i]++;
            }
        }
    }
}


//sorting by non-decreasing number of consonant letters
void sortConsonants(int cnt, std::string words[N_MAX], int countConsonants[N_MAX]) {
    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            if (countConsonants[i] < countConsonants[j]) {
                std::swap(words[i], words[j]);
                std::swap(countConsonants[i], countConsonants[j]);
            }
        }
    }
}


//the function checks whether a word is a palindrome
bool isWordPalindrome(int cnt, std::string wordls[N_MAX]) {
    for (int i = 0; i < cnt; ++i) {
        std::string reverseWordl{ "" };
        if (wordls[i].length() < 2) {
            continue;
        }
        for (int j = wordls[i].length() - 1; j >= 0; --j) {
            reverseWordl += wordls[i][j];
        }
        if (wordls[i] == reverseWordl) {
            return true;
        }
    }
    return false;
}

//vowel duplication
void isVowels(std::string& s) {
    for (int i = 0; i < s.length(); ++i) {
        if (isVowels(s[i])) {
            //adding a consonant and shifting to avoid endless duplication
            s.insert(i, 1, s[i]);
            i++;
        }
    }   
}


//sort in reverse alphabetical order
void sortPalindrome(int cnt, std::string words[N_MAX]) {
    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            if (words[i] < words[j]) {
                std::swap(words[i], words[j]);
            }
        }
    }
}


int main() {
    int cnt{};
    std::string words[N_MAX];

    if (!read(cnt, words))
        return -1;

    clearWords(cnt, words);

    if (isWordPalindrome(cnt, words)) {
        for (int i = 0; i < cnt; ++i) {
            isVowels(words[i]);
        }
        sortPalindrome(cnt, words);
    }
    else {
        int countConsonants[N_MAX]{ 0 };
        numberConsonants(cnt, words, countConsonants);
        sortConsonants(cnt, words, countConsonants);
    }
     
    write(cnt, words);
    return 0;
}
