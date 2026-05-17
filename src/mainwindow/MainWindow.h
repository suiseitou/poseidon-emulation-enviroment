#pragma once
#include <QMainWindow>
#include "../pages/MainPage.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainPage *m_mainPage;
};