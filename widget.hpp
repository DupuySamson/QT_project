#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>


#include "game.hpp"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Game* game, QWidget *parent = nullptr);
    ~Widget();

public slots:
    void handleGuessButtonClicked();
    void updateCurrentGuessLabel();
    void updateRemainingGuessesLabel(int remainingGuesses);

private:
    Game *m_game;
    QLabel *titleLabel;
    QLabel *currentGuessLabel;
    QPlainTextEdit *currentGuessEdit;
    QLabel *remainingGuessesLabel;
    QLabel *remainingGuessesValue;
    QLineEdit *guessLineEdit;
    QPushButton *guessButton;
};

#endif