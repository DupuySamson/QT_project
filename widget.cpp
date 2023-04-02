#include "widget.hpp"
#include "game.hpp"


Widget::Widget(QWidget *parent):
    QWidget(parent)
    
{
    m_game(new Game(this))
    titleLabel = new QLabel("Pendu");
    currentGuessLabel = new QLabel("Mot: ");
    currentGuessEdit = new QPlainTextEdit();
    currentGuessEdit->setReadOnly(true);
    remainingGuessLabel = new QLabel("Essai restant: ");
    remainignGuessValue = new QLabel(QString::number(m_game->getRemainingGuesses()));
    guessLabel = new QLabel("Proposer une lettre: ");
    guessLineEdit = new QLineEdit();
    guessButton = new QPushButton("Proposer!");

    QVBoxLayout *layout = newQVBoxLayout();
    layout->addWidget(titleLabel);
    layout->addWidget(currentGuessLabel);
    layout->addWidget(currentGuessEdit);
    layout->addWidget(remainingGuessLabel);
    layout->addWidget(remainingGuessValue);
    layout->addWidget(guessLabel);
    layout->addWidget(guessLineEdit);
    layout->addWidget(guessButton);

    setLayout(layout);
    setWindowTitle("Pendu basique ...");

    m_game->initializeGame(this);

    connect(m_game, &Game::currentGuessChanged, this, &Widget::updateCurrentGuessLabel);
    connect(m_game, &Game::remainingGuessChaned, this, &Widget::updateremainingGuessesLabel);
    connect(guessButton, &QPushButton::clicked, this, &Widget::handleGuessButtonClicked);

    updateCurrentGuessLabel(m_game->currentGuess());
    updateRemainingGuessLabel(m_game->remainingGuesses());
}

Widget::~Widget()
{
}

void Widget::handleGuessButtonClicked()
{
    QString guess = guessLineEdit->text();

    m_game->handleGuess(guess);

    guessLineEdit->clear();
}

void Widget::updateCurrentGuessLabel(QString currentGuess)
{
    currentGuessLabel->setText(currentGuess);
}

void Widget::updateRemainingGuessLabel(int remainingGuesses){
    remainingGuessesLabel->setText(QString::number(remainingGuesses));
}

