-- Task 1 --

CREATE USER makuta IDENTIFIED BY pass;

-- Task 2 --

GRANT CREATE SESSION TO makuta;

-- Task 3 -- 
-- DROP VIEW STUD; - Delete view

CREATE VIEW STUD AS SELECT * FROM STUDENT WHERE HOME = 'Lutsk' WITH CHECK OPTION;
GRANT UPDATE ON system.STUD To makuta;
UPDATE system.stud SET home = 'Kiev'  WHERE home = 'Lutsk';
UPDATE system.stud SET home = 'Lutsk' WHERE home = 'Kiev';
