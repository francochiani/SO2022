#!/bin/bash

#Se piden dos numeros y se hace la operacion pasada por parametro
echo -n "Ingrese el nro1 --> "
read nro1

echo -n "Ingrese el nro2 --> "
read nro2

if [ $1 == 'suma' ]
then
	let resultado=$nro1+$nro2
	echo "$nro1 + $nro2 = $resultado"
elif [ $1 == 'resta' ]
then
	let resultado=$nro1-$nro2
	echo "$nro1 - $nro2 = $resultado"
elif [ $1 == 'multiplicacion' ]
then
	let resultado=$nro1*$nro2
	echo "$nro1 * $nro2 = $resultado"
elif [ $1 == 'division' ]
then
	let resultado=$nro1/$nro2
	echo "$nro1 / $nro2 = $resultado"
fi

