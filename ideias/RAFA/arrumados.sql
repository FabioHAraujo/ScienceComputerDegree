use hoteisbomsono;
create table apartamentos_arrumados (
	idFuncionario INT not null,
	idApartamento INT not null,
	dia	DATE,
	primary key (idFuncionario, idApartamento)
);