#!/bin/bash

#цикл считывает флаги из командной строки
for i in 1 2 3 4
do
case "$1" in
--input_folder) input_folder="$2";;
--extension) extension="$2";;
--backup_folder) backup_folder="$2";;
--backup_archive_name) backup_archive_name="$2";;
esac
shift
shift
done

#находим пути до необходимых папок
backup_folder=$( readlink -f "$backup_folder" )
input_folder=$( readlink -f "$input_folder" )


init=$( pwd )

#во временной папке, чтобы не засорят компьютер, создаем файл, в который будем записывать пути до нужных папок 
touch /tmp/paths.txt

#записываем пути до папок, чтобы создать туже архитектуру
find "${input_folder}" -type d -printf "%P\0" > /tmp/paths.txt

mkdir "${backup_folder}"
cd "${backup_folder}"

#создаем все папки в backup папке
xargs --null mkdir < /tmp/paths.txt &> /dev/null

cd "$init"

#снова во временной папке создаем файл для путей до всех нужных файлов
touch /tmp/paths_files.txt

#записываем пути до файлов только с необходимым расширением 
find "${input_folder}" -type f -name "*.${extension}" -printf "%P\n" > /tmp/paths_files.txt

cd "$init"
cd "$input_folder"

#циклом копируем все файлы, пути которых мы сохранили, в папку восстановления
while IFS= read -r path; do
    cp "${path}" "${backup_folder}/${path}"
done < /tmp/paths_files.txt

cd "$init"
#создаем архив из папки восстановления
tar zcf "${backup_archive_name}" "${backup_folder}" &> /dev/null

echo done
