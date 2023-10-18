-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Jun 13, 2019 at 11:26 PM
-- Server version: 5.7.26
-- PHP Version: 7.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `projetolartec`
--

-- --------------------------------------------------------

--
-- Table structure for table `cliente`
--

DROP TABLE IF EXISTS `cliente`;
CREATE TABLE IF NOT EXISTS `cliente` (
  `nome` varchar(100) COLLATE utf8_bin NOT NULL,
  `cpf` varchar(14) COLLATE utf8_bin NOT NULL,
  `codigo_cliente` int(11) NOT NULL AUTO_INCREMENT,
  `email` varchar(50) COLLATE utf8_bin NOT NULL,
  `tel` varchar(20) COLLATE utf8_bin NOT NULL,
  `rua` varchar(100) COLLATE utf8_bin NOT NULL,
  `bairro` varchar(50) COLLATE utf8_bin NOT NULL,
  `complemento` varchar(50) COLLATE utf8_bin NOT NULL,
  `cidade` varchar(50) COLLATE utf8_bin NOT NULL,
  `estado` varchar(2) COLLATE utf8_bin NOT NULL,
  `cep` varchar(10) COLLATE utf8_bin NOT NULL,
  `obs` text COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`codigo_cliente`)
) ENGINE=MyISAM AUTO_INCREMENT=51 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `cliente`
--

INSERT INTO `cliente` (`nome`, `cpf`, `codigo_cliente`, `email`, `tel`, `rua`, `bairro`, `complemento`, `cidade`, `estado`, `cep`, `obs`) VALUES
(' Joao da Silva Sauro', '423.257.323-01', 41, 'joao@hotmail.com', '(23)34567-3421', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 666', 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000', ''),
('Jesuis de Nazare', '423.257.323-01', 45, 'noceutempao@hotmail.com', '(23)34567-3421', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 666', 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000', ''),
('Joao da Silva ', '434.644.246-01', 21, 'marcio@hotmail.com', '(23)34567-3421', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', 'Sao Joao da Boa Vista', 'SP', '13870-000', ''),
('Josefino 2', '434.644.246-01', 43, 'marcio@hotmail.com', '(23)34567-3421', 'Rua da Minha Casa', 'Bairro da Minha Rua', '', 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000', ''),
('Joao da Silva', '231.423.231-02', 44, 'joao@hotmail.com', '(23)34567-3421', 'Av. Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 666', 'AguaÃ­', 'MG', '13870-000', ''),
('    Pedro de Oliveira', '235.342.123-01', 50, 'pedro@hotmail.com', '(23)13242-2313', 'Av. Rua da Minha Casa,113', 'Bairro da Minha Rua', '', 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000', 'Cobrar a vista\r\nCliente devendo x'),
(' Marcio Ferre', '434.644.246-01', 34, 'otavio@hotmail.com', '(23)34567-3421', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 231', 'Vargem Grande do Sul', 'SP', '23134-231', ''),
('Paulo Fernandes Santos', '395.021.603-04', 48, 'PauloFernandesSantos@teleworm.us', '(11) 2510-4783', 'Rua DamiÃ£o Ferreira de Aquino, 577', 'CubatÃ£o-SP', '', 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000', '');

-- --------------------------------------------------------

--
-- Table structure for table `funcionario`
--

DROP TABLE IF EXISTS `funcionario`;
CREATE TABLE IF NOT EXISTS `funcionario` (
  `nome` varchar(100) COLLATE utf8_bin NOT NULL,
  `funcao` varchar(100) COLLATE utf8_bin NOT NULL,
  `email` varchar(100) COLLATE utf8_bin NOT NULL,
  `tel` varchar(100) COLLATE utf8_bin NOT NULL,
  `cpf` varchar(100) COLLATE utf8_bin NOT NULL,
  `rua` varchar(100) COLLATE utf8_bin NOT NULL,
  `bairro` varchar(100) COLLATE utf8_bin NOT NULL,
  `comp` varchar(100) COLLATE utf8_bin NOT NULL,
  `cart_trab` varchar(100) COLLATE utf8_bin NOT NULL,
  `data_adm` varchar(100) COLLATE utf8_bin NOT NULL,
  `data_dem` varchar(100) COLLATE utf8_bin NOT NULL,
  `hora` varchar(100) COLLATE utf8_bin NOT NULL,
  `salario` varchar(100) COLLATE utf8_bin NOT NULL,
  `codigo_func` int(11) NOT NULL AUTO_INCREMENT,
  `cidade` varchar(100) COLLATE utf8_bin NOT NULL,
  `estado` varchar(100) COLLATE utf8_bin NOT NULL,
  `cep` varchar(100) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`codigo_func`)
) ENGINE=MyISAM AUTO_INCREMENT=15 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `funcionario`
--

INSERT INTO `funcionario` (`nome`, `funcao`, `email`, `tel`, `cpf`, `rua`, `bairro`, `comp`, `cart_trab`, `data_adm`, `data_dem`, `hora`, `salario`, `codigo_func`, `cidade`, `estado`, `cep`) VALUES
('Felipe Antonio ', 'Recepcionista', 'marcio@hotmail.com', '(23)34567-3421', '423.257.323-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342', '02/32/1203', '', '08-18', 'R$1200,00', 8, 'Ãguas da Prata', 'SP', '13870-000'),
('dsadasdasd', 'Administrador', 'joao@hotmail.com', '(23)34567-3421', '434.644.246-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342dasd', '02/32/1203', '', '08-18', 'R$1200,00', 9, 'AguaÃ­', 'SP', '13870-000'),
('Joao da Silva', 'Atendente', 'joao@hotmail.com', '(23)34567-3421', '423.257.323-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342', '02/32/1203', '', '08-18', 'R$1200,00', 10, 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000'),
('Marcio Ferreira', 'Tecnico', 'joao@hotmail.com', '(23)34567-3421', '423.257.323-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342', '02/32/1203', '', '08-18', 'R$1200,00', 11, 'AguaÃ­', 'SP', '13870-000'),
('Felipe Antonio', 'Atendente', 'joao@hotmail.com', '(23)34567-3421', '423.257.323-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342', '02/32/1203', '', '08-18', 'R$1200,00', 12, 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000'),
('Paulo Fernandes Santos', 'Tecnico', 'otavio@hotmail.com', '(23)34567-3421', '434.644.246-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342', '02/32/1203', '', '08-18', 'R$1200,00', 13, 'Ãguas da Prata', 'SP', '13870-000'),
('Pedro de Oliveira', 'Recepcionista', 'joao@hotmail.com', '(23)34567-3421', '423.257.323-01', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', '454832l53342', '02/32/1203', '', '08-18', 'R$1200,00', 14, 'SÃ£o JoÃ£o da Boa Vista', 'SP', '13870-000');

-- --------------------------------------------------------

--
-- Table structure for table `os`
--

DROP TABLE IF EXISTS `os`;
CREATE TABLE IF NOT EXISTS `os` (
  `codigo_cliente` int(10) NOT NULL,
  `nome` varchar(100) COLLATE utf8_bin NOT NULL,
  `data_atend` varchar(50) COLLATE utf8_bin NOT NULL,
  `nome_atend` varchar(100) COLLATE utf8_bin NOT NULL,
  `nome_tec` varchar(100) COLLATE utf8_bin NOT NULL,
  `rua` varchar(100) COLLATE utf8_bin NOT NULL,
  `bairro` varchar(100) COLLATE utf8_bin NOT NULL,
  `comp` varchar(100) COLLATE utf8_bin NOT NULL,
  `cidade` varchar(100) COLLATE utf8_bin NOT NULL,
  `taxa` varchar(50) COLLATE utf8_bin NOT NULL,
  `estado` varchar(50) COLLATE utf8_bin NOT NULL,
  `cep` varchar(50) COLLATE utf8_bin NOT NULL,
  `produto` varchar(100) COLLATE utf8_bin NOT NULL,
  `tipo_atend` varchar(100) COLLATE utf8_bin NOT NULL,
  `pecas` text COLLATE utf8_bin NOT NULL,
  `valor_pecas` varchar(50) COLLATE utf8_bin NOT NULL,
  `maodeobra` text COLLATE utf8_bin NOT NULL,
  `valor_mo` varchar(50) COLLATE utf8_bin NOT NULL,
  `valor_total` varchar(50) COLLATE utf8_bin NOT NULL,
  `data_agend` varchar(50) COLLATE utf8_bin NOT NULL,
  `status` varchar(100) COLLATE utf8_bin NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `os`
--

INSERT INTO `os` (`codigo_cliente`, `nome`, `data_atend`, `nome_atend`, `nome_tec`, `rua`, `bairro`, `comp`, `cidade`, `taxa`, `estado`, `cep`, `produto`, `tipo_atend`, `pecas`, `valor_pecas`, `maodeobra`, `valor_mo`, `valor_total`, `data_agend`, `status`) VALUES
(523, 'Joao da Silva', '', 'Felipe Antonio', 'Paulo Fernandes Santos', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', 'AguaÃ­', '', 'SP', '13870-000', 'Lavadora Electrolux 239-ME', 'Garantia Electrolux', 'xxx', '123', 'xxx', '321', '432', '03/05/2019', 'NÃ£o Paga'),
(6321, 'Josefino', '', 'Felipe Antonio', 'Paulo Fernandes Santos', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', 'SÃ£o JoÃ£o da Boa Vista', '', 'SP', '13870-000', 'Lavadora Electrolux 239-ME', 'Garantia Electrolux', 'wdw', '123', 'eee', '323', '242', '05/10/2019', 'NÃ£o Paga'),
(88, 'Joao da Silva', '23/02/2019', 'Felipe Antonio', 'Paulo Fernandes Santos', 'Rua da Minha Casa', 'Bairro da Minha Rua', 'Apto. 555', 'Ãguas da Prata', 'R$42,00', 'SP', '13870-000', 'Lavadora Electrolux 239-ME', 'Garantia Electrolux', 'xr', '23', 'xe', '23213', 'R$470,00', '02/09/2019', 'Cliente NÃ£o Autorizou');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
