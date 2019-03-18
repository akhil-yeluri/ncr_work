create table details(name varchar(1),id int);
use ncrwork;
select * from details;
drop table details;
create table details(name varchar(1),id int);
alter table details add address varchar(20);
exec sp_columns details;
alter table details drop column id;
alter table details add id int;
exec sp_help details;
exec sp_rename 'details' ,'employee';
select * from employee;
alter table employee drop column address;
alter table employee add salary int;
exec sp_help employee;
drop table employee;
create table employee(name varchar(20),empid int,department_number int,salary int,job varchar(20),commission int,location varchar(20));
exec sp_help employee;
insert into employee values('akhil',1,6,143000,'software developer',50000,'dallas'),('anil',2,6,1000,'clerk',500,'dallas'),('satish',3,6,1500,'clerk',500,'dallas');
select * from employee;

/*1*/select name from employee where salary>=1000 and salary<=2000;

insert into employee values('chris green',4,23,43000,'ux developer',5000,'dallas');

/*2*/select department_number,name from employee order by department_number,name;

exec sp_help employee;
insert into employee values('akhil yeluri',1,10,143000,'software developer',50000,'dallas'),('aizant',2,10,1000,'clerk',500,'dallas'),('azure',3,20,1500,'clerk',500,'dallas');
select * from employee;

/*4*/select name,department_number from employee where department_number in (10,20) order by name;

insert into employee values('theon grejoy',1,10,13000,'software developer',5000,'dallas'),('night kingll',1,10,13000000,'white walker',5000,'winter');

/*6*/select name,job from employee where name like '%%th%' or name like '%ll%'  ;

/*3*/ select distinct(job) as 'different jobs' from employee;

/*8*/ select name,(salary + commission) as 'remuneration' from employee;

alter table employee add HasManager varchar(3);

exec sp_help employee;

update employee set HasManager='yes';

select * from employee;

update employee set HasManager='no' where name like '%th%' or name like '%akhil yeluri%';

/*7*/ select name from employee where HasManager like 'yes';

insert into employee values('cerseiL',7,7,10,'sales',500000,'kingsL','no'),('jaimeL',8,7,130,'sales',50000,'kingsL','yes'),('tyrionL',9,7,13080,'sales',50000,'dragonS','no');

/*9*/ select name,(salary*12) as 'annual salary', commission from employee where job='sales' and salary<commission order by salary desc,name;

/*10*/ select name,(salary*0.15) "salary increased by 15%",CONCAT(name,CONCAT(' is a ',job)) "job role" from employee;

/*11*/ update employee set job='salesperson' where job='sales'; 

/*12*/ select job,max(salary) "highest salary",min(salary) "min salary" from employee group by job; 

/*13*/ select count(name) "Number of Managers" from employee where HasManager='yes';

/*14*/ select job,avg(salary) "average salary" ,sum(salary)+sum(commission) "Total Remuneration given" from employee group by job;

/*15*/ select (max(salary)-min(salary)) "difference between highest and lowest salary" from employee;

/*16*/ select job "job description" from employee group by job having count(name) >=3 ;

/*17*/ select count(empid)"total ids" , count(distinct (empid))"distinct ids" from employee;

/*18*/ select job,min(salary)"Minimum salary" from employee group by job  ;

/*creating new tables*/
 CREATE TABLE dept(
  deptno int,
  dname  nVARCHAR(14),
  loc    nVarchar(13),
  CONSTRAINT pk_dept PRIMARY KEY (deptno));

 CREATE TABLE emp(
  empno    int,
  ename    nVARCHAR(10),
  job      nVARCHAR(9),
  mgr      INT,
  hiredate DATE,
  sal      DECIMAL(7,2),
  comm     DECIMAL(7,2),
  deptno   INT,
  CONSTRAINT pk_emp PRIMARY KEY (empno),
  constraint fk_deptno foreign key (deptno) references dept(deptno)
);

/*dept and emp2 tables*/


INSERT INTO dept VALUES(10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO dept VALUES(20, 'RESEARCH', 'DALLAS');
INSERT INTO dept VALUES(30, 'SALES', 'CHICAGO');
INSERT INTO dept VALUES(40, 'OPERATIONS', 'BOSTON');


INSERT INTO emp VALUES(
 7839, 'KING', 'PRESIDENT', null,
 convert(datetime,'1981-11-17'),
 5000, null, 10);

INSERT INTO emp VALUES(
 7698, 'BLAKE', 'MANAGER', 7839,
 ('1-5-1981'),
 2850, null, 30);

INSERT INTO emp VALUES(
 7782, 'CLARK', 'MANAGER', 7839,
 '9-6-1981',
 2450, null, 10);

INSERT INTO emp VALUES(
 7566, 'JONES', 'MANAGER', 7839,
 ('2-4-1981'),
 2975, null, 20);

INSERT INTO emp VALUES(
 7788, 'SCOTT', 'ANALYST', 7566,
('13-JUL-87'),
 3000, null, 20);

INSERT INTO emp VALUES(
 7902, 'FORD', 'ANALYST', 7566,
('3-12-1981'),
 3000, null, 20 );

INSERT INTO emp VALUES(
 7369, 'SMITH', 'CLERK', 7902,
 convert(datetime,'1980-12-17'),
 800, null, 20 );

INSERT INTO emp VALUES(
 7499, 'ALLEN', 'SALESMAN', 7698,
 ('1981-2-20'),
 1600, 300, 30);

INSERT INTO emp VALUES(
 7521, 'WARD', 'SALESMAN', 7698,
 ('1981-2-22'),
 1250, 500, 30 );

INSERT INTO emp VALUES(
 7654, 'MARTIN', 'SALESMAN', 7698,
 ('1981-9-28'),
 1250, 1400, 30 );

INSERT INTO emp VALUES(
 7844, 'TURNER', 'SALESMAN', 7698,
 ('1981-8-9'),
 1500, 0, 30);

INSERT INTO emp VALUES(
 7876, 'ADAMS', 'CLERK', 7788,
 ('13-JUL-87'),
 1100, null, 20 );

INSERT INTO emp VALUES(
 7900, 'JAMES', 'CLERK', 7698,
 ('3-12-1981'),
 950, null, 30 );

INSERT INTO emp VALUES(
 7934, 'MILLER', 'CLERK', 7782,
 ('1982-1-23'),
 1300, null, 10 );

 CREATE TABLE salgrade(
  grade int,
  losal int,
  hisal int
);

INSERT INTO salgrade VALUES (1, 700, 1200);
INSERT INTO salgrade VALUES (2, 1201, 1400);
INSERT INTO salgrade VALUES (3, 1401, 2000);
INSERT INTO salgrade VALUES (4, 2001, 3000);
INSERT INTO salgrade VALUES (5, 3001, 9999);

 select * from emp;
 select * from dept;


 /*18*/ select min(sal)"minimum salary",mgr from emp group by  mgr having mgr in (select mgr from emp where mgr is not null) and min(sal)>1000 order by min(sal) desc;

 /*19*/ select  ename,dname from emp,dept where emp.deptno=dept.deptno order by dname;

 /*20*/ select ename,dname,emp.deptno from emp,dept where emp.deptno=dept.deptno; 

 /*21*/  select ename"name",loc"location",dname "department" from emp,dept where emp.deptno=dept.deptno and emp.sal>1500;

 /*22*/  select ename "employees from grade 3" from emp,salgrade where emp.sal>=salgrade.losal and sal<= salgrade.hisal and salgrade.grade=3;

 /*23*/ select ename from emp where deptno in (select deptno from dept where loc ='dallas');

 /*24*/ select ename,job,sal,(select grade from salgrade where emp.sal>=losal and emp.sal<=hisal)"grade",dname from emp,dept where emp.deptno=dept.deptno and emp.job!='clerk' order by emp.sal desc;

 /*25*/ select * from emp where sal*12>=36000 or job='clerk';

 /*26*/ select dname,deptno from dept where dept.deptno not in(select emp.deptno from emp);

 /*27*/ select job ,max(sal)"max salary" from emp group by job order by max(sal) desc; 
