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