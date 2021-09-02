##Репозиторий для сдачи работ по курсу Информатика и Программирование

В этом репозитории будут собраны полезные материалы для прохождения курса, а также организована работа по сдаче лабораторных работ.

###Необходимые ресурсы

  - [Microsoft Visual Studio 2019 Community][https://visualstudio.microsoft.com/ru/vs/community/] как пример интегрированной среды разработки (IDE) приложенийю
  - [Git][git] как пример системы контроля версий (VCS). [Git for Windows][https://git-scm.com/downloads] [tortoisegit][https://tortoisegit.org/]
  - [GitHub][https://github.com] как пример хостинга для проектов.


###Контакты

Усова Марина Андреевна: oppabang@mail.ru

###Результаты
Таблица успеваемости - https://docs.google.com/spreadsheets/d/1MoguRn2Q_OdIwSN-sMbbFOrdAJctn4IrnG3s8Yem0DU/edit?usp=sharing

###Основные команды для работы с git и Github

  1. Создать свой личный аккаунт на [GitHub][https://github.com], если таковой
     отсутствует.

  2. Сделать fork [центрального репозитория] [https://github.com/MAUsova/Informatics-and-Programming] (Сделали на практике) к себе в личное пространство на GitHub. В результате
     будет создана копия репозитория с названием
	 1. В правом верхнем углу окна GitHub нажать кнопку `Fork`.
     2. Выбрать в качестве организации, куда направить форк, организацию,
        соответствующую вашему личному аккаунту.

  3. Клонировать origin-репозиторий к себе на локальный компьютер,
     воспользовавшись следующей командой:

  ```bash
  $ git clone {адрес вашего репозитория}
  ```

  4. Перейти в созданную директорию :

  ```bash
  $ cd Informatics-and-Programming/
  ```


  5. Настроить имя пользователя, из-под которого будут выполняться все операции
     с репозиторием Git:

  ```bash
  $ git config --local user.name "Your Name"
  $ git config --local user.email "your.email@somewhere.com"
  ```
  
  Просмотр текущих настроек
  git config --list
  
  Очистить текущие параметры
  git config --local credential.helper ""

  Примечание: если не выполнить указанную операцию, то при попытке размещения
  изменений на сервер появится сообщение, приведенное ниже.

  ```
  warning: push.default is unset; its implicit value is changing in
  Git 2.0 from 'matching' to 'simple'. To squelch this message
  and maintain the current behavior after the default changes, use:

    git config --global push.default matching

  To squelch this message and adopt the new behavior now, use:

    git config --global push.default simple

  When push.default is set to 'matching', git will push local branches
  to the remote branches that already exist with the same name.

  In Git 2.0, Git will default to the more conservative 'simple'
  behavior, which only pushes the current branch to the corresponding
  remote branch that 'git pull' uses to update the current branch.

  See 'git help config' and search for 'push.default' for further information.
  (the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
  'current' instead of 'simple' if you sometimes use older versions of Git)

  Username for 'https://https://github.com.com': <your-github-account>
  Password for 'https://https://github.com-account@https://github.com.com': <your-password-from-github-account>
  ```

#### Работа с ветками

Когда сделан форк репозитория, у вас по умолчанию создается единственная ветка
`master`. Тем не менее, при решении независимых задач следует создавать
отдельные ветки Git. Далее показаны основные команды для управления ветками на
примере ветки `my-branch`.

  1. Получить список веток:

  ```bash
  $ git branch [-v]
  # [-v] - список с информацией о последних коммитах
  ```

  2. Создать ветку:

  ```bash
  $ git branch my-branch
  ```

  3. Перейти в ветку:

  ```bash
  $ git checkout my-branch
  ```

  4. Создать ветку `my-branch` и сразу перейти в нее:

  ```bash
  $ git checkout [-b] my-branch
  # [-b] - создание и переход в ветку <branch_name>
  ```

  5. Удалить ветку в локальном репозитории:

  ```bash
  $ git branch -d <branch_name>
  # [-D] - используется для принудительного удаления веток
  ```

#### Работа с изменениями

При работе с файлами в ветке необходимо управлять изменениями. Далее приведен
перечень основных команд, которые могут понадобиться.

  1. Получить список текущих изменений:

  ```bash
  $ git status
  ```

  2. Пометить файл как добавленный в текущую ветку репозитория (файл будет
     добавлен в историю после выполнения команды `git commit`):

  ```bash
  $ git add [<file_name>]
  # <file_name> - название файла для добавления в commit
  #     если вместо имени указан символ *, то будут добавлены все новые файлы,
  #     не совпадающие с масками, указанными в .gitignore
  ```

  3. Добавить изменения в текущую ветку локального репозитория:

  ```bash
  $ git commit [-m "<message_to_commit>"] [-a]
  # [-a] - автоматически добавляет изменения для существующих на сервере файлов
  #     без выполнения команды git add
  # [--amend] - перезаписывает последний коммит (используется, если не забыты
  #     изменения)
  ```

  4. Разместить изменения, которые были добавлены в локальный репозиторий
     с помощью команды `git commit`:

  ```bash
  $ git push [-u] origin [<branch_name>]
  # [-u] - отслеживать версию ветки <branch_name> на удалённом сервере
  #     (origin). Позволяет получать изменения с сервера при помощи команды git pull
  #     без явного указания имени удалённого репозитория и имени ветки.
  ```

  5. Получить изменения с сервера при помощи команды `git pull` и слить их с
     отслеживаемыми ветками:

  ```bash
  $ git pull [remotename [<branch_name>]]
  ```
