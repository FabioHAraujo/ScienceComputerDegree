set search_path to ddl;

select distinct codp from peca -- A)

select * from peca; -- B)

select pname from peca where color = 'Red'; -- C)

select pname, color, city from peca order by pname; -- D)

select pname, color, city from peca where color = 'Red' or color = 'Blue'; -- E)

select pname, color, city from peca where city = 'Paris' and (color = 'Red' or color = 'Blue'); -- F)

select sname from fornecedor where city = 'Paris' order by sname desc; -- G)

select codp, cods from expedicao where qty > 100 and qty < 500; -- H)

select distinct cods from expedicao where codp = 'P1' or codp = 'P2'; -- I)

select * from peca where color <> 'Red' and (weight >= 10 and weight <=15); -- J)

select sname, status from fornecedor order by status desc; -- K)

select * from fornecedor; -- VERIFICANDO ANTES

delete from fornecedor where status > 30; -- L)

select * from fornecedor; --- E DEPOIS

select * from expedicao; -- ANTES

delete from expedicao where qty < 50 and cods = 'S1';

select * from expedicao; -- DEPOIS

select * from peca; -- ANTES

update peca set color = 'Green', city = 'Rome' where codp = 'P4';

select * from peca; -- DEPOIS

update expedicao set qty = qty*3 where codp = 'P1';

select * from expedicao;

select codp, cods from peca, fornecedor;







