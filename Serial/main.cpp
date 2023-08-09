#include <QApplication>
#include "serialterminal.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SerialTerminal terminal;
    terminal.show();

    return app.exec();
}

