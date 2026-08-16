<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Orbitron&weight=900&size=36&pause=300&color=FF0000&center=true&vCenter=true&width=800&lines=✦+QSSGRAM+✦;TELEGRAM%2C+RELOADED;STYLE+MEETS+CODE" alt="Typing SVG" />
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png" width="100%">
</p>

---

<div align="center">
  <img src="https://img.shields.io/github/v/release/kizill-top-jr/QssGram?style=for-the-badge&color=purple&label=Версия&logo=github" />
  <img src="https://img.shields.io/github/license/kizill-top-jr/QssGram?style=for-the-badge&color=blue&label=Лицензия" />
  <img src="https://img.shields.io/github/actions/workflow/status/kizill-top-jr/QssGram/build.yml?style=for-the-badge&label=Сборка&logo=githubactions" />
  <img src="https://img.shields.io/github/stars/kizill-top-jr/QssGram?style=for-the-badge&color=yellow&label=Звёзды&logo=github" />
  <img src="https://img.shields.io/badge/Чат-в_Telegram-26A5E4?style=for-the-badge&logo=telegram" />
  <img src="https://img.shields.io/badge/OS-Windows%20%7C%20Linux%20%7C%20macOS-9cf?style=for-the-badge&logo=linux" />
</div>

---

# ✦ QSSGRAM ✦
### *Telegram Desktop, переосмысленный через QSS*

> **«Где стиль встречает код, а кастомизация становится искусством.»**  
> — *KIZILL_TOP_JR, 2026*

---

## 📖 О чём эта хуйня?

**QssGram** – это не просто форк Telegram Desktop. Это **оружие дизайнера-разработчика**, позволяющее перекраивать интерфейс мессенджера **на лету**, без пересборок, без перезапусков, без компромиссов. Всё, что тебе нужно – знать QSS (Qt Style Sheets) и иметь чувство стиля.

> 🚀 **Свобода творчества:** хочешь тёмную тему с неоновыми акцентами? Легко. Хочешь минимализм в духе космической станции? Без проблем. Хочешь, чтобы твой Telegram выглядел как интерфейс звездолёта? **Делай.**

---

## ✨ Что мы тут наворотили

- 🎨 **Живая кастомизация** – QSS-стили подгружаются в реальном времени.
- ⚡ **Мгновенная перезагрузка** – сохранил .qss → интерфейс обновился за миллисекунду.
- 🧩 **Интеграция в один вызов** – достаточно `QssManager::instance()->loadStylesheet()`.
- 🔍 **Автоматический вотчер** – `QFileSystemWatcher` следит за файлом и перезагружает стили при каждом сохранении.
- 🛠 **Ручной релоад** – метод `reload()` для тех, кто любит держать всё под контролем.
- 📦 **Нулевая зависимость** – работает внутри стандартного Qt-стека, без лишних библиотек.
- 🌍 **Кроссплатформенность** – Windows, Linux, macOS (везде, где работает оригинальный Telegram).
- 🧠 **Интеллектуальная система стилей** – поддержка вложенных селекторов, переменных и динамических состояний.

---

## 🚀 Быстрый старт (для нетерпеливых)

1. **Скачай** последний релиз с [Releases](https://github.com/kizill-top-jr/QssGram/releases).
2. **Создай** файл стилей, например `~/.config/QssGram/style.qss`.
3. **Загрузи** его в приложении (или используй встроенную настройку).
4. **Редактируй** – изменения применяются сразу без перезапуска.
5. **Наслаждайся** уникальным интерфейсом, которого нет ни у кого.

---

## 🎨 Пример QSS-кода (чтобы ты понял, на что способен)

```css
/* Основное окно – космическая глубина */
QWidget#mainWindow {
    background-color: #0b0b1a;
    border: 1px solid #1a1a3e;
}

/* Список чатов – с лёгкой дымкой и стеклянным эффектом */
ChatListWidget {
    background-color: rgba(20, 20, 46, 0.9);
    border-right: 2px solid #2a2a5e;
    border-radius: 0 12px 12px 0;
    backdrop-filter: blur(4px);
}

/* Элемент чата – интерактивный, с плавными переходами */
ChatItem {
    background: transparent;
    border-radius: 10px;
    padding: 10px 14px;
    margin: 2px 0;
    transition: background 0.2s, transform 0.1s;
}

ChatItem:hover {
    background-color: #2a2a5e;
    transform: scale(1.02);
}

ChatItem:selected {
    background-color: #3a3a8a;
    border-left: 4px solid #ff4500;
}

/* Поле ввода – как стекло, с неоновой подсветкой */
InputField {
    background-color: rgba(20, 20, 46, 0.7);
    border: 1px solid #4a4a8a;
    border-radius: 14px;
    color: #d0d0f0;
    padding: 10px 16px;
    backdrop-filter: blur(8px);
}

InputField:focus {
    border-color: #ff4500;
    box-shadow: 0 0 20px rgba(255, 69, 0, 0.3);
}

/* Кнопки – с неоновым отливом и эффектом нажатия */
QPushButton {
    background-color: #3a3a7a;
    border: none;
    border-radius: 8px;
    color: #ffffff;
    padding: 8px 20px;
    font-weight: bold;
    transition: background 0.15s, transform 0.1s;
}

QPushButton:hover {
    background-color: #5a5aaa;
    box-shadow: 0 0 16px #6a6aca;
    transform: translateY(-1px);
}

QPushButton:pressed {
    background-color: #2a2a5a;
    transform: translateY(1px);
}

/* Скроллбары – тонкие и стильные */
QScrollBar:vertical {
    background: transparent;
    width: 6px;
    margin: 0px 2px;
}

QScrollBar::handle:vertical {
    background: #5a5aaa;
    border-radius: 3px;
    min-height: 30px;
}

QScrollBar::handle:vertical:hover {
    background: #7a7aca;
}

/* Анимированное свечение для новых сообщений */
@keyframes pulse {
    0% { opacity: 0.6; }
    50% { opacity: 1; }
    100% { opacity: 0.6; }
}

.ChatItem-unread {
    animation: pulse 1.5s infinite;
    background-color: rgba(255, 69, 0, 0.1);
}
