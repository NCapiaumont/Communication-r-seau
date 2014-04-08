#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Connecter_triggered();
    void traiterMessagesDuServeur();
    void on_pushButtonEnvoyer_clicked();

    void on_action_Quitter_triggered();

    void on_action_Nouvelle_conversation_triggered();

private:
    Ui::MainWindow *ui;
    QTcpSocket * laSocketVersLeServeur;
};

#endif // MAINWINDOW_H
