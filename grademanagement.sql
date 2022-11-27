/*
Navicat MySQL Data Transfer

Source Server         : mysql
Source Server Version : 50730
Source Host           : localhost:3306
Source Database       : grademanagement

Target Server Type    : MYSQL
Target Server Version : 50730
File Encoding         : 65001

Date: 2022-11-12 16:29:19
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `id` int(11) NOT NULL,
  `password` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('10001', '123456');

-- ----------------------------
-- Table structure for exam
-- ----------------------------
DROP TABLE IF EXISTS `exam`;
CREATE TABLE `exam` (
  `major` varchar(45) NOT NULL,
  `subject` varchar(45) NOT NULL,
  `term` int(11) DEFAULT NULL,
  `class` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`major`,`subject`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of exam
-- ----------------------------
INSERT INTO `exam` VALUES ('计科', 'c++', '1', '笔试');
INSERT INTO `exam` VALUES ('计科', '微机原理', '2', '笔试');
INSERT INTO `exam` VALUES ('计科', '软件工程', '2', '笔试');
INSERT INTO `exam` VALUES ('计科', '高数', '1', '笔试');
INSERT INTO `exam` VALUES ('通信', 'c++', '1', '笔试');
INSERT INTO `exam` VALUES ('通信', '信号与系统', '2', '笔试');
INSERT INTO `exam` VALUES ('通信', '微机原理', '2', '笔试');
INSERT INTO `exam` VALUES ('通信', '高数', '1', '笔试');

-- ----------------------------
-- Table structure for grade
-- ----------------------------
DROP TABLE IF EXISTS `grade`;
CREATE TABLE `grade` (
  `Sno` int(11) NOT NULL,
  `subject` varchar(45) NOT NULL,
  `grade` int(11) DEFAULT NULL,
  PRIMARY KEY (`Sno`,`subject`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of grade
-- ----------------------------
INSERT INTO `grade` VALUES ('1001', 'c++', '82');
INSERT INTO `grade` VALUES ('1001', '软件工程', '83');
INSERT INTO `grade` VALUES ('1001', '高数', '80');
INSERT INTO `grade` VALUES ('1002', '高数', '81');
INSERT INTO `grade` VALUES ('1003', 'c++', '82');
INSERT INTO `grade` VALUES ('1003', '信号与系统', '83');
INSERT INTO `grade` VALUES ('1003', '高数', '81');

-- ----------------------------
-- Table structure for major
-- ----------------------------
DROP TABLE IF EXISTS `major`;
CREATE TABLE `major` (
  `Mname` varchar(45) NOT NULL,
  `department` varchar(45) NOT NULL,
  PRIMARY KEY (`Mname`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of major
-- ----------------------------
INSERT INTO `major` VALUES ('计科', '理工部');
INSERT INTO `major` VALUES ('通信', '理工部');

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `Sno` int(11) NOT NULL,
  `Sname` varchar(45) DEFAULT NULL,
  `Sage` int(11) DEFAULT NULL,
  `Sclass` int(11) DEFAULT NULL,
  `major` varchar(45) DEFAULT NULL,
  `password` varchar(45) DEFAULT '123456',
  `born` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`Sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('1001', '赵', '20', '19', '计科', '123456', '2000/1/1');
INSERT INTO `student` VALUES ('1002', '钱', '20', '19', '计科', '123456', '2000.3');
INSERT INTO `student` VALUES ('1003', '孙', '20', '19', '通信', '123456', '2000.5');
INSERT INTO `student` VALUES ('1004', '李', '20', '19', '通信', '123456', '2000.7');
INSERT INTO `student` VALUES ('1005', '周', '19', '20', '计科', '123456', '2001.2');
INSERT INTO `student` VALUES ('1006', '吴', '19', '20', '计科', '123456', '2001.4');
INSERT INTO `student` VALUES ('1007', '郑', '19', '20', '通信', '123456', '2001.6');
INSERT INTO `student` VALUES ('1008', '王', '19', '20', '通信', '123456', '2001.8');

-- ----------------------------
-- Table structure for subject
-- ----------------------------
DROP TABLE IF EXISTS `subject`;
CREATE TABLE `subject` (
  `NO` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`NO`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of subject
-- ----------------------------
INSERT INTO `subject` VALUES ('1', '高数');
INSERT INTO `subject` VALUES ('2', 'c++');
INSERT INTO `subject` VALUES ('3', '软件工程');
INSERT INTO `subject` VALUES ('4', '微机原理');
INSERT INTO `subject` VALUES ('5', '信号与系统');

-- ----------------------------
-- Table structure for teacher
-- ----------------------------
DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher` (
  `id` int(11) NOT NULL,
  `name` varchar(45) DEFAULT NULL,
  `password` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of teacher
-- ----------------------------
INSERT INTO `teacher` VALUES ('10001', '冯', '123456');
INSERT INTO `teacher` VALUES ('10002', '陈', '123456');
