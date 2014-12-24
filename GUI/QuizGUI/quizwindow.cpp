#include <stdio.h>
#include "quizwindow.h"
#include "ui_quizwindow.h"
#include "quiz.h"

bool charged = false;
bool answered = false;

QuizWindow::QuizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuizWindow)
{
    ui->setupUi(this);
}

QuizWindow::~QuizWindow()
{
    delete ui;
    if(charged) finish();
}

void QuizWindow::on_bFile_clicked()
{
    if(charged) finish();
    QString nameFile = ui->tFile->text();
    ui->tFile->clear();
    char *name = nameFile.toLocal8Bit().data();
    if(!chargeFile(name)){
        QString out;
        out.sprintf("Arquivo <%s> aberto!\n%d perguntas carregadas", name, getNQst());
        ui->tAnswer->setText(out);
        charged = true;
    }else{
        ui->tAnswer->setText("Erro!");
        charged = false;
    }
}

void QuizWindow::on_bQuestion_clicked()
{
    if(charged){
        char *qst = genQst();
        char *ans = genAns();
        QString qQst;
        qQst.sprintf("%s%s\n", qst, ans);
        ui->tAnswer->setPlainText(qQst);
        free(ans);
        answered = false;
    }
}

void QuizWindow::on_bRAns_clicked()
{
    if(charged && !answered){
        QString qAns;
        qAns.sprintf("RESPOSTA: %c) %s\n", nRightAns(), rightAns());
        ui->tAnswer->append(qAns);
        answered = true;
    }
}
