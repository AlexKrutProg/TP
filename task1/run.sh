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

backup_folder=$( readlink -f "$backup_folder" )
input_folder=$( readlink -f "$input_folder" )


init=$( pwd )

touch /tmp/paths.txt

find "${input_folder}" -type d -printf "%P\0" > /tmp/paths.txt

# OK so far
# exit 1

mkdir "${backup_folder}"
cd "${backup_folder}"

xargs --null mkdir < /tmp/paths.txt &> /dev/null

cd "$init"
#cd ${input_folder}
#exit 1

touch /tmp/paths_files.txt

find "${input_folder}" -type f -name "*.${extension}" -printf "%P\n" > /tmp/paths_files.txt

cd "$init"
cd "$input_folder"

while IFS= read -r path; do
    cp "${path}" "${backup_folder}/${path}"
done < /tmp/paths_files.txt

cd "$init"

tar zcf "${backup_archive_name}" "${backup_folder}" &> /dev/null

echo done
