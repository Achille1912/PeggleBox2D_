#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    /* il main() di un’applicazione grafica Qt deve sempre iniziare con l’istanziazione di una QApplication
       se provo ad istanziare oggetti Qt prima di aver istanziato una QApplication, si genera un errore a tempo di esecuzione
    */

    /*
        un widget è creato hidden (non visibile)
        ragionevole, per avere il tempo di personalizzarlo prima di renderlo visibile ed evitare effetti di flickering
        il metodo show() rende un widget visibile e lo disegna su schermo
        virtual paintEvent() è la funzione deputata al disegno su schermo
        è invocata automaticamente quando cambia lo stato dell’oggetto
        si può ridefinire (overriding) e quindi si può  ridisegnare (e personalizzare) un widget come vogliamo!
    */

    //istanzio applicazione Qt
    QApplication app(argc, argv);

    PGG::Game::instance()->show();

    //eseguo applicazione Qt
    return app.exec();

    /* eseguire (mediante il metodo exec()) una QApplication significa lasciare il controllo a Qt dopo aver creato tutti gli elementi grafici
       ovvero significa entrare nell’event loop
       e mettersi in attesa di interazioni dell’utente (ad es. da tastiera e mouse) che generano eventi
    */
}
