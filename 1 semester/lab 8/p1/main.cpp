#include <iostream>
#include <string>
#include <fstream>

//Var 1
/* Дан файл, содержащий английский текст. Найти в тексте N<=2000 слов,
содержащих наибольшее количество одинаковых букв. Записать найденные слова в
текстовый файл в порядке невозрастания количества одинаковых букв. Для каждого
слова вывести также это количество. Все найденные слова должны быть разными! */


const int N_MAX{ 2000 };


//reading a file
bool read(int& n, int& cnt, std::string words[N_MAX]) {
    std::ifstream in("input.txt");
    if (!in.is_open()) {
        std::cerr << "File not found" << '\n';
        return false;
    }

    //writing words from a file to an array of strings
    in >> n;
    cnt = 0;
    while (!in.eof()) {
        in >> words[cnt];
        cnt++;
    }
    return true;
}


//writing words that match the conditions to a file
void write(int n, int cnt, std::string words[N_MAX], int countLetters[N_MAX]) {
    std::string previous{ "" };

    for (int i = 0; i < cnt && n != 0; ++i) {
        if (words[i] != previous) {
            previous = words[i];
            std::cout << "<" << words[i] << "> " << countLetters[i] << '\n';
            n--;
        }
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


//counting identical letters
void countEqualLetters(int cnt, std::string words[N_MAX], int countLetters[N_MAX]) {
    for (int i = 0; i < cnt; ++i) {
        //array the number of characters of a single number
        char letters[256]{ 0 };
        // lower case
        for (int j = 0; j < words[i].length(); ++j) {
            char c = tolower(words[i][j]);
            letters[c]++;
        }

        int max{ INT_MIN };
        for (int k = 0; k < 256; ++k) {
            if (letters[k] > max) {
                max = letters[k];
            }
        }
        countLetters[i] = max;
    }
}


//sorting by non-increasing number of identical letters
void sort(int cnt, std::string words[N_MAX], int countLetters[N_MAX]) {
    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            if ((countLetters[i] < countLetters[j]) ||
                (countLetters[i] == countLetters[j] && words[i] < words[j])) {
                std::swap(countLetters[i], countLetters[j]);
                std::swap(words[i], words[j]);
            }
        }
    }
}


int main() {
    //the number of output words
    int n{};
    int cnt{};
    std::string words[N_MAX];

    if (!read(n, cnt, words))
        return -1;

    clearWords(cnt, words);
    //array of the maximum repeated letters in the index word [i] in an array words
    int countLetters[N_MAX]{ 0 };
    countEqualLetters(cnt, words, countLetters);

    sort(cnt, words, countLetters);

    write(n, cnt, words, countLetters);
    return 0;
}
