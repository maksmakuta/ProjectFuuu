declare
    out number := 0;
    num number;
    n number;
    x number;

    fac number := 1;    
begin
    x := &x;
    n := &n;

    for a in 0..n loop
        for b in 1..n loop
            fac := fac * b;
        end loop;
        num := power(x,a) / fac;
        out := num + out;
        fac := 1;
    end loop;
    
    dbms_output.put_line('Out : ' || out);
    
end;
/
