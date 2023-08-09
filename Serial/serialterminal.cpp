#include "serialterminal.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QDebug>

SerialTerminal::SerialTerminal(QWidget *parent) : QWidget(parent) {
    serialPort = new QSerialPort(this);

    setupUi();
    updatePortList();

    connect(portComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SerialTerminal::updatePortList);
    connect(connectButton, &QPushButton::clicked, this, &SerialTerminal::connectSerialPort);
    connect(disconnectButton, &QPushButton::clicked, this, &SerialTerminal::disconnectSerialPort);
    connect(sendButton, &QPushButton::clicked, this, &SerialTerminal::sendData);
    connect(serialPort, &QSerialPort::readyRead, this, &SerialTerminal::readData);
}

SerialTerminal::~SerialTerminal() {
    if (serialPort->isOpen())
        serialPort->close();
}

void SerialTerminal::setupUi() {
    portLabel = new QLabel("Serial Port:");
    portComboBox = new QComboBox;
    baudRateLabel = new QLabel("Baud Rate:");
    baudRateComboBox = new QComboBox;
    connectButton = new QPushButton("Connect");
    disconnectButton = new QPushButton("Disconnect");
    dataToSendTextEdit = new QTextEdit;
    receivedDataTextEdit = new QTextEdit;
    sendButton = new QPushButton("Send");

    baudRateComboBox->addItem("9600");
    baudRateComboBox->addItem("19200");
    baudRateComboBox->addItem("38400");
    baudRateComboBox->addItem("57600");
    baudRateComboBox->addItem("115200");

    QHBoxLayout *portLayout = new QHBoxLayout;
    portLayout->addWidget(portLabel);
    portLayout->addWidget(portComboBox);
    portLayout->addWidget(baudRateLabel);
    portLayout->addWidget(baudRateComboBox);
    portLayout->addWidget(connectButton);
    portLayout->addWidget(disconnectButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(portLayout);
    mainLayout->addWidget(dataToSendTextEdit);
    mainLayout->addWidget(receivedDataTextEdit);
    mainLayout->addWidget(sendButton);

    setLayout(mainLayout);
}

void SerialTerminal::updatePortList() {
    portList.clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        portList.append(info.portName());
    }
    portComboBox->clear();
    portComboBox->addItems(portList);
}

void SerialTerminal::connectSerialPort() {
    QString portName = portComboBox->currentText();
    int baudRate = baudRateComboBox->currentText().toInt();

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);

    if (serialPort->open(QIODevice::ReadWrite)) {
        connectButton->setEnabled(false);
        disconnectButton->setEnabled(true);
        portComboBox->setEnabled(false);
    } else {
        qDebug() << "Failed to open the serial port!";
    }
}

void SerialTerminal::disconnectSerialPort() {
    if (serialPort->isOpen()) {
        serialPort->close();
        connectButton->setEnabled(true);
        disconnectButton->setEnabled(false);
        portComboBox->setEnabled(true);
    }
}

void SerialTerminal::sendData() {
    QString dataToSend = dataToSendTextEdit->toPlainText();
    if (serialPort->isWritable()) {
        serialPort->write(dataToSend.toUtf8());
    }
}

void SerialTerminal::readData() {
    QByteArray data = serialPort->readAll();
    receivedDataTextEdit->append(data);
}

