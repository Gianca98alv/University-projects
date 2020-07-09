-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 24-06-2020 a las 10:40:02
-- Versión del servidor: 10.4.11-MariaDB
-- Versión de PHP: 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `examen_parcial2`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `client`
--

CREATE TABLE `client` (
  `idClient` bigint(20) NOT NULL,
  `name` varchar(15) COLLATE utf8_spanish_ci NOT NULL,
  `lastName` varchar(15) COLLATE utf8_spanish_ci NOT NULL,
  `iva` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientaddress`
--

CREATE TABLE `clientaddress` (
  `idClientAddress` bigint(20) NOT NULL,
  `address` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `type` varchar(15) COLLATE utf8_spanish_ci NOT NULL,
  `idClient` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientphone`
--

CREATE TABLE `clientphone` (
  `idClientPhone` bigint(20) NOT NULL,
  `phone` varchar(15) COLLATE utf8_spanish_ci NOT NULL,
  `type` varchar(15) COLLATE utf8_spanish_ci NOT NULL,
  `idClient` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `order`
--

CREATE TABLE `order` (
  `idOrder` bigint(20) NOT NULL,
  `orderNumber` int(11) NOT NULL,
  `date` date NOT NULL,
  `cost` float NOT NULL,
  `costIVA` float NOT NULL,
  `orderStatus` bigint(20) NOT NULL,
  `orderCategory` bigint(20) NOT NULL,
  `client` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ordercategory`
--

CREATE TABLE `ordercategory` (
  `idOrderCategory` bigint(20) NOT NULL,
  `category` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `percentage` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `orderstatus`
--

CREATE TABLE `orderstatus` (
  `idOrderStatus` bigint(20) NOT NULL,
  `status` varchar(15) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`idClient`);

--
-- Indices de la tabla `clientaddress`
--
ALTER TABLE `clientaddress`
  ADD PRIMARY KEY (`idClientAddress`),
  ADD KEY `idClient` (`idClient`);

--
-- Indices de la tabla `clientphone`
--
ALTER TABLE `clientphone`
  ADD PRIMARY KEY (`idClientPhone`),
  ADD KEY `idClient` (`idClient`);

--
-- Indices de la tabla `order`
--
ALTER TABLE `order`
  ADD PRIMARY KEY (`idOrder`),
  ADD KEY `orderStatus` (`orderStatus`),
  ADD KEY `orderCategory` (`orderCategory`),
  ADD KEY `order_ibfk_1` (`client`);

--
-- Indices de la tabla `ordercategory`
--
ALTER TABLE `ordercategory`
  ADD PRIMARY KEY (`idOrderCategory`);

--
-- Indices de la tabla `orderstatus`
--
ALTER TABLE `orderstatus`
  ADD PRIMARY KEY (`idOrderStatus`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `client`
--
ALTER TABLE `client`
  MODIFY `idClient` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `clientaddress`
--
ALTER TABLE `clientaddress`
  MODIFY `idClientAddress` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `clientphone`
--
ALTER TABLE `clientphone`
  MODIFY `idClientPhone` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `order`
--
ALTER TABLE `order`
  MODIFY `idOrder` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `ordercategory`
--
ALTER TABLE `ordercategory`
  MODIFY `idOrderCategory` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `orderstatus`
--
ALTER TABLE `orderstatus`
  MODIFY `idOrderStatus` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `clientaddress`
--
ALTER TABLE `clientaddress`
  ADD CONSTRAINT `clientaddress_ibfk_1` FOREIGN KEY (`idClient`) REFERENCES `client` (`idClient`);

--
-- Filtros para la tabla `clientphone`
--
ALTER TABLE `clientphone`
  ADD CONSTRAINT `clientphone_ibfk_1` FOREIGN KEY (`idClient`) REFERENCES `client` (`idClient`);

--
-- Filtros para la tabla `order`
--
ALTER TABLE `order`
  ADD CONSTRAINT `order_ibfk_1` FOREIGN KEY (`client`) REFERENCES `client` (`idClient`),
  ADD CONSTRAINT `order_ibfk_2` FOREIGN KEY (`orderStatus`) REFERENCES `orderstatus` (`idOrderStatus`),
  ADD CONSTRAINT `order_ibfk_3` FOREIGN KEY (`orderCategory`) REFERENCES `ordercategory` (`idOrderCategory`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
