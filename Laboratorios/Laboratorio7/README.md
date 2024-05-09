# Instrucciones de ejecución
Para compilar el código para este laboratorio se utiliza un Makefile, para que funcione de forma correcta debe estar ubicado en la carpeta de Laboratorio7, seguidamente se ejecuta el siguiente comando:
```
mingw32-make
```
Una vez generado los archivos de forma correcta, se ejecuta el programa con el siguiente comando:
```
./bin/textprocessor -f data/input.txt -o data/output.txt -search "foo" -replace "bar"
```
En este caso se busca la palabra "foo" y se reemplaza con "bar", el archivo donde se da el reemplazo se encuentra en `./data/output.txt`

Si se desea limpiar el directorio, se hace ejecutando el siguiente comando:
```
mingw32-make clean
```

## Laboratorio 7
Este laboratorio consiste en practicar el uso de expressiones regulares y Makefiles, para ello se ingresa un archivo de texto en el que se pasa un patrón por argumentos, a la hora de correrlo se reemplaza el patrón si fue encontrado.