#pragma once

/*
 * QssManager синглтон для управления QSS (Qt Style Sheets) в приложении.
 * 
 * Основные задачи:
 * 1. Загружать стили из внешнего .qss-файла.
 * 2. Автоматически перезагружать их при изменении файла (через QFileSystemWatcher).
 * 3. Предоставлять метод для ручной перезагрузки (например, по хоткею).
 * 
 * Использование:
 *   QssManager::instance() в loadStylesheet("/путь/к/style.qss");
 * 
 * Для автоматической перезагрузки файл должен быть доступен для записи,
 * и менеджер отслеживает его изменения через системный вотчер.
 */

#include <QObject>
#include <QFileSystemWatcher>

class QssManager : public QObject
{
    Q_OBJECT

public:
    // Доступ к единственному экземпляру (синглтон)
    static QssManager* instance();

    // Загрузить стили из указанного пути
    // Если файл не существует будет предупреждение в лог, но приложение не упадёт.
    void loadStylesheet(const QString &path);

    // Перезагрузить последний загруженный файл (без указания пути)
    void reload();

private:
    // Приватный конструктор для синглтона
    explicit QssManager(QObject *parent = nullptr);

    // Сохраняем путь к текущему файлу, чтобы знать, что перезагружать
    QString currentPath;

    // Вотчер, который следит за изменениями файла
    QFileSystemWatcher *watcher;

private slots:
    // Слот, вызываемый при изменении отслеживаемого файла
    void onFileChanged(const QString &path);
};