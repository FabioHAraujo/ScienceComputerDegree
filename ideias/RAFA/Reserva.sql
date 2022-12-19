use hoteisbomsono;
create table  Reserva (
	idReserva	INT not null primary key auto_increment,
	dataEntrada	DATE,
	dataSaida	DATE,
	qntdPessoas	INT
	);