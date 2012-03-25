#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/controls/navigationcontrol.h>
#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include <bb/cascades/animation/groupanimation.h>
#include <bb/cascades/animation/translatetransition.h>
#include <bb/cascades/animation/stockcurve.h>

#include "Tumblr.hpp"
#include "TumblrApi.h"
#include "RequestEnvelope.h"
#include "HomeLayout.h"

using namespace bb::cascades;

Tumblr::Tumblr()
{
    QmlDocument *qml = QmlDocument::create("tumblrlogin.qml");
    qml->setContextProperty("cs", this);

    Control *root = qml->createRootNode<Control>();
    loginButton = root->findChild<Button*>("login");
    username = root->findChild<TextField*>("username");
    password = root->findChild<TextField*>("password");
    connect(loginButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    //connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestComplete(QNetworkReply*)));

    Application::setScene(root);
}

Tumblr::~Tumblr()
{
}

void Tumblr::makeLoginRequest()
{
	qDebug() << "Making request";
	xauth();
}

void Tumblr::onButtonClicked()
{
	if(TumblrApi::instance()->checkToken()) {
		loginButton->setText("Logging In");
		makeLoginRequest();
	} else {
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, TumblrApi::instance()->getUserInfo());
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	}
}

void Tumblr::requestComplete(QNetworkReply* reply)
{
	qDebug() << "Response Received";
	qDebug() << QString(reply->readAll());
}

void Tumblr::onLoginResponse(bool success) {
	if(success) {
		qDebug() << "Login success yayyyyy";
		loginButton->setText("Login Success");
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, TumblrApi::instance()->getUserInfo());
		//FIXME I think the this keyword is referring to the object doing the emitting and not the tumblr class and causing callback issues
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	} else {
		qDebug() << "Login failed womp womp";
		loginButton->setText("Login Failed");
	}
	disconnect(TumblrApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
}

void Tumblr::xauth() {
	if(username->text().length() > 0 && password->text().length() > 0) {
		connect(TumblrApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
		TumblrApi::instance()->xauth(username->text(),password->text());
	} else {
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		loginButton->setText("Please enter password, click again after you put the infoz in");
	}
}

void Tumblr::onUserDataLoad(AbstractObjectBase* user) {
	User* usr = dynamic_cast<User*>(user);
	HomeLayout *home = new HomeLayout(usr);
	Application::setScene(home);
}
