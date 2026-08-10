<!--
 █████╗ ██╗   ██╗██╗   ██╗ ██████╗ ██████╗  █████╗ ███╗   ███╗
██╔══██╗╚██╗ ██╔╝██║   ██║██╔════╝ ██╔══██╗██╔══██╗████╗ ████║
███████║ ╚████╔╝ ██║   ██║██║  ███╗██████╔╝███████║██╔████╔██║
██╔══██║  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗██╔══██║██║╚██╔╝██║
██║  ██║   ██║   ╚██████╔╝╚██████╔╝██║  ██║██║  ██║██║ ╚═╝ ██║
╚═╝  ╚═╝   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝
-->

# ✦ AyuGramDesktop ✦
### *Telegram Desktop, переосмысленный через QSS*

> "Где стиль встречает код, а кастомизация становится искусством."

---

[![Release](https://img.shields.io/github/v/release/kizill-top-jr/AyuGramDesktop-?style=for-the-badge&color=purple&label=Версия)](https://github.com/kizill-top-jr/AyuGramDesktop-/releases)
[![License](https://img.shields.io/github/license/kizill-top-jr/AyuGramDesktop-?style=for-the-badge&color=blue)](LICENSE)
[![Build](https://img.shields.io/github/actions/workflow/status/kizill-top-jr/AyuGramDesktop-/build.yml?style=for-the-badge&label=Сборка)](https://github.com/kizill-top-jr/AyuGramDesktop-/actions)
[![Stars](https://img.shields.io/github/stars/kizill-top-jr/AyuGramDesktop-?style=for-the-badge&color=yellow)](https://github.com/kizill-top-jr/AyuGramDesktop-/stargazers)
[![Telegram](https://img.shields.io/badge/Чат-в_Telegram-26A5E4?style=for-the-badge&logo=telegram)](https://t.me/your_channel)

---

## 📖 О чём это?

**AyuGramDesktop** – это форк официального Telegram Desktop, в который мы добавили **магию QSS**. Теперь ты можешь менять внешний вид клиента **на лету**, без пересборок и правки исходников. Просто редактируй `.qss`-файл, и интерфейс преображается мгновенно.

> 🚀 **Свобода творчества:** хочешь тёмную тему с неоновыми акцентами? Или минималистичный светлый дизайн? Легко! Всё ограничено только твоей фантазией (и знанием CSS).

---

## ✨ Особенности

- 🎨 **Живая кастомизация** – изменение стилей в реальном времени через QSS.
- ⚡ **Мгновенная перезагрузка** – сохранил файл → стили обновились.
- 🧩 **Простая интеграция** – достаточно одного вызова `QssManager::instance()->loadStylesheet()`.
- 🔍 **Встроенный вотчер** – `QFileSystemWatcher` автоматически перезагружает стили при изменении.
- 🛠 **Ручное управление** – метод `reload()` для принудительной перезагрузки.
- 📦 **Никаких зависимостей** – всё работает внутри стандартного Qt-стека.
- 🌍 **Кроссплатформенность** – Windows, Linux, macOS (как и оригинальный Telegram).

---

## 🚀 Быстрый старт

1. **Скачай** последний релиз или собери из исходников.
2. **Создай** файл стилей, например `~/.config/AyuGram/style.qss`.
3. **Загрузи** его в приложении – добавь в код (или используй готовую настройку, если она уже есть).
4. **Редактируй** – изменения применяются сразу.
5. **Наслаждайся** уникальным интерфейсом!

---

## 🎨 Пример QSS (чтобы ты понял, на что способен)

```css
/* Основное окно – космическая глубина */
QWidget#mainWindow {
    background-color: #0b0b1a;
    border: 1px solid #1a1a3e;
}

/* Список чатов – с лёгкой дымкой */
ChatListWidget {
    background-color: #14142e;
    border-right: 2px solid #2a2a5e;
}

/* Элемент чата – интерактивный и плавный */
ChatItem {
    background: transparent;
    border-radius: 10px;
    padding: 10px 14px;
    margin: 2px 0;
    transition: background 0.2s;
}

ChatItem:hover {
    background-color: #2a2a5e;
}

/* Поле ввода – как стекло */
InputField {
    background-color: rgba(20, 20, 46, 0.8);
    border: 1px solid #4a4a8a;
    border-radius: 14px;
    color: #d0d0f0;
    padding: 10px 16px;
}

/* Кнопки – с неоновым отливом */
QPushButton {
    background-color: #3a3a7a;
    border: none;
    border-radius: 8px;
    color: #ffffff;
    padding: 8px 20px;
    font-weight: bold;
}

QPushButton:hover {
    background-color: #5a5aaa;
    box-shadow: 0 0 12px #6a6aca;
}
