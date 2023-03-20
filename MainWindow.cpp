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
    this->setWindowIconText("");

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
    phrasesPopup.setWindowTitle("Your passphrases");
    phrasesPopup.setText(content);

    // show the popup
    phrasesPopup.exec();
}

