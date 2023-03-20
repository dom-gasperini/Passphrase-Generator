// Dominic Gasperini
// Passphrase Generator

// includes
#include "Generator.h"

/**
 * @brief Generator::Generator
 */
Generator::Generator()
{
    // read in word list file
    QFile file("word-list.txt");
    if(file.open(QIODevice::ReadOnly)) {
        // init file stream
        QTextStream fileIn(&file);

        // read each line and add to word list
        while(!fileIn.atEnd()) {
            QString word = fileIn.readLine();
            m_words.append(word);
        }
    }

    // if the word list cannot be read
    else {
        QMessageBox::information(0, "Failed to read word list file!", file.errorString());
    }

    // close the file
    file.close();

    // get special characters
    m_specialChars = {"!", "#", "@", "$", "%", "^", "&", "?"};
}


// --- Getters --- //
/**
 * @brief Generator::getPhrases
 * @return
 */
QVector<QString> Generator::getPhrases() {
    return m_phrases;
}


// --- Generator --- //
void Generator::generatePassphrases(Complexity level) {
    // inits
    QVector<QString> selectedWords;
    QString tmpPhrase = "";
    int numberAddon;
    int randomIndex;

    // clear old phrases
    m_phrases.clear();

    for (int i = 0; i < NUM_PHRASES; ++i) {
        // get 3 random words
        for (int i = 0; i < 3; ++i) {
            randomIndex = QRandomGenerator::global()->bounded(m_words.size());
            selectedWords.append(m_words.at(randomIndex));
        }

        tmpPhrase += selectedWords.at(0);

        // add complexity
        if (level >= MODERATE) {
            numberAddon = QRandomGenerator::global()->bounded(11);
            tmpPhrase += QString::number(numberAddon);
        }

        tmpPhrase += "-";
        if (level >= MODERATE) {
            QString tmpWord = selectedWords.at(1);
            // captialize first letter
            tmpWord.front() = tmpWord.front().toUpper();
            tmpPhrase += tmpWord;
        }
        else {
            tmpPhrase += selectedWords.at(1);
        }
        tmpPhrase += "-";
        tmpPhrase += selectedWords.at(2);

        // add more complexity
        if (level == COMPLEX) {
            randomIndex = QRandomGenerator::global()->bounded(m_specialChars.size());
            tmpPhrase += m_specialChars.at(randomIndex);
        }

        // add to passphrase vector
        m_phrases.append(tmpPhrase);

        // clear data
        selectedWords.clear();
        tmpPhrase.clear();
    }
}





