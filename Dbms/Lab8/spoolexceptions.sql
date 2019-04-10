SQL> @"E:\B.Harish\Sem 4\Dbms\Lab8\exceptions"
SQL> set serveroutput on
SQL> set echo on
SQL> --*****************************************************************************
SQL> insert into receipts values(99999,sysdate,21);

1 row created.

SQL> 
SQL> declare
  2    x_rno receipts.rno%type :=84665;
  3    --select r.rno from receipts r,item_list i where  r.rno=i.receipt group by r.rno having	count(i.item)>1 ;  use 99994
  4    --select r.rno from receipts r,item_list i where  r.rno=i.receipt group by r.rno having	count(i.item)=1 ; use 84665
  5    --select r.rno from receipts r,item_list i where  r.rno=i.receipt group by r.rno having	count(i.item)=0;
  6    x_qty number(2):=1;
  7  begin
  8    x_rno:=&Rno;
  9  
 10    select (i.item) into x_qty
 11    from item_list i,receipts r
 12    where r.rno=i.receipt
 13    and r.rno=x_rno;
 14  
 15  Exception
 16    when no_data_found then
 17  	 --dbms_output.put_line(chr(10)||'Error_Code: '||sqlcode||chr(10)||'Msg: '||sqlerrm);
 18  	 dbms_output.put_line(chr(10)||'Receipt '||x_rno||' contains no item');
 19    when too_many_rows then
 20  	 dbms_output.put_line(chr(10)||'Receipt '||x_rno||' contains more than one item');
 21    when others then
 22  	 dbms_output.put_line(chr(10)||'Receipt '||x_rno||' contains a single item only'||chr(10)||'Qty: '||x_qty);
 23  
 24  end;
 25  --*****************************"OPUTPUT BELOW"**********************************
 26  /
Enter value for rno: 99999
old   8:   x_rno:=&Rno;
new   8:   x_rno:=99999;

Receipt 99999 contains no item                                                 

PL/SQL procedure successfully completed.

SQL> /
Enter value for rno: 99994
old   8:   x_rno:=&Rno;
new   8:   x_rno:=99994;

Receipt 99994 contains more than one item                                      

PL/SQL procedure successfully completed.

SQL> /
Enter value for rno: 84665
old   8:   x_rno:=&Rno;
new   8:   x_rno:=84665;

Receipt 84665 contains a single item only
Qty: 1                               

PL/SQL procedure successfully completed.

SQL> delete from receipts where rno = 99999;

1 row deleted.

SQL> --*****************************************************************************
SQL> 
SQL> --2:
SQL> 
SQL> --add these line and don't forget to undo the changes after pl/sql block;
SQL> alter table receipts add today date default sysdate;

Table altered.

SQL> alter table receipts modify dateOfPurchase date add constraint
  2    ck_date check(dateOfPurchase<=today);

Table altered.

SQL> --"Dont forget to execute the stms. below this pl/sql block"
SQL> 
SQL> create or replace procedure query2
  2  (x_rno receipts.rno%type,
  3   x_date receipts.dateofpurchase%type)
  4  as
  5    insExcept   Exception;
  6    pragma exception_init (insExcept,-2290);
  7  
  8  begin
  9    insert into receipts(rno,dateofpurchase) values (x_rno,x_date);
 10  Exception
 11    when insExcept then
 12  	 dbms_output.put_line(chr(10)||q'!#### You are trying to insert a date that is greater than today's date #####!');
 13    when others then
 14  	 dbms_output.put_line('Error Code: '||sqlcode||chr(10)||'Error Msg: '||sqlerrm);
 15  end query2;
 16  --*****************************"OPUTPUT BELOW"**********************************
 17  /

Procedure created.

SQL> 
SQL> exec query2(&rno,&dateofpurchase);
Enter value for rno: 65432
Enter value for dateofpurchase: '14-MAR-19'

#### You are trying to insert a date that is greater than today's date #####   

PL/SQL procedure successfully completed.

SQL> --"Dont forget to execute the stms. below"
SQL> alter table receipts drop constraint ck_date;

Table altered.

SQL> alter table receipts drop column today;

Table altered.

SQL> --*****************************************************************************
SQL> 
SQL> select rno,dateofpurchase from receipts where rno=65432;

       RNO DATEOFPUR                                                            
---------- ---------                                                            
     65432 10-FEB-19                                                            

SQL> delete from receipts where rno=65432;

1 row deleted.

SQL> spool off
