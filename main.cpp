#include <QApplication>
#include "widget.hpp"
#include "game.hpp"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    Game g;

    Widget w(&g);
    w.show();

    return app.exec();
}