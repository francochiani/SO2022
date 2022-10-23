#!/bin/bash

#Se crean los 3 directorios
mkdir ./$1
mkdir ./$1/dir1
mkdir ./$1/dir2

#El head nos da las primeros 10 lineas y el tail -n5 nos da las ultimas 5 lineas
head /etc/passwd | sort -r > ./$1/dir1/ordenado_tp1_2022_dir1.txt
tail -n5 /etc/passwd | sort -r > ./$1/dir2/ordenado_tp1_2022_dir2.txt
echo "$(wc -l /etc/passwd)"




