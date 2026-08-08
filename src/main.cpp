/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.
For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/

#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QShortcut>
#include <QDebug>

#include "core/launcher.h"
#include "qss/QssManager.h"

static QString getQssFilePath(const QCommandLineParser &parser)
{
    if (parser.isSet("qss")) {
        QString path = parser.value("qss");
        if (!path.isEmpty())
            return QDir::cleanPath(path);
    }
    // сначала ищем рядом с исполняемым файлом
    QString defaultPath = QCoreApplication::applicationDirPath() + "/style.qss";
    if (QFile::exists(defaultPath))
        return defaultPath;
    // потом в домашней папке пользователя
    QString homePath = QDir::homePath() + "/.AyuGram/style.qss";
    if (QFile::exists(homePath))
        return homePath;
    return defaultPath;
}

int main(int argc, char *argv[])
{
    // 1. Создаём QApplication сами (раньше это делал лаунчер)
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("AyuGram");
    QCoreApplication::setApplicationName("AyuGramDesktop");
    QCoreApplication::setApplicationVersion("1.0");

    // 2. Разбираем аргументы командной строки (чтобы поддержать --qss)
    QCommandLineParser parser;
    parser.setApplicationDescription("AyuGramDesktop with QSS support");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(QCommandLineOption("qss", "Path to QSS stylesheet file", "file"));
    parser.process(app);

    // 3. Загружаем QSS-стили (после создания QApplication)
    QString qssPath = getQssFilePath(parser);
    QssManager::instance()->loadStylesheet(qssPath);

    // 4. Хоткей для перезагрузки стилей (глобальный, без родителя)
    QShortcut *reloadShortcut = new QShortcut(QKeySequence("Ctrl+Shift+R"), nullptr);
    QObject::connect(reloadShortcut, &QShortcut::activated, []() {
        qDebug() << "Manual QSS reload triggered";
        QssManager::instance()->reload();
    });

    // 5. Хоткей для включения/отключения стилей
    static bool qssEnabled = true;
    QShortcut *toggleShortcut = new QShortcut(QKeySequence("Ctrl+Shift+Q"), nullptr);
    QObject::connect(toggleShortcut, &QShortcut::activated, []() {
        qssEnabled = !qssEnabled;
        if (qssEnabled) {
            QssManager::instance()->reload();
            qDebug() << "QSS enabled";
        } else {
            qApp->setStyleSheet(QString());
            qDebug() << "QSS disabled";
        }
    });

    // 6. Создаём лаунчер (он не будет создавать новый QApplication, т.к. он уже есть)
    const auto launcher = Core::Launcher::Create(argc, argv);
    if (!launcher)
        return 1;

    // 7. Запускаем основной цикл приложения
    return launcher->exec();
}