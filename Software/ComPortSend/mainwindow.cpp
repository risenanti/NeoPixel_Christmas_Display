#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_serialPort = new QSerialPort(this);
    m_serialPort->setBaudRate(115200);

    serConnect   = new QPushButton(this);
    gButton      = new QPushButton(this);
    rButton      = new QPushButton(this);
    bButton      = new QPushButton(this);
    defButton    = new QPushButton(this);


    connect(ui->serConnect, SIGNAL(clicked()),
                this, SLOT(openPort()));

    connect(ui->gButton, SIGNAL(clicked()),
                this, SLOT(writeG()));
    connect(ui->bButton, SIGNAL(clicked()),
                this, SLOT(writeB()));
    connect(ui->rButton, SIGNAL(clicked()),
                this, SLOT(writeR()));
    connect(ui->defButton, SIGNAL(clicked()),
                this, SLOT(writeDefault()));
   }



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPort(void)
{
    m_serialPort->setPortName("COM10");
    m_serialPort->open(QIODevice::WriteOnly);
}

void MainWindow::write(const QByteArray &writeData)
{
    m_writeData = writeData;

    qint64 bytesWritten = m_serialPort->write(writeData);
}

void MainWindow::writeG(void)
{
    m_writeData = "G";

    qint64 bytesWritten = m_serialPort->write("G");
}

void MainWindow::writeB(void)
{
    m_writeData = "B";

    qint64 bytesWritten = m_serialPort->write("B");
}

void MainWindow::writeR(void)
{
    m_writeData = "R";

    qint64 bytesWritten = m_serialPort->write("R");
}

void MainWindow::writeDefault(void)
{
    m_writeData = "X";

    qint64 bytesWritten = m_serialPort->write("X");
}
