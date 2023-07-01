
-- 10: Obtener los nombres de todas las marcas de vehículos y para aquellas que existan modelos obtener los nombres 
--     de los modelos.

SELECT nom_marca, nom_modelo
FROM practbd.marcas LEFT OUTER JOIN practbd.modelos
     USING (cod_marca);
     
SELECT nom_marca, nom_modelo
FROM practbd.modelos RIGHT OUTER JOIN practbd.marcas
     USING(cod_marca);
     
-- 11: Obtener el nombre y nif de las personas de Cáceres y para aquellas que sean agentes obtener también su número de agente.

SELECT nif, apellido1, apellido2, nombre, num_agente
FROM practbd.personas LEFT OUTER JOIN practbd.agentes
     USING(nif)
WHERE municipio = 'CACERES';

SELECT nom_marca, nom_modelo
FROM practbd.agentes RIGHT OUTER JOIN practbd.personas
     USING(nif)
WHERE municipio = 'CACERES';

-- 12: Obtener los nombres de todos los modelos de vehículos y para aquellos que existan vehículos obtener su 
--     matricula y el nombre de su propietario.

SELECT nom_modelo, matricula, apellido1, apellido2, nombre 
FROM practbd.modelos LEFT OUTER JOIN practbd.vehiculos
     USING(cod_marca, cod_modelo)
     LEFT OUTER JOIN practbd.personas 
                ON(propietario = nif);
                
SELECT nom_modelo, matricula, apellido1, apellido2, nombre 
FROM practbd.personas INNER JOIN practbd.vehiculos
         ON(nif = propietario)
     RIGHT OUTER JOIN practbd.modelos 
        USING(cod_marca, cod_modelo);

-- 13: Obtener los nif de las personas junto con el número de multas que tienen. Para aquellas personas que no tienen 
--     multas debe salir un 0. Ordenar por nif

SELECT nif, COUNT(expediente) AS "Nº multas"
FROM practbd.personas LEFT OUTER JOIN practbd.multas
                        ON(nif = infractor)
GROUP BY nif
ORDER BY nif;

-- 14: Obtener los nif y el nombre completo de las personas junto con el número de multas que tienen.  Para aquellas personas 
--     que no tienen multas debe salir un 0. Ordenar por apellidos y nombre.

SELECT nif, apellido1, apellido2, nombre, COUNT(expediente) AS "Nº multas"
FROM practbd.personas LEFT OUTER JOIN practbd.multas
                        ON(nif = infractor)
GROUP BY nif, apellido1, apellido2, nombre
ORDER BY apellido1, apellido2;