set search_path to trabalho;

CREATE TABLE pousada (
	idPousada SERIAL PRIMARY KEY,
	nome TEXT NOT NULL,
	telefone TEXT,
	qtdQuartos NUMERIC,
	cep TEXT,
	cidade TEXT,
	bairro TEXT,
	numero TEXT
);

CREATE TABLE colaborador (
    idColaborador SERIAL PRIMARY KEY,
    nome TEXT NOT NULL,
    email TEXT NOT NULL,
    senha TEXT NOT NULL,
    diaContratacao DATE NOT NULL,
    diaDesligamento DATE
);

ALTER TABLE colaborador ADD COLUMN idPousada INT references pousada(idPousada);

CREATE TABLE funcao (
	idFuncao SERIAL PRIMARY KEY,
	nomeFuncao TEXT NOT NULL,
	salBase DECIMAL NOT NULL,
	comissao DECIMAL,
	dataCriacao DATE NOT NULL
);

ALTER TABLE colaborador ADD COLUMN idFuncao INT references funcao(idFuncao);

ALTER TABLE funcao ALTER COLUMN dataCriacao SET DEFAULT CURRENT_DATE;


ALTER TABLE funcao
ALTER COLUMN comissao SET DATA TYPE DECIMAL(10, 2);

CREATE TABLE quarto (
    idQuarto SERIAL PRIMARY KEY,
    idPousada INT REFERENCES pousada(idPousada),
    qtdCamaCasal INT,
    qtdCamaSolteiro INT,
    numero TEXT NOT NULL,
    ocupado BOOLEAN,
    frigobar BOOLEAN,
    andar INT,
    arrumado BOOLEAN,
    arrumadoPorUltimo TIMESTAMP,
    ultimaCamareira INT REFERENCES colaborador(idColaborador)
);

CREATE TABLE cliente (
    idCliente SERIAL PRIMARY KEY,
    numIdentidade TEXT NOT NULL,
    tipoIdentidade TEXT,
    nome TEXT NOT NULL,
    orgaoExpeditor TEXT,
    endereco TEXT NOT NULL,
    telefone TEXT,
    email TEXT,
    profissao TEXT NOT NULL,
    cidade TEXT NOT NULL,
    nacionalidade TEXT NOT NULL,
    estado TEXT,
    dataNascimento DATE NOT NULL,
    pais TEXT,
    genero TEXT
);

CREATE TABLE reserva (
    idReserva SERIAL PRIMARY KEY,
    idCliente INT REFERENCES cliente(idCliente),
    meioTransporte TEXT,
    dataEntrada DATE NOT NULL,
    dataSaida DATE NOT NULL,
    qtdPessoas INT,
    paisOrigem TEXT,
    estadoOrigem TEXT,
    cidadeOrigem TEXT,
    paisDestino TEXT,
    estadoDestino TEXT,
    cidadeDestino TEXT,
    motivoHospedagem TEXT NOT NULL,
    formaPagamento TEXT NOT NULL
);

CREATE TABLE conta (
    idConta SERIAL PRIMARY KEY,
    totalConta DECIMAL NOT NULL
);

ALTER TABLE conta
ADD COLUMN idReserva INT REFERENCES reserva(idReserva);

CREATE TABLE produto (
    idProduto SERIAL PRIMARY KEY,
    nome TEXT NOT NULL,
    preco DECIMAL(10, 2) NOT NULL
);

CREATE TABLE consumo (
    idConta INT REFERENCES conta(idConta),
    idProduto INT REFERENCES produto(idProduto),
    qtdDoProduto INT NOT NULL,
    precoTotal DECIMAL(10, 2) NOT NULL
);

CREATE TABLE reserva_quarto (
    idReserva INT REFERENCES reserva(idReserva),
    idQuarto INT REFERENCES quarto(idQuarto),
    PRIMARY KEY (idReserva, idQuarto)
);


INSERT INTO pousada (nome, telefone, qtdQuartos, cep, cidade, bairro, numero)
VALUES ('Pousada do Mar', '(123) 456-7890', 50, '12345-678', 'Cidade A', 'Bairro X', '123');

INSERT INTO pousada (nome, telefone, qtdQuartos, cep, cidade, bairro, numero)
VALUES ('Pousada das Montanhas', '(987) 654-3210', 30, '98765-432', 'Cidade B', 'Bairro Y', '456');

INSERT INTO pousada (nome, telefone, qtdQuartos, cep, cidade, bairro, numero)
VALUES ('Pousada do Lago', '(555) 123-4567', 40, '55555-555', 'Cidade C', 'Bairro Z', '789');

select * from pousada;


INSERT INTO funcao (nomeFuncao, salBase, comissao)
VALUES ('Recepcionista', 2500.00, 0.10);

INSERT INTO funcao (nomeFuncao, salBase, comissao)
VALUES ('Camareira', 2000.00, 0.05);

INSERT INTO funcao (nomeFuncao, salBase, comissao)
VALUES ('Gerente', 3500.00, 0.15);

select * from funcao;


INSERT INTO colaborador (nome, email, senha, diaContratacao, diaDesligamento, idPousada, idFuncao)
VALUES ('João Silva', 'joao@example.com', 'senha123', '2023-01-15', NULL, 1, 1);

INSERT INTO colaborador (nome, email, senha, diaContratacao, diaDesligamento, idPousada, idFuncao)
VALUES ('Maria Santos', 'maria@example.com', 'senha456', '2023-02-20', NULL, 2, 2);

INSERT INTO colaborador (nome, email, senha, diaContratacao, diaDesligamento, idPousada, idFuncao)
VALUES ('Pedro Oliveira', 'pedro@example.com', 'senha789', '2023-03-25', NULL, 3, 3);

select * from colaborador;

INSERT INTO quarto (idPousada, qtdCamaCasal, qtdCamaSolteiro, numero, ocupado, frigobar, andar, arrumado, arrumadoPorUltimo, ultimaCamareira)
VALUES (1, 2, 1, '101', FALSE, TRUE, 1, TRUE, '2023-01-10 08:00:00', 5);

INSERT INTO quarto (idPousada, qtdCamaCasal, qtdCamaSolteiro, numero, ocupado, frigobar, andar, arrumado, arrumadoPorUltimo, ultimaCamareira)
VALUES (1, 1, 0, '102', TRUE, FALSE, 1, FALSE, NULL, NULL);

INSERT INTO quarto (idPousada, qtdCamaCasal, qtdCamaSolteiro, numero, ocupado, frigobar, andar, arrumado, arrumadoPorUltimo, ultimaCamareira)
VALUES (2, 3, 0, '201', FALSE, TRUE, 2, TRUE, '2023-01-11 09:00:00', 5);

select * from quarto;

select * from colaborador inner join funcao on colaborador.idFuncao = funcao.idFuncao;

insert into produto (nome, preco)
values ('Coca Cola', '5.99');

select * from produto;

-- Inserção do Cliente 1
INSERT INTO cliente (numIdentidade, tipoIdentidade, nome, orgaoExpeditor, endereco, telefone, email, profissao, cidade, nacionalidade, estado, dataNascimento, pais, genero)
VALUES ('12345678', 'RG', 'Maria da Silva', 'SSP', 'Rua A, 123', '(987) 654-3210', 'maria@example.com', 'Advogada', 'Cidade A', 'Brasileira', 'SP', '1980-05-15', 'Brasil', 'Feminino');

-- Inserção do Cliente 2
INSERT INTO cliente (numIdentidade, tipoIdentidade, nome, orgaoExpeditor, endereco, telefone, email, profissao, cidade, nacionalidade, estado, dataNascimento, pais, genero)
VALUES ('87654321', 'RG', 'José Pereira', 'SSP', 'Avenida X, 456', '(123) 456-7890', 'jose@example.com', 'Engenheiro', 'Cidade B', 'Brasileira', 'RJ', '1975-08-20', 'Brasil', 'Masculino');

-- Inserção do Cliente 3
INSERT INTO cliente (numIdentidade, tipoIdentidade, nome, orgaoExpeditor, endereco, telefone, email, profissao, cidade, nacionalidade, estado, dataNascimento, pais, genero)
VALUES ('11223344', 'RG', 'Ana Oliveira', 'SSP', 'Rua B, 789', '(555) 123-4567', 'ana@example.com', 'Médica', 'Cidade C', 'Brasileira', 'MG', '1990-03-25', 'Brasil', 'Feminino');


select * from cliente;

-- Inserção da Reserva 1
INSERT INTO reserva (idCliente, meioTransporte, dataEntrada, dataSaida, qtdPessoas, paisOrigem, estadoOrigem, cidadeOrigem, paisDestino, estadoDestino, cidadeDestino, motivoHospedagem, formaPagamento)
VALUES (1, 'Avião', '2023-11-15', '2023-11-20', 2, 'Brasil', 'SP', 'Cidade A', 'Brasil', 'RJ', 'Cidade B', 'Férias', 'Cartão de Crédito');

-- Inserção da Reserva 2
INSERT INTO reserva (idCliente, meioTransporte, dataEntrada, dataSaida, qtdPessoas, paisOrigem, estadoOrigem, cidadeOrigem, paisDestino, estadoDestino, cidadeDestino, motivoHospedagem, formaPagamento)
VALUES (2, 'Carro', '2023-12-10', '2023-12-15', 3, 'Brasil', 'RJ', 'Cidade B', 'Brasil', 'SP', 'Cidade A', 'Negócios', 'Dinheiro');

-- Inserção da Reserva 3
INSERT INTO reserva (idCliente, meioTransporte, dataEntrada, dataSaida, qtdPessoas, paisOrigem, estadoOrigem, cidadeOrigem, paisDestino, estadoDestino, cidadeDestino, motivoHospedagem, formaPagamento)
VALUES (3, 'Ônibus', '2024-01-05', '2024-01-10', 2, 'Brasil', 'MG', 'Cidade C', 'Brasil', 'SP', 'Cidade A', 'Férias', 'Cartão de Débito');

select * from reserva;

select * from colaborador;

-- Inserção do Quarto 1
INSERT INTO quarto (idPousada, qtdCamaCasal, qtdCamaSolteiro, numero, ocupado, frigobar, andar, arrumado, arrumadoPorUltimo, ultimaCamareira)
VALUES (1, 1, 2, '101', FALSE, TRUE, 1, TRUE, '2023-11-10 08:00:00', 5);

-- Inserção do Quarto 2
INSERT INTO quarto (idPousada, qtdCamaCasal, qtdCamaSolteiro, numero, ocupado, frigobar, andar, arrumado, arrumadoPorUltimo, ultimaCamareira)
VALUES (1, 1, 1, '102', FALSE, TRUE, 1, TRUE, '2023-11-11 09:00:00', 5);

-- Inserção do Quarto 3
INSERT INTO quarto (idPousada, qtdCamaCasal, qtdCamaSolteiro, numero, ocupado, frigobar, andar, arrumado, arrumadoPorUltimo, ultimaCamareira)
VALUES (1, 2, 1, '103', FALSE, FALSE, 1, TRUE, '2023-11-12 10:00:00', 5);


select * from quarto;

insert into reserva_quarto (idReserva, idQuarto) values (1, 4);

select * from reserva_quarto;

select * from reserva_quarto inner join quarto on reserva_quarto.idQuarto = quarto.idQuarto inner join reserva on reserva_quarto.idReserva = reserva.idReserva
inner join cliente on reserva.idCliente = cliente.idCliente;