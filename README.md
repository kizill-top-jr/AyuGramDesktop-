<p align="center">
  <img src="https://raw.githubusercontent.com/kizill-top-jr/QssGram/master/resources/logo.png" width="120" alt="QssGram Logo">
</p>

<h1 align="center">✦ QSSGRAM ✦</h1>
<p align="center"><strong>Telegram Desktop, переосмысленный через QSS</strong></p>

<p align="center">
  <img src="https://img.shields.io/github/v/release/kizill-top-jr/QssGram?style=flat-square&color=purple&label=Версия" />
  <img src="https://img.shields.io/github/license/kizill-top-jr/QssGram?style=flat-square&color=blue" />
  <img src="https://img.shields.io/github/stars/kizill-top-jr/QssGram?style=flat-square&color=yellow" />
  <img src="https://img.shields.io/badge/Чат-@QssGram_Chat-26A5E4?style=flat-square&logo=telegram" />
  <img src="https://img.shields.io/badge/Канал-@QssGram-26A5E4?style=flat-square&logo=telegram" />
</p>

---

## 📌 О проекте

**QssGram** – это форк Telegram Desktop с полной поддержкой **QSS** (Qt Style Sheets).  
Ты можешь менять **каждый пиксель** интерфейса на лету – без пересборок и перезапусков.

> Просто редактируй .qss файл – и интерфейс меняется мгновенно.

---

## 🚀 Быстрый старт

1. Скачай последнюю версию в [Releases](https://github.com/kizill-top-jr/QssGram/releases).
2. Положи файл `style.qss` рядом с `QssGram.exe`.
3. Запусти приложение – стили применятся автоматически.
4. Меняй содержимое `style.qss` – результат виден сразу.

---

## 🎨 Пример конфига

```css
/* Тёмная тема с акцентами */
QWidget {
    background: #1a1a1a;
    color: #dddddd;
}
QPushButton {
    background: #2a2a2a;
    border: 1px solid #444;
    border-radius: 6px;
    padding: 6px 12px;
}
QPushButton:hover {
    background: #3a3a3a;
}
