#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

std::string getRandomWord() {
    std::vector<std::string> words = {"saas", "merhaba", "bilgisayar", "programlama", "algoritma"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);
    return words[dis(gen)];
}

int main() {
    std::cout << "Adam Asmaca Oyununa Hoş Geldiniz!" << std::endl;
    std::string quest = getRandomWord();
    std::string answer(quest.length(), '_');
    std::string guessed_letters;
    char guess;
    
    int max_attempts = quest.length() + 2;  // Kelime uzunluğu + 2 hak
    int attempts = 0;
    
    while(answer != quest && attempts < max_attempts) {
        std::cout << "\nKelime: " << answer << std::endl;
        std::cout << "Kalan hak: " << max_attempts - attempts << "/" << max_attempts << std::endl;
        std::cout << "Tahmin edilen harfler: " << guessed_letters << std::endl;
        std::cout << "Bir harf tahmin edin: ";
        std::cin >> guess;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        guess = std::tolower(guess);
        
        if(std::isalpha(guess) && guessed_letters.find(guess) == std::string::npos) {
            guessed_letters += guess;
            
            if(quest.find(guess) != std::string::npos) {
                for(int i = 0; i < quest.length(); i++) {
                    if(quest[i] == guess) {
                        answer[i] = guess;
                    }
                }
                std::cout << "Doğru tahmin!" << std::endl;
            } else {
                std::cout << "Yanlış tahmin." << std::endl;
                attempts++;
            }
        } else if(guessed_letters.find(guess) != std::string::npos) {
            std::cout << "Bu harfi zaten tahmin ettiniz." << std::endl;
        } else {
            std::cout << "Lütfen geçerli bir harf girin." << std::endl;
        }
        attempts++;
    }
    
    if(answer == quest) {
        std::cout << "\nTebrikler! Kelimeyi doğru bildiniz: " << quest << std::endl;
    } else {
        std::cout << "\nÜzgünüm, hakkınız bitti. Doğru kelime: " << quest << std::endl;
    }
    
    return 0;
}
