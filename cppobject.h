#ifndef CPPOBJECT_H
#define CPPOBJECT_H

#include <QObject>

//派生自QObject
//使用qmlRegisterType注册到QML中
class CppObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged) //注册属性，使之可以在QML中访问--具体语法百度Q_PROPERTY
    Q_PROPERTY(int year READ getYear WRITE setYear NOTIFY yearChanged)

public:
    explicit CppObject(QObject *parent = nullptr);
    Q_INVOKABLE void sendSignal();  //功能为发送信号  //通过Q_INVOKABLE宏标记的public函数可以在QML中访问
    void setName(const QString &name);  //给类属性添加访问方法--myName
    QString getName() const;   //给类属性添加访问方法--myYear
    void setYear(int year);
    int getYear() const;

signals:   //信号可以在QML中访问

    void cppSignalA();  //一个无参信号
    void cppSignalB(const QString &str,int value);//一个带参数信号
    void nameChanged(const QString name);
    void yearChanged(int year);

public slots:  //public槽函数可以在QML中访问
    void cppSlotA();  //一个无参槽函数
    void cppSlotB(const QString &str,int value);  //一个带参数槽函数

private:
    QString myName;  //类的属性
    int myYear;
};

#endif // CPPOBJECT_H
