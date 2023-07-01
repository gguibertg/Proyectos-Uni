
-- 6: Obtener el nombre de los propietarios de vehículos, tales que sus vehículos han intervenido en multas de más de 90 euros 
--    y que el número de multas en total de sus vehículos es 2 o más.

SELECT nif, apellido1, apellido2, nombre
FROM practbd.personas INNER JOIN practbd.vehiculos
                            ON(nif = propietario)
                      INNER JOIN practbd.multas
                            USING(matricula)
WHERE importe > 90
GROUP BY nif, apellido1, apellido2, nombre 
      HAVING COUNT(*) > 1;

-- 7: Mostrar los datos de los vehículos de marca AUDI que tienen más de 70 caballos de potencia.

SELECT *
FROM practbd.marcas INNER JOIN practbd.modelos
                          USING(cod_marca)
                    INNER JOIN practbd.vehiculos
                          USING(cod_marca, cod_modelo)
WHERE nom_marca = 'AUDI'
  AND potencia > 70;
  
-- 9: Mostrar el nombre completo de las personas que tienen multas en el año 2002 con el número multas que se le han puesto 
--    en ese año y el importe total de dichas multas

SELECT nif, apellido1, apellido2, nombre, COUNT(*) AS "N1 Multas", SUM(importe) AS "Importe total"
FROM practbd.personas INNER JOIN practbd.multas
                            ON(nif = infractor)
WHERE EXTRACT(YEAR FROM FECHA) = 2002
GROUP BY nif, apellido1, apellido2, nombre;

