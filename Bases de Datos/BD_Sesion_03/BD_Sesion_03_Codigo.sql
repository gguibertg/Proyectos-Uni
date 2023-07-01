SELECT *
FROM practbd.alumnos;

CREATE TABLE alum_101
AS SELECT num_exp, apellido1, apellido2, nombre
FROM practbd.alumnos
WHERE titulacion = 101;

DESC alum_101;

SELECT *
FROM alum_101;

ALTER TABLE alum_101
ADD (PRIMARY KEY(num_exp));

CREATE SEQUENCE snum_exp
START WITH 6 INCREMENT BY 1
MAXVALUE 99999;

SELECT * 
FROM USER_OBJECTS;

INSERT INTO alum_101
(num_exp, apellido1, apellido2, nombre)
VALUES(snum_exp.nextval, 'García', 'García', 'Andrés');

INSERT INTO alum_101
(num_exp, apellido1, apellido2, nombre)
VALUES(snum_exp.nextval, 'GUIBERTEAU', 'GARCÍA', 'GABRIEL FERNANDO');

INSERT INTO alum_101
(num_exp, apellido1, apellido2, nombre)
VALUES(snum_exp.nextval, 'PEREZ', '', 'ANA');

INSERT INTO alum_101
(num_exp, apellido1, apellido2, nombre)
SELECT num_exp, apellido1, apellido2, nombre
FROM practbd.alumnos
WHERE titulacion = 102;

INSERT INTO alum_101
(num_exp, apellido1, apellido2, nombre)
SELECT snum_exp.nextval, apellido1, 'LOPEZ', nombre
FROM practbd.alumnos
WHERE titulacion = 102;

UPDATE alum_101
SET apellido2 = 'MARTIN', nombre = 'PEDRO'
WHERE apellido2 = 'García'
  AND APELLIDO1 = 'García'
  AND nombre = 'Andrés';
  
DELETE 
FROM alum_101
WHERE num_exp > 5;

SELECT *
FROM alum_101;

DROP SEQUENCE snum_exp;

DROP TABLE alum_101;

SELECT * 
FROM USER_OBJECTS;

SELECT *
FROM practbd.receta;

SELECT SUM(calorias_racion) AS "TOTAL CALORIAS", 
       SUM(precio) AS "TOTAL PRECIO",
       TRUNC((SUM(tiempo)/60,0) || ' H Y ' || mod(sum(tiempo),60) || 'M ') AS "TIEMPO ESTIMADO"
FROM practbd.receta
WHERE cod_receta IN (1, 2, 7);
