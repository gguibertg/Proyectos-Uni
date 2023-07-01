
-- Profesores que han dado m�s de 9 cr�ditos en total en DABD en alg�n curso pero que nunca han dado clase de IASI

SELECT profesor
FROM practbd.docencia
WHERE asignatura = 'DABD'
  AND cred_labora + cred_teoria > 9
MINUS
SELECT profesor
FROM practbd.docencia
WHERE asignatura = 'IASI';

-- Asignaturas de las que han dado clase en 2010 Maria o Ana

SELECT DISTINCT asignatura
FROM practbd.docencia
WHERE a�o = 2010
  AND profesor IN ('MARIA', 'ANA');
  
-- Profesores que han tenido cr�ditos tanto de teor�a como de laboratorio en cualquier asignatura en los a�os 2010 y 2012

SELECT profesor
FROM practbd.docencia
WHERE a�o = 2010
  AND cred_teoria > 0
  AND cred_labora > 0
INTERSECT
SELECT profesor
FROM practbd.docencia
WHERE a�o = 2012
  AND cred_teoria > 0
  AND cred_labora > 0;
  
-- Ejercicio 7 de enunciados de ejemplo -> Nif de las personas que tienen multas.

SELECT DISTINCT infractor AS nif, 'CON MULTAS' AS situacion
FROM practbd.multas;

-- Ejercicio 8 -> Nif de los sin multas 

SELECT nif, 'SIN MULTAS' AS personas
FROM practbd.personas 
MINUS
SELECT infractor, 'SIN MULTAS' AS situacion
FROM practbd.multas;

-- Ejercicio 9 Nif de todas las personas con y sin multas

SELECT nif, 'SIN MULTAS' AS situacion
FROM practbd.personas 
MINUS
SELECT infractor AS nif, 'SIN MULTAS' AS situacion
FROM practbd.multas
UNION
SELECT infractor AS nif, 'CON MULTAS' AS situacion
FROM practbd.multas
ORDER BY situacion, nif;


