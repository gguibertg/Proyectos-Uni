SELECT rownum, num_exp,
    TO_CHAR (fecha_apertura_exp, 'DD-MM-YYYY')
FROM practbd.alumnos;

CREATE TABLE alumno(
    num_exp NUMBER(5),
    TITULACION CHAR(5),
    apellidos VARCHAR2(30),
    nombre VARCHAR2(18),
    fecha_alta DATE,
    nota_media NUMBER(4,2));
    
DESC alumno;

CREATE TABLE empleado(
    num_emp NUMBER(5) PRIMARY KEY,
    num_segsocial NUMBER(12) NOT NULL UNIQUE,
    apellidos VARCHAR2(20) NOT NULL,
    nombre VARCHAR(18) NOT NULL,
    fecha_alta DATE DEFAULT SYSDATE,
    nivel_acceso CHAR(2) DEFAULT '01',
    salario NUMBER(9,2) CHECK (salario >= 0 AND salario <= 1000000.00)
    );
    
DESC empleado;

ALTER TABLE empleado
    ADD (dias_vacaciones NUMBER(3) DEFAULT 31);
    
ALTER TABLE empleado
    MODIFY(apellidos VARCHAR2(40), nivel_acceso NOT NULL);
    
ALTER TABLE empleado
    ADD(CHECK (dias_vacaciones <= 120));

DESC empleado;



