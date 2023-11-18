create schema ddl;

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

set search_path to ddl;

INSERT INTO peca VALUES('P1','Nut','Red',12,'London');
INSERT INTO peca VALUES('P2','Bolt','Green',17,'Paris');
INSERT INTO peca VALUES('P3','Screw','Blue',17,'Rome');
INSERT INTO peca VALUES('P4','Hammer','Red',14,'London');
INSERT INTO peca VALUES('P5','Cam','Blue',12,'Paris');
INSERT INTO peca VALUES('P6','Cog','Black',19,'London');

INSERT INTO fornecedor VALUES('S1','Smith',20,'London');
INSERT INTO fornecedor VALUES('S2','Jones',10,'Paris');
INSERT INTO fornecedor VALUES('S3','Blake',30,'Paris');
INSERT INTO fornecedor VALUES('S4','Clark',20,'London');
INSERT INTO fornecedor VALUES('S5','Adams',30,'Athens');

INSERT INTO expedicao VALUES('S1','P1',300);
INSERT INTO expedicao VALUES('S1','P2',200);
INSERT INTO expedicao VALUES('S1','P3',400);
INSERT INTO expedicao VALUES('S1','P4',200);
INSERT INTO expedicao VALUES('S1','P5',100);
INSERT INTO expedicao VALUES('S1','P6',100);
INSERT INTO expedicao VALUES('S2','P1',300);
INSERT INTO expedicao VALUES('S2','P2',400);
INSERT INTO expedicao VALUES('S3','P2',200);
INSERT INTO expedicao VALUES('S4','P2',200);
INSERT INTO expedicao VALUES('S4','P4',300);
INSERT INTO expedicao VALUES('S4','P5',400);

alter table peca alter column city set default 'London';
alter table peca add constraint nome_unico unique (pname);
alter table peca add constraint valida_cores check (color in ('Red', 'Blue', 'Green'));
alter table peca add constraint checa_peso check (weight > 0);
alter table fornecedor add constraint fornec_unico unique (sname);
alter table expedicao add constraint checa_qtd check (qty > 0);
alter table expedicao add column data timestamp;
delete from expedicao where data is not null;
update expedicao set data = '1969-07-20 02:56:00' where cods = 'S1' and codp = 'P1';
update expedicao set data = '1945-08-06 08:15:00' where cods = 'S1' and codp = 'P2';	
update expedicao set data = '2001-09-11 08:46:00' where cods = 'S1' and codp = 'P3';
update expedicao set data = '1914-06-28 10:45:00' where cods = 'S1' and codp = 'P4';
update expedicao set data = '1944-06-06 06:30:00' where cods = 'S1' and codp = 'P5';
update expedicao set data = '1912-04-15 23:40:00' where cods = 'S1' and codp = 'P6';
update expedicao set data = '1989-11-09 18:57:00' where cods = 'S2' and codp = 'P1';
update expedicao set data = '1986-04-26 01:23:45' where cods = 'S2' and codp = 'P2';
update expedicao set data = '1945-08-15 12:00:00' where cods = 'S3' and codp = 'P2';
update expedicao set data = '1776-07-04 17:00:00' where cods = 'S4' and codp = 'P2';
update expedicao set data = '1919-06-28 15:12:00' where cods = 'S4' and codp = 'P4';
update expedicao set data = '1945-07-16 05:29:45' where cods = 'S4' and codp = 'P5';

alter table expedicao add constraint pk_expedicao primary key (codp, cods, data);
