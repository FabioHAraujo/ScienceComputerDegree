use youtube;
create table usuario (
	idUser	INT not null primary key auto_increment,
	nome 	VARCHAR(100),
	email	VARCHAR(100),
	telefone	VARCHAR(100),
	senha	VARCHAR(100)
)