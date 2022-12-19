use hoteisbomsono;
alter table Reserva add column idCliente int;
alter table Reserva add constraint fkIdCliente foreign key (idCliente) references Cliente (idCliente) on delete cascade;
alter table Reserva add column idConta int;
alter table Reserva add constraint fkIdConta foreign key (idConta) references Conta (idConta) on delete cascade;
alter table Reserva add column idApartamento int;
alter table Reserva add constraint fkIdApartamento foreign key (idApartamento) references Apartamento (idApartamento) on delete cascade;