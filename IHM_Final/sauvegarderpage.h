#ifndef SAUVEGARDERPAGE_H
#define SAUVEGARDERPAGE_H

#include <QDialog>

namespace Ui {
class sauvegarderpage;
}

class sauvegarderpage : public QDialog
{
    Q_OBJECT

public:
    explicit sauvegarderpage(QWidget *parent = nullptr);
    ~sauvegarderpage();

private slots:
    void on_butSave_clicked();

    void on_nomPiece_textEdited(const QString &arg1);

    void on_butDeco_clicked();

signals:
    void changePage(QString value);

private:
    Ui::sauvegarderpage *ui;
    QString piece;
};

#endif // SAUVEGARDERPAGE_H
