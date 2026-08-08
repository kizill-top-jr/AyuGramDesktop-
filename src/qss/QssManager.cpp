#include "QssManager.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

// Статический экземпляр синглтона
QssManager* QssManager::instance()
{
    static QssManager mgr; // Инициализация при первом вызове (thread-safe в C++11)
    return &mgr;
}

// Конструктор: создаём вотчер, подключаем сигнал
QssManager::QssManager(QObject *parent)
    : QObject(parent)
    , watcher(new QFileSystemWatcher(this))
{
    // При изменении любого файла из списка вотчера вызываем наш слот
    connect(watcher, &QFileSystemWatcher::fileChanged,
            this, &QssManager::onFileChanged);
}

// Основной метод загрузки
void QssManager::loadStylesheet(const QString &path)
{
    // Нормализуем путь (чтобы не было дублей с слешами/обратными слешами)
    QString normalizedPath = QDir::cleanPath(path);
    currentPath = normalizedPath;

    QFile file(normalizedPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Если файл не открылся просто пишем предупреждение, не ломаем приложение.
        qWarning() << "[QssManager] Не удалось открыть QSS-файл:" << normalizedPath;
        return;
    }

    // Читаем весь файл в строку
    QTextStream stream(&file);
    QString style = stream.readAll();
    file.close();

    // Применяем стиль ко всему приложению (глобально)
    qApp->setStyleSheet(style);

    qDebug() << "[QssManager] QSS загружен и применён:" << normalizedPath;

    // Добавляем файл в вотчер, если его ещё нет (чтобы следить за изменениями)
    if (!watcher->files().contains(normalizedPath)) {
        watcher->addPath(normalizedPath);
        qDebug() << "[QssManager] Начат мониторинг файла:" << normalizedPath;
    }
}

// Перезагрузка последнего загруженного файла
void QssManager::reload()
{
    if (currentPath.isEmpty()) {
        qWarning() << "[QssManager] Нет загруженного файла для перезагрузки.";
        return;
    }
    // Просто вызываем загрузку по сохранённому пути
    loadStylesheet(currentPath);
}

// Слот-обработчик изменения файла
void QssManager::onFileChanged(const QString &path)
{
    // Проверяем, что изменился именно наш текущий файл (мало ли других)
    if (path == currentPath) {
        qDebug() << "[QssManager] Обнаружено изменение файла, перезагружаем стили...";
        // Перезагружаем с небольшой задержкой, чтобы файл точно сохранился
        // (на случай, если редактор ещё пишет в него)
        QTimer::singleShot(100, this, [this]() {
            reload();
        });
    }
}