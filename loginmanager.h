#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H
#include "qstring.h"
#include "qcryptographichash.h"
#include "qmap.h"

QString getHashFrom(const QString &inputString);

class LoginManager
{
private:
    QMap<QString, QString> AccountsMap;
public:
    LoginManager();
    bool isValidEmail(const QString& enail);
    QString AccountValidator(const QString& email, const QString& passwordHash);
};

#endif // LOGINMANAGER_H
