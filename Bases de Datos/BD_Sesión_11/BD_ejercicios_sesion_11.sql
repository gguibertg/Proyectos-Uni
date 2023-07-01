
-- Ejercicio 1
CREATE TABLE tipo_receta (
                          cod_tipo CHAR(1) PRIMARY KEY,
                          nom_tipo VARCHAR(30) NOT NULL UNIQUE);
                          
-- Ejercicio 2    
INSERT INTO tipo_receta
SELECT *
FROM practbd.tipo_receta;

-- Ejercicio 3
CREATE TABLE receta
AS SELECT * 
   FROM practbd.receta;
   
DESC receta;

-- Ejercicio 4

ALTER TABLE receta
ADD (PRIMARY KEY (cod_receta),
     FOREIGN KEY (tipo_receta) REFERENCES tipo_receta(cod_tipo));
    
DESC receta;

-- Ejercicio 5

DELETE 
FROM tipo_receta
WHERE nom_tipo = 'ENTRANTE';

-- Ejercicico 6:

CREATE SEQUENCE snum_receta
START WITH 20
INCREMENT BY 1
MAXVALUE 99999;

-- Ejercicio 10

INSERT INTO receta
      (cod_receta, nom_receta, tipo_receta)
VALUES(snum_receta.nextval, 'CREMA DE BERBERECHOS', 'A');

-- Ejercicio 11: Crea un índice en RECETA para optimizar el acceso por el nombre de la receta.

CREATE INDEX romReceta_idx ON receta (nom_receta);

-- Sintaxis básica de una vista

CREATE VIEW nombreVista
AS; -- consulta;

-- Ejercicio 12: Crea una vista sobre tu tabla de RECETA, que se llame RECETA_POSTRE que solo muestre el código, nombre y tipo de las recetas de postre. Realiza una consulta a la vista.

CREATE VIEW receta_postre
AS SELECT cod_receta, nom_receta, tipo_receta
   FROM receta
   WHERE tipo_receta = 'T';

SELECT * FROM receta_postre;

CREATE OR REPLACE VIEW receta_postre
AS SELECT cod_receta, nom_receta, tipo_receta
   WHERE tipo_receta = 'T'
   WITH CHECK OPTION;



