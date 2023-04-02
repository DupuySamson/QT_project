#include "game.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

Game::Game(QObject *parent) : QObject (parent){
    m_remainingGuesses = 10;
    m_wordToGuess = "";
    m_currentGuess = "";
}

void Game::initializeGame(){
    std::ifstream infile("wordlist.txt");
    std::string word;
    std::vector<std::string> words;

    while (infile >> word){
        words.push_back(word);
    }

    std::random_shuffle(words.begin(), words.end());
    m_wordToGuess = words[0];

    m_currentGuess = std::string(m_wordToGuess.length(), '_');

    emit currentGuessChanged(m_currentGuess);
    emit remainingGuessChanged(m_remainingGuesses);
}

bool Game::isGameWon(){
    return m_wordToGuess == m_currentGuess;
}

bool Game::isGameLost(){
    return m_remainingGuesses == 0;
}

void Game::handleGuess(QString guess){
    std::string guessStr = guess.toStdString();

    if(m_guessedLetters.find(guessStr) != m_guessedLetters.end()){
        std::cout <<"Vous avez déja deviné cette lettre" << std::endl;
        return;
    }

    m_guessedLetters.insert(guessStr);

    if(m_wordToGuess.find(guessStr) != std::string::npos){
        for(int i = 0; i < m_wordToGuess.length(); i++){
            if(m_wordToGuess[i] == guessStr[0]){
                m_currentGuess[i] == guessStr[0];
            }
        }
        emit currentGuessChanged(m_currentGuess);
    }else{
        m_remainingGuesses--;
        emit remainingGuessChanged(m_remainingGuesses);
    }
}