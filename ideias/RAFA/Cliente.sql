use hoteisbomsono;
create table Cliente (
	idCliente	INT not null primary key auto_increment,
	nome	VARCHAR(100),
	email	VARCHAR(100),
	telefone VARCHAR(100),
	senha	VARCHAR(100),
	nacionalidade	VARCHAR(100),
	cep		VARCHAR(100),
	cidade	VARCHAR(100),
	bairro VARCHAR(100),
	numero	INT
);