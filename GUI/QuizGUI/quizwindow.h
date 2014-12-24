#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>

namespace Ui {
class QuizWindow;
}

class QuizWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuizWindow(QWidget *parent = 0);
    ~QuizWindow();

private slots:
    void on_bFile_clicked();

    void on_bQuestion_clicked();

    void on_bRAns_clicked();

private:
    Ui::QuizWindow *ui;
};

#endif // QUIZWINDOW_H
