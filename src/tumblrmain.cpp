#include <QtCore/QObject>

#include <bb/cascades/Application>

#include "Tumblr.hpp"

using ::bb::cascades::Application;

int main(int argc, char **argv)
{
    // this is where the server is started etc
    Application app(argc, argv);

    Tumblr::instance();
//    QObject::connect(&app, SIGNAL(aboutToQuit()), &mainApp, SLOT(doCleanup()));

    return Application::exec(); // we complete the transaction started in the app constructor and start the client event loop here
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
    // not as nice of course
}
