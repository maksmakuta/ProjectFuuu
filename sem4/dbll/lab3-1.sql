CREATE TABLE OFFICES ( 
    OFFICE INTEGER PRIMARY KEY, 
    CITY VARCHAR2(30) NOT NULL, 
    REGION VARCHAR2(30) NOT NULL,
    MGR INTEGER, 
    TARGET NUMBER, 
    SALES NUMBER NOT NULL 
);
    
    Insert into OFFICES values (1, 'Lutsk', 'Vol', 20, 20, 300);
    Insert into OFFICES values (2, 'Lviv', 'Lviv', 30, 20, 600);
    Insert into OFFICES values (3, 'Kovel', 'Vol', 50, 10, 200);
    Insert into OFFICES values (4, 'Rivne', 'Rivn', 20, 20, 300);
-- comment 
-- task1
    
    SET SERVEROUTPUT ON
DECLARE
-- Cursor declaration --
CURSOR get_offices IS
SELECT * FROM OFFICES;
-- Record to store the fetched data --
v_gt get_offices%ROWTYPE;
BEGIN
DBMS_OUTPUT.enable;
IF(get_offices%ISOPEN) THEN
DBMS_OUTPUT.put_line('Cursor get_offices is open now!');
ELSE
DBMS_OUTPUT.put_line('Cursor get_offices is close now!');
END IF;
-- location (1) -- cursor is open --
OPEN get_offices; 
IF(get_offices%ISOPEN) THEN
DBMS_OUTPUT.put_line('Cursor get_offices is open now!');
ELSE
DBMS_OUTPUT.put_line('Cursor get_offices is close now!');
END IF;
-- location (2)
FETCH get_offices INTO v_gt; -- fetch first row --
IF(get_offices%FOUND) THEN
DBMS_OUTPUT.put_line('Row is Found!');
ELSE
DBMS_OUTPUT.put_line('Row is not Found!');
END IF;
DBMS_OUTPUT.put_line(TO_CHAR(v_gt.OFFICE)||' '||v_gt.CITY||' '
||'The count row is '||TO_CHAR(get_offices%ROWCOUNT));
-- location (3)
FETCH get_offices INTO v_gt; -- fetch second row --
IF(get_offices%NOTFOUND) THEN
DBMS_OUTPUT.put_line('Row is not Found!');
ELSE
DBMS_OUTPUT.put_line('Row is Found!');
END IF;
DBMS_OUTPUT.put_line(TO_CHAR(v_gt.OFFICE)||' '||v_gt.CITY||' '
||'The count row is '||TO_CHAR(get_offices%ROWCOUNT));
-- location (4)
FETCH get_offices INTO v_gt; -- Third first --
IF(get_offices%FOUND) THEN
DBMS_OUTPUT.put_line('Row is Found!');
ELSE
DBMS_OUTPUT.put_line('Row is not Found!');
END IF;
DBMS_OUTPUT.put_line(TO_CHAR(v_gt.OFFICE)||' '||v_gt.CITY||' '
||'The count row is '||TO_CHAR(get_offices%ROWCOUNT));
-- location (5)
CLOSE get_offices; -- cursor is close --
-- location (6)
END;
/
