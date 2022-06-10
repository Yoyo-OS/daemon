#ifndef DSTORETOOL_H
#define DSTORETOOL_H

#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QDirIterator>
#include <QProcess>
#include <QFileSystemWatcher>

#include <unistd.h>

class DStoreTool : public QObject
{
    Q_OBJECT

public:
    explicit DStoreTool(QObject *parent = nullptr);
    void run();

private:
    QFileSystemWatcher * m_watcher;
    QList<QJsonObject> enumAppInfoList();
    void linkDir(const QString &source, const QString &target);
    void setRpath(const QString &file, const QString &path);
    QString getGlic();
    void linkApp(const QJsonObject &app);
    void cleanLink();
    void update();
};

#endif // DSTORETOOL_H
