declare
    out number := 0;
    num number := 0;
begin

    for a in 1..5 loop
        num := a + (a/10);
        out := num * out;
    end loop;
    
    dbms_output.put_line('Out : ' || out);
    
end;
/
