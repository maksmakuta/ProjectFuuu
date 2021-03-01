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

    
    -- lab 3
    
   SET SERVEROUTPUT ON
DECLARE
    CURSOR get_offices IS   
    SELECT * FROM OFFICES;
    v_gt get_offices%ROWTYPE;
BEGIN
    OPEN get_offices;

    LOOP EXIT WHEN get_offices%NOTFOUND;
        DBMS_OUTPUT.enable;
        -- Use operator FETCH to get variables!
        FETCH get_offices INTO v_gt;
        DBMS_OUTPUT.put_line('Get Data: '||TO_CHAR(v_gt.OFFICE)||' '||v_gt.CITY||' '
        ||v_gt.REGION||' '||TO_CHAR(v_gt.MGR)||' '||TO_CHAR(v_gt.TARGET)||' '||TO_CHAR(v_gt.SALES));
    END LOOP;
    
    CLOSE get_offices; 

    END;
/
    
