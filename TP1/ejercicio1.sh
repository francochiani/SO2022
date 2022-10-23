#!/bin/bash

#Se guarda la fecha actual para despues poder restaurarla.
fechaActual=$(date --rfc-3339='seconds') 
let diasRestantes=365-$(date +%j)

echo "Hola $1, Ud. está logueado como usuario $(whoami)."
echo "Hoy es $(date +%A), $(date +%d) de $(date +%B) de $(date +%Y)."
echo "Faltan $diasRestantes dias para que termine el año 2022." 

#Se cambia la fecha a 2022-03-18 para poder calcular los dias restantes.
date --set "2022-03-18" > /dev/null
let diasRestantes2=365-$(date +%j)
echo "Si hoy fuera 18/03/2022, faltarían $diasRestantes2 días para que termine el año 2022."

#Se restaura la fecha que el sistema tenia al comienzo de la ejecucion.
date --set "$fechaActual" > /dev/null