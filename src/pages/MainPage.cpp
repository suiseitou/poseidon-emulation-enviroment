#include "MainPage.h"

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
{
    m_output    = new QTextEdit(this);
    m_input     = new QTextEdit(this);
    m_submitBtn = new QPushButton("Run", this);
    m_output->setReadOnly(true);

    auto *inputRow = new QHBoxLayout();
    inputRow->addWidget(m_input);
    inputRow->addWidget(m_submitBtn);

    auto *leftWidget = new QWidget(this);
    auto *leftLayout = new QVBoxLayout(leftWidget);
    leftLayout->addWidget(m_output, 2);
    leftLayout->addLayout(inputRow, 1);

    auto *rightWidget = new QWidget(this);
    auto *rightLayout = new QVBoxLayout(rightWidget);
    m_stackDisplay = new QTextEdit(rightWidget);
    m_stackDisplay->setReadOnly(true);
    m_stackDisplay->setFont(QFont("Courier New", 10));
    rightLayout->addWidget(m_stackDisplay);

    auto *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(leftWidget);
    splitter->addWidget(rightWidget);
    splitter->setSizes({500, 500});

    auto *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(splitter);
    setLayout(mainLayout);

    connect(m_submitBtn, &QPushButton::clicked, this, &MainPage::onSubmit);
}
void MainPage::onSubmit() {
    QString input = m_input->toPlainText().trimmed();
    if (input.isEmpty()) return;

    for (const QString &line : input.split('\n', Qt::SkipEmptyParts)) {
    for (const QString &token : line.split(QRegularExpression("[ \t]+"), Qt::SkipEmptyParts)) {
        m_Interpreter.executeOpcodeName(token.toStdString());
    }
    }

    m_stackDisplay->setText(QString::fromStdString(m_Interpreter.getStackState()));
    m_output->append(input);
    m_output->append("--------------");

    m_input->clear();
}

MainPage::~MainPage() {}