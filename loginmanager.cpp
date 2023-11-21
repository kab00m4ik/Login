#include "loginmanager.h"
#include "qdebug.h"


LoginManager::LoginManager()
{
    // valid Accounts
    this->AccountsMap.insert("123@gmail.com", getHashFrom("123"));
    this->AccountsMap.insert("email@gmail.com", getHashFrom("password"));
}

bool LoginManager::isValidEmail(const QString &email)
{
    if(email.contains(' ')) return false;
    if(email.count('@') > 1) return false;
    int DomainStartId = email.indexOf('@');
    if(DomainStartId == -1) return false;

    QString mail = email.mid(0, DomainStartId);
    QString domain = email.mid(DomainStartId, email.length() - 1);

    if(!domain.contains('.')) return false;
    if(mail.length()>64) return false;

    QString SpecSymbols = "?“#$%&`*+–_./|\^{}~" + '"';
    if(SpecSymbols.contains(mail[0]) || SpecSymbols.contains(mail[mail.length() - 1]));

    return true;
}

QString LoginManager::AccountValidator(const QString& email, const QString& passwordHash)
{
    if(!isValidEmail(email))
    {
        return "Wrong email format";
    }
    auto it = AccountsMap.find(email);//зберігаємо ітератор на знайдену пару (щоб не викликати функцію 2 рази)
    if(it==AccountsMap.end())return "Email is not registered";
    return it.value() == passwordHash? "Login successful!" : "Password is not registered"; // перевіряємо чи збігається хеш паролю
}

QString getHashFrom(const QString &inputString)
{
    QByteArray byteArray = QCryptographicHash::hash(inputString.toUtf8(), QCryptographicHash::Sha256);
    QString hashedString = byteArray.toHex();
    return hashedString;
}
