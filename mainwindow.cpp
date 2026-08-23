#include "mainwindow.h"

#include <QWidget>
#include <QStackedWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QFont>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QAbstractItemView>

// =====================================================
// CONSTRUCTOR
// =====================================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    username = "Priyanshu";
    pin = "1234";
    balance = 10000.00;

    setWindowTitle("Priyanshu ATM - Night Mode");

    resize(1150, 720);
    setMinimumSize(950, 600);

    pages = new QStackedWidget(this);

    setCentralWidget(pages);

    createLoginPage();
    createMainPage();

    pages->setCurrentWidget(loginPage);

    addTransaction("Account Created", 10000);
}


// =====================================================
// DESTRUCTOR
// =====================================================

MainWindow::~MainWindow()
{
}


// =====================================================
// COMMON BUTTON STYLE
// =====================================================

QString mainButtonStyle()
{
    return
        "QPushButton {"
        "background-color: #2563EB;"
        "color: #D1D5DB;"
        "border: none;"
        "border-radius: 10px;"
        "padding: 12px;"
        "font-size: 15px;"
        "font-weight: bold;"
        "}"

        "QPushButton:hover {"
        "background-color: #3B82F6;"
        "color: #E5E7EB;"
        "}"

        "QPushButton:pressed {"
        "background-color: #1D4ED8;"
        "}";
}


// =====================================================
// LOGIN PAGE
// =====================================================

void MainWindow::createLoginPage()
{
    loginPage = new QWidget();

    loginPage->setStyleSheet(
        "background-color: #0F1115;"
        );

    QVBoxLayout *mainLayout =
        new QVBoxLayout(loginPage);

    mainLayout->setContentsMargins(
        150, 50, 150, 50
        );

    mainLayout->addStretch();

    // ATM icon
    QLabel *logo =
        new QLabel("🏧");

    logo->setAlignment(Qt::AlignCenter);

    QFont logoFont;
    logoFont.setPointSize(50);

    logo->setFont(logoFont);

    mainLayout->addWidget(logo);

    // Title
    QLabel *title =
        new QLabel("PRIYANSHU ATM");

    title->setAlignment(Qt::AlignCenter);

    QFont titleFont;
    titleFont.setPointSize(30);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #D1D5DB;"
        );

    mainLayout->addWidget(title);

    QLabel *subtitle =
        new QLabel(
            "Secure • Simple • Smart Banking"
            );

    subtitle->setAlignment(Qt::AlignCenter);

    subtitle->setStyleSheet(
        "color: #777B82;"
        "font-size: 14px;"
        );

    mainLayout->addWidget(subtitle);

    mainLayout->addSpacing(25);

    // Login card
    QFrame *card =
        new QFrame();

    card->setMaximumWidth(450);

    card->setStyleSheet(
        "QFrame {"
        "background-color: #181B21;"
        "border: 1px solid #2A2F38;"
        "border-radius: 18px;"
        "}"
        );

    QVBoxLayout *cardLayout =
        new QVBoxLayout(card);

    cardLayout->setContentsMargins(
        40, 35, 40, 35
        );

    QLabel *loginTitle =
        new QLabel("LOGIN");

    loginTitle->setAlignment(Qt::AlignCenter);

    QFont loginFont;
    loginFont.setPointSize(22);
    loginFont.setBold(true);

    loginTitle->setFont(loginFont);

    loginTitle->setStyleSheet(
        "color: #B0B3B8;"
        );

    cardLayout->addWidget(loginTitle);

    cardLayout->addSpacing(15);

    // Username
    QLabel *userLabel =
        new QLabel("Username");

    userLabel->setStyleSheet(
        "color: #777B82;"
        "font-size: 14px;"
        );

    usernameEdit =
        new QLineEdit();

    usernameEdit->setPlaceholderText(
        "Enter username"
        );

    usernameEdit->setMinimumHeight(45);

    usernameEdit->setStyleSheet(
        "QLineEdit {"
        "background-color: #20242B;"
        "color: #B0B3B8;"
        "border: 2px solid #2A2F38;"
        "border-radius: 8px;"
        "padding: 8px;"
        "font-size: 15px;"
        "}"

        "QLineEdit:focus {"
        "border: 2px solid #2563EB;"
        "}"

        "QLineEdit::placeholder {"
        "color: #555A63;"
        "}"
        );

    cardLayout->addWidget(userLabel);
    cardLayout->addWidget(usernameEdit);

    cardLayout->addSpacing(12);

    // PIN
    QLabel *pinLabel =
        new QLabel("PIN");

    pinLabel->setStyleSheet(
        "color: #777B82;"
        "font-size: 14px;"
        );

    pinEdit =
        new QLineEdit();

    pinEdit->setPlaceholderText(
        "Enter 4-digit PIN"
        );

    pinEdit->setEchoMode(
        QLineEdit::Password
        );

    pinEdit->setMaxLength(4);

    pinEdit->setMinimumHeight(45);

    pinEdit->setStyleSheet(
        "QLineEdit {"
        "background-color: #20242B;"
        "color: #B0B3B8;"
        "border: 2px solid #2A2F38;"
        "border-radius: 8px;"
        "padding: 8px;"
        "font-size: 15px;"
        "}"

        "QLineEdit:focus {"
        "border: 2px solid #2563EB;"
        "}"

        "QLineEdit::placeholder {"
        "color: #555A63;"
        "}"
        );

    cardLayout->addWidget(pinLabel);
    cardLayout->addWidget(pinEdit);

    cardLayout->addSpacing(15);

    // Login button
    QPushButton *loginButton =
        new QPushButton("LOGIN  →");

    loginButton->setMinimumHeight(50);

    loginButton->setStyleSheet(
        mainButtonStyle()
        );

    cardLayout->addWidget(loginButton);

    QLabel *hint =
        new QLabel(
            "Demo Login: Priyanshu / 1234"
            );

    hint->setAlignment(Qt::AlignCenter);

    hint->setStyleSheet(
        "color: #555A63;"
        "font-size: 12px;"
        );

    cardLayout->addWidget(hint);

    // Center card
    QHBoxLayout *cardLayoutOuter =
        new QHBoxLayout();

    cardLayoutOuter->addStretch();
    cardLayoutOuter->addWidget(card);
    cardLayoutOuter->addStretch();

    mainLayout->addLayout(cardLayoutOuter);

    mainLayout->addStretch();

    pages->addWidget(loginPage);

    connect(
        loginButton,
        &QPushButton::clicked,
        this,
        &MainWindow::login
        );

    connect(
        pinEdit,
        &QLineEdit::returnPressed,
        this,
        &MainWindow::login
        );
}


// =====================================================
// MAIN PAGE
// =====================================================

void MainWindow::createMainPage()
{
    mainPage = new QWidget();

    mainPage->setStyleSheet(
        "background-color: #0F1115;"
        );

    QHBoxLayout *mainLayout =
        new QHBoxLayout(mainPage);

    mainLayout->setContentsMargins(
        0, 0, 0, 0
        );

    mainLayout->setSpacing(0);

    // =================================================
    // SIDEBAR
    // =================================================

    QWidget *sidebar =
        new QWidget();

    sidebar->setFixedWidth(235);

    sidebar->setStyleSheet(
        "background-color: #15181E;"
        "border-right: 1px solid #2A2F38;"
        );

    QVBoxLayout *sideLayout =
        new QVBoxLayout(sidebar);

    sideLayout->setContentsMargins(
        18, 25, 18, 20
        );

    QLabel *logo =
        new QLabel("🏧  ATM");

    logo->setAlignment(Qt::AlignCenter);

    logo->setStyleSheet(
        "color: #B0B3B8;"
        "font-size: 23px;"
        "font-weight: bold;"
        );

    sideLayout->addWidget(logo);

    sideLayout->addSpacing(25);

    QPushButton *homeButton =
        new QPushButton("🏠   Dashboard");

    QPushButton *depositButton =
        new QPushButton("💵   Deposit");

    QPushButton *withdrawButton =
        new QPushButton("🏧   Withdraw");

    QPushButton *statementButton =
        new QPushButton("📜   Transactions");

    QPushButton *pinButton =
        new QPushButton("🔑   Change PIN");

    QPushButton *sideButtons[] = {
        homeButton,
        depositButton,
        withdrawButton,
        statementButton,
        pinButton
    };

    for (QPushButton *button : sideButtons)
    {
        button->setMinimumHeight(45);

        button->setStyleSheet(
            "QPushButton {"
            "background-color: transparent;"
            "color: #777B82;"
            "text-align: left;"
            "padding: 10px;"
            "border-radius: 8px;"
            "font-size: 14px;"
            "}"

            "QPushButton:hover {"
            "background-color: #20242B;"
            "color: #B0B3B8;"
            "}"

            "QPushButton:pressed {"
            "background-color: #252A32;"
            "}"
            );

        sideLayout->addWidget(button);
    }

    sideLayout->addStretch();

    QPushButton *logoutButton =
        new QPushButton("🚪   Logout");

    logoutButton->setMinimumHeight(45);

    logoutButton->setStyleSheet(
        "QPushButton {"
        "background-color: #3A1F23;"
        "color: #B0B3B8;"
        "border: 1px solid #5A292F;"
        "border-radius: 8px;"
        "font-size: 14px;"
        "font-weight: bold;"
        "}"

        "QPushButton:hover {"
        "background-color: #54272C;"
        "color: #D1D5DB;"
        "}"
        );

    sideLayout->addWidget(logoutButton);

    // =================================================
    // CONTENT
    // =================================================

    contentArea =
        new QWidget();

    contentArea->setStyleSheet(
        "background-color: #0F1115;"
        );

    QVBoxLayout *contentLayout =
        new QVBoxLayout(contentArea);

    contentLayout->setContentsMargins(
        30, 25, 30, 25
        );

    // Header
    QHBoxLayout *header =
        new QHBoxLayout();

    welcomeLabel =
        new QLabel("Welcome, Priyanshu!");

    QFont welcomeFont;
    welcomeFont.setPointSize(23);
    welcomeFont.setBold(true);

    welcomeLabel->setFont(welcomeFont);

    welcomeLabel->setStyleSheet(
        "color: #B0B3B8;"
        );

    header->addWidget(welcomeLabel);

    header->addStretch();

    QLabel *status =
        new QLabel("● Account Active");

    status->setStyleSheet(
        "color: #6F9B7A;"
        "font-size: 13px;"
        "font-weight: bold;"
        );

    header->addWidget(status);

    contentLayout->addLayout(header);

    // Content pages
    contentPages =
        new QStackedWidget();

    homePage =
        new QWidget();

    depositPage =
        new QWidget();

    withdrawPage =
        new QWidget();

    transactionPage =
        new QWidget();

    pinPage =
        new QWidget();

    contentPages->addWidget(homePage);
    contentPages->addWidget(depositPage);
    contentPages->addWidget(withdrawPage);
    contentPages->addWidget(transactionPage);
    contentPages->addWidget(pinPage);

    contentLayout->addWidget(contentPages);

    createHomePage();
    createDepositPage();
    createWithdrawPage();
    createTransactionPage();
    createPinPage();

    // Connections
    connect(
        homeButton,
        &QPushButton::clicked,
        this,
        &MainWindow::showHome
        );

    connect(
        depositButton,
        &QPushButton::clicked,
        this,
        &MainWindow::showDeposit
        );

    connect(
        withdrawButton,
        &QPushButton::clicked,
        this,
        &MainWindow::showWithdraw
        );

    connect(
        statementButton,
        &QPushButton::clicked,
        this,
        &MainWindow::showTransactions
        );

    connect(
        pinButton,
        &QPushButton::clicked,
        this,
        &MainWindow::showChangePin
        );

    connect(
        logoutButton,
        &QPushButton::clicked,
        this,
        &MainWindow::logout
        );

    mainLayout->addWidget(sidebar);
    mainLayout->addWidget(contentArea);

    pages->addWidget(mainPage);
}


// =====================================================
// HOME PAGE
// =====================================================

void MainWindow::createHomePage()
{
    QVBoxLayout *layout =
        new QVBoxLayout(homePage);

    layout->setContentsMargins(
        0, 20, 0, 0
        );

    // Balance Card
    QFrame *balanceCard =
        new QFrame();

    balanceCard->setMinimumHeight(160);

    balanceCard->setStyleSheet(
        "QFrame {"
        "background-color: #181B21;"
        "border: 1px solid #2A2F38;"
        "border-radius: 18px;"
        "}"
        );

    QVBoxLayout *balanceLayout =
        new QVBoxLayout(balanceCard);

    QLabel *balanceTitle =
        new QLabel("AVAILABLE BALANCE");

    balanceTitle->setAlignment(
        Qt::AlignCenter
        );

    balanceTitle->setStyleSheet(
        "color: #777B82;"
        "font-size: 13px;"
        "font-weight: bold;"
        );

    balanceLabel =
        new QLabel("Rs. 10,000.00");

    balanceLabel->setAlignment(
        Qt::AlignCenter
        );

    QFont balanceFont;
    balanceFont.setPointSize(32);
    balanceFont.setBold(true);

    balanceLabel->setFont(balanceFont);

    balanceLabel->setStyleSheet(
        "color: #8AB4F8;"
        );

    balanceLayout->addWidget(balanceTitle);
    balanceLayout->addWidget(balanceLabel);

    layout->addWidget(balanceCard);

    layout->addSpacing(15);

    QLabel *quickTitle =
        new QLabel("Quick Actions");

    QFont quickFont;
    quickFont.setPointSize(20);
    quickFont.setBold(true);

    quickTitle->setFont(quickFont);

    quickTitle->setStyleSheet(
        "color: #B0B3B8;"
        );

    layout->addWidget(quickTitle);

    QGridLayout *grid =
        new QGridLayout();

    grid->setSpacing(15);

    QPushButton *deposit =
        new QPushButton(
            "💵\nDeposit Money"
            );

    QPushButton *withdraw =
        new QPushButton(
            "🏧\nWithdraw Money"
            );

    QPushButton *statement =
        new QPushButton(
            "📜\nTransactions"
            );

    QPushButton *pin =
        new QPushButton(
            "🔑\nChange PIN"
            );

    QPushButton *cards[] = {
        deposit,
        withdraw,
        statement,
        pin
    };

    for (QPushButton *button : cards)
    {
        button->setMinimumHeight(85);

        button->setStyleSheet(
            "QPushButton {"
            "background-color: #181B21;"
            "color: #B0B3B8;"
            "border: 1px solid #2A2F38;"
            "border-radius: 12px;"
            "font-size: 15px;"
            "font-weight: bold;"
            "}"

            "QPushButton:hover {"
            "background-color: #20242B;"
            "color: #D1D5DB;"
            "border: 1px solid #3B82F6;"
            "}"

            "QPushButton:pressed {"
            "background-color: #252A32;"
            "}"
            );
    }

    grid->addWidget(deposit, 0, 0);
    grid->addWidget(withdraw, 0, 1);
    grid->addWidget(statement, 1, 0);
    grid->addWidget(pin, 1, 1);

    layout->addLayout(grid);

    layout->addSpacing(10);

    QLabel *quickWithdrawTitle =
        new QLabel("Quick Withdraw");

    quickWithdrawTitle->setStyleSheet(
        "color: #777B82;"
        "font-size: 16px;"
        "font-weight: bold;"
        );

    layout->addWidget(quickWithdrawTitle);

    QHBoxLayout *quickLayout =
        new QHBoxLayout();

    QPushButton *q500 =
        new QPushButton("₹500");

    QPushButton *q1000 =
        new QPushButton("₹1,000");

    QPushButton *q2000 =
        new QPushButton("₹2,000");

    QPushButton *q5000 =
        new QPushButton("₹5,000");

    QPushButton *quickButtons[] = {
        q500,
        q1000,
        q2000,
        q5000
    };

    for (QPushButton *button : quickButtons)
    {
        button->setMinimumHeight(45);

        button->setStyleSheet(
            mainButtonStyle()
            );

        quickLayout->addWidget(button);
    }

    layout->addLayout(quickLayout);

    // Connections
    connect(
        deposit,
        &QPushButton::clicked,
        this,
        &MainWindow::showDeposit
        );

    connect(
        withdraw,
        &QPushButton::clicked,
        this,
        &MainWindow::showWithdraw
        );

    connect(
        statement,
        &QPushButton::clicked,
        this,
        &MainWindow::showTransactions
        );

    connect(
        pin,
        &QPushButton::clicked,
        this,
        &MainWindow::showChangePin
        );

    connect(
        q500,
        &QPushButton::clicked,
        this,
        &MainWindow::quickWithdraw
        );

    connect(
        q1000,
        &QPushButton::clicked,
        this,
        &MainWindow::quickWithdraw
        );

    connect(
        q2000,
        &QPushButton::clicked,
        this,
        &MainWindow::quickWithdraw
        );

    connect(
        q5000,
        &QPushButton::clicked,
        this,
        &MainWindow::quickWithdraw
        );
}


// =====================================================
// DEPOSIT PAGE
// =====================================================

void MainWindow::createDepositPage()
{
    QVBoxLayout *layout =
        new QVBoxLayout(depositPage);

    layout->setContentsMargins(
        40, 40, 40, 40
        );

    QLabel *title =
        new QLabel("💵  Deposit Money");

    QFont titleFont;
    titleFont.setPointSize(25);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #B0B3B8;"
        );

    layout->addWidget(title);

    QLabel *info =
        new QLabel(
            "Enter the amount you want to add "
            "to your account."
            );

    info->setStyleSheet(
        "color: #777B82;"
        "font-size: 14px;"
        );

    layout->addWidget(info);

    layout->addSpacing(20);

    depositAmount =
        new QDoubleSpinBox();

    depositAmount->setRange(
        1,
        1000000
        );

    depositAmount->setValue(1000);

    depositAmount->setPrefix("Rs. ");

    depositAmount->setDecimals(2);

    depositAmount->setMinimumHeight(55);

    depositAmount->setStyleSheet(
        "QDoubleSpinBox {"
        "background-color: #181B21;"
        "color: #B0B3B8;"
        "border: 2px solid #2A2F38;"
        "border-radius: 10px;"
        "padding: 10px;"
        "font-size: 20px;"
        "}"

        "QDoubleSpinBox:focus {"
        "border: 2px solid #2563EB;"
        "}"
        );

    layout->addWidget(depositAmount);

    layout->addSpacing(15);

    QPushButton *button =
        new QPushButton(
            "DEPOSIT MONEY"
            );

    button->setMinimumHeight(55);

    button->setStyleSheet(
        mainButtonStyle()
        );

    layout->addWidget(button);

    layout->addStretch();

    connect(
        button,
        &QPushButton::clicked,
        this,
        &MainWindow::depositMoney
        );
}


// =====================================================
// WITHDRAW PAGE
// =====================================================

void MainWindow::createWithdrawPage()
{
    QVBoxLayout *layout =
        new QVBoxLayout(withdrawPage);

    layout->setContentsMargins(
        40, 40, 40, 40
        );

    QLabel *title =
        new QLabel(
            "🏧  Withdraw Money"
            );

    QFont titleFont;
    titleFont.setPointSize(25);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #B0B3B8;"
        );

    layout->addWidget(title);

    QLabel *info =
        new QLabel(
            "Enter the amount you want to withdraw."
            );

    info->setStyleSheet(
        "color: #777B82;"
        "font-size: 14px;"
        );

    layout->addWidget(info);

    layout->addSpacing(20);

    withdrawAmount =
        new QDoubleSpinBox();

    withdrawAmount->setRange(
        1,
        1000000
        );

    withdrawAmount->setValue(500);

    withdrawAmount->setPrefix("Rs. ");

    withdrawAmount->setDecimals(2);

    withdrawAmount->setMinimumHeight(55);

    withdrawAmount->setStyleSheet(
        "QDoubleSpinBox {"
        "background-color: #181B21;"
        "color: #B0B3B8;"
        "border: 2px solid #2A2F38;"
        "border-radius: 10px;"
        "padding: 10px;"
        "font-size: 20px;"
        "}"

        "QDoubleSpinBox:focus {"
        "border: 2px solid #2563EB;"
        "}"
        );

    layout->addWidget(withdrawAmount);

    layout->addSpacing(15);

    QPushButton *button =
        new QPushButton(
            "WITHDRAW MONEY"
            );

    button->setMinimumHeight(55);

    button->setStyleSheet(
        mainButtonStyle()
        );

    layout->addWidget(button);

    layout->addStretch();

    connect(
        button,
        &QPushButton::clicked,
        this,
        &MainWindow::withdrawMoney
        );
}


// =====================================================
// TRANSACTION PAGE
// =====================================================

void MainWindow::createTransactionPage()
{
    QVBoxLayout *layout =
        new QVBoxLayout(transactionPage);

    layout->setContentsMargins(
        20, 20, 20, 20
        );

    QLabel *title =
        new QLabel(
            "📜  Transaction History"
            );

    QFont titleFont;
    titleFont.setPointSize(25);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #B0B3B8;"
        );

    layout->addWidget(title);

    transactionTable =
        new QTableWidget();

    transactionTable->setColumnCount(3);

    transactionTable->setHorizontalHeaderLabels(
        {
            "No.",
            "Transaction",
            "Amount"
        }
        );

    transactionTable->horizontalHeader()
        ->setSectionResizeMode(
            1,
            QHeaderView::Stretch
            );

    transactionTable->horizontalHeader()
        ->setStretchLastSection(true);

    transactionTable->setAlternatingRowColors(
        true
        );

    transactionTable->setEditTriggers(
        QAbstractItemView::NoEditTriggers
        );

    transactionTable->setSelectionBehavior(
        QAbstractItemView::SelectRows
        );

    transactionTable->setStyleSheet(
        "QTableWidget {"
        "background-color: #181B21;"
        "color: #B0B3B8;"
        "border: 1px solid #2A2F38;"
        "gridline-color: #2A2F38;"
        "alternate-background-color: #20242B;"
        "}"

        "QTableWidget::item {"
        "padding: 8px;"
        "}"

        "QTableWidget::item:selected {"
        "background-color: #2563EB;"
        "color: #D1D5DB;"
        "}"

        "QHeaderView::section {"
        "background-color: #20242B;"
        "color: #777B82;"
        "padding: 10px;"
        "border: none;"
        "font-weight: bold;"
        "}"
        );

    layout->addWidget(transactionTable);
}


// =====================================================
// CHANGE PIN PAGE
// =====================================================

void MainWindow::createPinPage()
{
    QVBoxLayout *layout =
        new QVBoxLayout(pinPage);

    layout->setContentsMargins(
        40, 40, 40, 40
        );

    QLabel *title =
        new QLabel(
            "🔑  Change PIN"
            );

    QFont titleFont;
    titleFont.setPointSize(25);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #B0B3B8;"
        );

    layout->addWidget(title);

    layout->addSpacing(15);

    oldPinEdit =
        new QLineEdit();

    oldPinEdit->setPlaceholderText(
        "Current PIN"
        );

    newPinEdit =
        new QLineEdit();

    newPinEdit->setPlaceholderText(
        "New 4-digit PIN"
        );

    confirmPinEdit =
        new QLineEdit();

    confirmPinEdit->setPlaceholderText(
        "Confirm new PIN"
        );

    QLineEdit *fields[] = {
        oldPinEdit,
        newPinEdit,
        confirmPinEdit
    };

    for (QLineEdit *field : fields)
    {
        field->setEchoMode(
            QLineEdit::Password
            );

        field->setMaxLength(4);

        field->setMinimumHeight(50);

        field->setStyleSheet(
            "QLineEdit {"
            "background-color: #181B21;"
            "color: #B0B3B8;"
            "border: 2px solid #2A2F38;"
            "border-radius: 8px;"
            "padding: 10px;"
            "font-size: 16px;"
            "}"

            "QLineEdit:focus {"
            "border: 2px solid #2563EB;"
            "}"

            "QLineEdit::placeholder {"
            "color: #555A63;"
            "}"
            );

        layout->addWidget(field);

        layout->addSpacing(10);
    }

    QPushButton *button =
        new QPushButton(
            "CHANGE PIN"
            );

    button->setMinimumHeight(55);

    button->setStyleSheet(
        mainButtonStyle()
        );

    layout->addWidget(button);

    layout->addStretch();

    connect(
        button,
        &QPushButton::clicked,
        this,
        &MainWindow::changePin
        );
}


// =====================================================
// LOGIN
// =====================================================

void MainWindow::login()
{
    QString enteredUsername =
        usernameEdit->text().trimmed();

    QString enteredPin =
        pinEdit->text();

    if (enteredUsername.isEmpty() ||
        enteredPin.isEmpty())
    {
        QMessageBox::warning(
            this,
            "Login",
            "Please enter username and PIN."
            );

        return;
    }

    if (enteredUsername != username)
    {
        QMessageBox::critical(
            this,
            "Login Failed",
            "Incorrect username."
            );

        return;
    }

    if (enteredPin != pin)
    {
        QMessageBox::critical(
            this,
            "Login Failed",
            "Incorrect PIN."
            );

        return;
    }

    welcomeLabel->setText(
        "Welcome, " + username + "!"
        );

    updateBalance();

    pages->setCurrentWidget(mainPage);

    usernameEdit->clear();
    pinEdit->clear();
}


// =====================================================
// BALANCE
// =====================================================

void MainWindow::updateBalance()
{
    balanceLabel->setText(
        QString("Rs. %1")
            .arg(balance, 0, 'f', 2)
        );
}


// =====================================================
// DEPOSIT
// =====================================================

void MainWindow::depositMoney()
{
    double amount =
        depositAmount->value();

    if (amount <= 0)
    {
        QMessageBox::warning(
            this,
            "Invalid Amount",
            "Enter a valid amount."
            );

        return;
    }

    balance += amount;

    addTransaction(
        "Deposit",
        amount
        );

    updateBalance();

    QMessageBox::information(
        this,
        "Deposit Successful",
        QString(
            "Amount Deposited: Rs. %1\n\n"
            "New Balance: Rs. %2"
            )
            .arg(amount, 0, 'f', 2)
            .arg(balance, 0, 'f', 2)
        );

    showHome();
}


// =====================================================
// WITHDRAW
// =====================================================

void MainWindow::withdrawMoney()
{
    double amount =
        withdrawAmount->value();

    if (amount <= 0)
    {
        QMessageBox::warning(
            this,
            "Invalid Amount",
            "Enter a valid amount."
            );

        return;
    }

    if (amount > balance)
    {
        QMessageBox::critical(
            this,
            "Insufficient Balance",
            QString(
                "Insufficient balance.\n\n"
                "Available Balance: Rs. %1"
                )
                .arg(balance, 0, 'f', 2)
            );

        return;
    }

    balance -= amount;

    addTransaction(
        "Withdrawal",
        amount
        );

    updateBalance();

    QMessageBox::information(
        this,
        "Withdrawal Successful",
        QString(
            "Please collect your cash.\n\n"
            "Withdrawn: Rs. %1\n"
            "Remaining: Rs. %2"
            )
            .arg(amount, 0, 'f', 2)
            .arg(balance, 0, 'f', 2)
        );

    showHome();
}


// =====================================================
// QUICK WITHDRAW
// =====================================================

void MainWindow::quickWithdraw()
{
    QPushButton *button =
        qobject_cast<QPushButton *>(sender());

    if (!button)
        return;

    QString text =
        button->text();

    text.remove("₹");
    text.remove(",");

    double amount =
        text.toDouble();

    if (amount > balance)
    {
        QMessageBox::warning(
            this,
            "Insufficient Balance",
            "Insufficient balance."
            );

        return;
    }

    balance -= amount;

    addTransaction(
        "Quick Withdrawal",
        amount
        );

    updateBalance();

    QMessageBox::information(
        this,
        "Withdrawal Successful",
        QString(
            "Please collect your cash.\n\n"
            "Amount: Rs. %1\n"
            "Remaining Balance: Rs. %2"
            )
            .arg(amount, 0, 'f', 2)
            .arg(balance, 0, 'f', 2)
        );
}


// =====================================================
// ADD TRANSACTION
// =====================================================

void MainWindow::addTransaction(
    const QString &type,
    double amount)
{
    transactionType.append(type);
    transactionAmount.append(amount);

    if (!transactionTable)
        return;

    int row =
        transactionTable->rowCount();

    transactionTable->insertRow(row);

    transactionTable->setItem(
        row,
        0,
        new QTableWidgetItem(
            QString::number(row + 1)
            )
        );

    transactionTable->setItem(
        row,
        1,
        new QTableWidgetItem(type)
        );

    QString amountText;

    if (amount == 0)
    {
        amountText = "-";
    }
    else
    {
        amountText =
            QString("Rs. %1")
                .arg(amount, 0, 'f', 2);
    }

    transactionTable->setItem(
        row,
        2,
        new QTableWidgetItem(
            amountText
            )
        );
}


// =====================================================
// SHOW HOME
// =====================================================

void MainWindow::showHome()
{
    contentPages->setCurrentWidget(
        homePage
        );

    updateBalance();
}


// =====================================================
// SHOW DEPOSIT
// =====================================================

void MainWindow::showDeposit()
{
    contentPages->setCurrentWidget(
        depositPage
        );
}


// =====================================================
// SHOW WITHDRAW
// =====================================================

void MainWindow::showWithdraw()
{
    contentPages->setCurrentWidget(
        withdrawPage
        );
}


// =====================================================
// SHOW TRANSACTIONS
// =====================================================

void MainWindow::showTransactions()
{
    contentPages->setCurrentWidget(
        transactionPage
        );
}


// =====================================================
// SHOW CHANGE PIN
// =====================================================

void MainWindow::showChangePin()
{
    contentPages->setCurrentWidget(
        pinPage
        );
}


// =====================================================
// CHANGE PIN
// =====================================================

void MainWindow::changePin()
{
    QString oldPin =
        oldPinEdit->text();

    QString newPin =
        newPinEdit->text();

    QString confirmPin =
        confirmPinEdit->text();

    if (oldPin != pin)
    {
        QMessageBox::critical(
            this,
            "Incorrect PIN",
            "Current PIN is incorrect."
            );

        return;
    }

    QRegularExpression regex(
        "^[0-9]{4}$"
        );

    if (!regex.match(newPin).hasMatch())
    {
        QMessageBox::warning(
            this,
            "Invalid PIN",
            "New PIN must contain exactly "
            "4 digits."
            );

        return;
    }

    if (newPin != confirmPin)
    {
        QMessageBox::warning(
            this,
            "PIN Mismatch",
            "New PIN and confirmation PIN "
            "do not match."
            );

        return;
    }

    pin = newPin;

    addTransaction(
        "PIN Changed",
        0
        );

    oldPinEdit->clear();
    newPinEdit->clear();
    confirmPinEdit->clear();

    QMessageBox::information(
        this,
        "Success",
        "PIN changed successfully."
        );

    showHome();
}


// =====================================================
// LOGOUT
// =====================================================

void MainWindow::logout()
{
    QMessageBox::StandardButton reply;

    reply =
        QMessageBox::question(
            this,
            "Logout",
            "Are you sure you want to logout?",
            QMessageBox::Yes |
                QMessageBox::No
            );

    if (reply == QMessageBox::Yes)
    {
        pages->setCurrentWidget(
            loginPage
            );

        usernameEdit->clear();
        pinEdit->clear();

        QMessageBox::information(
            this,
            "Logged Out",
            "You have been logged out successfully."
            );
    }
}
