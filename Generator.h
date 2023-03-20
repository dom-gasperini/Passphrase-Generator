// Dominic Gasperini
// Passphrase Generator

#ifndef GENERATOR_H
#define GENERATOR_H

// includes
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QRandomGenerator>

// defines
#define NUM_PHRASES     3       // the number of passphrases to generate

// enums
typedef enum Complexity {
    BASIC,
    MODERATE,
    COMPLEX
} Complexity;

/**
 * @brief The Generator class
 */
class Generator
{
public:
    // constructor
    Generator();

    // getters
    QVector<QString> getPhrases();
    QVector<QString> getWords();

    // generator
    void generatePassphrases(Complexity level);

private:
    QVector<QString> m_phrases;
    QVector<QString> m_words;
    QVector<QString> m_specialChars;
};

#endif // GENERATOR_H
