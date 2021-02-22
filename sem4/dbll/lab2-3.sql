declare
    y number := 0;
    x number;
begin
    for a in 0..5 loop
        x := a*2;
        y := x**2 - 2*x -2;
        dbms_output.put_line('x = ' || x || ' y = ' || y);
    end loop;
end;
/
