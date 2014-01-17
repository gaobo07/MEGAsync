#ifndef UPDATERGUI_H
#define UPDATERGUI_H

#include <QMainWindow>
#include <QStringList>

namespace Ui {
class UpdaterGUI;
}

class UpdaterGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdaterGUI(QWidget *parent = 0);
    ~UpdaterGUI();

private slots:
    void on_bChangeFolder_clicked();

    void on_bChangeKey_clicked();

    void on_bGenerateKey_clicked();

    void on_bGenerateUpdate_clicked();

    void on_bVerifyUpdate_clicked();

private:
    bool readKeys(QString path);
    bool verifySourcePath(QString path);

    Ui::UpdaterGUI *ui;
    QStringList dstPaths;
    QStringList updateFiles;
    QStringList finalSourcePaths;
    char PUBLIC_KEY[2048];
    char PRIVATE_KEY[2048];

    static const QString VERSION;
    static const QString BASE_UPDATE_URL;
};

#endif // UPDATERGUI_H
