SET SERVEROUTPUT ON

CREATE or replace function f(x in number) return number
    IS
        y number;
    BEGIN
        y := x*x-x;
        return y;
    END f;
/


declare
    x number := &x;
    y number;
begin
    y := f(x);
    dbms_output.put_line('f(x) = ' || y);
end;
/
