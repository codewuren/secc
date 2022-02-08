/*
*   Author: CodeWuRen
*/

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
    QStatusBar *statbar = statusBar();

private slots:
    void NewFile();
    void OpenFile();
    void SaveAs();
    void Save();
    void About();

public:
    void CreateStatusBar();
    void ChangeStatusBar(QString fileName);
    void ClearStatusBar();
    void OpenFileCommand();
};
#endif // MAINWINDOW_H
