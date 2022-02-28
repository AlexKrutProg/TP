#!/bin/bash

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

touch /tmp/paths.txt

find ${input_folder} -type d -printf "%P\0" > /tmp/paths.txt

mkdir ${backup_folder}
cd ${backup_folder}

xargs --null mkdir < /tmp/paths.txt &> /dev/null

cd ${input_folder}

touch /tmp/paths_files.txt

find ${input_folder} -type f -name "*.${extension}" -printf "%P\n" > /tmp/paths_files.txt


while IFS= read -r path; do
    cp ${path} ${backup_folder}/${path}
done < /tmp/paths_files.txt

tar -zcvf ${backup_archive_name} ${backup_folder} &>/dev/null

echo done
