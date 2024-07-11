#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <vector>
#include <limits>

std::string getRandomWord() {
    std::vector<std::string> words = {
        "podcast", "emoji", "selfie", "blockchain", "influencer",
        "cryptocurrency", "streaming", "metaverse", "avatar", "tweet",
        "vlog", "binge", "meme", "drone", "hashtag",
        "startup", "cybersecurity", "algorithm", "bitcoin", "smartphone",
        "artificial", "virtual", "cloud", "digital", "quantum",
        "robotics", "biotechnology", "nanotechnology", "augmented", "wifi",
        "internet", "gigabit", "neural", "machine", "learning",
        "encryption", "firewall", "phishing", "malware", "software",
        "hardware", "database", "network", "interface", "protocol",
        "server", "router", "bandwidth", "pixel", "resolution"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);
    return words[dis(gen)];
}

int main() {
    std::cout << "Welcome to the Hangman Game!" << std::endl;

    std::string quest = getRandomWord();
    std::string answer(quest.length(), '_');
    std::string guessed_letters;
    char guess;
    
    int max_attempts = quest.length() + 2;  // Word length + 2 attempts
    int attempts = 0;

    while (answer != quest && attempts < max_attempts) {
        std::cout << "\nWord: " << answer << std::endl;
        std::cout << "Remaining attempts: " << max_attempts - attempts << "/" << max_attempts << std::endl;
        std::cout << "Guessed letters: " << guessed_letters << std::endl;
        std::cout << "Guess a letter: ";
        std::cin >> guess;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        guess = std::tolower(guess);

        if (std::isalpha(guess) && guessed_letters.find(guess) == std::string::npos) {
            guessed_letters += guess;

            if (quest.find(guess) != std::string::npos) {
                for (size_t i = 0; i < quest.length(); i++) {
                    if (quest[i] == guess) {
                        answer[i] = guess;
                    }
                }
                std::cout << "Correct letter!" << std::endl;
            } else {
                std::cout << "Incorrect letter." << std::endl;
                attempts++;
            }
        } else if (guessed_letters.find(guess) != std::string::npos) {
            std::cout << "You already guessed this letter." << std::endl;
        } else {
            std::cout << "Please enter a valid letter." << std::endl;
        }
    }

    if (answer == quest) {
        std::cout << "\nCongratulations! You guessed the word correctly: " << quest << std::endl;
    } else {
        std::cout << "\nSorry, you ran out of attempts. The correct word was: " << quest << std::endl;
    }

    return 0;
}
