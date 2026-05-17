#pragma once
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSplitter>
#include <QRegularExpression>
#include "../core/Interpreter.h"

class MainPage : public QWidget {
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void onSubmit();

private:
    Interpreter m_Interpreter{};
    QTextEdit   *m_output;
    QTextEdit *m_stackDisplay;
    QTextEdit   *m_input;
    QPushButton *m_submitBtn;
};