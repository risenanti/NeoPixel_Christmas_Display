#include <QMainWindow>
#include<QtWidgets>

#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

void setName(const QString &name);


public slots:
    void openPort(void);
    void write(const QByteArray &writedata);
    void writeG(void);
    void writeB(void);
    void writeR(void);

    void writeDefault(void);


private:
    Ui::MainWindow *ui;


    QPushButton *serConnect;
    QPushButton *gButton;
    QPushButton *rButton;
    QPushButton *bButton;
    QPushButton *defButton;

    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    QTimer          m_timer;
};

