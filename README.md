# login-system
console application of login system with cpp and mysql by devops

"libmysql.dill" is a file that present in "lib" folder of MYSQL (MySQL\MySQL Server 8.0\lib)

# softwares
Dev-cpp cpp MYSQL 

# Step 1:
    1) select project option - Directories - library Directories
        add "MySQL\MySQL Server 8.0\lib" folder path.
    2) select project option - Directories - include Directories
        add "MySQL\MySQL Server 8.0\include" folder path
        add "MySQL\MySQL Server 8.0\include\mysql" folder path
    3) select project option - Parameters - linker
        add "-lmysql"
# step 2:
    create database with name "SCHOOL"
    and table with name "login"
    __________________________
    | username  | password   |
    --------------------------
    | henry     | hen@3h     |
    --------------------------
# step 3:
    open "logincpp.dev" in Dev-cpp
# step 4:
    run "main.cpp" 
