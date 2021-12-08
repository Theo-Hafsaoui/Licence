tp=# create table Employe(
EID integer CHECK(EID>9 AND EID<100) PRIMARY KEY,
Nom VARCHAR(20),Dept VARCHAR(2),
CONSTRAINT Dept_fk
   FOREIGN KEY (dept)
      REFERENCES Departement (did));
CREATE TABLE

##########################################

INSERT INTO Departement VALUES ('01','Info');

"tp=# ROLLBACK ;
WARNING:  there is no transaction in progress
ROLLBACK"

##########################################
tp=# begin transaction;
   INSERT INTO Departement VALUES ('02','SupInfo');

   result: 
   pendant
    did | libelle
-----+---------
 01  | Info
 02  | SupInfo


 did | libelle
-----+---------
 01  | Info

Apres le commit
tp=# Table departement
tp-# ;
 did | libelle
-----+---------
 01  | Info
 02  | SupInfo

tp=# Table departement
tp-# ;
 did | libelle
-----+---------
 01  | Info
 02  | SupInfo
(2 rows)

##########################################
tp=# begin transaction;
BEGIN
tp=*# INSERT INTO Departement VALUES ('03','MegaSupInfo');
INSERT 0 1
tp=*# commit;
COMMIT
tp=# rollback;
WARNING:  there is no transaction in progress
ROLLBACK
tp=# table departement
tp-# ;
 did |   libelle
-----+-------------
 01  | Info
 02  | SupInfo
 03  | MegaSupInfo
(3 rows)
##########################################
tp=# begin transaction;
BEGIN
tp=*# INSERT INTO Departement VALUES ('04','OmegaMegaSupInfo');
INSERT 0 1
tp=*# quit
could not save history to file "/var/lib/postgres/.psql_history": No such file or directory
[postgres@Stormblessed ~]$ psql
psql (13.4)
Type "help" for help.

postgres=# t
table     truncate
postgres=# t
table     truncate
postgres=# table de

postgres=# table de

postgres=# table dep

postgres=# table dep

postgres=# \c tp
You are now connected to database "tp" as user "postgres".
tp=# table departement ;
 did |   libelle
-----+-------------
 01  | Info
 02  | SupInfo
 03  | MegaSupInfo
(3 rows)

tp=#
#########################################
Sauvegarder
########
p=# truncate table departement CASCADE;
NOTICE:  truncate cascades to table "employe"
TRUNCATE TABLE
tp=# table departement
;
 did | libelle
-----+---------
(0 rows)
8/le rollback a permis la restauration.
9/j ai tout perdu

#########################################
10 et 11/
tp=# INSERT INTO employe VALUES (10,'quentin','C1');
INSERT 0 1
tp=# INSERT INTO Departement VALUES ('C1','SupInfoNull');
ERROR:  duplicate key value violates unique constraint "departement_pkey"
DETAIL:  Key (did)=(C1) already exists.
12/ on peut pas
tp=# INSERT INTO employe VALUES (20,'edouar','C2');
ERROR:  insert or update on table "employe" violates foreign key constraint "dept_fk"
DETAIL:  Key (dept)=(C2) is not present in table "departement".
13/
tp=# delete from departement where did = 'C1';
ERROR:  update or delete on table "departement" violates foreign key constraint "dept_fk" on table "employe"
DETAIL:  Key (did)=(C1) is still referenced from table "employe".
14/
tp=# alter table employe drop constraint dept_fk;
ALTER TABLE
tp=# table departement ;
 did | libelle
-----+----------
 C1  | InfoNull
(1 row)

tp=# table employe ;
 eid |   nom   | dept
-----+---------+------
  10 | quentin | C1
(1 row)
16/
alter table employe add constraint dept_fkey foreign key (dept) references Departement(did) ON DELETE CASCADE;
ALTER TABLE
17/
tp=# delete from departement where did = 'C1';
DELETE 1
tp=# table employe ;
 eid |   nom   | dept
-----+---------+------
  10 | quentin | C1
(1 row)

tp=# table departement ;
 did | libelle
-----+---------
tp=# table employe ; table departement ;
 eid | nom | dept
-----+-----+------
(0 rows)

 did | libelle
-----+---------
(0 rows)
18/
tp=# INSERT INTO Departement VALUES ('C1','SupInfoNull');
INSERT 0 1
tp=# table departement
tp-# ;
 did |   libelle
-----+-------------
 C1  | SupInfoNull
(1 row)

tp=# INSERT INTO employe VALUES (10,'quentin','C1');
INSERT 0 1
19/
tp=# alter table employe add constraint dept_fkey foreign key (dept) references Departement(did) deferrable;
ALTER TABLE
20/
tp=# delete from departement where did = 'C1';
ERROR:  update or delete on table "departement" violates foreign key constraint "dept_fkey" on table "employe"
DETAIL:  Key (did)=(C1) is still referenced from table "employe".
21/
tp=# begin transaction ;
BEGIN
tp=*# SET CONSTRAINTS dept_fkey deferred;
SET CONSTRAINTS
tp=*# delete from departement where did = 'C1';
DELETE 1
tp=*# table departement
;
 did | libelle
-----+---------
(0 rows)

tp=*# commit;
ERROR:  update or delete on table "departement" violates foreign key constraint "dept_fkey" on table "employe"
DETAIL:  Key (did)=(C1) is still referenced from table "employe".
tp=# table departement
;
 did |   libelle
-----+-------------
 C1  | SupInfoNull
(1 row)

Partie 2
3/ terminal 1:
tp=# begin transaction ;
BEGIN
tp=*# INSERT INTO Departement VALUES ('03','OmegaInfo');
INSERT 0 1
tp=*# table departement ;
 did |   libelle
-----+-------------
 C1  | SupInfoNull
 03  | OmegaInfo
(2 rows)

tp=*# table departement ;
 did |     libelle
-----+------------------
 C1  | SupInfoNull
 04  | OmegaMegaSupInfo
 03  | OmegaInfo
(3 rows)

terminal 2:

postgres=#
postgres=# \c tp
You are now connected to database "tp" as user "postgres".
tp=# begin transaction ;
BEGIN
tp=*# INSERT INTO Departement VALUES ('04','OmegaMegaSupInfo');
INSERT 0 1
tp=*# table departement ;
 did |     libelle
-----+------------------
 C1  | SupInfoNull
 04  | OmegaMegaSupInfo
(2 rows)

tp=*# commit;
COMMIT

q4 et q5/ le terminal 2 ce met en attente. et se remet en libre si on fait
un rollback ou commit.

q6/les table sont vide
q7/ajout d un departement.
q8 et 9/les table sont update suite au commit
q10/ca bloque
q11/elle se debloque
q12/les table sont mis a jour
q14 et 15/la duxieme insertion ne fonctione pas si la premier n'est pas commit
q16/les deux fonctionne
q17/la session se met en attente
q19 et 20/une fois commit l'update se propage.
