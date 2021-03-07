SET SERVEROUTPUT ON

CREATE OR REPLACE FUNCTION FACTORIAL(NUM IN NUMBER) RETURN NUMBER
IS
BEGIN
    IF (NUM <=1) THEN
        RETURN (NUM);
    ELSE
        RETURN (NUM * FACTORIAL(NUM-1));
    END IF;
END FACTORIAL;
/

declare
    x number := &x;
    y number;
begin
    y := FACTORIAL(x);
    dbms_output.put_line(x || '! = ' || y);
end;
/
