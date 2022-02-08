/*
*   Author: CodeWuRen
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arg.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    CreateStatusBar();
    highlighter = new Highlighter(ui->textEdit->document()); //highlight
    OpenFileCommand(); // To open a file if user used command with the arguement of file name
    /* Some Bindings */
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(NewFile()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(OpenFile()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(SaveAs()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(Save()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(About()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::NewFile() {
    // Global referencing the current file that we are clearing
    currentFile.clear();

    // Clear status bar
    ClearStatusBar();

    // Clear the textEdit widget buffer
    ui->textEdit->setText(QString());
}

void MainWindow::OpenFile() {
    // Opens a dialog that allows you to select a file to open
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    if (fileName != "") {
        // An object for reading and writing files
        QFile file(fileName);

        // Store the currentFile name
        currentFile = fileName;

        // Try to open the file as a read only file if possible or display a
        // warning dialog box
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Set status bar
        ChangeStatusBar(fileName);

        // Interface for reading text
        QTextStream in(&file);

        // Copy text in the string
        QString text = in.readAll();

        // Put the text in the textEdit widget
        ui->textEdit->setText(text);

        // Close the file
        file.close();
    }

}

void MainWindow::SaveAs() {
    // Opens a dialog for saving a file
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    if (fileName != "") {
        // An object for reading and writing files
        QFile file(fileName);

        // Try to open a file with write only options
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }

        // Store the currentFile name
        currentFile = fileName;

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Set status bar
        ChangeStatusBar(fileName);

        // Interface for writing text
        QTextStream out(&file);

        // Copy text in the textEdit widget and convert to plain text
        QString text = ui->textEdit->toPlainText();

        // Output to file
        out << text;

        // Close the file
        file.close();
    }
}

void MainWindow::Save() {
    if (currentFile != "") {
        // An object for reading and writing files
        QFile file(currentFile);

        // Try to open a file with write only options
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }

        // Set the title for the window to the file name
        setWindowTitle(currentFile);

        // Set status bar
        ChangeStatusBar(currentFile);

        // Interface for writing text
        QTextStream out(&file);

        // Copy text in the textEdit widget and convert to plain text
        QString text = ui->textEdit->toPlainText();

        // Output to file
        out << text;

        // Close the file
        file.close();
    }
    else SaveAs(); // If don't exist this file then create it
}

void MainWindow::About() {
    QMessageBox::information(NULL, "About", "I\'m a high school student from China.\nMy Blog is https://codewuren.github.io\nAnd you can follow me on GitHub at https://github.com", QMessageBox::Close, QMessageBox::Close);
}

void MainWindow::CreateStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::ChangeStatusBar(QString fileName) {
    statusBar()->clearMessage();
    statusBar()->showMessage(fileName);
}

void MainWindow::ClearStatusBar() {
    statusBar()->clearMessage();
}

// To open a file if user used command with the arguement of file name
void MainWindow::OpenFileCommand(){
    if (FN != "") {
        // An object for reading and writing files
        QFile file(FN);

        // Store the currentFile name
        currentFile = FN;

        // Try to open the file as a read only file if possible or display a
        // warning dialog box
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString() + "" + FN);
            return;
        }

        // Set the title for the window to the file name
        setWindowTitle(FN);

        // Set status bar
        ChangeStatusBar(FN);

        // Interface for reading text
        QTextStream in(&file);

        // Copy text in the string
        QString text = in.readAll();

        // Put the text in the textEdit widget
        ui->textEdit->setText(text);

        // Close the file
        file.close();
    }
}
