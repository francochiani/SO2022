#!/bin/bash

echo "$(ps)"
echo " "
echo "Se esta generando una lista de archivos que comienzan con c"
echo " "

#Se buscan todos los archivos que comienzan con c desde el archivo raiz
find / -iname 'c*' > $1.txt &

echo "$(ps)"
echo " "

echo "Ingrese el id del proceso de busqueda de archivos que inician con la letra c:"
read idproc
kill $idproc