print("hello world")
import sqlite3

# to do 

# Connect to database
def connect():
    conn = sqlite3.connect("to_do.db")
    cursor = conn.cursor()
    return (conn,cursor)

# it should be a cli interface that ask whether to create, read, update or remove
# CRUD
# Create task
def create_task(conn,cursor):
    
    task_name = input("Please enter task's name : ")
    task_description = input("Please enter task's content : ")
    cursor.execute("INSERT INTO tasks(task_name,task_description) VALUES(?,?)",(task_name,task_description))
    conn.commit()
    print("Task added to database")
# Read tasks
def display_tasks(cursor):
    cursor.execute("SELECT * from tasks")
    tasks = cursor.fetchall()
    for id, task_name, task_description in tasks:
        print(f"{id}-- {task_name} -- {task_description}")
    
# Update Tasks
def update_task(conn,cursor):
    #get the content of the task by id
    task_id = int(input("Please enter id: "))
    cursor.execute("SELECT task_name,task_description FROM tasks WHERE id=?",(task_id,))
    task = cursor.fetchone()
    delete_task(conn,cursor,task_id)
    create_task(conn,cursor)
    # delete the task 
    # create the task
# Delete task
def delete_task(conn,cursor,task_id):
    cursor.execute("DELETE FROM tasks WHERE id=?",(task_id,))
    conn.commit()
    print("Task deleted")
def main():
    conn, cursor = connect()

    #create table 
    cursor.execute('''CREATE TABLE IF NOT EXISTS tasks(
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    task_name TEXT,
                    task_description TEXT
                    )''')

    
    # create cli interface
    while True:
        user_input =  input("1-Create, 2-Read , 3-Delete : ")

        if user_input == 'q':
            break
        if user_input == '1':
            create_task(conn,cursor)
        if user_input == "2":
            display_tasks(cursor)
        if user_input == "3":
            task_id = int(input("which task ? : "))
            delete_task(conn,cursor,task_id)
        if user_input == "4":
            update_task(conn,cursor)
            
    conn.close()
    return
main()