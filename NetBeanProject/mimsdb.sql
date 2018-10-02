-- phpMyAdmin SQL Dump
-- version 4.5.2
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: May 22, 2017 at 11:18 AM
-- Server version: 5.7.9
-- PHP Version: 5.6.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mimsdb`
--

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

DROP TABLE IF EXISTS `login`;
CREATE TABLE IF NOT EXISTS `login` (
  `user` varchar(15) NOT NULL,
  `password` varbinary(128) NOT NULL,
  `type` set('ADMIN','WORKER') DEFAULT 'WORKER',
  `staffid` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`user`),
  KEY `staff_fk_idx` (`staffid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `login`
--

INSERT INTO `login` (`user`, `password`, `type`, `staffid`) VALUES
('Ganesh', 0x6536643539663039353866663338663236316634623662366664653062373633, 'WORKER', 'S0003'),
('Guru', 0x3435643930396138313733393866663935366562373966663131343663356534, 'ADMIN', 'S0001'),
('Harish', 0x3639386339363334323436303130333938653863343237626464313264333734, 'WORKER', 'S0002'),
('Sam', 0x6261306530636465316266373263323864343335633839613636616663363161, 'WORKER', 'S0005');

--
-- Triggers `login`
--
DROP TRIGGER IF EXISTS `passwd_encrypt`;
DELIMITER $$
CREATE TRIGGER `passwd_encrypt` BEFORE INSERT ON `login` FOR EACH ROW BEGIN
SET NEW.password = md5(NEW.password);
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `medicine`
--

DROP TABLE IF EXISTS `medicine`;
CREATE TABLE IF NOT EXISTS `medicine` (
  `mid` varchar(15) NOT NULL,
  `mname` varchar(45) DEFAULT NULL,
  `price` float NOT NULL,
  `mgfdate` date NOT NULL,
  `expdate` date NOT NULL,
  `qty` int(11) NOT NULL DEFAULT '0',
  `desc` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`mid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `medicine`
--

INSERT INTO `medicine` (`mid`, `mname`, `price`, `mgfdate`, `expdate`, `qty`, `desc`) VALUES
('M0002', 'Cofsils', 5, '2016-12-20', '2016-12-20', 15, 'Cough Tablet'),
('M0001', 'Paracitamol', 2, '2017-03-01', '2017-03-01', 1, 'Fever');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

DROP TABLE IF EXISTS `staff`;
CREATE TABLE IF NOT EXISTS `staff` (
  `staffid` varchar(45) NOT NULL,
  `staffname` varchar(45) NOT NULL,
  `staffsalary` double NOT NULL,
  `stafftype` set('ADMIN','WORKER') DEFAULT 'WORKER',
  PRIMARY KEY (`staffid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`staffid`, `staffname`, `staffsalary`, `stafftype`) VALUES
('S0001', 'Guru', 20000, 'ADMIN'),
('S0002', 'Harish', 18000, 'WORKER'),
('S0003', 'Ganesh', 18000, 'WORKER'),
('S0005', 'Sam', 17000, 'WORKER');

--
-- Triggers `staff`
--
DROP TRIGGER IF EXISTS `staff_AFTER_INSERT`;
DELIMITER $$
CREATE TRIGGER `staff_AFTER_INSERT` AFTER INSERT ON `staff` FOR EACH ROW BEGIN
	Insert into login(user,password,staffid) values(NEW.staffname,NEW.staffname,NEW.staffid);
END
$$
DELIMITER ;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `login`
--
ALTER TABLE `login`
  ADD CONSTRAINT `staff_fk` FOREIGN KEY (`staffid`) REFERENCES `staff` (`staffid`) ON DELETE CASCADE ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
