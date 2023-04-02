#ifndef GAME_HPP
#define GAME_HPP

#include <QObject>
#include <string>
#include <set>

class Game : public QObject {
    Q_OBJECT

public: 
    explicit Game(QObject *parent = nullptr);

    Q_INVOKABLE void initializeGame();
    Q_INVOKABLE bool isGameWon();
    Q_INVOKABLE bool isGameLost();
    Q_INVOKABLE void handleGuess(QString guess);

signals:
    void currentGuessChanged(std::string currentGuess);
    void remainingGuessChanged(int remainingGuesses);

private:
    int m_remainingGuesses;
    std::string m_wordToGuess;
    std::string m_currentGuess;
    std::set<std::string> m_guessedLetters;
};

#endif