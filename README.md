# Шаблон для оформления учебной документации на кафедре ПИИТУ НТУ "ХПИ" с использованием издательской системы XeLaTeX

## Краткое описание
Это набор шаблонов, который позволяет быстро оформлять учебную документацию для студентов кафедры ПИИТУ НТУ "ХПИ". В настоящий момент имеются следующие возможности:
 * Поля страниц, нумерация страниц, шрифт не требуют ручной настройки;
 * Автоматизированная подготовка содержания документа;
 * Автоматизированное оформление библиографического списка в соответствии со стандартом ДСТУ;
 * Поддержка вставки, масштабирования, подписи изображений;  
 * Поддержка вставки листингов, в том числе длинных листингов на несколько страниц в соответствии с требованиями стандарта;
 * Автоматическая подготовка и нумерация объектов. Перекрёстные ссылки;
 * Возможность смены ориентации одной или нескольких страниц, всего документа;
 * Поддержка длинных таблиц с разрывами;
 * Автоматическое оформление приложений, простановка дат, списков сокращений и прочих мелочей.
 
Набор состоит из множества пакетов, большинство из них не используются в каждом документе. Например, если не требуется поддержка листингов, пакет <tt>kpi.util.listing</tt> подключать не нужно. Это улучшает понимание возможностей набора для пользователей и не замусоривает область видимости, облегчает компиляцию документов.

Основной шаблон - <tt>kpi.template.document.tex</tt>. Он подходит для оформления отчётов, дипломных и курсовых работ. Для оформления заявлений, объяснительных и прочих подобных документов есть шаблон <tt>kpi.template.statement.tex</tt>.

Подробная документация в формате TeX и PDF находится в поддиректории "doc".

## Библиография
Для работы с библиографией используется BibTeX. .bst-файлы приложены.

Для оформления записей в bib-файл можете воспользоваться <a href="https://chrome.google.com/webstore/detail/any-bibtex/pcneplpbjokfakcgcihplkaomiolelim">плагином</a> к Google Chrome.

## Инструментарий
Пакет ориентирован на компиляцию с помощью XeLaTeX. В состав включены bat-файлы для задач очистки и компиляции проекта. В последнем используется утилита <tt>latexmk</tt>.

Пакет разрабатывается и поддерживается в среде <a href="http://texstudio.sourceforge.net/" target="_blank">TeXstudio</a>, разработан <tt>CWL</tt>-файл для автодополнения и подсказок по синтаксису пакетов в этой IDE.

## Лицензия
Данный набор шаблонов выпускается под лицензией CC-BY-SA (http://creativecommons.org/licenses/by-sa/3.0/), то есть никаких гарантий на функционал или просто работоспособность не предоставляется. Вы можете как угодно изменять этот пакет, с сохранением первоначального авторства за его оригинальными авторами (Livich и Vbolshutkin).

## Статус проекта
Этот набор не является официальным и не поддерживается никаким подразделением НТУ "ХПИ".