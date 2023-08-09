#ifndef SERIALTERMINAL_H
#define SERIALTERMINAL_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class SerialTerminal : public QWidget {
    Q_OBJECT

public:
    SerialTerminal(QWidget *parent = nullptr);
    ~SerialTerminal();

private slots:
    void connectSerialPort();
    void disconnectSerialPort();
    void sendData();
    void readData();

private:
    void setupUi();
    void updatePortList();

    QSerialPort *serialPort;
    QStringList portList;
    QLabel *portLabel;
    QComboBox *portComboBox;
    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QTextEdit *dataToSendTextEdit;
    QTextEdit *receivedDataTextEdit;
    QPushButton *sendButton;
};

#endif // SERIALTERMINAL_H

