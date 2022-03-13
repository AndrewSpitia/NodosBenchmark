# NodosBenchmark

En este repositorio se encuentran los archivos para la elaboración del primer parcial para la asignatura de Computación Paralela y Distribuida. 

Contenido
---
* Los programas (*benchmarks*) en el repositorio son Algorithm1.c, Algorithm2.cpp y Algorithm3.cpp que son los utilizados para el desarrollo de la práctica. Cada algoritmo realiza una multiplicación de matrices de distintas formas. Para la pŕactica se utilizan para hacer una comparativa.
* Hay un archivo *Makefile* que optimiza la compilación de los programas mencionados anteriormente. Para ejecutar los programas, se utiliza
  ```make nombreDelprogramaSinExtension```
* Hay un archivo *launcher.pl* que compila y ejecuta los programas mencionados. Este realiza ejecuciones de los 3 algoritmos en tamaños de matrices de ```n*n``` con valores de n iguales a 100, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800 y 3000. Para ejecutarlo, debe primero cambiar el nombre de su máquina en el archivo *machine.txt*. Para correr:
  ```./launcher.pl```
* Hay una carpeta con nombre *results* que contiene los resultados de la ejecución de los programas en algunos nodos de cómputo. 
* Hay un archivo *graficas_parcial_1.ipynb* que lee los archivos de la carpeta *results* y los procesa para generar las gráficas que se ven en la carpeta *ImagenesResultados* 
* Se agregaron archivos que no eran necesarios para práctica pero sí para optimizar la lectura de datos (```corrector.py``` y ```sorter.py```), en donde preciamente los datos estaban separados por tabulaciones y estos scripts lo convirtieron a separado por comas.    
