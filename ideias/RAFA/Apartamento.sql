use hoteisbomsono;
create table  Apartamento (
	idAparatamento INT not null primary key auto_increment,
	qntdCamaSolteiro	INT not null,
	qntdCamaCasal		INT not null,
	numero	INT not null,
	ocupado	BOOLEAN,
	adaptado	BOOLEAN,
	frigobar	BOOLEAN
	);