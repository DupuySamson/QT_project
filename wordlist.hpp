#ifndef WORDLIST_HPP
#define WORDLIST_HPP

#include <QObject>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextSteam>
#include <QDebug>

class WordList : public QObject {
    Q_OBJECT

public:
    WordList();
    QString getRandomWord const;
    bool contains(const QString& word) const;

private:
    QStringList m_words;
};

#endif