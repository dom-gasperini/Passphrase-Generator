// Dominic Gasperini
// Passphrase Generator

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// includes
#include <QMainWindow>
#include <QTimer>
#include <QStyleFactory>
#include "Generator.h"
#include "AboutDlg.h"

// namespace declaration
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // constructor & destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // palette
    QPalette m_currentPalette;

    // Timers
    QTimer *m_pUpdateDisplayTimer;

    // class variables
   Generator *m_pGenerator;
   AboutDlg *m_pAboutDlg;

private slots:
   void UpdateDisplay();
   void on_actionAbout_triggered();

   void on_generatePhrasesBtn_clicked();

   void on_actionDark_Mode_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
