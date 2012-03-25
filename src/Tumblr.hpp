#ifndef TUMBLR_H
#define TUMBLR_H

#include <QtCore/QObject>
#include <QSettings>
#include <QtNetwork/qnetworkreply.h>
#include <bb/cascades/Application>
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
    Button *loginButton;
    TextField *username;
    TextField *password;
    void makeLoginRequest();
    void getAccess();
    void xauth();
private:
private slots:
	void onButtonClicked();
	void requestComplete(QNetworkReply*);
	void onLoginResponse(bool);
	void onUserDataLoad(AbstractObjectBase*);
};

#endif // ifndef HELLOCASCADESAPP_H
