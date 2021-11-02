#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "../dirent-master/include/dirent.h"    // для работы с директориями
#include <sys/stat.h>                           // для установления размера файла

/// <summary>
/// функция, возвращающая размер файла
/// </summary>
/// <param name="file">полный или относительный путь до файла</param>
/// <returns>размер файла</returns>
int getFileSize(const char* file) {
  struct stat st;
  int full_size = 0;

  if (stat(file, &st) == 0) {
    // если это папка
    if ((st.st_mode & S_IFMT) == S_IFDIR)
      return -1;
    // если обычный файл
    else if ((st.st_mode & S_IFMT) == S_IFREG)
      return st.st_size;
    // если что-то иное (сокет, FIFO (именованный канал) и др.)
    else
      return -2;
  }
}

/// <summary>
/// функция, печатающая названия файлов и размеры в каталоге и внутренних подкаталогов
/// </summary>
/// <param name="path">путь до каталога</param>
void getSizesFromDir(char* path) {
  struct dirent* cur_file;
  DIR* dir;

  char full_file_path[200];

  // открываем рабочую директорию
  dir = opendir(path);

  // если удалось открыть директорию
  if (dir) {
    // считываем файлы внутри директории в переменную cur_file, пока файлы не кончатся
    while ((cur_file = readdir(dir)) != NULL) {
      // игнорируем системные папки ./ и ../
      // если попались записи, начинающиеся на . или .. - пропускаем их
      if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
        // копируем путь в новую переменную, вставляем символ разделителя директории,
        // добавляем имя элемента (файла или папки)
        strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
        // получаем размер или -1, если это не файл, а вложенная папка
        int cur_file_size = getFileSize(full_file_path);
        if (cur_file_size >= 0)
          // для файла печатаем его имя и размер
          printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
        else if (cur_file_size == -1)
          // для вложенной папки вызываем РЕКУРСИВНО написанный метод
          getSizesFromDir(full_file_path);
      }
    }
    // не забываем закрыть директорию
    closedir(dir);
  }
}

int main() {
  char path[200];

  // считываем путь (по сути scanf_s для строки)
  printf("Input path to dir: ");
  gets(path);

  getSizesFromDir(path);

  return 0;
}
