// Dominic Gasperini
// Passphrase Generator

// includes
#include "MainWindow.h"
#include "ui_MainWindow.h"

// defines
#define DISPLAY_UPDATE_INTERVAL     200      // in milliseconds

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // setup ui
    ui->setupUi(this);
    this->setWindowTitle("Passphrase Generator");
    this->setWindowIcon(QIcon("lock.ico"));
    qApp->setStyle(QStyleFactory::create("Fusion"));
    m_currentPalette = this->palette();

    // init class variables
    m_pGenerator = new Generator();

    // init dialogs
    m_pAboutDlg = new AboutDlg();

    // init timers
    m_pUpdateDisplayTimer = new QTimer();
    m_pUpdateDisplayTimer->setInterval(DISPLAY_UPDATE_INTERVAL);
    connect(m_pUpdateDisplayTimer, SIGNAL(timeout()), this, SLOT(UpdateDisplay()));
    m_pUpdateDisplayTimer->start();
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::UpdateDisplay
 */
void MainWindow::UpdateDisplay() {
    // update example textbox
    switch (ui->complexityCmbx->currentIndex()) {
    case 0:
        ui->exampleComplexityTextLineE->setText("\"pass-phrase-example\"");
        break;

    case 1:
        ui->exampleComplexityTextLineE->setText("\"pass3-Phrase-example\"");
        break;

    case 2:
        ui->exampleComplexityTextLineE->setText("\"pass8-Phrase-example!\"");
        break;

    default:
        ui->exampleComplexityTextLineE->setText("undefined example :/");
        break;
    }
}


/**
 * @brief MainWindow::on_actionAbout_triggered
 */
void MainWindow::on_actionAbout_triggered()
{
    m_pAboutDlg->show();
}


/**
 * @brief MainWindow::on_generatePhrasesBtn_clicked
 */
void MainWindow::on_generatePhrasesBtn_clicked()
{
    // inits
    QMessageBox phrasesPopup;
    QVector<QString> phrases;
    QString content = "";

    // generate passphrases
    m_pGenerator->generatePassphrases((Complexity)ui->complexityCmbx->currentIndex());
    phrases = m_pGenerator->getPhrases();

    // add phrases to the popup
    for (int i = 0; i < phrases.size(); ++i) {
        if (i == phrases.size() - 1) {
            content += phrases.at(i) + "\n";
        }
        else {
            content += phrases.at(i) + "\n\n";
        }
    }

    // set popup content
    phrasesPopup.setWindowIcon(QIcon("lock.ico"));
    phrasesPopup.setWindowTitle("Generated Passphrases");
    phrasesPopup.setText(content);

    // show the popup
    phrasesPopup.exec();
}


/**
 * @brief MainWindow::on_actionDark_Mode_toggled
 * @param arg1
 */
void MainWindow::on_actionDark_Mode_toggled(bool checked)
{
    if (checked)
    {
        // Set Style
        qApp->setStyle(QStyleFactory::create("Fusion"));
        // Init a Dark Mode Palette
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window,QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
        darkPalette.setColor(QPalette::Base,QColor(42,42,42));
        darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
        darkPalette.setColor(QPalette::ToolTipBase,Qt::white);
        darkPalette.setColor(QPalette::ToolTipText,Qt::white);
        darkPalette.setColor(QPalette::Text,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
        darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
        darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
        darkPalette.setColor(QPalette::Button,QColor(53,53,53));
        darkPalette.setColor(QPalette::ButtonText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
        darkPalette.setColor(QPalette::BrightText,Qt::red);
        darkPalette.setColor(QPalette::Link,QColor(42,130,218));
        darkPalette.setColor(QPalette::Highlight, QColor(142,45,197));
        darkPalette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
        darkPalette.setColor(QPalette::HighlightedText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::HighlightedText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::white);

        // Set to Dark Mode
        qApp->setPalette(darkPalette);

        // Change Progress Bar Color to Green
        QPalette progressBarPalette;
        progressBarPalette.setColor(QPalette::Highlight, Qt::green);
    }

    else
    {
        // Reset to Light Mode
        m_currentPalette.setColor(QPalette::Text, Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::black);
        m_currentPalette.setColor(QPalette::ButtonText,Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::Disabled, QPalette::Text, Qt::black);
        m_currentPalette.setColor(QPalette::WindowText, Qt::black);
        m_currentPalette.setColor(QPalette::Disabled, QPalette::WindowText, Qt::black);
        m_currentPalette.setColor(QPalette::ToolTipBase,Qt::black);
        m_currentPalette.setColor(QPalette::ToolTipText,Qt::black);
        m_currentPalette.setColor(QPalette::Disabled,QPalette::Highlight, Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText,Qt::black);
        m_currentPalette.setColor(QPalette::Disabled,QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::All, QPalette::ButtonText, Qt::black);
        m_currentPalette.setColor(QPalette::All, QPalette::Text, Qt::black);
        m_currentPalette.setColor(QPalette::ButtonText, Qt::black);
        m_currentPalette.setColor(QPalette::WindowText, Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::BrightText, Qt::black);
        qApp->setPalette(m_currentPalette);
        // Reset Style to Windows Vista
        qApp->setStyle(QStyleFactory::create("Fusion"));
    }
}

