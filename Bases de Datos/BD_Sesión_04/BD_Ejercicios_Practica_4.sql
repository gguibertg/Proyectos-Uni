
-- Ejercicio 15: Obtener cu�ntos estudiantes hay en total en cada titulaci�n

SELECT titulacion, COUNT(*) AS "N� Alumnos"
FROM practbd.est_alum
GROUP BY titulacion;

-- Ejercicio 16: Obtener cu�ntos estudiantes de cada sexo hay en cada titulaci�n, ordenando por titulaci�n y sexo

SELECT titulacion, sexo, COUNT(*) AS "N� Alumnos"
FROM practbd.est_alum
GROUP BY titulacion, sexo
ORDER BY titulacion, sexo;

-- Ejercicio 17: Obtener cu�ntas estudiantes (sexo femenino) hay en cada tituaci�n

SELECT titulacion, COUNT(*) AS "N� Alumnas"
FROM practbd.est_alum
WHERE sexo = 'F'
GROUP BY titulacion;

-- Ejercicio 18: Para cada titulaci�n obtener la altura m�xima y el promedio de n�mero de pie de los estudiantes de sexo
-- masculino

SELECT titulacion, MAX(altura) AS "Altura m�xima", ROUND(AVG(numpie),1) AS "Promedio pie" 
FROM practbd.est_alum
WHERE sexo = 'M'
GROUP BY titulacion;

-- Ejercicio 19: Para cada titulaci�n obtener la altura m�xima y el promedio de n�mero de pie de pie de los estudiantes de sexo
-- masculino, mostrando solo las titulaciones donde hay m�s de 1 estidinte de sexo masculino

SELECT titulacion, MAX(altura) AS "Altura m�xima", ROUND(AVG(numpie),1) AS "Promedio pie" 
FROM practbd.est_alum
WHERE sexo = 'M'
GROUP BY titulacion HAVING COUNT(*) > 1;

-- Ejercicio 10: Obtener los nombres de municipios que existen en la tabla personas y el n�mero de personas de cada municipio

SELECT municipio, COUNT(*) AS "N� personas" 
FROM practbd.personas
GROUP BY municipio;

-- Ejercicio 11: Obtener los municipios donde viven personas cuyo primer apellido incluye una A y el n�mero de personas 
-- de este tipo que hay en cada municipio

SELECT  municipio, COUNT(*) AS "N� personas"
FROM practbd.personas
WHERE apellido1 LIKE '%A%'
GROUP BY municipio;

-- Ejercicio 12: Obtener los municipios donde vive m�s de una persona cuyo primer apellido incluye una A y el n�mero de 
-- personas de este tipo que hay en cada municipio

SELECT  municipio, COUNT(*) AS "N� personas"
FROM practbd.personas
WHERE apellido1 LIKE '%A%'
GROUP BY municipio having COUNT(*) > 1;

-- Ejercicio 13: Obtener los nif de las personas junto con el n�mero de multas que tienen. Para aquellas personas que no 
-- tienen multas debe salir 0. Ordenar por nif.

SELECT infractor AS nif, COUNT(*) AS "N� multas"
FROM practbd.multas
GROUP BY infractor
UNION
(SELECT nif, 0 AS "N� Multas"
FROM practbd.personas
MINUS
SELECT infractor AS nif, 0 AS "N� Multas"
FROM practbd.multas)
ORDER BY nif;

-- Ejercicio 14: Obtener los nif de las personas que tienen multas de importe menor que 200 euros conduciendo m�s de un 
-- veh�culo diferente

-- COUNT(*) --> Cuenta el n�mero de filas
-- COUNT(atributo) --> Cuenta n�mero de filas del atributo distintos de NULL
-- COUNT(DISTINCT atributo) --> Cuenta los valores distintos del atributo

SELECT infractor AS nif
FROM practbd.multas
WHERE importe < 200
GROUP BY infractor HAVING COUNT( DISTINCT matricula) > 1;




