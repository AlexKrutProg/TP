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

mkdir ${input_folder}/${backup_folder}
cp ${input_folder}/*.${extension} ${input_folder}/${backup_folder}/

cd ${input_folder}/

tar -zcvf ${backup_archive_name} ${backup_folder}

echo done
