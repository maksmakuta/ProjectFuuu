-- Task 1 --
-- clear screen --

select * from student
select * from lecturer
select * from subject
select * from university
select * from exam_marks
select * from subj_lect

-- Task 2 --

CREATE USER makuta IDENTIFIED BY m10

-- Task 3 --

select username, account_status from dba_users
ALTER USER makuta ACCOUNT LOCK
ALTER USER makuta ACCOUNT UNLOCK

-- Task 4 --

GRANT CREATE SESSION TO makuta

-- Task 5 --

alter user makuta IDENTIFIED BY m12

-- Task 6 --

CREATE PUBLIC SYNONYM student1 FOR stud.student;

-- Task 7 --

GRANT ALl ON student1 To makuta;

-- Task 8 --

if table(Student1) is empty {
    INSERT INTO STUDENT1 VALUES(  1, 'Bicalo', 'Andriy', 'VNU', 'Lutsk',1000);
    INSERT INTO STUDENT1 VALUES(  2, 'Antoniuk', 'Boris', 'LNTU', 'Kharkiv',1200);
    INSERT INTO STUDENT1 VALUES(  3, 'Chariv', 'Mukola', 'SNU', 'Rivne',800);
    INSERT INTO STUDENT1 VALUES(  4, 'Hmelnyk', 'NIkita', 'VNU', 'Lutsk',1150);
    INSERT INTO STUDENT1 VALUES(  5, 'Polyak', 'Galina', 'LNTU', 'Donetsk',1100);
}

select name, surname from student1 where stipend > 1000
select name, surname from stud.student1 where stipend > 1000

INSERT INTO STUDENT1  VALUES( 95, 'Kolosov',  'Nik', 'VNU', 'Lutsk',1300);
INSERT INTO Stud.STUDENT1 VALUES( 98, 'Isparamal','Beed','LNTU', 'Rivne', 1250);

UPDATE STUDENT1       SET STIPEND = 2 * STIPEND WHERE City = 'Lutsk';
UPDATE STUD.STUDENT1 SET STIPEND = 2 * STIPEND WHERE City = 'Lutsk';
