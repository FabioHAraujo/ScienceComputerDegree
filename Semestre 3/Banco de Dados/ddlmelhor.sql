CREATE SCHEMA ddl;

CREATE TABLE ddl.PECA (
    codp TEXT PRIMARY KEY,
    pname TEXT,
    color TEXT,
    weight INT,
    city TEXT
);

CREATE TABLE ddl.FORNECEDOR (
    cods TEXT PRIMARY KEY,
    sname TEXT,
    status INT,
    city TEXT
);

CREATE TABLE ddl.EXPEDICAO (
    cods TEXT,
    codp TEXT,
    qty INT,
    FOREIGN KEY (cods) REFERENCES ddl.FORNECEDOR (cods),
    FOREIGN KEY (codp) REFERENCES ddl.PECA (codp)
);

SET search_path TO ddl;

INSERT INTO peca VALUES('P1', 'Nut', 'Red', 12, 'London');
INSERT INTO peca VALUES('P2', 'Bolt', 'Green', 17, 'Paris');
INSERT INTO peca VALUES('P3', 'Screw', 'Blue', 17, 'Rome');
INSERT INTO peca VALUES('P4', 'Hammer', 'Red', 14, 'London');
INSERT INTO peca VALUES('P5', 'Cam', 'Blue', 12, 'Paris');
INSERT INTO peca VALUES('P6', 'Cog', 'Black', 19, 'London');

INSERT INTO fornecedor VALUES('S1', 'Smith', 20, 'London');
INSERT INTO fornecedor VALUES('S2', 'Jones', 10, 'Paris');
INSERT INTO fornecedor VALUES('S3', 'Blake', 30, 'Paris');
INSERT INTO fornecedor VALUES('S4', 'Clark', 20, 'London');
INSERT INTO fornecedor VALUES('S5', 'Adams', 30, 'Athens');

INSERT INTO expedicao VALUES('S1', 'P1', 300);
INSERT INTO expedicao VALUES('S1', 'P2', 200);
INSERT INTO expedicao VALUES('S1', 'P3', 400);
INSERT INTO expedicao VALUES('S1', 'P4', 200);
INSERT INTO expedicao VALUES('S1', 'P5', 100);
INSERT INTO expedicao VALUES('S1', 'P6', 100);
INSERT INTO expedicao VALUES('S2', 'P1', 300);
INSERT INTO expedicao VALUES('S2', 'P2', 400);
INSERT INTO expedicao VALUES('S3', 'P2', 200);
INSERT INTO expedicao VALUES('S4', 'P2', 200);
INSERT INTO expedicao VALUES('S4', 'P4', 300);
INSERT INTO expedicao VALUES('S4', 'P5', 400);

ALTER TABLE peca ALTER COLUMN city SET DEFAULT 'London';
ALTER TABLE peca ADD CONSTRAINT nome_unico UNIQUE (pname);
ALTER TABLE peca ADD CONSTRAINT valida_cores CHECK (color IN ('Red', 'Blue', 'Green'));
ALTER TABLE peca ADD CONSTRAINT checa_peso CHECK (weight > 0);
ALTER TABLE fornecedor ADD CONSTRAINT fornec_unico UNIQUE (sname);
ALTER TABLE expedicao ADD CONSTRAINT checa_qtd CHECK (qty > 0);
ALTER TABLE expedicao ADD COLUMN data TIMESTAMP;
DELETE FROM expedicao WHERE data IS NOT NULL;
UPDATE expedicao SET data = '1969-07-20 02:56:00' WHERE cods = 'S1' AND codp = 'P1';
UPDATE expedicao SET data = '1945-08-06 08:15:00' WHERE cods = 'S1' AND codp = 'P2';
UPDATE expedicao SET data = '2001-09-11 08:46:00' WHERE cods = 'S1' AND codp = 'P3';
UPDATE expedicao SET data = '1914-06-28 10:45:00' WHERE cods = 'S1' AND codp = 'P4';
UPDATE expedicao SET data = '1944-06-06 06:30:00' WHERE cods = 'S1' AND codp = 'P5';
UPDATE expedicao SET data = '1912-04-15 23:40:00' WHERE cods = 'S1' AND codp = 'P6';
UPDATE expedicao SET data = '1989-11-09 18:57:00' WHERE cods = 'S2' AND codp = 'P1';
UPDATE expedicao SET data = '1986-04-26 01:23:45' WHERE cods = 'S2' AND codp = 'P2';
UPDATE expedicao SET data = '1945-08-15 12:00:00' WHERE cods = 'S3' AND codp = 'P2';
UPDATE expedicao SET data = '1776-07-04 17:00:00' WHERE cods = 'S4' AND codp = 'P2';
UPDATE expedicao SET data = '1919-06-28 15:12:00' WHERE cods = 'S4' AND codp = 'P4';
UPDATE expedicao SET data = '1945-07-16 05:29:45' WHERE cods = 'S4' AND codp = 'P5';

ALTER TABLE expedicao ADD CONSTRAINT pk_expedicao PRIMARY KEY (codp, cods, data);
