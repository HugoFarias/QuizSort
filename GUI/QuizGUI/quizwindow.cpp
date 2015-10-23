#include <stdio.h>
#include <QFileDialog>
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
    //QString nameFile = ui->tFile->text();
    QString nameFile = QFileDialog::getOpenFileName(this, tr("Abrir arquivo de Quiz"), "", tr("Arquivos de Quiz (*.qz)"));
    //ui->tFile->clear();
    char *name = nameFile.toLocal8Bit().data();
    if(!chargeFile(name)){
        QString out;
        out.sprintf("Arquivo <%s> aberto!\n%d perguntas carregadas", name, getNQst());
        ui->tAnswer->setText(out);
        charged = true;
    }else{
        ui->tAnswer->setText("");
        charged = false;
    }
}

void QuizWindow::on_bQuestion_clicked()
{
    if(charged){
        QString qQst;
        char *qst = genQst();
        if(!(long)qst){
            qQst = "FIM DE JOGO!!!";
        }else{
            char *ans = genAns();
            qQst.sprintf("%s%s\n", qst, ans);
            free(ans);
            answered = false;
        }
        ui->tAnswer->setPlainText(qQst);
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
