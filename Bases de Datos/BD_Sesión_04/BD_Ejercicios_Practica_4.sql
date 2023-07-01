
-- Ejercicio 15: Obtener cuántos estudiantes hay en total en cada titulación

SELECT titulacion, COUNT(*) AS "Nº Alumnos"
FROM practbd.est_alum
GROUP BY titulacion;

-- Ejercicio 16: Obtener cuántos estudiantes de cada sexo hay en cada titulación, ordenando por titulación y sexo

SELECT titulacion, sexo, COUNT(*) AS "Nº Alumnos"
FROM practbd.est_alum
GROUP BY titulacion, sexo
ORDER BY titulacion, sexo;

-- Ejercicio 17: Obtener cuántas estudiantes (sexo femenino) hay en cada tituación

SELECT titulacion, COUNT(*) AS "Nº Alumnas"
FROM practbd.est_alum
WHERE sexo = 'F'
GROUP BY titulacion;

-- Ejercicio 18: Para cada titulación obtener la altura máxima y el promedio de número de pie de los estudiantes de sexo
-- masculino

SELECT titulacion, MAX(altura) AS "Altura máxima", ROUND(AVG(numpie),1) AS "Promedio pie" 
FROM practbd.est_alum
WHERE sexo = 'M'
GROUP BY titulacion;

-- Ejercicio 19: Para cada titulación obtener la altura máxima y el promedio de número de pie de pie de los estudiantes de sexo
-- masculino, mostrando solo las titulaciones donde hay más de 1 estidinte de sexo masculino

SELECT titulacion, MAX(altura) AS "Altura máxima", ROUND(AVG(numpie),1) AS "Promedio pie" 
FROM practbd.est_alum
WHERE sexo = 'M'
GROUP BY titulacion HAVING COUNT(*) > 1;

-- Ejercicio 10: Obtener los nombres de municipios que existen en la tabla personas y el número de personas de cada municipio

SELECT municipio, COUNT(*) AS "Nº personas" 
FROM practbd.personas
GROUP BY municipio;

-- Ejercicio 11: Obtener los municipios donde viven personas cuyo primer apellido incluye una A y el número de personas 
-- de este tipo que hay en cada municipio

SELECT  municipio, COUNT(*) AS "Nº personas"
FROM practbd.personas
WHERE apellido1 LIKE '%A%'
GROUP BY municipio;

-- Ejercicio 12: Obtener los municipios donde vive más de una persona cuyo primer apellido incluye una A y el número de 
-- personas de este tipo que hay en cada municipio

SELECT  municipio, COUNT(*) AS "Nº personas"
FROM practbd.personas
WHERE apellido1 LIKE '%A%'
GROUP BY municipio having COUNT(*) > 1;

-- Ejercicio 13: Obtener los nif de las personas junto con el número de multas que tienen. Para aquellas personas que no 
-- tienen multas debe salir 0. Ordenar por nif.

SELECT infractor AS nif, COUNT(*) AS "Nº multas"
FROM practbd.multas
GROUP BY infractor
UNION
(SELECT nif, 0 AS "Nº Multas"
FROM practbd.personas
MINUS
SELECT infractor AS nif, 0 AS "Nº Multas"
FROM practbd.multas)
ORDER BY nif;

-- Ejercicio 14: Obtener los nif de las personas que tienen multas de importe menor que 200 euros conduciendo más de un 
-- vehículo diferente

-- COUNT(*) --> Cuenta el número de filas
-- COUNT(atributo) --> Cuenta número de filas del atributo distintos de NULL
-- COUNT(DISTINCT atributo) --> Cuenta los valores distintos del atributo

SELECT infractor AS nif
FROM practbd.multas
WHERE importe < 200
GROUP BY infractor HAVING COUNT( DISTINCT matricula) > 1;




