#!/bin/bash

a=false
suma=0
directorio=$1

#Si la variable a es false es porque todavia no se detecto un directorio valido.
#No se sale del while hasta que el usuario ingrese un directorio valido o corte la ejecucion.

while [ $a != true ]
do
	if [ -d "$directorio" ] # -d busca si existe y es un directorio.
	then 
		a=true
		for x in $(ls $directorio)
		do 	
			ruta="$directorio/$x"
			let suma=$suma+$(stat -c%s $ruta) 
			#Para cada archivo del directorio se usa el stat para saber su tamaño en bytes 
		done
		echo "Total directorio $directorio = $suma"
	else
		#El directorio no existe o no es valido, se pide que el usuario ingrese otro.
		echo "$directorio no es un directorio válido, ingrese uno correcto:"
		read directorio2
		directorio=$directorio2
	fi
done
			


