-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Jan 24, 2021 at 05:41 PM
-- Server version: 5.7.31
-- PHP Version: 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `housing_loan`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
CREATE TABLE IF NOT EXISTS `admin` (
  `Admin_ID` varchar(4) NOT NULL,
  `Password` varchar(12) DEFAULT NULL,
  `FName` varchar(50) DEFAULT NULL,
  `LName` varchar(50) DEFAULT NULL,
  `Age` int(3) DEFAULT NULL,
  `Address` varchar(100) DEFAULT NULL,
  `Email` varchar(30) DEFAULT NULL,
  `PhoneNumber` varchar(12) DEFAULT NULL,
  PRIMARY KEY (`Admin_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`Admin_ID`, `Password`, `FName`, `LName`, `Age`, `Address`, `Email`, `PhoneNumber`) VALUES
('AD01', 'Pipan060912.', 'BRUCE', 'BANNER', 23, 'No.212, Jalan 4/7, Taman Sentul', 'Bruce123@gmail.com', '01256445643'),
('AD02', 'Chong123.', 'Chong', 'Xuan', 30, 'No.211,Seremban.', 'Chong30@gmail.com', '0192834311'),
('AD03', 'Chin123.', 'TONY', 'STARK', 27, 'No.211,Jalan 2/9, Taman Muar.', 'Tony123@GMAIL.COM', '0147659865');

-- --------------------------------------------------------

--
-- Table structure for table `amount`
--

DROP TABLE IF EXISTS `amount`;
CREATE TABLE IF NOT EXISTS `amount` (
  `Amount_ID` int(4) NOT NULL AUTO_INCREMENT,
  `Client_ID` varchar(4) NOT NULL,
  `House_type` varchar(50) DEFAULT NULL,
  `Amount` decimal(9,2) DEFAULT NULL,
  `Interest_rate` decimal(9,2) DEFAULT NULL,
  `Loan_Period` int(3) DEFAULT NULL,
  `Down_payment` decimal(8,2) DEFAULT NULL,
  `Total_loan_amount` decimal(9,2) DEFAULT NULL,
  `Monthly_repayment` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`Amount_ID`),
  KEY `Client_ID` (`Client_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `amount`
--

INSERT INTO `amount` (`Amount_ID`, `Client_ID`, `House_type`, `Amount`, `Interest_rate`, `Loan_Period`, `Down_payment`, `Total_loan_amount`, `Monthly_repayment`) VALUES
(13, 'CL01', 'BUNGALOW', '3500000.00', '2.60', 25, '12.00', '3080000.00', '13973.02');

-- --------------------------------------------------------

--
-- Table structure for table `client`
--

DROP TABLE IF EXISTS `client`;
CREATE TABLE IF NOT EXISTS `client` (
  `Client_ID` varchar(4) NOT NULL,
  `FName` varchar(50) DEFAULT NULL,
  `LName` varchar(50) DEFAULT NULL,
  `Age` int(3) DEFAULT NULL,
  `Address` varchar(100) DEFAULT NULL,
  `Email` varchar(30) DEFAULT NULL,
  `PhoneNumber` varchar(12) DEFAULT NULL,
  PRIMARY KEY (`Client_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `client`
--

INSERT INTO `client` (`Client_ID`, `FName`, `LName`, `Age`, `Address`, `Email`, `PhoneNumber`) VALUES
('CL01', 'NATASHA', 'ROMANOFF', 32, 'No.343,Jalan 3/9, Taman Sentosa.', 'NatRom321@gmail.com', '0192336232'),
('CL03', 'TONY', 'STARK', 35, 'No.353, Jalan 5, Taman Melur.', 'TS123@gmail.com', '0198273126'),
('CL04', 'CARL', 'JOHNSON', 25, 'No.21, Jalan 4/7, Taman Desa Pinggiran Bayu.', 'CJ123@gmail.com', '0192836352'),
('CL05', 'WANDA', 'Maximoff', 53, 'No.215, Jalan 4, Taman Desa Pinggiran Tanjung.', 'WMOFF456@gmail.com', '0198273676'),
('CL06', 'JAMES', 'SMITH', 34, 'No.394, Jalan4/6, Taman Maju Jaya.', 'James0609@gmail.com', '0198723451');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

DROP TABLE IF EXISTS `staff`;
CREATE TABLE IF NOT EXISTS `staff` (
  `Staff_ID` varchar(4) NOT NULL,
  `Password` varchar(12) DEFAULT NULL,
  `FName` varchar(50) DEFAULT NULL,
  `LName` varchar(50) DEFAULT NULL,
  `Age` int(3) DEFAULT NULL,
  `Address` varchar(100) DEFAULT NULL,
  `Email` varchar(30) DEFAULT NULL,
  `PhoneNumber` varchar(12) DEFAULT NULL,
  PRIMARY KEY (`Staff_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`Staff_ID`, `Password`, `FName`, `LName`, `Age`, `Address`, `Email`, `PhoneNumber`) VALUES
('ST01', 'Wade0908070.', 'WADE', 'WILSON', 34, 'No.246, Jalan 4, Taman Bahagia.', 'WW123@gmail.com', '0127839762'),
('ST02', 'JohnWick123.', 'WICK', 'JOHN', 45, 'No.321,Jalan 6, Taman Orkid', 'JW123@gmail.com', '0192239421'),
('ST03', 'Kiyan060912.', 'Kiyan', 'Eara', 27, 'No.311, Jalan 8, Taman Desa Pinggiran Bayu.', 'Ki123@gmail.com', '0129637212');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `amount`
--
ALTER TABLE `amount`
  ADD CONSTRAINT `amount_ibfk_1` FOREIGN KEY (`Client_ID`) REFERENCES `client` (`Client_ID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
