use hoteisbomsono;
alter table Funcionario add column idHotel int;
alter table Funcionario add constraint fkIdHotel foreign key (idHotel) references Hotel (idHotel) on delete cascade;