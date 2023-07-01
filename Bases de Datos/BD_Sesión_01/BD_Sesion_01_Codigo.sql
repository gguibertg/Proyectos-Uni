SELECT nombre, pais
FROM practbd.aerolineas;

DESC practbd.aerolineas

SELECT * 
FROM ALL_USERS;

SELECT *
FROM USER_TABLE;

SELECT *
FROM ALL_TABLES;

SELECT *
FROM ALL_TABLES
WHERE owner = 'PRACTBD';

CREATE TABLE provincias
(cod_provincia NUMBER(2), 
 nom_provincia VARCHAR2(30) NOT NULL,
 PRIMARY KEY (cod_provincia));
 
SELECT * 
FROM USER_TABLES;

SELECT * 
FROM provincias;

INSERT INTO provincias
(cod_provincia, nom_provincia)
VALUES (10,'Cáceres');

SELECT * 
FROM provincias;

INSERT INTO provincias
(cod_provincia, nom_provincia)
VALUES (6,'Madrid');

SELECT * 
FROM provincias;

UPDATE provincias
SET nom_provincia = 'Badajoz'
WHERE cod_provincia = 6;

SELECT * 
FROM provincias;

DELETE FROM provincias
WHERE cod_provincia = 10;

SELECT * 
FROM provincias;

DROP TABLE provincias;

SELECT * 
FROM provincias;


