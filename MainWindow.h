// Dominic Gasperini
// Passphrase Generator

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// includes
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
