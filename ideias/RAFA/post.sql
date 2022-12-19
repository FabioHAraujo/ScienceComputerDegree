use youtube;
create table post (
	idPost	INT not null primary key auto_increment,
	titulo	VARCHAR(100),
	counteudo	TEXT,
	autor int,
	foreign key (autor) references usuario(idUser) on delete cascade
);