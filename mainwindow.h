#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "highlighter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
    Highlighter *highlighter;

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionSave_triggered();
    void on_actionAbout_triggered();
};
#endif // MAINWINDOW_H
