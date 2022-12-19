use hoteisbomsono;
create table Hotel (
	idHotel	INT not null primary key auto_increment,
	nome	VARCHAR(100),
	telefone	VARCHAR(100),
	qntdQuartos	INT,
	cep	VARCHAR(100),
	cidade	VARCHAR(100),
	bairro	VARCHAR(100),
	numero	INT,
	qntdApartamentos	INT
	);