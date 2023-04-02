#include "wordlist.hpp"

WordList::WordList(){
    QFile file(":/wordlist.txt");
    if( file.open(QIODevice:ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            if(!line.isEmpty()){
                m_words.append(line.trimmed().toUpper());
            }
        }
        file.close();
    }else{
        qWarnning() <<"Impossible d'ouvrir le fichier wordlist.txt";
    }
}

QString WordList::getRandomWord() const {
    int index = qrand() % m_words.size();
    return m_words.at(index);
}

bool WordList::contains(const QString& word) const{
    return m_words.contains(word.toUpper());
}