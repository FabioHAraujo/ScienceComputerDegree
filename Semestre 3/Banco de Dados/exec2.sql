-- SELECIONANDO CAMINHO --

set search_path to ddl;

-- 1)

select fornecedor.*, peca.* from fornecedor, peca; -- 30 REGISTROS -- A)

select fornecedor.*, expedicao.* from fornecedor, expedicao; -- 60 REGISTROS -- B)

select peca.*, expedicao.* from peca, expedicao; -- 72 REGISTROS -- C)

select fornecedor.*, peca.*, expedicao.* from fornecedor, peca, expedicao; -- 360 REGISTROS -- D)

select fornecedor.sname from expedicao inner join fornecedor on fornecedor.cods = expedicao.cods; -- A)

select distinct peca.pname from expedicao inner join peca on peca.codp = expedicao.codp; -- B)

select peca.pname from peca inner join expedicao on peca.codp = expedicao.codp inner join fornecedor on fornecedor.cods = expedicao.cods where fornecedor.sname = 'Jones'; -- C)

select fornecedor.sname, fornecedor.city from fornecedor inner join expedicao on expedicao.cods = fornecedor.cods inner join peca on expedicao.codp = peca.codp where peca.color = 'Red' or peca.color = 'Blue'; -- D)

select distinct fornecedor.sname, fornecedor.city from fornecedor inner join expedicao on expedicao.cods = fornecedor.cods inner join peca on expedicao.codp = peca.codp where peca.color = 'Red' or peca.color = 'Blue'; -- E)

select fornecedor.sname, peca.pname from peca inner join fornecedor on fornecedor.city = peca.city; -- F)

select peca.pname, fornecedor.sname from peca inner join expedicao on expedicao.codp = peca.codp inner join fornecedor on expedicao.cods = fornecedor.cods; -- G)

select peca.pname, fornecedor.sname from peca inner join expedicao on expedicao.codp = peca.codp inner join fornecedor on expedicao.cods = fornecedor.cods where expedicao.qty >= 300; -- H)

select peca.pname, peca.color, expedicao.qty from peca inner join expedicao on expedicao.codp = peca.codp inner join fornecedor on expedicao.cods = fornecedor.cods where fornecedor.sname = 'Clark'; -- I)

select * from expedicao inner join fornecedor on expedicao.cods = fornecedor.cods where fornecedor.status >= 30;

-- 3)

select sname from fornecedor where city like 'L%'; -- A)

select sname from fornecedor where city like 'L%' or city like '%ris'; -- B)

-- LEMBRAR DO LIKE %, CONTAR LETRAS, CONTAR QUANTIDADE TOTAL DA SELECAO DE CELULAS, GROUP BY, E AFINS.