-- Variant 1 --
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

select username, account_status from dba_users where username like 'MAKUTA' // CAPS are support
ALTER USER makuta ACCOUNT LOCK
ALTER USER makuta ACCOUNT UNLOCK

-- Task 4 --

GRANT CREATE SESSION TO makuta

-- Task 5 --

alter user makuta IDENTIFIED BY m12

-- Task 6 --

CREATE PUBLIC SYNONYM stud FOR student;

-- Task 7 --

GRANT ALl ON student To makuta;

-- Task 8 --

additions{

CREATE TABLE student(
    student_id Number,
    surname varchar(16),
    name varchar(16),
    stipend number,
    kurs number,
    home varchar(16),
    birthday date,
    univ_id number
);

    if table(Student) is empty {
        INSERT INTO STUDENT VALUES(1, 'Bicalo',  'Andriy', 1000, 3,'Lutsk',  to_date('21.06.1995','DD.MM.YYYY'),1);
        INSERT INTO STUDENT VALUES(2, 'Antoniuk','Boris',  1200, 3,'Kharkiv',to_date('03.04.1995','DD.MM.YYYY'),2);
        INSERT INTO STUDENT VALUES(3, 'Chariv',  'Mukola',  800, 4,'Rivne',  to_date('31.03.1996','DD.MM.YYYY'),1);
        INSERT INTO STUDENT VALUES(4, 'Hmelnyk', 'NIkita',  950, 3,'Lutsk',  to_date('01.02.1995','DD.MM.YYYY'),1);
        INSERT INTO STUDENT VALUES(5, 'Polyak',  'Galina', 1250, 4,'Donetsk',to_date('24.09.1996','DD.MM.YYYY'),2);
    }

    -- check table data --
        SELECT column_name, data_type
        FROM USER_TAB_COLUMNS
        WHERE table_name = 'STUDENT'
    -- END --
}
select name, surname from STUDENT where stipend > 1000
select name, surname from STUD where stipend > 1000

INSERT INTO STUDENT  VALUES( 96, 'Kolosov',  'Been',  950, 2, 'Lutsk',to_date('11.01.2001','DD.MM.YYYY'),3);
INSERT INTO stud     VALUES( 93, 'Isparamal','Imail',1650, 4 ,'Rivne',to_date('16.06.2003','DD.MM.YYYY'),3);

UPDATE STUDENT SET STIPEND = 2 * STIPEND WHERE home = 'Lutsk';
UPDATE STUD    SET STIPEND = 2 * STIPEND WHERE home = 'Lutsk';

-- Task 9 --
REVOKE SELECT, INSERT, UPDATE ON student FROM makuta;

-- Task 10 --

CREATE ROLE ROLL1;
GRANT SELECT, UPDATE, INSERT ON student TO ROLL1;
GRANT ROLL1 TO makuta;

-- Task 11 -> Task 8 --

-- Task 12 --

Drop role ROLL1;
DROP PUBLIC SYNONYM stud;
