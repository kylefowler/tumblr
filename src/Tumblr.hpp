#ifndef TUMBLR_H
#define TUMBLR_H

#include <QtCore/QObject>
#include <QSettings>
#include <QtNetwork/qnetworkreply.h>
#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/cascades/NavigationControl>
#include "AbstractObjectBase.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Button;
        class TextField;
        class SequentialAnimation;
    }
}
class Tumblr : public QObject
{
    Q_OBJECT

public:
    Tumblr();
    ~Tumblr();
    static Tumblr* instance();
    NavigationControl* nav;
private:
    static Tumblr* appInstance;
private slots:
};

#endif // ifndef HELLOCASCADESAPP_H
