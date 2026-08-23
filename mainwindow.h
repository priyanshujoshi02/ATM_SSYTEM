#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>

class QStackedWidget;
class QLineEdit;
class QLabel;
class QPushButton;
class QTableWidget;
class QDoubleSpinBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void login();
    void logout();

    void showHome();
    void showDeposit();
    void showWithdraw();
    void showTransactions();
    void showChangePin();

    void depositMoney();
    void withdrawMoney();
    void quickWithdraw();

    void changePin();

private:
    void createLoginPage();
    void createMainPage();
    void createHomePage();
    void createDepositPage();
    void createWithdrawPage();
    void createTransactionPage();
    void createPinPage();

    void updateBalance();
    void addTransaction(const QString &type, double amount);

    QStackedWidget *pages;
    QStackedWidget *contentPages;

    // Login
    QWidget *loginPage;
    QLineEdit *usernameEdit;
    QLineEdit *pinEdit;

    // Main
    QWidget *mainPage;
    QWidget *contentArea;

    // Home
    QWidget *homePage;
    QLabel *balanceLabel;
    QLabel *welcomeLabel;

    // Deposit
    QWidget *depositPage;
    QDoubleSpinBox *depositAmount;

    // Withdraw
    QWidget *withdrawPage;
    QDoubleSpinBox *withdrawAmount;

    // Transactions
    QWidget *transactionPage;
    QTableWidget *transactionTable;

    // PIN
    QWidget *pinPage;
    QLineEdit *oldPinEdit;
    QLineEdit *newPinEdit;
    QLineEdit *confirmPinEdit;

    // Account
    QString username;
    QString pin;
    double balance;

    QVector<QString> transactionType;
    QVector<double> transactionAmount;
};

#endif
