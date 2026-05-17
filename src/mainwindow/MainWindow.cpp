#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_mainPage = new MainPage(this);
    setCentralWidget(m_mainPage);
    setWindowTitle("Poseidon");
    resize(1280, 720);
}

MainWindow::~MainWindow() {}