SET SERVEROUTPUT ON

CREATE OR REPLACE FUNCTION test_add RETURN NUMBER
IS
    c test%rowtype;
    sum_ integer := 0;
BEGIN
     FOR c IN (SELECT * FROM test) LOOP
     sum_ := sum_ + c.x;       
     END LOOP;
     
     RETURN sum_;
END test_add;
/

declare
    y number;
begin
    y := test_add;
    dbms_output.put_line('sum = ' || y);
end;
/
