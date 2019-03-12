SQL> @"E:\B.Harish\Sem 4\Dbms\Lab6\ex6.sql"
SQL> set serveroutput on;
SQL> SET ECHO ON
SQL> --1. For the given receipt number, calculate the Discount as follows:
SQL> 
SQL> drop sequence ordinal_no_seq;

Sequence dropped.

SQL> create sequence ordinal_no_seq
  2  	 start with 1
  3  	 increment by 1
  4  	 minvalue 1
  5  	 maxvalue 10
  6  	 cycle
  7  	 cache 4
  8  	 order;

Sequence created.

SQL> 
SQL> CREATE OR REPLACE PROCEDURE discountCalc(x_rno IN receipts.rno%TYPE) AS
  2  
  3    x_date receipts.dateOfPurchase%type :='19-OCT-2007';
  4  
  5    CURSOR cursorOne IS
  6  	 SELECT  p.food, p.flavour, c.fname, c.lname, p.price
  7  	 FROM products p, item_list i, receipts r, customers c
  8  	 WHERE p.pid = i.item AND i.receipt = x_rno AND r.dateOfPurchase = x_date
  9  	 AND r.rno=i.receipt AND c.cid = r.cid
 10  	 GROUP BY p.flavour, p.food, p.price, c.fname, c.lname;
 11  
 12    type discountClass IS RECORD(
 13  	 a_food products.food%type,
 14  	 a_flavour products.flavour%type,
 15  	 a_fname customers.fname%type,
 16  	 a_lname customers.lname%type,
 17  	 price products.price%type
 18    );
 19    discObj discountClass;
 20    discount number(2,2);
 21    totalVal number := 0;
 22    amt number := 0;
 23  
 24  BEGIN
 25  
 26    SELECT  sum(p.price) into totalVal
 27  	   FROM products p, item_list i, receipts r, customers c
 28  	   WHERE p.pid = i.item AND i.receipt = x_rno AND r.dateOfPurchase = x_date
 29  	   AND r.rno=i.receipt AND c.cid = r.cid;
 30  
 31    IF (totalVal BETWEEN 10 AND 25 )THEN
 32  	     discount := 0.05;
 33  	   ELSIF (totalVal BETWEEN 25 AND 50) THEN
 34  	     discount := 0.10;
 35  	   ELSIF (totalVal > 50) THEN
 36  	     discount := 0.20;
 37  	   ELSE
 38  	     discount := 0;
 39  	   END IF;
 40  
 41    OPEN cursorOne;
 42  	 LOOP
 43  	   FETCH cursorOne into discObj;
 44  	   EXIT WHEN cursorOne%NOTFOUND;
 45  
 46  	   IF ordinal_no_seq.nextval = 1 THEN
 47  	     DBMS_OUTPUT.PUT_LINE('*******************************************************************************');
 48  	     DBMS_OUTPUT.PUT_LINE('Receipt Number: ' || x_rno || '	       Customer Name: ' || discObj.a_fname || ' ' || discObj.a_lname);
 49  	     DBMS_OUTPUT.PUT_LINE('Receipt Date: ' || x_date);
 50  	     DBMS_OUTPUT.PUT_LINE('*******************************************************************************');
 51  	     DBMS_OUTPUT.PUT_LINE(' ');
 52  	     DBMS_OUTPUT.PUT_LINE('Sno	     Flavour	   Food       Price');
 53  	   END IF;
 54  
 55  
 56  
 57  	 DBMS_OUTPUT.PUT_LINE(ordinal_no_seq.nextval/2 || '	     ' || discObj.a_flavour || '	' || discObj.a_food || '	 ' ||discObj.price);
 58  
 59  	 END LOOP;
 60  
 61  	 DBMS_OUTPUT.PUT_LINE('Total Amount:   $' || totalVal);
 62  	 DBMS_OUTPUT.PUT_LINE('Total Discount:	 (' || discount*100 || '% )	       :$' || discount*totalVal);
 63  	 amt:=totalVal - discount*totalVal;
 64  	 DBMS_OUTPUT.PUT_LINE('Amount to be paid:   $' || amt);
 65    CLOSE cursorOne;
 66  
 67  EXCEPTION
 68    WHEN OTHERS THEN
 69  	 DBMS_OUTPUT.PUT_LINE('Sqlcode:  '||sqlcode||' SqlerrMsg:  '||sqlerrm);
 70  END discountCalc;
 71  /

Procedure created.

SQL> 
SQL> exec discountCalc(13355);
******************************************************************************* 
Receipt Number: 13355             Customer Name: SHARRON TOUSSAND               
Receipt Date: 19-OCT-07                                                         
******************************************************************************* 
Sno       Flavour       Food       Price                                        
1          Napoleon        Cake         13.49                                   
2          Opera        Cake         15.95                                      
3          Lemon        Cookie         .79                                      
Total Amount:   $30.23                                                          
Total Discount:   (10% )            :$3.023                                     
Amount to be paid:   $27.207                                                    

PL/SQL procedure successfully completed.

SQL> 
SQL> 
SQL> --4:Write a stored function to display the customer name who ordered maximum for the
SQL> --given food and flavor.
SQL> 
SQL> create or replace function Max_Customer
  2    (x_food products.food%type,
  3  	x_flavour products.flavour%type
  4    )
  5    return varchar
  6  
  7    IS
  8  
  9    x_cust_fname customers.fname%type;
 10    x_cust_lname customers.lname%type;
 11  
 12  BEGIN
 13  
 14  
 15  select * into x_cust_fname,x_cust_lname from
 16  (select c.fname,c.lname from customers c,products p,receipts r,item_list i
 17  where c.cid=r.cid and r.rno=i.receipt and p.pid=i.item
 18  and p.food =x_food and p.flavour = x_flavour
 19  group by c.fname,c.lname order by count(i.item) desc) where rownum=1;
 20  
 21  DBMS_OUTPUT.PUT_LINE(chr(10)||'Customer Name: '||x_cust_fname||'  '||x_cust_lname);
 22  
 23  return concat(concat(x_cust_fname,' '),x_cust_lname);
 24  
 25  end Max_Customer;
 26  /

Function created.

SQL> 
SQL> declare
  2    op varchar(50);
  3  BEGIN
  4  
  5    op:=Max_Customer('&Food','&Flavour');
  6  
  7  end;
  8  /
Enter value for food: Tart
Enter value for flavour: Apple
old   5:   op:=Max_Customer('&Food','&Flavour');
new   5:   op:=Max_Customer('Tart','Apple');

Customer Name: CHARLENE  MESDAQ                                                

PL/SQL procedure successfully completed.

SQL> spool off
