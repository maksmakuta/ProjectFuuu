SET SERVEROUTPUT ON

CREATE OR REPLACE PROCEDURE print_table
    IS
        cursor1 OFFICES%ROWTYPE;
    BEGIN
        FOR cursor1 IN (SELECT * FROM OFFICES) 
          LOOP
            DBMS_OUTPUT.PUT_LINE(cursor1.office || ' ' || cursor1.city || ' ' || cursor1.region
            || ' ' || cursor1.mgr || ' ' || cursor1.target || ' ' || cursor1.sales);
          END LOOP;
    END print_table;
/
