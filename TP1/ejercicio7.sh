#!/bin/bash

#Se crea y se edita el manfile.txt eliminando los espacios en blanco
man $1 | sed '/^ *$/d'  > lineas.txt
rm manfile.txt 2> /dev/null

while IPS= read -r line
do
	echo $line >> manfile.txt
done < lineas.txt
rm lineas.txt


#Se busca las lineas que empiezan con vocales o con numeros
grep -i '^[-*]a' manfile.txt > vocales.txt
grep -i '^a' manfile.txt >> vocales.txt
grep -i '^[-*]e' manfile.txt >> vocales.txt
grep -i '^e' manfile.txt >> vocales.txt
grep -i '^[-*]i' manfile.txt >> vocales.txt
grep -i '^i' manfile.txt >> vocales.txt
grep -i '^[-*]o' manfile.txt >> vocales.txt
grep -i '^o' manfile.txt >> vocales.txt
grep -i '^[-*]u' manfile.txt >> vocales.txt
grep -i '^u' manfile.txt >> vocales.txt

grep '^[0-9]' manfile.txt > numeros.txt


#Se muestra la cantidad de lineas, palabras y caracteres de los 3 archivos
echo "Archivo: $1"
echo "lineas: $(wc -l manfile.txt)"
echo "palabras: $(wc -w manfile.txt)"
echo "caracteres: $(wc -m manfile.txt)"
echo "Archivo contiene vocales"
echo "lineas: $(wc -l vocales.txt)"
echo "palabras: $(wc -w vocales.txt)"
echo "caracteres: $(wc -m vocales.txt)"
echo "Archivo contiene numeros"
echo "lineas: $(wc -l numeros.txt)"
echo "palabras: $(wc -w numeros.txt)"
echo "caracteres: $(wc -m numeros.txt)"

rm manfile.txt



